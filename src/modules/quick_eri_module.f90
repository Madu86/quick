!---------------------------------------------------------------------!
! Created by Madu Manathunga on 04/16/2020                            !
!                                                                     !
! Previous contributors: Yipu Miao, Xio He, Alessandro Genoni,        !
!                         Ken Ayers & Ed Brothers                     !
!                                                                     ! 
! Copyright (C) 2020-2021 Merz lab                                    !
! Copyright (C) 2020-2021 Götz lab                                    !
!                                                                     !
! This Source Code Form is subject to the terms of the Mozilla Public !
! License, v. 2.0. If a copy of the MPL was not distributed with this !
! file, You can obtain one at http://mozilla.org/MPL/2.0/.            !
!_____________________________________________________________________!

#ifdef OSHELL
module quick_oshell_module
#else
module quick_cshell_module
#endif

   implicit double precision(a-h,o-z)
   private
#ifdef OSHELL
   public :: get_oshell_eri
   public :: get_oshell_eri_energy 
#else
   public :: cshell ! Should be private, but we still need this for deprecated
                    ! subroutines such as addInt in shell.f90
   public :: get_cshell_eri
   public :: get_cshell_eri_energy
   public :: get_eri_precomputables 
#endif 
contains

#ifndef OSHELL

subroutine get_eri_precomputables

   !-----------------------------------------------------------------
   ! This subroutine computes precomputable quantities given by
   ! HGP equations 8, 9 and 15. The resulting quantities are
   ! stored in Apri, Ppri and Kpri. Additionally we compute Xcoeff 
   ! which is a combined coefficient for two indices (a product of 
   ! Kpri and normalized coefficients).
   ! See HGP paper for equations and APPENDIX: COMPUTER IMPLEMENTATION
   ! section: 
   ! Head‐Gordon, M.; Pople, J. A. A Method for Two‐electron 
   ! Gaussian Integral and Integral Derivative Evaluation Using
   ! Recurrence Relations. J. Chem. Phys. 1988, 89, 5777–5786.
   !__________________________________________________________________

   use allmod

   implicit none

#ifdef MPIV
   include "mpif.h"
#endif

   integer ics,ips,jcs,jps,itemp,itemp2,i
   integer NA,NB
   double precision AA,BB,XYZA(3),XYZB(3),DAB
   if (master) then
   ! ics cycle
   do ics=1,jshell                       ! ics is the shell no.
      do ips=1,quick_basis%kprim(ics)                ! ips is prim no. for certain shell

         ! jcs cycle
         do jcs=1,jshell
            do jps=1,quick_basis%kprim(jcs)

               ! We have ics,jcs, ips and jps, which is the prime for shell, so we can
               ! obtain its global prim. and its exponents and coeffecients
               NA=quick_basis%kstart(ics)+IPS-1         ! we can get globle prim no. for ips
               NB=quick_basis%kstart(jcs)+jps-1         ! and jps

               AA=quick_basis%gcexpo(ips,quick_basis%ksumtype(ics))    ! so we have the exponent part for ics shell ips prim
               BB=quick_basis%gcexpo(jps,quick_basis%ksumtype(jcs))    ! and jcs shell jps prim
               Apri(NA,NB)=AA+BB                     ! A'=expo(A)+expo(B)
               do i=1,3
                  XYZA(i)=xyz(i,quick_basis%katom(ics))     ! xyz(A)
                  XYZB(i)=xyz(i,quick_basis%katom(jcs))     ! xyz(B)
               enddo
               !DAB=quick_molspec%atomdistance(quick_basis%katom(ics),quick_basis%katom(jcs))
               DAB = dsqrt((xyz(1,quick_basis%katom(ics))-xyz(1,quick_basis%katom(jcs)))**2 + &
                           (xyz(2,quick_basis%katom(ics))-xyz(2,quick_basis%katom(jcs)))**2 + &
                           (xyz(3,quick_basis%katom(ics))-xyz(3,quick_basis%katom(jcs)))**2 )

               ! P' is the weighting center of NpriI and NpriJ
               !              expo(A)*xyz(A)+expo(B)*xyz(B)
               ! P'(A,B)  = ------------------------------
               !                 expo(A) + expo(B)
               do i=1,3
                  Ppri(i,NA,NB) = (XYZA(i)*AA + XYZB(i)*BB)/(AA+BB)
               enddo

               !                    expo(A)*expo(B)*(xyz(A)-xyz(B))^2              1
               ! K'(A,B) =  exp[ - ------------------------------------]* -------------------
               !                            expo(A)+expo(B)                  expo(A)+expo(B)
               Kpri(NA,NB) = dexp(-AA*BB/(AA+BB)*(DAB**2))/(AA+BB)

               do  itemp=quick_basis%Qstart(ics),quick_basis%Qfinal(ics)
                  do itemp2=quick_basis%Qstart(jcs),quick_basis%Qfinal(jcs)

                     ! Xcoeff(A,B,itmp1,itmp2)=K'(A,B)*a(itmp1)*a(itmp2)
                     quick_basis%Xcoeff(NA,NB,itemp,itemp2)=Kpri(NA,NB)* &

                           quick_basis%gccoeff(ips,quick_basis%ksumtype(ics)+Itemp )* &

                           quick_basis%gccoeff(jps,quick_basis%ksumtype(jcs)+Itemp2)
                  enddo
               enddo

            enddo
         enddo
      enddo
   enddo
   endif

#ifdef MPIV
      if (bMPI) then
         call MPI_BCAST(Ppri,3*jbasis*jbasis,mpi_double_precision,0,MPI_COMM_WORLD,mpierror)
         call MPI_BCAST(Kpri,jbasis*jbasis,mpi_double_precision,0,MPI_COMM_WORLD,mpierror)
         call MPI_BCAST(Apri,jbasis*jbasis,mpi_double_precision,0,MPI_COMM_WORLD,mpierror)
         call MPI_BCAST(quick_basis%Xcoeff,jbasis*jbasis*4*4,mpi_double_precision,0,MPI_COMM_WORLD,mpierror)
         call MPI_BARRIER(MPI_COMM_WORLD,mpierror)
      endif
#endif

end subroutine get_eri_precomputables
#endif

#ifdef OSHELL
subroutine get_oshell_eri(II_arg)
#else
subroutine get_cshell_eri(II_arg)
#endif

   !------------------------------------------------
   ! This subroutine is to get 2e integral
   !------------------------------------------------
   use allmod
   implicit double precision(a-h,o-z)
   double precision testtmp,cutoffTest
   integer II_arg
   common /hrrstore/II,JJ,KK,LL,NBI1,NBI2,NBJ1,NBJ2,NBK1,NBK2,NBL1,NBL2
   II = II_arg
   do JJ = II,jshell
       testtmp = Ycutoff(II,JJ)
      do KK = II,jshell
         do LL = KK,jshell

          cutoffTest = testtmp * Ycutoff(KK,LL)
          if (cutoffTest .gt. quick_method%integralCutoff) then
            DNmax =  max(4.0d0*cutmatrix(II,JJ), &
                  4.0d0*cutmatrix(KK,LL), &
                  cutmatrix(II,LL), &
                  cutmatrix(II,KK), & 
                  cutmatrix(JJ,KK), &
                  cutmatrix(JJ,LL))
            ! (IJ|KL)^2<=(II|JJ)*(KK|LL) if smaller than cutoff criteria, then
            ! ignore the calculation to save computation time
            
            if ( cutoffTest * DNmax  .gt. quick_method%integralCutoff ) &
#ifdef OSHELL 
                call oshell
#else
                call cshell
#endif
           endif
         enddo
      enddo 
   enddo

#ifdef OSHELL
end subroutine get_oshell_eri
#else
end subroutine get_cshell_eri
#endif


