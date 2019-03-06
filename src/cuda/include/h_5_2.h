#include "../gpu_common.h"
#include "./h_all_files.h"
// Class for B =            5  L =            2
__device__ __inline__  f_5_2_t :: f_5_2_t ( f_5_1_t t_5_1_0, f_5_1_t t_5_1_1, f_5_0_t t_5_0_0, f_5_0_t t_5_0_1, QUICKDouble CDtemp, QUICKDouble ABcom, f_4_1_t t_4_1_1, QUICKDouble ABCDtemp, QUICKDouble Qtempx, QUICKDouble Qtempy, QUICKDouble Qtempz,  QUICKDouble WQtempx, QUICKDouble WQtempy, QUICKDouble WQtempz) {
    x_35_4 = Qtempx * t_5_1_0.x_35_2 + WQtempx * t_5_1_1.x_35_2 + ABCDtemp * t_4_1_1.x_22_2 ;
    x_36_4 = Qtempx * t_5_1_0.x_36_2 + WQtempx * t_5_1_1.x_36_2 + 2 * ABCDtemp * t_4_1_1.x_25_2 ;
    x_37_4 = Qtempx * t_5_1_0.x_37_2 + WQtempx * t_5_1_1.x_37_2 + 2 * ABCDtemp * t_4_1_1.x_24_2 ;
    x_38_4 = Qtempx * t_5_1_0.x_38_2 + WQtempx * t_5_1_1.x_38_2 + 3 * ABCDtemp * t_4_1_1.x_23_2 ;
    x_39_4 = Qtempx * t_5_1_0.x_39_2 + WQtempx * t_5_1_1.x_39_2 + ABCDtemp * t_4_1_1.x_30_2 ;
    x_40_4 = Qtempx * t_5_1_0.x_40_2 + WQtempx * t_5_1_1.x_40_2 + ABCDtemp * t_4_1_1.x_31_2 ;
    x_41_4 = Qtempx * t_5_1_0.x_41_2 + WQtempx * t_5_1_1.x_41_2 ;
    x_42_4 = Qtempx * t_5_1_0.x_42_2 + WQtempx * t_5_1_1.x_42_2 ;
    x_43_4 = Qtempx * t_5_1_0.x_43_2 + WQtempx * t_5_1_1.x_43_2 + 2 * ABCDtemp * t_4_1_1.x_27_2 ;
    x_44_4 = Qtempx * t_5_1_0.x_44_2 + WQtempx * t_5_1_1.x_44_2 + 3 * ABCDtemp * t_4_1_1.x_21_2 ;
    x_45_4 = Qtempx * t_5_1_0.x_45_2 + WQtempx * t_5_1_1.x_45_2 + 2 * ABCDtemp * t_4_1_1.x_29_2 ;
    x_46_4 = Qtempx * t_5_1_0.x_46_2 + WQtempx * t_5_1_1.x_46_2 + 3 * ABCDtemp * t_4_1_1.x_20_2 ;
    x_47_4 = Qtempx * t_5_1_0.x_47_2 + WQtempx * t_5_1_1.x_47_2 ;
    x_48_4 = Qtempx * t_5_1_0.x_48_2 + WQtempx * t_5_1_1.x_48_2 ;
    x_49_4 = Qtempx * t_5_1_0.x_49_2 + WQtempx * t_5_1_1.x_49_2 + ABCDtemp * t_4_1_1.x_34_2 ;
    x_50_4 = Qtempx * t_5_1_0.x_50_2 + WQtempx * t_5_1_1.x_50_2 + 4 * ABCDtemp * t_4_1_1.x_26_2 ;
    x_51_4 = Qtempx * t_5_1_0.x_51_2 + WQtempx * t_5_1_1.x_51_2 + ABCDtemp * t_4_1_1.x_33_2 ;
    x_52_4 = Qtempx * t_5_1_0.x_52_2 + WQtempx * t_5_1_1.x_52_2 + 4 * ABCDtemp * t_4_1_1.x_28_2 ;
    x_53_4 = Qtempx * t_5_1_0.x_53_2 + WQtempx * t_5_1_1.x_53_2 + 5 * ABCDtemp * t_4_1_1.x_32_2 ;
    x_54_4 = Qtempx * t_5_1_0.x_54_2 + WQtempx * t_5_1_1.x_54_2 ;
    x_55_4 = Qtempx * t_5_1_0.x_55_2 + WQtempx * t_5_1_1.x_55_2 ;
    x_35_5 = Qtempy * t_5_1_0.x_35_3 + WQtempy * t_5_1_1.x_35_3 + 2 * ABCDtemp * t_4_1_1.x_25_3 ;
    x_36_5 = Qtempy * t_5_1_0.x_36_3 + WQtempy * t_5_1_1.x_36_3 + ABCDtemp * t_4_1_1.x_21_3 ;
    x_37_5 = Qtempy * t_5_1_0.x_37_3 + WQtempy * t_5_1_1.x_37_3 + 2 * ABCDtemp * t_4_1_1.x_23_3 ;
    x_38_5 = Qtempy * t_5_1_0.x_38_3 + WQtempy * t_5_1_1.x_38_3 + ABCDtemp * t_4_1_1.x_26_3 ;
    x_39_5 = Qtempy * t_5_1_0.x_39_3 + WQtempy * t_5_1_1.x_39_3 + 3 * ABCDtemp * t_4_1_1.x_24_3 ;
    x_40_5 = Qtempy * t_5_1_0.x_40_3 + WQtempy * t_5_1_1.x_40_3 + ABCDtemp * t_4_1_1.x_27_3 ;
    x_41_5 = Qtempy * t_5_1_0.x_41_3 + WQtempy * t_5_1_1.x_41_3 + 2 * ABCDtemp * t_4_1_1.x_31_3 ;
    x_42_5 = Qtempy * t_5_1_0.x_42_3 + WQtempy * t_5_1_1.x_42_3 + 3 * ABCDtemp * t_4_1_1.x_22_3 ;
    x_43_5 = Qtempy * t_5_1_0.x_43_3 + WQtempy * t_5_1_1.x_43_3 ;
    x_44_5 = Qtempy * t_5_1_0.x_44_3 + WQtempy * t_5_1_1.x_44_3 ;
    x_45_5 = Qtempy * t_5_1_0.x_45_3 + WQtempy * t_5_1_1.x_45_3 + 3 * ABCDtemp * t_4_1_1.x_20_3 ;
    x_46_5 = Qtempy * t_5_1_0.x_46_3 + WQtempy * t_5_1_1.x_46_3 + 2 * ABCDtemp * t_4_1_1.x_28_3 ;
    x_47_5 = Qtempy * t_5_1_0.x_47_3 + WQtempy * t_5_1_1.x_47_3 + ABCDtemp * t_4_1_1.x_34_3 ;
    x_48_5 = Qtempy * t_5_1_0.x_48_3 + WQtempy * t_5_1_1.x_48_3 + 4 * ABCDtemp * t_4_1_1.x_30_3 ;
    x_49_5 = Qtempy * t_5_1_0.x_49_3 + WQtempy * t_5_1_1.x_49_3 ;
    x_50_5 = Qtempy * t_5_1_0.x_50_3 + WQtempy * t_5_1_1.x_50_3 ;
    x_51_5 = Qtempy * t_5_1_0.x_51_3 + WQtempy * t_5_1_1.x_51_3 + 4 * ABCDtemp * t_4_1_1.x_29_3 ;
    x_52_5 = Qtempy * t_5_1_0.x_52_3 + WQtempy * t_5_1_1.x_52_3 + ABCDtemp * t_4_1_1.x_32_3 ;
    x_53_5 = Qtempy * t_5_1_0.x_53_3 + WQtempy * t_5_1_1.x_53_3 ;
    x_54_5 = Qtempy * t_5_1_0.x_54_3 + WQtempy * t_5_1_1.x_54_3 + 5 * ABCDtemp * t_4_1_1.x_33_3 ;
    x_55_5 = Qtempy * t_5_1_0.x_55_3 + WQtempy * t_5_1_1.x_55_3 ;
    x_35_6 = Qtempx * t_5_1_0.x_35_3 + WQtempx * t_5_1_1.x_35_3 + ABCDtemp * t_4_1_1.x_22_3 ;
    x_36_6 = Qtempx * t_5_1_0.x_36_3 + WQtempx * t_5_1_1.x_36_3 + 2 * ABCDtemp * t_4_1_1.x_25_3 ;
    x_37_6 = Qtempx * t_5_1_0.x_37_3 + WQtempx * t_5_1_1.x_37_3 + 2 * ABCDtemp * t_4_1_1.x_24_3 ;
    x_38_6 = Qtempx * t_5_1_0.x_38_3 + WQtempx * t_5_1_1.x_38_3 + 3 * ABCDtemp * t_4_1_1.x_23_3 ;
    x_39_6 = Qtempx * t_5_1_0.x_39_3 + WQtempx * t_5_1_1.x_39_3 + ABCDtemp * t_4_1_1.x_30_3 ;
    x_40_6 = Qtempx * t_5_1_0.x_40_3 + WQtempx * t_5_1_1.x_40_3 + ABCDtemp * t_4_1_1.x_31_3 ;
    x_41_6 = Qtempx * t_5_1_0.x_41_3 + WQtempx * t_5_1_1.x_41_3 ;
    x_42_6 = Qtempx * t_5_1_0.x_42_3 + WQtempx * t_5_1_1.x_42_3 ;
    x_43_6 = Qtempx * t_5_1_0.x_43_3 + WQtempx * t_5_1_1.x_43_3 + 2 * ABCDtemp * t_4_1_1.x_27_3 ;
    x_44_6 = Qtempx * t_5_1_0.x_44_3 + WQtempx * t_5_1_1.x_44_3 + 3 * ABCDtemp * t_4_1_1.x_21_3 ;
    x_45_6 = Qtempx * t_5_1_0.x_45_3 + WQtempx * t_5_1_1.x_45_3 + 2 * ABCDtemp * t_4_1_1.x_29_3 ;
    x_46_6 = Qtempx * t_5_1_0.x_46_3 + WQtempx * t_5_1_1.x_46_3 + 3 * ABCDtemp * t_4_1_1.x_20_3 ;
    x_47_6 = Qtempx * t_5_1_0.x_47_3 + WQtempx * t_5_1_1.x_47_3 ;
    x_48_6 = Qtempx * t_5_1_0.x_48_3 + WQtempx * t_5_1_1.x_48_3 ;
    x_49_6 = Qtempx * t_5_1_0.x_49_3 + WQtempx * t_5_1_1.x_49_3 + ABCDtemp * t_4_1_1.x_34_3 ;
    x_50_6 = Qtempx * t_5_1_0.x_50_3 + WQtempx * t_5_1_1.x_50_3 + 4 * ABCDtemp * t_4_1_1.x_26_3 ;
    x_51_6 = Qtempx * t_5_1_0.x_51_3 + WQtempx * t_5_1_1.x_51_3 + ABCDtemp * t_4_1_1.x_33_3 ;
    x_52_6 = Qtempx * t_5_1_0.x_52_3 + WQtempx * t_5_1_1.x_52_3 + 4 * ABCDtemp * t_4_1_1.x_28_3 ;
    x_53_6 = Qtempx * t_5_1_0.x_53_3 + WQtempx * t_5_1_1.x_53_3 + 5 * ABCDtemp * t_4_1_1.x_32_3 ;
    x_54_6 = Qtempx * t_5_1_0.x_54_3 + WQtempx * t_5_1_1.x_54_3 ;
    x_55_6 = Qtempx * t_5_1_0.x_55_3 + WQtempx * t_5_1_1.x_55_3 ;
    x_35_7 = Qtempx * t_5_1_0.x_35_1 + WQtempx * t_5_1_1.x_35_1 + CDtemp * ( t_5_0_0.x_35_0 -  ABcom * t_5_0_1.x_35_0 ) + ABCDtemp * t_4_1_1.x_22_1 ;
    x_36_7 = Qtempx * t_5_1_0.x_36_1 + WQtempx * t_5_1_1.x_36_1 + CDtemp * ( t_5_0_0.x_36_0 -  ABcom * t_5_0_1.x_36_0 ) + 2 * ABCDtemp * t_4_1_1.x_25_1 ;
    x_37_7 = Qtempx * t_5_1_0.x_37_1 + WQtempx * t_5_1_1.x_37_1 + CDtemp * ( t_5_0_0.x_37_0 -  ABcom * t_5_0_1.x_37_0 ) + 2 * ABCDtemp * t_4_1_1.x_24_1 ;
    x_38_7 = Qtempx * t_5_1_0.x_38_1 + WQtempx * t_5_1_1.x_38_1 + CDtemp * ( t_5_0_0.x_38_0 -  ABcom * t_5_0_1.x_38_0 ) + 3 * ABCDtemp * t_4_1_1.x_23_1 ;
    x_39_7 = Qtempx * t_5_1_0.x_39_1 + WQtempx * t_5_1_1.x_39_1 + CDtemp * ( t_5_0_0.x_39_0 -  ABcom * t_5_0_1.x_39_0 ) + ABCDtemp * t_4_1_1.x_30_1 ;
    x_40_7 = Qtempx * t_5_1_0.x_40_1 + WQtempx * t_5_1_1.x_40_1 + CDtemp * ( t_5_0_0.x_40_0 -  ABcom * t_5_0_1.x_40_0 ) + ABCDtemp * t_4_1_1.x_31_1 ;
    x_41_7 = Qtempx * t_5_1_0.x_41_1 + WQtempx * t_5_1_1.x_41_1 + CDtemp * ( t_5_0_0.x_41_0 -  ABcom * t_5_0_1.x_41_0 ) ;
    x_42_7 = Qtempx * t_5_1_0.x_42_1 + WQtempx * t_5_1_1.x_42_1 + CDtemp * ( t_5_0_0.x_42_0 -  ABcom * t_5_0_1.x_42_0 ) ;
    x_43_7 = Qtempx * t_5_1_0.x_43_1 + WQtempx * t_5_1_1.x_43_1 + CDtemp * ( t_5_0_0.x_43_0 -  ABcom * t_5_0_1.x_43_0 ) + 2 * ABCDtemp * t_4_1_1.x_27_1 ;
    x_44_7 = Qtempx * t_5_1_0.x_44_1 + WQtempx * t_5_1_1.x_44_1 + CDtemp * ( t_5_0_0.x_44_0 -  ABcom * t_5_0_1.x_44_0 ) + 3 * ABCDtemp * t_4_1_1.x_21_1 ;
    x_45_7 = Qtempx * t_5_1_0.x_45_1 + WQtempx * t_5_1_1.x_45_1 + CDtemp * ( t_5_0_0.x_45_0 -  ABcom * t_5_0_1.x_45_0 ) + 2 * ABCDtemp * t_4_1_1.x_29_1 ;
    x_46_7 = Qtempx * t_5_1_0.x_46_1 + WQtempx * t_5_1_1.x_46_1 + CDtemp * ( t_5_0_0.x_46_0 -  ABcom * t_5_0_1.x_46_0 ) + 3 * ABCDtemp * t_4_1_1.x_20_1 ;
    x_47_7 = Qtempx * t_5_1_0.x_47_1 + WQtempx * t_5_1_1.x_47_1 + CDtemp * ( t_5_0_0.x_47_0 -  ABcom * t_5_0_1.x_47_0 ) ;
    x_48_7 = Qtempx * t_5_1_0.x_48_1 + WQtempx * t_5_1_1.x_48_1 + CDtemp * ( t_5_0_0.x_48_0 -  ABcom * t_5_0_1.x_48_0 ) ;
    x_49_7 = Qtempx * t_5_1_0.x_49_1 + WQtempx * t_5_1_1.x_49_1 + CDtemp * ( t_5_0_0.x_49_0 -  ABcom * t_5_0_1.x_49_0 ) + ABCDtemp * t_4_1_1.x_34_1 ;
    x_50_7 = Qtempx * t_5_1_0.x_50_1 + WQtempx * t_5_1_1.x_50_1 + CDtemp * ( t_5_0_0.x_50_0 -  ABcom * t_5_0_1.x_50_0 ) + 4 * ABCDtemp * t_4_1_1.x_26_1 ;
    x_51_7 = Qtempx * t_5_1_0.x_51_1 + WQtempx * t_5_1_1.x_51_1 + CDtemp * ( t_5_0_0.x_51_0 -  ABcom * t_5_0_1.x_51_0 ) + ABCDtemp * t_4_1_1.x_33_1 ;
    x_52_7 = Qtempx * t_5_1_0.x_52_1 + WQtempx * t_5_1_1.x_52_1 + CDtemp * ( t_5_0_0.x_52_0 -  ABcom * t_5_0_1.x_52_0 ) + 4 * ABCDtemp * t_4_1_1.x_28_1 ;
    x_53_7 = Qtempx * t_5_1_0.x_53_1 + WQtempx * t_5_1_1.x_53_1 + CDtemp * ( t_5_0_0.x_53_0 -  ABcom * t_5_0_1.x_53_0 ) + 5 * ABCDtemp * t_4_1_1.x_32_1 ;
    x_54_7 = Qtempx * t_5_1_0.x_54_1 + WQtempx * t_5_1_1.x_54_1 + CDtemp * ( t_5_0_0.x_54_0 -  ABcom * t_5_0_1.x_54_0 ) ;
    x_55_7 = Qtempx * t_5_1_0.x_55_1 + WQtempx * t_5_1_1.x_55_1 + CDtemp * ( t_5_0_0.x_55_0 -  ABcom * t_5_0_1.x_55_0 ) ;
    x_35_8 = Qtempy * t_5_1_0.x_35_2 + WQtempy * t_5_1_1.x_35_2 + CDtemp * ( t_5_0_0.x_35_0 -  ABcom * t_5_0_1.x_35_0 ) + 2 * ABCDtemp * t_4_1_1.x_25_2 ;
    x_36_8 = Qtempy * t_5_1_0.x_36_2 + WQtempy * t_5_1_1.x_36_2 + CDtemp * ( t_5_0_0.x_36_0 -  ABcom * t_5_0_1.x_36_0 ) + ABCDtemp * t_4_1_1.x_21_2 ;
    x_37_8 = Qtempy * t_5_1_0.x_37_2 + WQtempy * t_5_1_1.x_37_2 + CDtemp * ( t_5_0_0.x_37_0 -  ABcom * t_5_0_1.x_37_0 ) + 2 * ABCDtemp * t_4_1_1.x_23_2 ;
    x_38_8 = Qtempy * t_5_1_0.x_38_2 + WQtempy * t_5_1_1.x_38_2 + CDtemp * ( t_5_0_0.x_38_0 -  ABcom * t_5_0_1.x_38_0 ) + ABCDtemp * t_4_1_1.x_26_2 ;
    x_39_8 = Qtempy * t_5_1_0.x_39_2 + WQtempy * t_5_1_1.x_39_2 + CDtemp * ( t_5_0_0.x_39_0 -  ABcom * t_5_0_1.x_39_0 ) + 3 * ABCDtemp * t_4_1_1.x_24_2 ;
    x_40_8 = Qtempy * t_5_1_0.x_40_2 + WQtempy * t_5_1_1.x_40_2 + CDtemp * ( t_5_0_0.x_40_0 -  ABcom * t_5_0_1.x_40_0 ) + ABCDtemp * t_4_1_1.x_27_2 ;
    x_41_8 = Qtempy * t_5_1_0.x_41_2 + WQtempy * t_5_1_1.x_41_2 + CDtemp * ( t_5_0_0.x_41_0 -  ABcom * t_5_0_1.x_41_0 ) + 2 * ABCDtemp * t_4_1_1.x_31_2 ;
    x_42_8 = Qtempy * t_5_1_0.x_42_2 + WQtempy * t_5_1_1.x_42_2 + CDtemp * ( t_5_0_0.x_42_0 -  ABcom * t_5_0_1.x_42_0 ) + 3 * ABCDtemp * t_4_1_1.x_22_2 ;
    x_43_8 = Qtempy * t_5_1_0.x_43_2 + WQtempy * t_5_1_1.x_43_2 + CDtemp * ( t_5_0_0.x_43_0 -  ABcom * t_5_0_1.x_43_0 ) ;
    x_44_8 = Qtempy * t_5_1_0.x_44_2 + WQtempy * t_5_1_1.x_44_2 + CDtemp * ( t_5_0_0.x_44_0 -  ABcom * t_5_0_1.x_44_0 ) ;
    x_45_8 = Qtempy * t_5_1_0.x_45_2 + WQtempy * t_5_1_1.x_45_2 + CDtemp * ( t_5_0_0.x_45_0 -  ABcom * t_5_0_1.x_45_0 ) + 3 * ABCDtemp * t_4_1_1.x_20_2 ;
    x_46_8 = Qtempy * t_5_1_0.x_46_2 + WQtempy * t_5_1_1.x_46_2 + CDtemp * ( t_5_0_0.x_46_0 -  ABcom * t_5_0_1.x_46_0 ) + 2 * ABCDtemp * t_4_1_1.x_28_2 ;
    x_47_8 = Qtempy * t_5_1_0.x_47_2 + WQtempy * t_5_1_1.x_47_2 + CDtemp * ( t_5_0_0.x_47_0 -  ABcom * t_5_0_1.x_47_0 ) + ABCDtemp * t_4_1_1.x_34_2 ;
    x_48_8 = Qtempy * t_5_1_0.x_48_2 + WQtempy * t_5_1_1.x_48_2 + CDtemp * ( t_5_0_0.x_48_0 -  ABcom * t_5_0_1.x_48_0 ) + 4 * ABCDtemp * t_4_1_1.x_30_2 ;
    x_49_8 = Qtempy * t_5_1_0.x_49_2 + WQtempy * t_5_1_1.x_49_2 + CDtemp * ( t_5_0_0.x_49_0 -  ABcom * t_5_0_1.x_49_0 ) ;
    x_50_8 = Qtempy * t_5_1_0.x_50_2 + WQtempy * t_5_1_1.x_50_2 + CDtemp * ( t_5_0_0.x_50_0 -  ABcom * t_5_0_1.x_50_0 ) ;
    x_51_8 = Qtempy * t_5_1_0.x_51_2 + WQtempy * t_5_1_1.x_51_2 + CDtemp * ( t_5_0_0.x_51_0 -  ABcom * t_5_0_1.x_51_0 ) + 4 * ABCDtemp * t_4_1_1.x_29_2 ;
    x_52_8 = Qtempy * t_5_1_0.x_52_2 + WQtempy * t_5_1_1.x_52_2 + CDtemp * ( t_5_0_0.x_52_0 -  ABcom * t_5_0_1.x_52_0 ) + ABCDtemp * t_4_1_1.x_32_2 ;
    x_53_8 = Qtempy * t_5_1_0.x_53_2 + WQtempy * t_5_1_1.x_53_2 + CDtemp * ( t_5_0_0.x_53_0 -  ABcom * t_5_0_1.x_53_0 ) ;
    x_54_8 = Qtempy * t_5_1_0.x_54_2 + WQtempy * t_5_1_1.x_54_2 + CDtemp * ( t_5_0_0.x_54_0 -  ABcom * t_5_0_1.x_54_0 ) + 5 * ABCDtemp * t_4_1_1.x_33_2 ;
    x_55_8 = Qtempy * t_5_1_0.x_55_2 + WQtempy * t_5_1_1.x_55_2 + CDtemp * ( t_5_0_0.x_55_0 -  ABcom * t_5_0_1.x_55_0 ) ;
    x_35_9 = Qtempz * t_5_1_0.x_35_3 + WQtempz * t_5_1_1.x_35_3 + CDtemp * ( t_5_0_0.x_35_0 -  ABcom * t_5_0_1.x_35_0 ) + 2 * ABCDtemp * t_4_1_1.x_24_3 ;
    x_36_9 = Qtempz * t_5_1_0.x_36_3 + WQtempz * t_5_1_1.x_36_3 + CDtemp * ( t_5_0_0.x_36_0 -  ABcom * t_5_0_1.x_36_0 ) + 2 * ABCDtemp * t_4_1_1.x_23_3 ;
    x_37_9 = Qtempz * t_5_1_0.x_37_3 + WQtempz * t_5_1_1.x_37_3 + CDtemp * ( t_5_0_0.x_37_0 -  ABcom * t_5_0_1.x_37_0 ) + ABCDtemp * t_4_1_1.x_20_3 ;
    x_38_9 = Qtempz * t_5_1_0.x_38_3 + WQtempz * t_5_1_1.x_38_3 + CDtemp * ( t_5_0_0.x_38_0 -  ABcom * t_5_0_1.x_38_0 ) + ABCDtemp * t_4_1_1.x_28_3 ;
    x_39_9 = Qtempz * t_5_1_0.x_39_3 + WQtempz * t_5_1_1.x_39_3 + CDtemp * ( t_5_0_0.x_39_0 -  ABcom * t_5_0_1.x_39_0 ) + ABCDtemp * t_4_1_1.x_29_3 ;
    x_40_9 = Qtempz * t_5_1_0.x_40_3 + WQtempz * t_5_1_1.x_40_3 + CDtemp * ( t_5_0_0.x_40_0 -  ABcom * t_5_0_1.x_40_0 ) + 3 * ABCDtemp * t_4_1_1.x_25_3 ;
    x_41_9 = Qtempz * t_5_1_0.x_41_3 + WQtempz * t_5_1_1.x_41_3 + CDtemp * ( t_5_0_0.x_41_0 -  ABcom * t_5_0_1.x_41_0 ) + 3 * ABCDtemp * t_4_1_1.x_22_3 ;
    x_42_9 = Qtempz * t_5_1_0.x_42_3 + WQtempz * t_5_1_1.x_42_3 + CDtemp * ( t_5_0_0.x_42_0 -  ABcom * t_5_0_1.x_42_0 ) + 2 * ABCDtemp * t_4_1_1.x_30_3 ;
    x_43_9 = Qtempz * t_5_1_0.x_43_3 + WQtempz * t_5_1_1.x_43_3 + CDtemp * ( t_5_0_0.x_43_0 -  ABcom * t_5_0_1.x_43_0 ) + 3 * ABCDtemp * t_4_1_1.x_21_3 ;
    x_44_9 = Qtempz * t_5_1_0.x_44_3 + WQtempz * t_5_1_1.x_44_3 + CDtemp * ( t_5_0_0.x_44_0 -  ABcom * t_5_0_1.x_44_0 ) + 2 * ABCDtemp * t_4_1_1.x_26_3 ;
    x_45_9 = Qtempz * t_5_1_0.x_45_3 + WQtempz * t_5_1_1.x_45_3 + CDtemp * ( t_5_0_0.x_45_0 -  ABcom * t_5_0_1.x_45_0 ) ;
    x_46_9 = Qtempz * t_5_1_0.x_46_3 + WQtempz * t_5_1_1.x_46_3 + CDtemp * ( t_5_0_0.x_46_0 -  ABcom * t_5_0_1.x_46_0 ) ;
    x_47_9 = Qtempz * t_5_1_0.x_47_3 + WQtempz * t_5_1_1.x_47_3 + CDtemp * ( t_5_0_0.x_47_0 -  ABcom * t_5_0_1.x_47_0 ) + 4 * ABCDtemp * t_4_1_1.x_31_3 ;
    x_48_9 = Qtempz * t_5_1_0.x_48_3 + WQtempz * t_5_1_1.x_48_3 + CDtemp * ( t_5_0_0.x_48_0 -  ABcom * t_5_0_1.x_48_0 ) + ABCDtemp * t_4_1_1.x_33_3 ;
    x_49_9 = Qtempz * t_5_1_0.x_49_3 + WQtempz * t_5_1_1.x_49_3 + CDtemp * ( t_5_0_0.x_49_0 -  ABcom * t_5_0_1.x_49_0 ) + 4 * ABCDtemp * t_4_1_1.x_27_3 ;
    x_50_9 = Qtempz * t_5_1_0.x_50_3 + WQtempz * t_5_1_1.x_50_3 + CDtemp * ( t_5_0_0.x_50_0 -  ABcom * t_5_0_1.x_50_0 ) + ABCDtemp * t_4_1_1.x_32_3 ;
    x_51_9 = Qtempz * t_5_1_0.x_51_3 + WQtempz * t_5_1_1.x_51_3 + CDtemp * ( t_5_0_0.x_51_0 -  ABcom * t_5_0_1.x_51_0 ) ;
    x_52_9 = Qtempz * t_5_1_0.x_52_3 + WQtempz * t_5_1_1.x_52_3 + CDtemp * ( t_5_0_0.x_52_0 -  ABcom * t_5_0_1.x_52_0 ) ;
    x_53_9 = Qtempz * t_5_1_0.x_53_3 + WQtempz * t_5_1_1.x_53_3 + CDtemp * ( t_5_0_0.x_53_0 -  ABcom * t_5_0_1.x_53_0 ) ;
    x_54_9 = Qtempz * t_5_1_0.x_54_3 + WQtempz * t_5_1_1.x_54_3 + CDtemp * ( t_5_0_0.x_54_0 -  ABcom * t_5_0_1.x_54_0 ) ;
    x_55_9 = Qtempz * t_5_1_0.x_55_3 + WQtempz * t_5_1_1.x_55_3 + CDtemp * ( t_5_0_0.x_55_0 -  ABcom * t_5_0_1.x_55_0 ) + 5 * ABCDtemp * t_4_1_1.x_34_3 ;
}