! Vertical Recursion by Xiao HE 07/07/07 version
#ifdef OSHELL
subroutine oshell
#else
subroutine cshell
#endif

   use allmod

   Implicit double precision(a-h,o-z)
   double precision P(3),Q(3),W(3),KAB,KCD,AAtemp(3)
   Parameter(NN=13)
   double precision FM(0:13)
   double precision RA(3),RB(3),RC(3),RD(3)

   double precision Qtemp(3),WQtemp(3),CDtemp,ABcom,Ptemp(3),WPtemp(3),ABtemp,CDcom,ABCDtemp
   integer II,JJ,KK,LL,NBI1,NBI2,NBJ1,NBJ2,NBK1,NBK2,NBL1,NBL2

   common /hrrstore/II,JJ,KK,LL,NBI1,NBI2,NBJ1,NBJ2,NBK1,NBK2,NBL1,NBL2
   COMMON /VRRcom/Qtemp,WQtemp,CDtemp,ABcom,Ptemp,WPtemp,ABtemp,CDcom,ABCDtemp
   COMMON /COM1/RA,RB,RC,RD

   do M=1,3
      RA(M)=xyz(M,quick_basis%katom(II))
      RB(M)=xyz(M,quick_basis%katom(JJ))
      RC(M)=xyz(M,quick_basis%katom(KK))
      RD(M)=xyz(M,quick_basis%katom(LL))
   enddo

  ! Get angular momenta quantum number for each of the 4 shells
  ! s=0~0, p=1~1, sp=0~1, d=2~2, f=3~3

   NII1=quick_basis%Qstart(II)
   NII2=quick_basis%Qfinal(II)
   NJJ1=quick_basis%Qstart(JJ)
   NJJ2=quick_basis%Qfinal(JJ)
   NKK1=quick_basis%Qstart(KK)
   NKK2=quick_basis%Qfinal(KK)
   NLL1=quick_basis%Qstart(LL)
   NLL2=quick_basis%Qfinal(LL)

!--------------------Madu---------------------------
!  write(*,'(A40,1x,I2,1x,I2,1x,I2,1x,I2,1x,I2,1x,I2,1x,I2,1x,I2)') &
!  "Madu: I1, I2, J1, J2, K1, K2, L1, L2", &
!  NII1, NII2, NJJ1, NJJ2, NKK1, NKK2, NLL1, NLL2
 ! stop
!--------------------Madu---------------------------

   NNAB=(NII2+NJJ2)
   NNCD=(NKK2+NLL2)

   NABCDTYPE=NNAB*10+NNCD


   NNAB=sumindex(NNAB)
   NNCD=sumindex(NNCD)
   NNA=sumindex(NII1-1)+1
   NNC=sumindex(NKK1-1)+1

   !The summation of the highest angular momentum number 
   !of each shell. 
   NABCD=NII2+NJJ2+NKK2+NLL2
   ITT=0

!--------------------Madu---------------------------
!  write(*,'(A30,2x,I5,2x,I5,2x,I5,2x,I5,2x,I5,2x,I5)') &
!  "Madu: NABCDTYPE, NNAB, NNCD, NNA, NNC, NABCD", &
!  NABCDTYPE, NNAB, NNCD, NNA, NNC, NABCD
  !stop
!--------------------Madu--------------------------

   !  the first cycle is for j prim
   !  JJJ and NpriJ are the tracking indices
   do JJJ=1,quick_basis%kprim(JJ)
     
      Nprij=quick_basis%kstart(JJ)+JJJ-1

      ! the second cycle is for i prim
      ! II and NpriI are the tracking indices
      do III=1,quick_basis%kprim(II)
         Nprii=quick_basis%kstart(II)+III-1
         !For NpriI and NpriJ primitives, we calculate the following quantities
         AB=Apri(Nprii,Nprij)    ! AB = Apri = expo(NpriI)+expo(NpriJ). Eqn 8 of HGP.
         ABtemp=0.5d0/AB         ! ABtemp = 1/(2Apri) = 1/2(expo(NpriI)+expo(NpriJ))
         ! This is term is required for Eqn 6 of HGP. 
         cutoffprim1=dnmax*cutprim(Nprii,Nprij)

         do M=1,3
            !Eqn 9 of HGP
            ! P' is the weighting center of NpriI and NpriJ
            !                           --->           --->
            ! ->  ------>       expo(I)*xyz(I)+expo(J)*xyz(J)
            ! P = P'(I,J)  = ------------------------------
            !                       expo(I) + expo(J)
            P(M)=Ppri(M,Nprii,Nprij)
           
            !Multiplication of Eqns 9  by Eqn 8 of HGP.. 
            !                        -->            -->
            ! ----->         expo(I)*xyz(I)+expo(J)*xyz(J)                                 -->            -->
            ! AAtemp = ----------------------------------- * (expo(I) + expo(J)) = expo(I)*xyz(I)+expo(J)*xyz(J)
            !                  expo(I) + expo(J)
            AAtemp(M)=P(M)*AB

            !Requires for HGP Eqn 6. 
            ! ----->   ->  ->
            ! Ptemp  = P - A
            Ptemp(M)=P(M)-RA(M)
         enddo

         ! the third cycle is for l prim
         ! LLL and npriL are the tracking indices
         do LLL=1,quick_basis%kprim(LL)
            Npril=quick_basis%kstart(LL)+LLL-1

            ! the forth cycle is for k prim
            ! the KKK and nprik are the tracking indices
            do KKK=1,quick_basis%kprim(KK)
               Nprik=quick_basis%kstart(KK)+KKK-1

               ! prim cutoff: cutoffprim(I,J,K,L) = dnmax * cutprim(I,J) * cutprim(K,L)
               cutoffprim=cutoffprim1*cutprim(Nprik,Npril)
               if(cutoffprim.gt.quick_method%primLimit)then

                  !Nita quantity of HGP Eqn 10. This is same as
                  !zita (AB) above. 
                  CD=Apri(Nprik,Npril)  ! CD = Apri = expo(NpriK) + expo(NpriL)

                  !First term of HGP Eqn 12 without sqrt. 
                  ABCD=AB+CD            ! ABCD = expo(NpriI)+expo(NpriJ)+expo(NpriK)+expo(NpriL)

                  !First term of HGP Eqn 13.
                  !         AB * CD      (expo(I)+expo(J))*(expo(K)+expo(L))
                  ! Rou = ----------- = ------------------------------------
                  !         AB + CD         expo(I)+expo(J)+expo(K)+expo(L)
                  ROU=AB*CD/ABCD

                  RPQ=0.0d0
                  
                  !First term of HGP Eqn 12 with sqrt. 
                  !              _______________________________
                  ! ABCDxiao = \/expo(I)+expo(J)+expo(K)+expo(L)
                  ABCDxiao=dsqrt(ABCD)

                  !Not sure why we calculate the following. 
                  CDtemp=0.5d0/CD       ! CDtemp =  1/2(expo(NpriK)+expo(NpriL))

                  !These terms are required for HGP Eqn 6.
                  !                expo(I)+expo(J)                        expo(K)+expo(L)
                  ! ABcom = --------------------------------  CDcom = --------------------------------
                  !          expo(I)+expo(J)+expo(K)+expo(L)           expo(I)+expo(J)+expo(K)+expo(L)
                  ABcom=AB/ABCD
                  CDcom=CD/ABCD

                  ! ABCDtemp = 1/2(expo(I)+expo(J)+expo(K)+expo(L))
                  ABCDtemp=0.5d0/ABCD

                  do M=1,3

                     !Calculate Q of HGP 10, which is same as P above. 
                     ! Q' is the weighting center of NpriK and NpriL
                     !                           --->           --->
                     ! ->  ------>       expo(K)*xyz(K)+expo(L)*xyz(L)
                     ! Q = P'(K,L)  = ------------------------------
                     !                       expo(K) + expo(L)
                     Q(M)=Ppri(M,Nprik,Npril)

                     !HGP Eqn 10. 
                     ! W' is the weight center for NpriI,NpriJ,NpriK and NpriL
                     !                --->             --->             --->            --->
                     ! ->     expo(I)*xyz(I) + expo(J)*xyz(J) + expo(K)*xyz(K) +expo(L)*xyz(L)
                     ! W = -------------------------------------------------------------------
                     !                    expo(I) + expo(J) + expo(K) + expo(L)
                     W(M)=(AAtemp(M)+Q(M)*CD)/ABCD

                     !Required for HGP Eqn 13.
                     !        ->  ->  2
                     ! RPQ =| P - Q |
                     XXXtemp=P(M)-Q(M)
                     RPQ=RPQ+XXXtemp*XXXtemp
                        
                     !Not sure why we need the next two terms. 
                     ! ---->   ->  ->
                     ! Qtemp = Q - K
                     Qtemp(M)=Q(M)-RC(M)

                     ! ----->   ->  ->
                     ! WQtemp = W - Q
                     ! ----->   ->  ->
                     ! WPtemp = W - P
                     WQtemp(M)=W(M)-Q(M)

                     !Required for HGP Eqns 6 and 16.
                     WPtemp(M)=W(M)-P(M)
                  enddo

                  !HGP Eqn 13. 
                  !             ->  -> 2
                  ! T = ROU * | P - Q|
                  T=RPQ*ROU
                  !                         2m        2
                  ! Fm(T) = integral(1,0) {t   exp(-Tt )dt}
                  ! NABCD is the m value, and FM returns the FmT value
                  call FmT(NABCD,T,FM)

                  !Go through all m values, obtain Fm values from FM array we
                  !just computed and calculate quantities required for HGP Eqn
                  !12. 
                  do iitemp=0,NABCD
                     ! Yxiaotemp(1,1,iitemp) is the starting point of recurrsion
                     Yxiaotemp(1,1,iitemp)=FM(iitemp)/ABCDxiao
                     !              _______________________________
                     ! ABCDxiao = \/expo(I)+expo(J)+expo(K)+expo(L)
                  enddo

                  ITT=ITT+1
                  ! now we will do vrr and and the double-electron integral
                  call vertical(NABCDTYPE)
                  do I2=NNC,NNCD
                     do I1=NNA,NNAB
                        Yxiao(ITT,I1,I2)=Yxiaotemp(I1,I2,0)
                     enddo
                  enddo
               endif
            enddo
         enddo
      enddo
   enddo

   do I=NII1,NII2
      NNA=Sumindex(I-1)+1
      do J=NJJ1,NJJ2
         NNAB=SumINDEX(I+J)
         do K=NKK1,NKK2
            NNC=Sumindex(k-1)+1
            do L=NLL1,NLL2
               NNCD=SumIndex(K+L)
!--------------------Madu---------------------------
!  write(*,'(A50,2x,I5,2x,I5,2x,I5,2x,I5,2x,I5,2x,I5)') &
!  "Madu: I, J, K, L, NNA, NNC, NNAB, NNCD", &
!  I, J, K, L, NNA, NNC, NNAB, NNCD 
!  stop
!--------------------Madu--------------------------
#ifdef OSHELL
                call iclass_oshell(I,J,K,L,NNA,NNC,NNAB,NNCD)
#else
                call iclass_cshell(I,J,K,L,NNA,NNC,NNAB,NNCD)
#endif
            enddo
         enddo
      enddo
   enddo
   201 return
#ifdef OSHELL
end subroutine oshell
#else
end subroutine cshell
#endif


! Horrizontal recursion and Fock matrix builder by Xiao HE 07/07/07 version
#ifdef OSHELL
subroutine iclass_oshell(I,J,K,L,NNA,NNC,NNAB,NNCD)
#else
subroutine iclass_cshell(I,J,K,L,NNA,NNC,NNAB,NNCD)
#endif
   use allmod

   Implicit double precision(A-H,O-Z)
   double precision store(120,120)
   INTEGER NA(3),NB(3),NC(3),ND(3)
   double precision P(3),Q(3),W(3),KAB,KCD
   Parameter(NN=13)
   double precision FM(0:13)
   double precision RA(3),RB(3),RC(3),RD(3)
   double precision AAtemp(3)
   double precision INTTMP(10000)
   integer INTNUM, IINT
   double precision Qtemp(3),WQtemp(3),CDtemp,ABcom,Ptemp(3),WPtemp(3),ABtemp,CDcom,ABCDtemp

   COMMON /VRRcom/Qtemp,WQtemp,CDtemp,ABcom,Ptemp,WPtemp,ABtemp,CDcom,ABCDtemp

   double precision X44(129600)

   COMMON /COM1/RA,RB,RC,RD
   COMMON /COM2/AA,BB,CC,DD,AB,CD,ROU,ABCD
   COMMON /COM4/P,Q,W
   COMMON /COM5/FM
   integer*4 A, B
   integer II,JJ,KK,LL,NBI1,NBI2,NBJ1,NBJ2,NBK1,NBK2,NBL1,NBL2
   common /xiaostore/store
   common /hrrstore/II,JJ,KK,LL,NBI1,NBI2,NBJ1,NBJ2,NBK1,NBK2,NBL1,NBL2

   do MM2 = NNC, NNCD
      do MM1 = NNA, NNAB
         store(MM1,MM2) = 0
      enddo
   enddo
!Madu: Following loop may be removed. 
!Its not used anywhere within the subroutine

   do M=1,3
      RA(M)=xyz(M,quick_basis%katom(II))
      RB(M)=xyz(M,quick_basis%katom(JJ))
      RC(M)=xyz(M,quick_basis%katom(KK))
      RD(M)=xyz(M,quick_basis%katom(LL))
   enddo

   NII1=quick_basis%Qstart(II)
   NII2=quick_basis%Qfinal(II)
   NJJ1=quick_basis%Qstart(JJ)
   NJJ2=quick_basis%Qfinal(JJ)
   NKK1=quick_basis%Qstart(KK)
   NKK2=quick_basis%Qfinal(KK)
   NLL1=quick_basis%Qstart(LL)
   NLL2=quick_basis%Qfinal(LL)


   NABCDTYPE=(NII2+NJJ2)*10+(NKK2+NLL2)

   NABCD=NII2+NJJ2+NKK2+NLL2
   itt = 0
   do JJJ=1,quick_basis%kprim(JJ)
      Nprij=quick_basis%kstart(JJ)+JJJ-1

      do III=1,quick_basis%kprim(II)
         Nprii=quick_basis%kstart(II)+III-1

         !X0 = 2.0d0*(PI)**(2.5d0), constants for HGP 15 
         ! multiplied twice for KAB and KCD

         X2=X0*quick_basis%Xcoeff(Nprii,Nprij,I,J)
         cutoffprim1=dnmax*cutprim(Nprii,Nprij)

         do LLL=1,quick_basis%kprim(LL)
            Npril=quick_basis%kstart(LL)+LLL-1

            do KKK=1,quick_basis%kprim(KK)
               Nprik=quick_basis%kstart(KK)+KKK-1
               cutoffprim=cutoffprim1*cutprim(Nprik,Npril)

               if(cutoffprim.gt.quick_method%primLimit)then

                  itt = itt+1
                  !This is the KAB x KCD value reqired for HGP 12.
                  !itt is the m value.
                  X44(ITT) = X2*quick_basis%Xcoeff(Nprik,Npril,K,L)
               endif
            enddo
         enddo
      enddo
   enddo

   !Here we complete HGP 12. 
   do MM2=NNC,NNCD
      do MM1=NNA,NNAB
         Ytemp=0.0d0
         do itemp=1,ITT
            Ytemp=Ytemp+X44(itemp)*Yxiao(itemp,MM1,MM2)
         enddo
         store(MM1,MM2)=Ytemp
!write(*,*) mpirank, Ytemp
      enddo
   enddo

!Get the start and end basis numbers for each angular momentum. 
!For eg. Qsbasis and Qfbasis are 1 and 3 for P basis. 
   NBI1=quick_basis%Qsbasis(II,I)
   NBI2=quick_basis%Qfbasis(II,I)
   NBJ1=quick_basis%Qsbasis(JJ,J)
   NBJ2=quick_basis%Qfbasis(JJ,J)
   NBK1=quick_basis%Qsbasis(KK,K)
   NBK2=quick_basis%Qfbasis(KK,K)
   NBL1=quick_basis%Qsbasis(LL,L)
   NBL2=quick_basis%Qfbasis(LL,L)

!--------------------Madu---------------------------
!  write(*,'(A50,2x,I5,2x,I5,2x,I5,2x,I5,2x,I5,2x,I5,2x,I5,2x,I5)') &
!  "Madu: I1, I2, J1, J2, K1, K2, L1, L2", &
!  NBI1,NBI2,NBJ1,NBJ2,NBK1,NBK2,NBL1,NBL2 
!  stop
!--------------------Madu--------------------------

   IJtype=10*I+J
   KLtype=10*K+L
   IJKLtype=100*IJtype+KLtype


   if((max(I,J,K,L).eq.2.and.(J.ne.0.or.L.ne.0)).or.(max(I,J,K,L).ge.3))IJKLtype=999

!quick_basis%ksumtype array has a cumulative sum of number of components of all
!shells 
   III1=quick_basis%ksumtype(II)+NBI1
   III2=quick_basis%ksumtype(II)+NBI2
   JJJ1=quick_basis%ksumtype(JJ)+NBJ1
   JJJ2=quick_basis%ksumtype(JJ)+NBJ2
   KKK1=quick_basis%ksumtype(KK)+NBK1
   KKK2=quick_basis%ksumtype(KK)+NBK2
   LLL1=quick_basis%ksumtype(LL)+NBL1
   LLL2=quick_basis%ksumtype(LL)+NBL2

!write(*,'(A20,2x,I3,2x,I3,2x,I3,2x,I3)') "Madu: II, JJ, KK,LL", &
!quick_basis%ksumtype(II),quick_basis%ksumtype(JJ), quick_basis%ksumtype(KK),&
!quick_basis%ksumtype(LL)

!do imadu=1,size(quick_basis%ksumtype)
!   write(*,*) imadu, quick_basis%ksumtype(imadu)
!enddo
!stop
!--------------------Madu---------------------------
!  write(*,'(A50,2x,I5,2x,I5,2x,I5,2x,I5,2x,I5,2x,I5,2x,I5,2x,I5)') &
!  "Madu: I1, I2, J1, J2, K1, K2, L1, L2", &
!  III1,III2,JJJ1,JJJ2,KKK1,KKK2,LLL1,LLL2
  !stop
!--------------------Madu--------------------------

   if (quick_method%nodirect) then
      INTNUM = 0
      do III=III1,III2
         do JJJ=max(III,JJJ1),JJJ2
            do KKK=max(III,KKK1),KKK2
               do LLL=max(KKK,LLL1),LLL2
                  if (III.lt.JJJ .and. III.lt. KKK .and. KKK.lt. LLL) then
                     call hrrwhole
                     if (abs(Y).gt.quick_method%maxIntegralCutoff) then
                        A = (III-1)*nbasis+JJJ-1
                        B = (KKK-1)*nbasis+LLL-1
                        INTNUM=INTNUM+1

                        if (incoreInt) then
                           incoreIndex = incoreIndex + 1
                           aIncore(incoreIndex) = A
                           bIncore(incoreIndex) = B
                           intIncore(incoreIndex) = Y
                        else
                           bufferInt = bufferInt + 1
                           aBuffer(bufferInt) = A
                           bBuffer(bufferInt) = B 
                           intBuffer(bufferInt) = Y
                        endif
                        if (bufferInt .eq. bufferSize) then
                           if (incoreInt) then
                           else
                              call writeInt(iIntFile, bufferSize, aBuffer, bBuffer, intBuffer)
                           endif

                           bufferInt = 0
                        endif
                     endif
                  else if((III.LT.KKK).OR.(JJJ.LE.LLL))then
                     call hrrwhole
                     if (abs(Y).gt.quick_method%maxintegralCutoff) then

                        A = (III-1)*nbasis+JJJ-1
                        B = (KKK-1)*nbasis+LLL-1

                        INTNUM=INTNUM+1

                        if (incoreInt) then
                           incoreIndex = incoreIndex + 1
                           aIncore(incoreIndex) = A
                           bIncore(incoreIndex) = B
                           intIncore(incoreIndex) = Y
                        else
                           bufferInt = bufferInt + 1
                           aBuffer(bufferInt) = A
                           bBuffer(bufferInt) = B
                           intBuffer(bufferInt) = Y
                        endif

                        if (bufferInt .eq. bufferSize) then
                           if (incoreInt) then

                           else
                              call writeInt(iIntFile, bufferSize, aBuffer, bBuffer, intBuffer)
                           endif
                           bufferInt = 0
                        endif
                     endif
                  endif
               enddo
            enddo
         enddo
      enddo

      intindex = intindex + INTNUM
   else


      if(II.lt.JJ.and.II.lt.KK.and.KK.lt.LL)then
         do III=III1,III2
            do JJJ=JJJ1,JJJ2
               do KKK=KKK1,KKK2
                  do LLL=LLL1,LLL2
                     call hrrwhole
                     ! Find the (ij|kl) integrals where j>i,k>i,l>k. Note that k and j
                     ! can be equal.
#ifdef OSHELL
                     DENSELK=quick_qm_struct%dense(LLL,KKK)+quick_qm_struct%denseb(LLL,KKK)
                     DENSEJI=quick_qm_struct%dense(JJJ,III)+quick_qm_struct%denseb(JJJ,III)

                     DENSEKIA=quick_qm_struct%dense(KKK,III)
                     DENSEKJA=quick_qm_struct%dense(KKK,JJJ)
                     DENSELJA=quick_qm_struct%dense(LLL,JJJ)
                     DENSELIA=quick_qm_struct%dense(LLL,III)

                     DENSEKIB=quick_qm_struct%denseb(KKK,III)
                     DENSEKJB=quick_qm_struct%denseb(KKK,JJJ)
                     DENSELJB=quick_qm_struct%denseb(LLL,JJJ)
                     DENSELIB=quick_qm_struct%denseb(LLL,III)

                     quick_qm_struct%o(JJJ,III) = quick_qm_struct%o(JJJ,III)+2.d0*DENSELK*Y
                     quick_qm_struct%o(LLL,KKK) = quick_qm_struct%o(LLL,KKK)+2.d0*DENSEJI*Y
                     quick_qm_struct%o(KKK,III) = quick_qm_struct%o(KKK,III)-quick_method%x_hybrid_coeff*DENSELJA*Y
                     quick_qm_struct%o(LLL,III) = quick_qm_struct%o(LLL,III)-quick_method%x_hybrid_coeff*DENSEKJA*Y
                     quick_qm_struct%o(JJJ,KKK) = quick_qm_struct%o(JJJ,KKK)-quick_method%x_hybrid_coeff*DENSELIA*Y
                     quick_qm_struct%o(JJJ,LLL) = quick_qm_struct%o(JJJ,LLL)-quick_method%x_hybrid_coeff*DENSEKIA*Y
                     quick_qm_struct%o(KKK,JJJ) = quick_qm_struct%o(KKK,JJJ)-quick_method%x_hybrid_coeff*DENSELIA*Y
                     quick_qm_struct%o(LLL,JJJ) = quick_qm_struct%o(LLL,JJJ)-quick_method%x_hybrid_coeff*DENSEKIA*Y

                     quick_qm_struct%ob(JJJ,III) = quick_qm_struct%ob(JJJ,III)+2.d0*DENSELK*Y
                     quick_qm_struct%ob(LLL,KKK) = quick_qm_struct%ob(LLL,KKK)+2.d0*DENSEJI*Y
                     quick_qm_struct%ob(KKK,III) = quick_qm_struct%ob(KKK,III)-quick_method%x_hybrid_coeff*DENSELJB*Y
                     quick_qm_struct%ob(LLL,III) = quick_qm_struct%ob(LLL,III)-quick_method%x_hybrid_coeff*DENSEKJB*Y
                     quick_qm_struct%ob(JJJ,KKK) = quick_qm_struct%ob(JJJ,KKK)-quick_method%x_hybrid_coeff*DENSELIB*Y
                     quick_qm_struct%ob(JJJ,LLL) = quick_qm_struct%ob(JJJ,LLL)-quick_method%x_hybrid_coeff*DENSEKIB*Y
                     quick_qm_struct%ob(KKK,JJJ) = quick_qm_struct%ob(KKK,JJJ)-quick_method%x_hybrid_coeff*DENSELIB*Y
                     quick_qm_struct%ob(LLL,JJJ) = quick_qm_struct%ob(LLL,JJJ)-quick_method%x_hybrid_coeff*DENSEKIB*Y

#else
                     DENSELK=quick_qm_struct%dense(LLL,KKK)
                     DENSEJI=quick_qm_struct%dense(JJJ,III)
                     DENSEKI=quick_qm_struct%dense(KKK,III)
                     DENSEKJ=quick_qm_struct%dense(KKK,JJJ)
                     DENSELJ=quick_qm_struct%dense(LLL,JJJ)
                     DENSELI=quick_qm_struct%dense(LLL,III)

                     quick_qm_struct%o(JJJ,III) = quick_qm_struct%o(JJJ,III)+2.d0*DENSELK*Y
                     quick_qm_struct%o(LLL,KKK) = quick_qm_struct%o(LLL,KKK)+2.d0*DENSEJI*Y
                     quick_qm_struct%o(KKK,III) = quick_qm_struct%o(KKK,III)-quick_method%x_hybrid_coeff*0.5d0*DENSELJ*Y
                     quick_qm_struct%o(LLL,III) = quick_qm_struct%o(LLL,III)-quick_method%x_hybrid_coeff*0.5d0*DENSEKJ*Y
                     quick_qm_struct%o(JJJ,KKK) = quick_qm_struct%o(JJJ,KKK)-quick_method%x_hybrid_coeff*0.5d0*DENSELI*Y
                     quick_qm_struct%o(JJJ,LLL) = quick_qm_struct%o(JJJ,LLL)-quick_method%x_hybrid_coeff*0.5d0*DENSEKI*Y
                     quick_qm_struct%o(KKK,JJJ) = quick_qm_struct%o(KKK,JJJ)-quick_method%x_hybrid_coeff*0.5d0*DENSELI*Y
                     quick_qm_struct%o(LLL,JJJ) = quick_qm_struct%o(LLL,JJJ)-quick_method%x_hybrid_coeff*0.5d0*DENSEKI*Y
#endif

!--------------------Madu---------------------------
!write(*,*) "II<JJ and II < KK and KK<LL = true"
!  write(*,'(A52,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3)') &
!  "Madu: II, JJ, KK, LL, III, JJJ, KKK, LLL", &
!  II, JJ, KK, LL, III,JJJ,KKK,LLL

! write(*,*) 2.d0*DENSELK,Y 
! write(*,*) 2.d0*DENSEJI,Y
! write(*,*) quick_method%x_hybrid_coeff*DENSELJX,Y
! write(*,*) quick_method%x_hybrid_coeff*DENSEKJX,Y
! write(*,*) quick_method%x_hybrid_coeff*DENSELIX,Y
! write(*,*) quick_method%x_hybrid_coeff*DENSEKIX,Y
! write(*,*) quick_method%x_hybrid_coeff*DENSELIX,Y
! write(*,*) quick_method%x_hybrid_coeff*DENSEKIX,Y
!stop
!--------------------Madu--------------------------

                  enddo
               enddo
            enddo
         enddo
      else
         do III=III1,III2
            do JJJ=max(III,JJJ1),JJJ2
               do KKK=max(III,KKK1),KKK2
                  do LLL=max(KKK,LLL1),LLL2
                     if(III.LT.KKK)then
                        call hrrwhole
                          !write(*,*) Y,III,JJJ,KKK,LLL
                        if(III.lt.JJJ.and.KKK.lt.LLL)then
                           ! Find the (ij|kl) integrals where j>i,k>i,l>k. Note that k and j
                           ! can be equal.
#ifdef OSHELL
                           DENSELK=quick_qm_struct%dense(LLL,KKK)+quick_qm_struct%denseb(LLL,KKK)
                           DENSEJI=quick_qm_struct%dense(JJJ,III)+quick_qm_struct%denseb(JJJ,III)

                           DENSEKIA=quick_qm_struct%dense(KKK,III)
                           DENSEKJA=quick_qm_struct%dense(KKK,JJJ)
                           DENSELJA=quick_qm_struct%dense(LLL,JJJ)
                           DENSELIA=quick_qm_struct%dense(LLL,III)

                           DENSEKIB=quick_qm_struct%denseb(KKK,III)
                           DENSEKJB=quick_qm_struct%denseb(KKK,JJJ)
                           DENSELJB=quick_qm_struct%denseb(LLL,JJJ)
                           DENSELIB=quick_qm_struct%denseb(LLL,III)


                           quick_qm_struct%o(JJJ,III) = quick_qm_struct%o(JJJ,III)+2.d0*DENSELK*Y
                           quick_qm_struct%o(LLL,KKK) = quick_qm_struct%o(LLL,KKK)+2.d0*DENSEJI*Y
                           quick_qm_struct%o(KKK,III) = quick_qm_struct%o(KKK,III)-quick_method%x_hybrid_coeff*DENSELJA*Y
                           quick_qm_struct%o(LLL,III) = quick_qm_struct%o(LLL,III)-quick_method%x_hybrid_coeff*DENSEKJA*Y
                           quick_qm_struct%o(JJJ,KKK) = quick_qm_struct%o(JJJ,KKK)-quick_method%x_hybrid_coeff*DENSELIA*Y
                           quick_qm_struct%o(JJJ,LLL) = quick_qm_struct%o(JJJ,LLL)-quick_method%x_hybrid_coeff*DENSEKIA*Y
                           quick_qm_struct%o(KKK,JJJ) = quick_qm_struct%o(KKK,JJJ)-quick_method%x_hybrid_coeff*DENSELIA*Y
                           quick_qm_struct%o(LLL,JJJ) = quick_qm_struct%o(LLL,JJJ)-quick_method%x_hybrid_coeff*DENSEKIA*Y

                           quick_qm_struct%ob(JJJ,III) = quick_qm_struct%ob(JJJ,III)+2.d0*DENSELK*Y
                           quick_qm_struct%ob(LLL,KKK) = quick_qm_struct%ob(LLL,KKK)+2.d0*DENSEJI*Y
                           quick_qm_struct%ob(KKK,III) = quick_qm_struct%ob(KKK,III)-quick_method%x_hybrid_coeff*DENSELJB*Y
                           quick_qm_struct%ob(LLL,III) = quick_qm_struct%ob(LLL,III)-quick_method%x_hybrid_coeff*DENSEKJB*Y
                           quick_qm_struct%ob(JJJ,KKK) = quick_qm_struct%ob(JJJ,KKK)-quick_method%x_hybrid_coeff*DENSELIB*Y
                           quick_qm_struct%ob(JJJ,LLL) = quick_qm_struct%ob(JJJ,LLL)-quick_method%x_hybrid_coeff*DENSEKIB*Y
                           quick_qm_struct%ob(KKK,JJJ) = quick_qm_struct%ob(KKK,JJJ)-quick_method%x_hybrid_coeff*DENSELIB*Y
                           quick_qm_struct%ob(LLL,JJJ) = quick_qm_struct%ob(LLL,JJJ)-quick_method%x_hybrid_coeff*DENSEKIB*Y
#else
                           DENSEKI=quick_qm_struct%dense(KKK,III)
                           DENSEKJ=quick_qm_struct%dense(KKK,JJJ)
                           DENSELJ=quick_qm_struct%dense(LLL,JJJ)
                           DENSELI=quick_qm_struct%dense(LLL,III)
                           DENSELK=quick_qm_struct%dense(LLL,KKK)
                           DENSEJI=quick_qm_struct%dense(JJJ,III)

                           quick_qm_struct%o(JJJ,III) = quick_qm_struct%o(JJJ,III)+2.d0*DENSELK*Y
                           quick_qm_struct%o(LLL,KKK) = quick_qm_struct%o(LLL,KKK)+2.d0*DENSEJI*Y
                           quick_qm_struct%o(KKK,III) = quick_qm_struct%o(KKK,III)-quick_method%x_hybrid_coeff*.5d0*DENSELJ*Y
                           quick_qm_struct%o(LLL,III) = quick_qm_struct%o(LLL,III)-quick_method%x_hybrid_coeff*.5d0*DENSEKJ*Y
                           quick_qm_struct%o(JJJ,KKK) = quick_qm_struct%o(JJJ,KKK)-quick_method%x_hybrid_coeff*.5d0*DENSELI*Y
                           quick_qm_struct%o(JJJ,LLL) = quick_qm_struct%o(JJJ,LLL)-quick_method%x_hybrid_coeff*.5d0*DENSEKI*Y
                           quick_qm_struct%o(KKK,JJJ) = quick_qm_struct%o(KKK,JJJ)-quick_method%x_hybrid_coeff*.5d0*DENSELI*Y
                           quick_qm_struct%o(LLL,JJJ) = quick_qm_struct%o(LLL,JJJ)-quick_method%x_hybrid_coeff*.5d0*DENSEKI*Y
#endif
!--------------------Madu---------------------------
!write(*,*) "II<JJ and II < KK and KK<LL = false, III<KKK = true"
!write(*,*) "III<JJJ and KKK<LLL"
!  write(*,'(A52,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3)')&
!  "Madu: II, JJ, KK, LL, I1, I2, J1, J2, K1, K2, L1, L2", &
!  II, JJ, KK, LL, III1,III2,JJJ1,JJJ2,KKK1,KKK2,LLL1,LLL2
!  write(*,'(A52,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3)') &
!  "Madu: II, JJ, KK, LL, III, JJJ, KKK, LLL", &
!  II, JJ, KK, LL, III,JJJ,KKK,LLL
  !stop
!--------------------Madu--------------------------

                           elseif(III.eq.JJJ.and.KKK.eq.LLL)then
                           ! Find  all the (ii|jj) integrals.
#ifdef OSHELL

                           DENSEJJ=quick_qm_struct%dense(KKK,KKK)+quick_qm_struct%denseb(KKK,KKK)
                           DENSEII=quick_qm_struct%dense(III,III)+quick_qm_struct%denseb(III,III)

                           DENSEJIA=quick_qm_struct%dense(KKK,III)
                           DENSEJIB=quick_qm_struct%denseb(KKK,III)

                           quick_qm_struct%o(III,III) = quick_qm_struct%o(III,III)+DENSEJJ*Y
                           quick_qm_struct%o(KKK,KKK) = quick_qm_struct%o(KKK,KKK)+DENSEII*Y
                           quick_qm_struct%o(KKK,III) = quick_qm_struct%o(KKK,III)-quick_method%x_hybrid_coeff*DENSEJIA*Y

                           quick_qm_struct%ob(III,III) = quick_qm_struct%ob(III,III)+DENSEJJ*Y
                           quick_qm_struct%ob(KKK,KKK) = quick_qm_struct%ob(KKK,KKK)+DENSEII*Y
                           quick_qm_struct%ob(KKK,III) = quick_qm_struct%ob(KKK,III)-quick_method%x_hybrid_coeff*DENSEJIB*Y
#else
                           DENSEJI=quick_qm_struct%dense(KKK,III)
                           DENSEJJ=quick_qm_struct%dense(KKK,KKK)
                           DENSEII=quick_qm_struct%dense(III,III)
                           
                           quick_qm_struct%o(III,III) = quick_qm_struct%o(III,III)+DENSEJJ*Y
                           quick_qm_struct%o(KKK,KKK) = quick_qm_struct%o(KKK,KKK)+DENSEII*Y
                           quick_qm_struct%o(KKK,III) = quick_qm_struct%o(KKK,III) &
                                -quick_method%x_hybrid_coeff*.5d0*DENSEJI*Y
#endif


!--------------------Madu---------------------------
!write(*,*) "II<JJ and II < KK and KK<LL = false, III<KKK = true"
!write(*,*) "III==JJJ and KKK==LLL"
!  write(*,'(A52,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3)')&
!  "Madu: II, JJ, KK, LL, I1, I2, J1, J2, K1, K2, L1, L2", &
!  II, JJ, KK, LL, III1,III2,JJJ1,JJJ2,KKK1,KKK2,LLL1,LLL2
  !stop
!--------------------Madu--------------------------

                           elseif(JJJ.eq.KKK.and.JJJ.eq.LLL)then
                           ! Find  all the (ij|jj) integrals.
#ifdef OSHELL
                           DENSEJI=quick_qm_struct%dense(JJJ,III)+quick_qm_struct%denseb(JJJ,III)
                           DENSEJJ=quick_qm_struct%dense(JJJ,JJJ)+quick_qm_struct%denseb(JJJ,JJJ)

                           DENSEJIA=quick_qm_struct%dense(JJJ,III)
                           DENSEJJA=quick_qm_struct%dense(JJJ,JJJ)

                           DENSEJIB=quick_qm_struct%denseb(JJJ,III)
                           DENSEJJB=quick_qm_struct%denseb(JJJ,JJJ)

                           quick_qm_struct%o(JJJ,III) = quick_qm_struct%o(JJJ,III)+DENSEJJ*Y &
                                -quick_method%x_hybrid_coeff*DENSEJJA*Y
                           quick_qm_struct%o(JJJ,JJJ) = quick_qm_struct%o(JJJ,JJJ)+2.0d0*DENSEJI*Y &
                                -quick_method%x_hybrid_coeff*2.0d0*DENSEJIA*Y 

                           quick_qm_struct%ob(JJJ,III) = quick_qm_struct%ob(JJJ,III)+DENSEJJ*Y &
                                -quick_method%x_hybrid_coeff*DENSEJJB*Y
                           quick_qm_struct%ob(JJJ,JJJ) = quick_qm_struct%ob(JJJ,JJJ)+2.0d0*DENSEJI*Y &
                                -2.0d0*quick_method%x_hybrid_coeff*DENSEJIB*Y
#else
                           DENSEJI=quick_qm_struct%dense(JJJ,III)
                           DENSEJJ=quick_qm_struct%dense(JJJ,JJJ)

                           ! Find  all the (ij|jj) integrals.
                           quick_qm_struct%o(JJJ,III) = quick_qm_struct%o(JJJ,III)+DENSEJJ*Y &
                                -quick_method%x_hybrid_coeff*.5d0*DENSEJJ*Y
                           quick_qm_struct%o(JJJ,JJJ) = quick_qm_struct%o(JJJ,JJJ)+2.0d0*DENSEJI*Y &
                                -quick_method%x_hybrid_coeff*DENSEJI*Y
#endif
 
                           !        ! Find  all the (ii|ij) integrals.
                           !        ! Find all the (ij|ij) integrals

                           ! Find all the (ij|ik) integrals where j>i,k>j
!--------------------Madu---------------------------
!write(*,*) "II<JJ and II < KK and KK<LL = false, III<KKK = true"
!write(*,*) "JJJ==KKK and JJJ==LLL"
!  write(*,'(A52,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3)')&
!  "Madu: II, JJ, KK, LL, I1, I2, J1, J2, K1, K2, L1, L2", &
!  II, JJ, KK, LL, III1,III2,JJJ1,JJJ2,KKK1,KKK2,LLL1,LLL2
!  write(*,'(A52,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3)') &
!  "Madu: II, JJ, KK, LL, III, JJJ, KKK, LLL", &
!  II, JJ, KK, LL, III,JJJ,KKK,LLL
  !stop
!--------------------Madu--------------------------
                           elseif(KKK.eq.LLL.and.III.lt.JJJ.and.JJJ.ne.KKK)then
                           ! Find all the (ij|kk) integrals where j>i, k>j.
#ifdef OSHELL
                           DENSEKK=quick_qm_struct%dense(KKK,KKK)+quick_qm_struct%denseb(KKK,KKK)
                           DENSEJI=quick_qm_struct%dense(JJJ,III)+quick_qm_struct%denseb(JJJ,III)

                           DENSEKIA=quick_qm_struct%dense(KKK,III)
                           DENSEKJA=quick_qm_struct%dense(KKK,JJJ)

                           DENSEKIB=quick_qm_struct%denseb(KKK,III)
                           DENSEKJB=quick_qm_struct%denseb(KKK,JJJ)

                           quick_qm_struct%o(JJJ,III) = quick_qm_struct%o(JJJ,III)+DENSEKK*Y
                           quick_qm_struct%o(KKK,KKK) = quick_qm_struct%o(KKK,KKK)+2.d0*DENSEJI*Y
                           quick_qm_struct%o(KKK,III) = quick_qm_struct%o(KKK,III)-quick_method%x_hybrid_coeff*DENSEKJA*Y
                           quick_qm_struct%o(KKK,JJJ) = quick_qm_struct%o(KKK,JJJ)-quick_method%x_hybrid_coeff*DENSEKIA*Y
                           quick_qm_struct%o(JJJ,KKK) = quick_qm_struct%o(JJJ,KKK)-quick_method%x_hybrid_coeff*DENSEKIA*Y

                           quick_qm_struct%ob(JJJ,III) = quick_qm_struct%ob(JJJ,III)+DENSEKK*Y
                           quick_qm_struct%ob(KKK,KKK) = quick_qm_struct%ob(KKK,KKK)+2.d0*DENSEJI*Y
                           quick_qm_struct%ob(KKK,III) = quick_qm_struct%ob(KKK,III)-quick_method%x_hybrid_coeff*DENSEKJB*Y
                           quick_qm_struct%ob(KKK,JJJ) = quick_qm_struct%ob(KKK,JJJ)-quick_method%x_hybrid_coeff*DENSEKIB*Y
                           quick_qm_struct%ob(JJJ,KKK) = quick_qm_struct%ob(JJJ,KKK)-quick_method%x_hybrid_coeff*DENSEKIB*Y
#else
                           DENSEKI=quick_qm_struct%dense(KKK,III)
                           DENSEKJ=quick_qm_struct%dense(KKK,JJJ)
                           DENSEKK=quick_qm_struct%dense(KKK,KKK)
                           DENSEJI=quick_qm_struct%dense(JJJ,III)

                           quick_qm_struct%o(JJJ,III) = quick_qm_struct%o(JJJ,III)+DENSEKK*Y
                           quick_qm_struct%o(KKK,KKK) = quick_qm_struct%o(KKK,KKK)+2.d0*DENSEJI*Y
                           quick_qm_struct%o(KKK,III) = quick_qm_struct%o(KKK,III)-quick_method%x_hybrid_coeff*.5d0*DENSEKJ*Y
                           quick_qm_struct%o(KKK,JJJ) = quick_qm_struct%o(KKK,JJJ)-quick_method%x_hybrid_coeff*.5d0*DENSEKI*Y
                           quick_qm_struct%o(JJJ,KKK) = quick_qm_struct%o(JJJ,KKK)-quick_method%x_hybrid_coeff*.5d0*DENSEKI*Y
#endif
!--------------------Madu---------------------------
!write(*,*) "II<JJ and II < KK and KK<LL = false, III<KKK = true"
!write(*,*) "KKK==LLL and III<JJJ and JJJ != KKK"
!  write(*,'(A52,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3)')&
!  "Madu: II, JJ, KK, LL, I1, I2, J1, J2, K1, K2, L1, L2", &
!  II, JJ, KK, LL, III1,III2,JJJ1,JJJ2,KKK1,KKK2,LLL1,LLL2
  !stop
!--------------------Madu--------------------------

                           !        ! Find all the (ik|jj) integrals where j>i, k>j.
                           elseif(III.eq.JJJ.and.KKK.lt.LLL)then
                           ! Find all the (ii|jk) integrals where j>i, k>j.
#ifdef OSHELL
                           DENSEII=quick_qm_struct%dense(III,III)+quick_qm_struct%denseb(III,III)
                           DENSEKJ=quick_qm_struct%dense(LLL,KKK)+quick_qm_struct%denseb(LLL,KKK)

                           DENSEKIA=quick_qm_struct%dense(LLL,III)
                           DENSEJIA=quick_qm_struct%dense(KKK,III)                          

                           DENSEKIB=quick_qm_struct%denseb(LLL,III)
                           DENSEJIB=quick_qm_struct%denseb(KKK,III)

                           quick_qm_struct%o(LLL,KKK) = quick_qm_struct%o(LLL,KKK)+DENSEII*Y
                           quick_qm_struct%o(III,III) = quick_qm_struct%o(III,III)+2.d0*DENSEKJ*Y
                           quick_qm_struct%o(KKK,III) = quick_qm_struct%o(KKK,III)-quick_method%x_hybrid_coeff*DENSEKIA*Y
                           quick_qm_struct%o(LLL,III) = quick_qm_struct%o(LLL,III)-quick_method%x_hybrid_coeff*DENSEJIA*Y

                           quick_qm_struct%ob(LLL,KKK) = quick_qm_struct%ob(LLL,KKK)+DENSEII*Y
                           quick_qm_struct%ob(III,III) = quick_qm_struct%ob(III,III)+2.d0*DENSEKJ*Y
                           quick_qm_struct%ob(KKK,III) = quick_qm_struct%ob(KKK,III)-quick_method%x_hybrid_coeff*DENSEKIB*Y
                           quick_qm_struct%ob(LLL,III) = quick_qm_struct%ob(LLL,III)-quick_method%x_hybrid_coeff*DENSEJIB*Y
#else
                           DENSEII=quick_qm_struct%dense(III,III)
                           DENSEJI=quick_qm_struct%dense(KKK,III)
                           DENSEKI=quick_qm_struct%dense(LLL,III)
                           DENSEKJ=quick_qm_struct%dense(LLL,KKK)

                           quick_qm_struct%o(LLL,KKK) = quick_qm_struct%o(LLL,KKK)+DENSEII*Y
                           quick_qm_struct%o(III,III) = quick_qm_struct%o(III,III)+2.d0*DENSEKJ*Y
                           quick_qm_struct%o(KKK,III) = quick_qm_struct%o(KKK,III)-quick_method%x_hybrid_coeff*.5d0*DENSEKI*Y
                           quick_qm_struct%o(LLL,III) = quick_qm_struct%o(LLL,III)-quick_method%x_hybrid_coeff*.5d0*DENSEJI*Y
#endif
!--------------------Madu---------------------------
!write(*,*) "II<JJ and II < KK and KK<LL = false, III<KKK = true"
!write(*,*) "III<JJJ and KKK<LLL"
!  write(*,'(A52,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3)')&
!  "Madu: II, JJ, KK, LL, I1, I2, J1, J2, K1, K2, L1, L2", &
!  II, JJ, KK, LL, III1,III2,JJJ1,JJJ2,KKK1,KKK2,LLL1,LLL2
  !stop
!--------------------Madu--------------------------
                        endif

                     else
                        if(JJJ.LE.LLL)then
                           call hrrwhole
                           !   write(*,*) Y, III,JJJ,KKK,LLL
                           if(III.eq.JJJ.and.III.eq.KKK.and.III.eq.LLL)then
                              ! do all the (ii|ii) integrals.
#ifdef OSHELL
                              DENSEII=quick_qm_struct%dense(III,III)+quick_qm_struct%denseb(III,III)

                              DENSEIIA=quick_qm_struct%dense(III,III)
                              DENSEIIB=quick_qm_struct%denseb(III,III)

                              quick_qm_struct%o(III,III) = quick_qm_struct%o(III,III)+DENSEII*Y-quick_method%x_hybrid_coeff &
                                                           *DENSEIIA*Y

                              quick_qm_struct%ob(III,III) = quick_qm_struct%ob(III,III)+DENSEII*Y- &
                                                            quick_method%x_hybrid_coeff*DENSEIIB*Y
#else
                              DENSEII=quick_qm_struct%dense(III,III)

                              quick_qm_struct%o(III,III) = quick_qm_struct%o(III,III)+DENSEII*Y &
                                -quick_method%x_hybrid_coeff*.5d0*DENSEII*Y
#endif
!--------------------Madu---------------------------
!write(*,*) "II<JJ and II < KK and KK<LL = false, III<KKK = false, JJJ<LLL=true"
!write(*,*) "III==JJJ and III==KKK and III==LLL"
!  write(*,'(A52,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3)')&
!  "Madu: II, JJ, KK, LL, I1, I2, J1, J2, K1, K2, L1, L2", &
!  II, JJ, KK, LL, III1,III2,JJJ1,JJJ2,KKK1,KKK2,LLL1,LLL2
  !stop
!--------------------Madu--------------------------
                              elseif(III.eq.JJJ.and.III.eq.KKK.and.III.lt.LLL)then

#ifdef OSHELL
                              DENSEJI=quick_qm_struct%dense(LLL,III)+quick_qm_struct%denseb(LLL,III)
                              DENSEII=quick_qm_struct%dense(III,III)+quick_qm_struct%denseb(III,III)

                              DENSEJIA=quick_qm_struct%dense(LLL,III)
                              DENSEIIA=quick_qm_struct%dense(III,III)

                              DENSEJIB=quick_qm_struct%denseb(LLL,III)
                              DENSEIIB=quick_qm_struct%denseb(III,III)                              

                              ! Find  all the (ii|ij) integrals.
                              quick_qm_struct%o(LLL,III) = quick_qm_struct%o(LLL,III)+DENSEII*Y &
                                -quick_method%x_hybrid_coeff*DENSEIIA*Y
                              quick_qm_struct%o(III,III) = quick_qm_struct%o(III,III)+2.0d0*DENSEJI*Y &
                                -quick_method%x_hybrid_coeff*2.0d0*DENSEJIA*Y 

                              quick_qm_struct%ob(LLL,III) = quick_qm_struct%ob(LLL,III)+DENSEII*Y &
                                -quick_method%x_hybrid_coeff*DENSEIIB*Y
                              quick_qm_struct%ob(III,III) = quick_qm_struct%ob(III,III)+2.0d0*DENSEJI*Y &
                                -quick_method%x_hybrid_coeff*2.0d0*DENSEJIB*Y
#else
                              DENSEJI=quick_qm_struct%dense(LLL,III)
                              DENSEII=quick_qm_struct%dense(III,III)

                              quick_qm_struct%o(LLL,III) = quick_qm_struct%o(LLL,III)+DENSEII*Y &
                                -quick_method%x_hybrid_coeff*.5d0*DENSEII*Y
                              quick_qm_struct%o(III,III) = quick_qm_struct%o(III,III)+2.0d0*DENSEJI*Y &
                                -quick_method%x_hybrid_coeff*DENSEJI*Y
#endif
!EORD
!--------------------Madu---------------------------
!write(*,*) "II<JJ and II < KK and KK<LL = false, III<KKK = false, JJJ<LLL=true"
!write(*,*) "III==JJJ and III==KKK and III<LLL"
!  write(*,'(A52,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3)')&
!  "Madu: II, JJ, KK, LL, I1, I2, J1, J2, K1, K2, L1, L2", &
!  II, JJ, KK, LL, III1,III2,JJJ1,JJJ2,KKK1,KKK2,LLL1,LLL2
  !stop
!--------------------Madu--------------------------

                              elseif(III.eq.KKK.and.JJJ.eq.LLL.and.III.lt.JJJ)then
                             ! Find all the (ij|ij) integrals
#ifdef OSHELL
                              DENSEJI=quick_qm_struct%dense(JJJ,III)+quick_qm_struct%denseb(JJJ,III)

                              DENSEJIA=quick_qm_struct%dense(JJJ,III)                             
                              DENSEJJA=quick_qm_struct%dense(JJJ,JJJ)
                              DENSEIIA=quick_qm_struct%dense(III,III)

                              DENSEJIB=quick_qm_struct%denseb(JJJ,III)
                              DENSEJJB=quick_qm_struct%denseb(JJJ,JJJ)
                              DENSEIIB=quick_qm_struct%denseb(III,III)
 
                              quick_qm_struct%o(JJJ,III) = quick_qm_struct%o(JJJ,III)+2.0d0*DENSEJI*Y &
                                                           -quick_method%x_hybrid_coeff*DENSEJIA*Y
                              quick_qm_struct%o(JJJ,JJJ) = quick_qm_struct%o(JJJ,JJJ)-quick_method%x_hybrid_coeff* &
                                                           DENSEIIA*Y
                              quick_qm_struct%o(III,III) = quick_qm_struct%o(III,III)-quick_method%x_hybrid_coeff* &
                                                           DENSEJJA*Y

                              quick_qm_struct%ob(JJJ,III) = quick_qm_struct%ob(JJJ,III)+2.0d0*DENSEJI*Y &
                                                            -quick_method%x_hybrid_coeff*DENSEJIB*Y
                              quick_qm_struct%ob(JJJ,JJJ) = quick_qm_struct%ob(JJJ,JJJ)-quick_method%x_hybrid_coeff*DENSEIIB*Y
                              quick_qm_struct%ob(III,III) = quick_qm_struct%ob(III,III)-quick_method%x_hybrid_coeff*DENSEJJB*Y
#else
                              DENSEJI=quick_qm_struct%dense(JJJ,III)
                              DENSEJJ=quick_qm_struct%dense(JJJ,JJJ)
                              DENSEII=quick_qm_struct%dense(III,III)

                              quick_qm_struct%o(JJJ,III) = quick_qm_struct%o(JJJ,III)+2.0d0*DENSEJI*Y &
                                -quick_method%x_hybrid_coeff*0.5d0*DENSEJI*Y
                              quick_qm_struct%o(JJJ,JJJ) = quick_qm_struct%o(JJJ,JJJ)-quick_method%x_hybrid_coeff*.5d0*DENSEII*Y
                              quick_qm_struct%o(III,III) = quick_qm_struct%o(III,III)-quick_method%x_hybrid_coeff*.5d0*DENSEJJ*Y
#endif

!--------------------M
!write(*,*) "II<JJ and II < KK and KK<LL = false, III<KKK = false, JJJ<LLL=true"
!write(*,*) "III==KKK and JJJ==LLL and III<JJJ"
!  write(*,'(A52,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3)')&
!  "Madu: II, JJ, KK, LL, I1, I2, J1, J2, K1, K2, L1, L2", &
!  II, JJ, KK, LL, III1,III2,JJJ1,JJJ2,KKK1,KKK2,LLL1,LLL2
  !stop
!--------------------Madu--------------------------
                              elseif(III.eq.KKK.and.III.lt.JJJ.and.JJJ.lt.LLL)then
                              ! Find all the (ij|ik) integrals where j>i,k>j
#ifdef OSHELL
                              DENSEKI=quick_qm_struct%dense(LLL,III)+quick_qm_struct%denseb(LLL,III)
                              DENSEJI=quick_qm_struct%dense(JJJ,III)+quick_qm_struct%denseb(JJJ,III)

                              DENSEKIA=quick_qm_struct%dense(LLL,III)
                              DENSEKJA=quick_qm_struct%dense(LLL,JJJ)
                              DENSEIIA=quick_qm_struct%dense(III,III)
                              DENSEJIA=quick_qm_struct%dense(JJJ,III)

                              DENSEKIB=quick_qm_struct%denseb(LLL,III)
                              DENSEKJB=quick_qm_struct%denseb(LLL,JJJ)
                              DENSEIIB=quick_qm_struct%denseb(III,III)
                              DENSEJIB=quick_qm_struct%denseb(JJJ,III)

                              quick_qm_struct%o(JJJ,III) = quick_qm_struct%o(JJJ,III)+2.0d0*DENSEKI*Y &
                                -quick_method%x_hybrid_coeff*DENSEKIA*Y
                              quick_qm_struct%o(LLL,III) = quick_qm_struct%o(LLL,III)+2.0d0*DENSEJI*Y &
                                - quick_method%x_hybrid_coeff*DENSEJIA*Y
                              quick_qm_struct%o(III,III) = quick_qm_struct%o(III,III)-quick_method%x_hybrid_coeff* &
                                                           2.d0*DENSEKJA*Y 
                              quick_qm_struct%o(LLL,JJJ) = quick_qm_struct%o(LLL,JJJ)-quick_method%x_hybrid_coeff* &
                                                           DENSEIIA*Y

                              quick_qm_struct%ob(JJJ,III) = quick_qm_struct%ob(JJJ,III)+2.0d0*DENSEKI*Y &
                                                            -quick_method%x_hybrid_coeff*DENSEKIB*Y
                              quick_qm_struct%ob(LLL,III) = quick_qm_struct%ob(LLL,III)+2.0d0*DENSEJI*Y &
                                                            - quick_method%x_hybrid_coeff*DENSEJIB*Y
                              quick_qm_struct%ob(III,III) = quick_qm_struct%ob(III,III)-quick_method%x_hybrid_coeff* &
                                                            2.0d0*DENSEKJB*Y 
                              quick_qm_struct%ob(LLL,JJJ) = quick_qm_struct%ob(LLL,JJJ)-quick_method%x_hybrid_coeff* &
                                                            DENSEIIB*Y
#else
                              DENSEKI=quick_qm_struct%dense(LLL,III)
                              DENSEKJ=quick_qm_struct%dense(LLL,JJJ)
                              DENSEII=quick_qm_struct%dense(III,III)
                              DENSEJI=quick_qm_struct%dense(JJJ,III)

                              quick_qm_struct%o(JJJ,III) = quick_qm_struct%o(JJJ,III)+2.0d0*DENSEKI*Y &
                                -quick_method%x_hybrid_coeff*0.5d0*DENSEKI*Y
                              quick_qm_struct%o(LLL,III) = quick_qm_struct%o(LLL,III)+2.0d0*DENSEJI*Y &
                                - quick_method%x_hybrid_coeff*0.5d0*DENSEJI*Y
                              quick_qm_struct%o(III,III) = quick_qm_struct%o(III,III)-quick_method%x_hybrid_coeff*1.d0*DENSEKJ*Y
                              quick_qm_struct%o(LLL,JJJ) = quick_qm_struct%o(LLL,JJJ)-quick_method%x_hybrid_coeff*.5d0*DENSEII*Y
#endif

!--------------------Madu---------------------------
!write(*,*) "II<JJ and II < KK and KK<LL = false, III<KKK = false, JJJ<LLL=true"
!write(*,*) "III==KKK and III<JJJ and JJJ<LLL"
!  write(*,'(A52,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3,1x,I3)')&
!  "Madu: II, JJ, KK, LL, I1, I2, J1, J2, K1, K2, L1, L2", &
!  II, JJ, KK, LL, III1,III2,JJJ1,JJJ2,KKK1,KKK2,LLL1,LLL2
  !stop
!--------------------Madu--------------------------

                           endif
                        endif
                     endif
                  enddo
               enddo
            enddo
         enddo
      endif
   endif

   201 return

#ifdef OSHELL
end subroutine iclass_oshell
#else
end subroutine iclass_cshell
#endif

   !------------------------------------------------
   ! This subroutine is to get 2e energy
   !------------------------------------------------

#ifdef OSHELL
subroutine get_oshell_eri_energy
#else
subroutine get_cshell_eri_energy
#endif
   use allmod
   implicit double precision(a-h,o-z)

   call cpu_time(timer_begin%TE)
#ifdef OSHELL
   quick_qm_struct%Eel=quick_qm_struct%Eel+Sum2Mat(quick_qm_struct%dense,quick_qm_struct%o,nbasis)+ &
                       Sum2Mat(quick_qm_struct%denseb,quick_qm_struct%ob,nbasis)
#else
   quick_qm_struct%Eel=quick_qm_struct%Eel+Sum2Mat(quick_qm_struct%dense,quick_qm_struct%o,nbasis)
#endif
   quick_qm_struct%Eel=quick_qm_struct%Eel/2.0d0
   call cpu_time(timer_end%TE) 
   timer_cumer%TE=timer_cumer%TE+timer_end%TE-timer_begin%TE 
#ifdef OSHELL
end subroutine get_oshell_eri_energy
#else
end subroutine get_cshell_eri_energy
#endif

#ifdef OSHELL
end module quick_oshell_module
#else
end module quick_cshell_module
#endif
