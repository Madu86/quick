#include "../gpu_common.h"
#include "./h_all_files.h"
// Class for L =            3  B =            6
__device__ __inline__  f_3_6_t :: f_3_6_t ( f_2_6_t t_2_6_0, f_2_6_t t_2_6_1, f_1_6_t t_1_6_0, f_1_6_t t_1_6_1, QUICKDouble ABtemp, QUICKDouble CDcom, f_2_5_t t_2_5_1, QUICKDouble ABCDtemp, QUICKDouble Ptempx, QUICKDouble Ptempy, QUICKDouble Ptempz,  QUICKDouble WPtempx, QUICKDouble WPtempy, QUICKDouble WPtempz) {
    x_10_56 = Ptempx * t_2_6_0.x_5_56 + WPtempx * t_2_6_1.x_5_56 + 4 * ABCDtemp * t_2_5_1.x_5_38 ;
    x_10_57 = Ptempx * t_2_6_0.x_5_57 + WPtempx * t_2_6_1.x_5_57 + ABCDtemp * t_2_5_1.x_5_48 ;
    x_10_58 = Ptempx * t_2_6_0.x_5_58 + WPtempx * t_2_6_1.x_5_58 + ABCDtemp * t_2_5_1.x_5_47 ;
    x_10_59 = Ptempx * t_2_6_0.x_5_59 + WPtempx * t_2_6_1.x_5_59 + ABCDtemp * t_2_5_1.x_5_41 ;
    x_10_60 = Ptempx * t_2_6_0.x_5_60 + WPtempx * t_2_6_1.x_5_60 + ABCDtemp * t_2_5_1.x_5_42 ;
    x_10_61 = Ptempx * t_2_6_0.x_5_61 + WPtempx * t_2_6_1.x_5_61 + 2 * ABCDtemp * t_2_5_1.x_5_40 ;
    x_10_62 = Ptempx * t_2_6_0.x_5_62 + WPtempx * t_2_6_1.x_5_62 + 3 * ABCDtemp * t_2_5_1.x_5_36 ;
    x_10_63 = Ptempx * t_2_6_0.x_5_63 + WPtempx * t_2_6_1.x_5_63 + 2 * ABCDtemp * t_2_5_1.x_5_39 ;
    x_10_64 = Ptempx * t_2_6_0.x_5_64 + WPtempx * t_2_6_1.x_5_64 + 3 * ABCDtemp * t_2_5_1.x_5_37 ;
    x_10_65 = Ptempx * t_2_6_0.x_5_65 + WPtempx * t_2_6_1.x_5_65 + 2 * ABCDtemp * t_2_5_1.x_5_35 ;
    x_10_66 = Ptempx * t_2_6_0.x_5_66 + WPtempx * t_2_6_1.x_5_66 ;
    x_10_67 = Ptempx * t_2_6_0.x_5_67 + WPtempx * t_2_6_1.x_5_67 ;
    x_10_68 = Ptempx * t_2_6_0.x_5_68 + WPtempx * t_2_6_1.x_5_68 + ABCDtemp * t_2_5_1.x_5_55 ;
    x_10_69 = Ptempx * t_2_6_0.x_5_69 + WPtempx * t_2_6_1.x_5_69 + 5 * ABCDtemp * t_2_5_1.x_5_50 ;
    x_10_70 = Ptempx * t_2_6_0.x_5_70 + WPtempx * t_2_6_1.x_5_70 + ABCDtemp * t_2_5_1.x_5_54 ;
    x_10_71 = Ptempx * t_2_6_0.x_5_71 + WPtempx * t_2_6_1.x_5_71 + 5 * ABCDtemp * t_2_5_1.x_5_52 ;
    x_10_72 = Ptempx * t_2_6_0.x_5_72 + WPtempx * t_2_6_1.x_5_72 ;
    x_10_73 = Ptempx * t_2_6_0.x_5_73 + WPtempx * t_2_6_1.x_5_73 ;
    x_10_74 = Ptempx * t_2_6_0.x_5_74 + WPtempx * t_2_6_1.x_5_74 + 2 * ABCDtemp * t_2_5_1.x_5_49 ;
    x_10_75 = Ptempx * t_2_6_0.x_5_75 + WPtempx * t_2_6_1.x_5_75 + 4 * ABCDtemp * t_2_5_1.x_5_44 ;
    x_10_76 = Ptempx * t_2_6_0.x_5_76 + WPtempx * t_2_6_1.x_5_76 + 2 * ABCDtemp * t_2_5_1.x_5_51 ;
    x_10_77 = Ptempx * t_2_6_0.x_5_77 + WPtempx * t_2_6_1.x_5_77 + 4 * ABCDtemp * t_2_5_1.x_5_46 ;
    x_10_78 = Ptempx * t_2_6_0.x_5_78 + WPtempx * t_2_6_1.x_5_78 ;
    x_10_79 = Ptempx * t_2_6_0.x_5_79 + WPtempx * t_2_6_1.x_5_79 + 3 * ABCDtemp * t_2_5_1.x_5_43 ;
    x_10_80 = Ptempx * t_2_6_0.x_5_80 + WPtempx * t_2_6_1.x_5_80 + 3 * ABCDtemp * t_2_5_1.x_5_45 ;
    x_10_81 = Ptempx * t_2_6_0.x_5_81 + WPtempx * t_2_6_1.x_5_81 + 6 * ABCDtemp * t_2_5_1.x_5_53 ;
    x_10_82 = Ptempx * t_2_6_0.x_5_82 + WPtempx * t_2_6_1.x_5_82 ;
    x_10_83 = Ptempx * t_2_6_0.x_5_83 + WPtempx * t_2_6_1.x_5_83 ;
    x_11_56 = Ptempx * t_2_6_0.x_4_56 + WPtempx * t_2_6_1.x_4_56 + ABtemp * ( t_1_6_0.x_2_56 -  CDcom * t_1_6_1.x_2_56 ) + 4 * ABCDtemp * t_2_5_1.x_4_38 ;
    x_11_57 = Ptempx * t_2_6_0.x_4_57 + WPtempx * t_2_6_1.x_4_57 + ABtemp * ( t_1_6_0.x_2_57 -  CDcom * t_1_6_1.x_2_57 ) + ABCDtemp * t_2_5_1.x_4_48 ;
    x_11_58 = Ptempx * t_2_6_0.x_4_58 + WPtempx * t_2_6_1.x_4_58 + ABtemp * ( t_1_6_0.x_2_58 -  CDcom * t_1_6_1.x_2_58 ) + ABCDtemp * t_2_5_1.x_4_47 ;
    x_11_59 = Ptempx * t_2_6_0.x_4_59 + WPtempx * t_2_6_1.x_4_59 + ABtemp * ( t_1_6_0.x_2_59 -  CDcom * t_1_6_1.x_2_59 ) + ABCDtemp * t_2_5_1.x_4_41 ;
    x_11_60 = Ptempx * t_2_6_0.x_4_60 + WPtempx * t_2_6_1.x_4_60 + ABtemp * ( t_1_6_0.x_2_60 -  CDcom * t_1_6_1.x_2_60 ) + ABCDtemp * t_2_5_1.x_4_42 ;
    x_11_61 = Ptempx * t_2_6_0.x_4_61 + WPtempx * t_2_6_1.x_4_61 + ABtemp * ( t_1_6_0.x_2_61 -  CDcom * t_1_6_1.x_2_61 ) + 2 * ABCDtemp * t_2_5_1.x_4_40 ;
    x_11_62 = Ptempx * t_2_6_0.x_4_62 + WPtempx * t_2_6_1.x_4_62 + ABtemp * ( t_1_6_0.x_2_62 -  CDcom * t_1_6_1.x_2_62 ) + 3 * ABCDtemp * t_2_5_1.x_4_36 ;
    x_11_63 = Ptempx * t_2_6_0.x_4_63 + WPtempx * t_2_6_1.x_4_63 + ABtemp * ( t_1_6_0.x_2_63 -  CDcom * t_1_6_1.x_2_63 ) + 2 * ABCDtemp * t_2_5_1.x_4_39 ;
    x_11_64 = Ptempx * t_2_6_0.x_4_64 + WPtempx * t_2_6_1.x_4_64 + ABtemp * ( t_1_6_0.x_2_64 -  CDcom * t_1_6_1.x_2_64 ) + 3 * ABCDtemp * t_2_5_1.x_4_37 ;
    x_11_65 = Ptempx * t_2_6_0.x_4_65 + WPtempx * t_2_6_1.x_4_65 + ABtemp * ( t_1_6_0.x_2_65 -  CDcom * t_1_6_1.x_2_65 ) + 2 * ABCDtemp * t_2_5_1.x_4_35 ;
    x_11_66 = Ptempx * t_2_6_0.x_4_66 + WPtempx * t_2_6_1.x_4_66 + ABtemp * ( t_1_6_0.x_2_66 -  CDcom * t_1_6_1.x_2_66 ) ;
    x_11_67 = Ptempx * t_2_6_0.x_4_67 + WPtempx * t_2_6_1.x_4_67 + ABtemp * ( t_1_6_0.x_2_67 -  CDcom * t_1_6_1.x_2_67 ) ;
    x_11_68 = Ptempx * t_2_6_0.x_4_68 + WPtempx * t_2_6_1.x_4_68 + ABtemp * ( t_1_6_0.x_2_68 -  CDcom * t_1_6_1.x_2_68 ) + ABCDtemp * t_2_5_1.x_4_55 ;
    x_11_69 = Ptempx * t_2_6_0.x_4_69 + WPtempx * t_2_6_1.x_4_69 + ABtemp * ( t_1_6_0.x_2_69 -  CDcom * t_1_6_1.x_2_69 ) + 5 * ABCDtemp * t_2_5_1.x_4_50 ;
    x_11_70 = Ptempx * t_2_6_0.x_4_70 + WPtempx * t_2_6_1.x_4_70 + ABtemp * ( t_1_6_0.x_2_70 -  CDcom * t_1_6_1.x_2_70 ) + ABCDtemp * t_2_5_1.x_4_54 ;
    x_11_71 = Ptempx * t_2_6_0.x_4_71 + WPtempx * t_2_6_1.x_4_71 + ABtemp * ( t_1_6_0.x_2_71 -  CDcom * t_1_6_1.x_2_71 ) + 5 * ABCDtemp * t_2_5_1.x_4_52 ;
    x_11_72 = Ptempx * t_2_6_0.x_4_72 + WPtempx * t_2_6_1.x_4_72 + ABtemp * ( t_1_6_0.x_2_72 -  CDcom * t_1_6_1.x_2_72 ) ;
    x_11_73 = Ptempx * t_2_6_0.x_4_73 + WPtempx * t_2_6_1.x_4_73 + ABtemp * ( t_1_6_0.x_2_73 -  CDcom * t_1_6_1.x_2_73 ) ;
    x_11_74 = Ptempx * t_2_6_0.x_4_74 + WPtempx * t_2_6_1.x_4_74 + ABtemp * ( t_1_6_0.x_2_74 -  CDcom * t_1_6_1.x_2_74 ) + 2 * ABCDtemp * t_2_5_1.x_4_49 ;
    x_11_75 = Ptempx * t_2_6_0.x_4_75 + WPtempx * t_2_6_1.x_4_75 + ABtemp * ( t_1_6_0.x_2_75 -  CDcom * t_1_6_1.x_2_75 ) + 4 * ABCDtemp * t_2_5_1.x_4_44 ;
    x_11_76 = Ptempx * t_2_6_0.x_4_76 + WPtempx * t_2_6_1.x_4_76 + ABtemp * ( t_1_6_0.x_2_76 -  CDcom * t_1_6_1.x_2_76 ) + 2 * ABCDtemp * t_2_5_1.x_4_51 ;
    x_11_77 = Ptempx * t_2_6_0.x_4_77 + WPtempx * t_2_6_1.x_4_77 + ABtemp * ( t_1_6_0.x_2_77 -  CDcom * t_1_6_1.x_2_77 ) + 4 * ABCDtemp * t_2_5_1.x_4_46 ;
    x_11_78 = Ptempx * t_2_6_0.x_4_78 + WPtempx * t_2_6_1.x_4_78 + ABtemp * ( t_1_6_0.x_2_78 -  CDcom * t_1_6_1.x_2_78 ) ;
    x_11_79 = Ptempx * t_2_6_0.x_4_79 + WPtempx * t_2_6_1.x_4_79 + ABtemp * ( t_1_6_0.x_2_79 -  CDcom * t_1_6_1.x_2_79 ) + 3 * ABCDtemp * t_2_5_1.x_4_43 ;
    x_11_80 = Ptempx * t_2_6_0.x_4_80 + WPtempx * t_2_6_1.x_4_80 + ABtemp * ( t_1_6_0.x_2_80 -  CDcom * t_1_6_1.x_2_80 ) + 3 * ABCDtemp * t_2_5_1.x_4_45 ;
    x_11_81 = Ptempx * t_2_6_0.x_4_81 + WPtempx * t_2_6_1.x_4_81 + ABtemp * ( t_1_6_0.x_2_81 -  CDcom * t_1_6_1.x_2_81 ) + 6 * ABCDtemp * t_2_5_1.x_4_53 ;
    x_11_82 = Ptempx * t_2_6_0.x_4_82 + WPtempx * t_2_6_1.x_4_82 + ABtemp * ( t_1_6_0.x_2_82 -  CDcom * t_1_6_1.x_2_82 ) ;
    x_11_83 = Ptempx * t_2_6_0.x_4_83 + WPtempx * t_2_6_1.x_4_83 + ABtemp * ( t_1_6_0.x_2_83 -  CDcom * t_1_6_1.x_2_83 ) ;
    x_12_56 = Ptempx * t_2_6_0.x_8_56 + WPtempx * t_2_6_1.x_8_56 + 4 * ABCDtemp * t_2_5_1.x_8_38 ;
    x_12_57 = Ptempx * t_2_6_0.x_8_57 + WPtempx * t_2_6_1.x_8_57 + ABCDtemp * t_2_5_1.x_8_48 ;
    x_12_58 = Ptempx * t_2_6_0.x_8_58 + WPtempx * t_2_6_1.x_8_58 + ABCDtemp * t_2_5_1.x_8_47 ;
    x_12_59 = Ptempx * t_2_6_0.x_8_59 + WPtempx * t_2_6_1.x_8_59 + ABCDtemp * t_2_5_1.x_8_41 ;
    x_12_60 = Ptempx * t_2_6_0.x_8_60 + WPtempx * t_2_6_1.x_8_60 + ABCDtemp * t_2_5_1.x_8_42 ;
    x_12_61 = Ptempx * t_2_6_0.x_8_61 + WPtempx * t_2_6_1.x_8_61 + 2 * ABCDtemp * t_2_5_1.x_8_40 ;
    x_12_62 = Ptempx * t_2_6_0.x_8_62 + WPtempx * t_2_6_1.x_8_62 + 3 * ABCDtemp * t_2_5_1.x_8_36 ;
    x_12_63 = Ptempx * t_2_6_0.x_8_63 + WPtempx * t_2_6_1.x_8_63 + 2 * ABCDtemp * t_2_5_1.x_8_39 ;
    x_12_64 = Ptempx * t_2_6_0.x_8_64 + WPtempx * t_2_6_1.x_8_64 + 3 * ABCDtemp * t_2_5_1.x_8_37 ;
    x_12_65 = Ptempx * t_2_6_0.x_8_65 + WPtempx * t_2_6_1.x_8_65 + 2 * ABCDtemp * t_2_5_1.x_8_35 ;
    x_12_66 = Ptempx * t_2_6_0.x_8_66 + WPtempx * t_2_6_1.x_8_66 ;
    x_12_67 = Ptempx * t_2_6_0.x_8_67 + WPtempx * t_2_6_1.x_8_67 ;
    x_12_68 = Ptempx * t_2_6_0.x_8_68 + WPtempx * t_2_6_1.x_8_68 + ABCDtemp * t_2_5_1.x_8_55 ;
    x_12_69 = Ptempx * t_2_6_0.x_8_69 + WPtempx * t_2_6_1.x_8_69 + 5 * ABCDtemp * t_2_5_1.x_8_50 ;
    x_12_70 = Ptempx * t_2_6_0.x_8_70 + WPtempx * t_2_6_1.x_8_70 + ABCDtemp * t_2_5_1.x_8_54 ;
    x_12_71 = Ptempx * t_2_6_0.x_8_71 + WPtempx * t_2_6_1.x_8_71 + 5 * ABCDtemp * t_2_5_1.x_8_52 ;
    x_12_72 = Ptempx * t_2_6_0.x_8_72 + WPtempx * t_2_6_1.x_8_72 ;
    x_12_73 = Ptempx * t_2_6_0.x_8_73 + WPtempx * t_2_6_1.x_8_73 ;
    x_12_74 = Ptempx * t_2_6_0.x_8_74 + WPtempx * t_2_6_1.x_8_74 + 2 * ABCDtemp * t_2_5_1.x_8_49 ;
    x_12_75 = Ptempx * t_2_6_0.x_8_75 + WPtempx * t_2_6_1.x_8_75 + 4 * ABCDtemp * t_2_5_1.x_8_44 ;
    x_12_76 = Ptempx * t_2_6_0.x_8_76 + WPtempx * t_2_6_1.x_8_76 + 2 * ABCDtemp * t_2_5_1.x_8_51 ;
    x_12_77 = Ptempx * t_2_6_0.x_8_77 + WPtempx * t_2_6_1.x_8_77 + 4 * ABCDtemp * t_2_5_1.x_8_46 ;
    x_12_78 = Ptempx * t_2_6_0.x_8_78 + WPtempx * t_2_6_1.x_8_78 ;
    x_12_79 = Ptempx * t_2_6_0.x_8_79 + WPtempx * t_2_6_1.x_8_79 + 3 * ABCDtemp * t_2_5_1.x_8_43 ;
    x_12_80 = Ptempx * t_2_6_0.x_8_80 + WPtempx * t_2_6_1.x_8_80 + 3 * ABCDtemp * t_2_5_1.x_8_45 ;
    x_12_81 = Ptempx * t_2_6_0.x_8_81 + WPtempx * t_2_6_1.x_8_81 + 6 * ABCDtemp * t_2_5_1.x_8_53 ;
    x_12_82 = Ptempx * t_2_6_0.x_8_82 + WPtempx * t_2_6_1.x_8_82 ;
    x_12_83 = Ptempx * t_2_6_0.x_8_83 + WPtempx * t_2_6_1.x_8_83 ;
    x_13_56 = Ptempx * t_2_6_0.x_6_56 + WPtempx * t_2_6_1.x_6_56 + ABtemp * ( t_1_6_0.x_3_56 -  CDcom * t_1_6_1.x_3_56 ) + 4 * ABCDtemp * t_2_5_1.x_6_38 ;
    x_13_57 = Ptempx * t_2_6_0.x_6_57 + WPtempx * t_2_6_1.x_6_57 + ABtemp * ( t_1_6_0.x_3_57 -  CDcom * t_1_6_1.x_3_57 ) + ABCDtemp * t_2_5_1.x_6_48 ;
    x_13_58 = Ptempx * t_2_6_0.x_6_58 + WPtempx * t_2_6_1.x_6_58 + ABtemp * ( t_1_6_0.x_3_58 -  CDcom * t_1_6_1.x_3_58 ) + ABCDtemp * t_2_5_1.x_6_47 ;
    x_13_59 = Ptempx * t_2_6_0.x_6_59 + WPtempx * t_2_6_1.x_6_59 + ABtemp * ( t_1_6_0.x_3_59 -  CDcom * t_1_6_1.x_3_59 ) + ABCDtemp * t_2_5_1.x_6_41 ;
    x_13_60 = Ptempx * t_2_6_0.x_6_60 + WPtempx * t_2_6_1.x_6_60 + ABtemp * ( t_1_6_0.x_3_60 -  CDcom * t_1_6_1.x_3_60 ) + ABCDtemp * t_2_5_1.x_6_42 ;
    x_13_61 = Ptempx * t_2_6_0.x_6_61 + WPtempx * t_2_6_1.x_6_61 + ABtemp * ( t_1_6_0.x_3_61 -  CDcom * t_1_6_1.x_3_61 ) + 2 * ABCDtemp * t_2_5_1.x_6_40 ;
    x_13_62 = Ptempx * t_2_6_0.x_6_62 + WPtempx * t_2_6_1.x_6_62 + ABtemp * ( t_1_6_0.x_3_62 -  CDcom * t_1_6_1.x_3_62 ) + 3 * ABCDtemp * t_2_5_1.x_6_36 ;
    x_13_63 = Ptempx * t_2_6_0.x_6_63 + WPtempx * t_2_6_1.x_6_63 + ABtemp * ( t_1_6_0.x_3_63 -  CDcom * t_1_6_1.x_3_63 ) + 2 * ABCDtemp * t_2_5_1.x_6_39 ;
    x_13_64 = Ptempx * t_2_6_0.x_6_64 + WPtempx * t_2_6_1.x_6_64 + ABtemp * ( t_1_6_0.x_3_64 -  CDcom * t_1_6_1.x_3_64 ) + 3 * ABCDtemp * t_2_5_1.x_6_37 ;
    x_13_65 = Ptempx * t_2_6_0.x_6_65 + WPtempx * t_2_6_1.x_6_65 + ABtemp * ( t_1_6_0.x_3_65 -  CDcom * t_1_6_1.x_3_65 ) + 2 * ABCDtemp * t_2_5_1.x_6_35 ;
    x_13_66 = Ptempx * t_2_6_0.x_6_66 + WPtempx * t_2_6_1.x_6_66 + ABtemp * ( t_1_6_0.x_3_66 -  CDcom * t_1_6_1.x_3_66 ) ;
    x_13_67 = Ptempx * t_2_6_0.x_6_67 + WPtempx * t_2_6_1.x_6_67 + ABtemp * ( t_1_6_0.x_3_67 -  CDcom * t_1_6_1.x_3_67 ) ;
    x_13_68 = Ptempx * t_2_6_0.x_6_68 + WPtempx * t_2_6_1.x_6_68 + ABtemp * ( t_1_6_0.x_3_68 -  CDcom * t_1_6_1.x_3_68 ) + ABCDtemp * t_2_5_1.x_6_55 ;
    x_13_69 = Ptempx * t_2_6_0.x_6_69 + WPtempx * t_2_6_1.x_6_69 + ABtemp * ( t_1_6_0.x_3_69 -  CDcom * t_1_6_1.x_3_69 ) + 5 * ABCDtemp * t_2_5_1.x_6_50 ;
    x_13_70 = Ptempx * t_2_6_0.x_6_70 + WPtempx * t_2_6_1.x_6_70 + ABtemp * ( t_1_6_0.x_3_70 -  CDcom * t_1_6_1.x_3_70 ) + ABCDtemp * t_2_5_1.x_6_54 ;
    x_13_71 = Ptempx * t_2_6_0.x_6_71 + WPtempx * t_2_6_1.x_6_71 + ABtemp * ( t_1_6_0.x_3_71 -  CDcom * t_1_6_1.x_3_71 ) + 5 * ABCDtemp * t_2_5_1.x_6_52 ;
    x_13_72 = Ptempx * t_2_6_0.x_6_72 + WPtempx * t_2_6_1.x_6_72 + ABtemp * ( t_1_6_0.x_3_72 -  CDcom * t_1_6_1.x_3_72 ) ;
    x_13_73 = Ptempx * t_2_6_0.x_6_73 + WPtempx * t_2_6_1.x_6_73 + ABtemp * ( t_1_6_0.x_3_73 -  CDcom * t_1_6_1.x_3_73 ) ;
    x_13_74 = Ptempx * t_2_6_0.x_6_74 + WPtempx * t_2_6_1.x_6_74 + ABtemp * ( t_1_6_0.x_3_74 -  CDcom * t_1_6_1.x_3_74 ) + 2 * ABCDtemp * t_2_5_1.x_6_49 ;
    x_13_75 = Ptempx * t_2_6_0.x_6_75 + WPtempx * t_2_6_1.x_6_75 + ABtemp * ( t_1_6_0.x_3_75 -  CDcom * t_1_6_1.x_3_75 ) + 4 * ABCDtemp * t_2_5_1.x_6_44 ;
    x_13_76 = Ptempx * t_2_6_0.x_6_76 + WPtempx * t_2_6_1.x_6_76 + ABtemp * ( t_1_6_0.x_3_76 -  CDcom * t_1_6_1.x_3_76 ) + 2 * ABCDtemp * t_2_5_1.x_6_51 ;
    x_13_77 = Ptempx * t_2_6_0.x_6_77 + WPtempx * t_2_6_1.x_6_77 + ABtemp * ( t_1_6_0.x_3_77 -  CDcom * t_1_6_1.x_3_77 ) + 4 * ABCDtemp * t_2_5_1.x_6_46 ;
    x_13_78 = Ptempx * t_2_6_0.x_6_78 + WPtempx * t_2_6_1.x_6_78 + ABtemp * ( t_1_6_0.x_3_78 -  CDcom * t_1_6_1.x_3_78 ) ;
    x_13_79 = Ptempx * t_2_6_0.x_6_79 + WPtempx * t_2_6_1.x_6_79 + ABtemp * ( t_1_6_0.x_3_79 -  CDcom * t_1_6_1.x_3_79 ) + 3 * ABCDtemp * t_2_5_1.x_6_43 ;
    x_13_80 = Ptempx * t_2_6_0.x_6_80 + WPtempx * t_2_6_1.x_6_80 + ABtemp * ( t_1_6_0.x_3_80 -  CDcom * t_1_6_1.x_3_80 ) + 3 * ABCDtemp * t_2_5_1.x_6_45 ;
    x_13_81 = Ptempx * t_2_6_0.x_6_81 + WPtempx * t_2_6_1.x_6_81 + ABtemp * ( t_1_6_0.x_3_81 -  CDcom * t_1_6_1.x_3_81 ) + 6 * ABCDtemp * t_2_5_1.x_6_53 ;
    x_13_82 = Ptempx * t_2_6_0.x_6_82 + WPtempx * t_2_6_1.x_6_82 + ABtemp * ( t_1_6_0.x_3_82 -  CDcom * t_1_6_1.x_3_82 ) ;
    x_13_83 = Ptempx * t_2_6_0.x_6_83 + WPtempx * t_2_6_1.x_6_83 + ABtemp * ( t_1_6_0.x_3_83 -  CDcom * t_1_6_1.x_3_83 ) ;
    x_14_56 = Ptempx * t_2_6_0.x_9_56 + WPtempx * t_2_6_1.x_9_56 + 4 * ABCDtemp * t_2_5_1.x_9_38 ;
    x_14_57 = Ptempx * t_2_6_0.x_9_57 + WPtempx * t_2_6_1.x_9_57 + ABCDtemp * t_2_5_1.x_9_48 ;
    x_14_58 = Ptempx * t_2_6_0.x_9_58 + WPtempx * t_2_6_1.x_9_58 + ABCDtemp * t_2_5_1.x_9_47 ;
    x_14_59 = Ptempx * t_2_6_0.x_9_59 + WPtempx * t_2_6_1.x_9_59 + ABCDtemp * t_2_5_1.x_9_41 ;
    x_14_60 = Ptempx * t_2_6_0.x_9_60 + WPtempx * t_2_6_1.x_9_60 + ABCDtemp * t_2_5_1.x_9_42 ;
    x_14_61 = Ptempx * t_2_6_0.x_9_61 + WPtempx * t_2_6_1.x_9_61 + 2 * ABCDtemp * t_2_5_1.x_9_40 ;
    x_14_62 = Ptempx * t_2_6_0.x_9_62 + WPtempx * t_2_6_1.x_9_62 + 3 * ABCDtemp * t_2_5_1.x_9_36 ;
    x_14_63 = Ptempx * t_2_6_0.x_9_63 + WPtempx * t_2_6_1.x_9_63 + 2 * ABCDtemp * t_2_5_1.x_9_39 ;
    x_14_64 = Ptempx * t_2_6_0.x_9_64 + WPtempx * t_2_6_1.x_9_64 + 3 * ABCDtemp * t_2_5_1.x_9_37 ;
    x_14_65 = Ptempx * t_2_6_0.x_9_65 + WPtempx * t_2_6_1.x_9_65 + 2 * ABCDtemp * t_2_5_1.x_9_35 ;
    x_14_66 = Ptempx * t_2_6_0.x_9_66 + WPtempx * t_2_6_1.x_9_66 ;
    x_14_67 = Ptempx * t_2_6_0.x_9_67 + WPtempx * t_2_6_1.x_9_67 ;
    x_14_68 = Ptempx * t_2_6_0.x_9_68 + WPtempx * t_2_6_1.x_9_68 + ABCDtemp * t_2_5_1.x_9_55 ;
    x_14_69 = Ptempx * t_2_6_0.x_9_69 + WPtempx * t_2_6_1.x_9_69 + 5 * ABCDtemp * t_2_5_1.x_9_50 ;
    x_14_70 = Ptempx * t_2_6_0.x_9_70 + WPtempx * t_2_6_1.x_9_70 + ABCDtemp * t_2_5_1.x_9_54 ;
    x_14_71 = Ptempx * t_2_6_0.x_9_71 + WPtempx * t_2_6_1.x_9_71 + 5 * ABCDtemp * t_2_5_1.x_9_52 ;
    x_14_72 = Ptempx * t_2_6_0.x_9_72 + WPtempx * t_2_6_1.x_9_72 ;
    x_14_73 = Ptempx * t_2_6_0.x_9_73 + WPtempx * t_2_6_1.x_9_73 ;
    x_14_74 = Ptempx * t_2_6_0.x_9_74 + WPtempx * t_2_6_1.x_9_74 + 2 * ABCDtemp * t_2_5_1.x_9_49 ;
    x_14_75 = Ptempx * t_2_6_0.x_9_75 + WPtempx * t_2_6_1.x_9_75 + 4 * ABCDtemp * t_2_5_1.x_9_44 ;
    x_14_76 = Ptempx * t_2_6_0.x_9_76 + WPtempx * t_2_6_1.x_9_76 + 2 * ABCDtemp * t_2_5_1.x_9_51 ;
    x_14_77 = Ptempx * t_2_6_0.x_9_77 + WPtempx * t_2_6_1.x_9_77 + 4 * ABCDtemp * t_2_5_1.x_9_46 ;
    x_14_78 = Ptempx * t_2_6_0.x_9_78 + WPtempx * t_2_6_1.x_9_78 ;
    x_14_79 = Ptempx * t_2_6_0.x_9_79 + WPtempx * t_2_6_1.x_9_79 + 3 * ABCDtemp * t_2_5_1.x_9_43 ;
    x_14_80 = Ptempx * t_2_6_0.x_9_80 + WPtempx * t_2_6_1.x_9_80 + 3 * ABCDtemp * t_2_5_1.x_9_45 ;
    x_14_81 = Ptempx * t_2_6_0.x_9_81 + WPtempx * t_2_6_1.x_9_81 + 6 * ABCDtemp * t_2_5_1.x_9_53 ;
    x_14_82 = Ptempx * t_2_6_0.x_9_82 + WPtempx * t_2_6_1.x_9_82 ;
    x_14_83 = Ptempx * t_2_6_0.x_9_83 + WPtempx * t_2_6_1.x_9_83 ;
    x_15_56 = Ptempy * t_2_6_0.x_5_56 + WPtempy * t_2_6_1.x_5_56 + ABtemp * ( t_1_6_0.x_3_56 -  CDcom * t_1_6_1.x_3_56 ) + ABCDtemp * t_2_5_1.x_5_50 ;
    x_15_57 = Ptempy * t_2_6_0.x_5_57 + WPtempy * t_2_6_1.x_5_57 + ABtemp * ( t_1_6_0.x_3_57 -  CDcom * t_1_6_1.x_3_57 ) + 4 * ABCDtemp * t_2_5_1.x_5_39 ;
    x_15_58 = Ptempy * t_2_6_0.x_5_58 + WPtempy * t_2_6_1.x_5_58 + ABtemp * ( t_1_6_0.x_3_58 -  CDcom * t_1_6_1.x_3_58 ) + ABCDtemp * t_2_5_1.x_5_49 ;
    x_15_59 = Ptempy * t_2_6_0.x_5_59 + WPtempy * t_2_6_1.x_5_59 + ABtemp * ( t_1_6_0.x_3_59 -  CDcom * t_1_6_1.x_3_59 ) + 2 * ABCDtemp * t_2_5_1.x_5_40 ;
    x_15_60 = Ptempy * t_2_6_0.x_5_60 + WPtempy * t_2_6_1.x_5_60 + ABtemp * ( t_1_6_0.x_3_60 -  CDcom * t_1_6_1.x_3_60 ) + 3 * ABCDtemp * t_2_5_1.x_5_35 ;
    x_15_61 = Ptempy * t_2_6_0.x_5_61 + WPtempy * t_2_6_1.x_5_61 + ABtemp * ( t_1_6_0.x_3_61 -  CDcom * t_1_6_1.x_3_61 ) + ABCDtemp * t_2_5_1.x_5_43 ;
    x_15_62 = Ptempy * t_2_6_0.x_5_62 + WPtempy * t_2_6_1.x_5_62 + ABtemp * ( t_1_6_0.x_3_62 -  CDcom * t_1_6_1.x_3_62 ) + ABCDtemp * t_2_5_1.x_5_44 ;
    x_15_63 = Ptempy * t_2_6_0.x_5_63 + WPtempy * t_2_6_1.x_5_63 + ABtemp * ( t_1_6_0.x_3_63 -  CDcom * t_1_6_1.x_3_63 ) + 3 * ABCDtemp * t_2_5_1.x_5_37 ;
    x_15_64 = Ptempy * t_2_6_0.x_5_64 + WPtempy * t_2_6_1.x_5_64 + ABtemp * ( t_1_6_0.x_3_64 -  CDcom * t_1_6_1.x_3_64 ) + 2 * ABCDtemp * t_2_5_1.x_5_38 ;
    x_15_65 = Ptempy * t_2_6_0.x_5_65 + WPtempy * t_2_6_1.x_5_65 + ABtemp * ( t_1_6_0.x_3_65 -  CDcom * t_1_6_1.x_3_65 ) + 2 * ABCDtemp * t_2_5_1.x_5_36 ;
    x_15_66 = Ptempy * t_2_6_0.x_5_66 + WPtempy * t_2_6_1.x_5_66 + ABtemp * ( t_1_6_0.x_3_66 -  CDcom * t_1_6_1.x_3_66 ) + ABCDtemp * t_2_5_1.x_5_55 ;
    x_15_67 = Ptempy * t_2_6_0.x_5_67 + WPtempy * t_2_6_1.x_5_67 + ABtemp * ( t_1_6_0.x_3_67 -  CDcom * t_1_6_1.x_3_67 ) + 5 * ABCDtemp * t_2_5_1.x_5_48 ;
    x_15_68 = Ptempy * t_2_6_0.x_5_68 + WPtempy * t_2_6_1.x_5_68 + ABtemp * ( t_1_6_0.x_3_68 -  CDcom * t_1_6_1.x_3_68 ) ;
    x_15_69 = Ptempy * t_2_6_0.x_5_69 + WPtempy * t_2_6_1.x_5_69 + ABtemp * ( t_1_6_0.x_3_69 -  CDcom * t_1_6_1.x_3_69 ) ;
    x_15_70 = Ptempy * t_2_6_0.x_5_70 + WPtempy * t_2_6_1.x_5_70 + ABtemp * ( t_1_6_0.x_3_70 -  CDcom * t_1_6_1.x_3_70 ) + 5 * ABCDtemp * t_2_5_1.x_5_51 ;
    x_15_71 = Ptempy * t_2_6_0.x_5_71 + WPtempy * t_2_6_1.x_5_71 + ABtemp * ( t_1_6_0.x_3_71 -  CDcom * t_1_6_1.x_3_71 ) + ABCDtemp * t_2_5_1.x_5_53 ;
    x_15_72 = Ptempy * t_2_6_0.x_5_72 + WPtempy * t_2_6_1.x_5_72 + ABtemp * ( t_1_6_0.x_3_72 -  CDcom * t_1_6_1.x_3_72 ) + 2 * ABCDtemp * t_2_5_1.x_5_47 ;
    x_15_73 = Ptempy * t_2_6_0.x_5_73 + WPtempy * t_2_6_1.x_5_73 + ABtemp * ( t_1_6_0.x_3_73 -  CDcom * t_1_6_1.x_3_73 ) + 4 * ABCDtemp * t_2_5_1.x_5_42 ;
    x_15_74 = Ptempy * t_2_6_0.x_5_74 + WPtempy * t_2_6_1.x_5_74 + ABtemp * ( t_1_6_0.x_3_74 -  CDcom * t_1_6_1.x_3_74 ) ;
    x_15_75 = Ptempy * t_2_6_0.x_5_75 + WPtempy * t_2_6_1.x_5_75 + ABtemp * ( t_1_6_0.x_3_75 -  CDcom * t_1_6_1.x_3_75 ) ;
    x_15_76 = Ptempy * t_2_6_0.x_5_76 + WPtempy * t_2_6_1.x_5_76 + ABtemp * ( t_1_6_0.x_3_76 -  CDcom * t_1_6_1.x_3_76 ) + 4 * ABCDtemp * t_2_5_1.x_5_45 ;
    x_15_77 = Ptempy * t_2_6_0.x_5_77 + WPtempy * t_2_6_1.x_5_77 + ABtemp * ( t_1_6_0.x_3_77 -  CDcom * t_1_6_1.x_3_77 ) + 2 * ABCDtemp * t_2_5_1.x_5_52 ;
    x_15_78 = Ptempy * t_2_6_0.x_5_78 + WPtempy * t_2_6_1.x_5_78 + ABtemp * ( t_1_6_0.x_3_78 -  CDcom * t_1_6_1.x_3_78 ) + 3 * ABCDtemp * t_2_5_1.x_5_41 ;
    x_15_79 = Ptempy * t_2_6_0.x_5_79 + WPtempy * t_2_6_1.x_5_79 + ABtemp * ( t_1_6_0.x_3_79 -  CDcom * t_1_6_1.x_3_79 ) ;
    x_15_80 = Ptempy * t_2_6_0.x_5_80 + WPtempy * t_2_6_1.x_5_80 + ABtemp * ( t_1_6_0.x_3_80 -  CDcom * t_1_6_1.x_3_80 ) + 3 * ABCDtemp * t_2_5_1.x_5_46 ;
    x_15_81 = Ptempy * t_2_6_0.x_5_81 + WPtempy * t_2_6_1.x_5_81 + ABtemp * ( t_1_6_0.x_3_81 -  CDcom * t_1_6_1.x_3_81 ) ;
    x_15_82 = Ptempy * t_2_6_0.x_5_82 + WPtempy * t_2_6_1.x_5_82 + ABtemp * ( t_1_6_0.x_3_82 -  CDcom * t_1_6_1.x_3_82 ) + 6 * ABCDtemp * t_2_5_1.x_5_54 ;
    x_15_83 = Ptempy * t_2_6_0.x_5_83 + WPtempy * t_2_6_1.x_5_83 + ABtemp * ( t_1_6_0.x_3_83 -  CDcom * t_1_6_1.x_3_83 ) ;
    x_16_56 = Ptempy * t_2_6_0.x_9_56 + WPtempy * t_2_6_1.x_9_56 + ABCDtemp * t_2_5_1.x_9_50 ;
    x_16_57 = Ptempy * t_2_6_0.x_9_57 + WPtempy * t_2_6_1.x_9_57 + 4 * ABCDtemp * t_2_5_1.x_9_39 ;
    x_16_58 = Ptempy * t_2_6_0.x_9_58 + WPtempy * t_2_6_1.x_9_58 + ABCDtemp * t_2_5_1.x_9_49 ;
    x_16_59 = Ptempy * t_2_6_0.x_9_59 + WPtempy * t_2_6_1.x_9_59 + 2 * ABCDtemp * t_2_5_1.x_9_40 ;
    x_16_60 = Ptempy * t_2_6_0.x_9_60 + WPtempy * t_2_6_1.x_9_60 + 3 * ABCDtemp * t_2_5_1.x_9_35 ;
    x_16_61 = Ptempy * t_2_6_0.x_9_61 + WPtempy * t_2_6_1.x_9_61 + ABCDtemp * t_2_5_1.x_9_43 ;
    x_16_62 = Ptempy * t_2_6_0.x_9_62 + WPtempy * t_2_6_1.x_9_62 + ABCDtemp * t_2_5_1.x_9_44 ;
    x_16_63 = Ptempy * t_2_6_0.x_9_63 + WPtempy * t_2_6_1.x_9_63 + 3 * ABCDtemp * t_2_5_1.x_9_37 ;
    x_16_64 = Ptempy * t_2_6_0.x_9_64 + WPtempy * t_2_6_1.x_9_64 + 2 * ABCDtemp * t_2_5_1.x_9_38 ;
    x_16_65 = Ptempy * t_2_6_0.x_9_65 + WPtempy * t_2_6_1.x_9_65 + 2 * ABCDtemp * t_2_5_1.x_9_36 ;
    x_16_66 = Ptempy * t_2_6_0.x_9_66 + WPtempy * t_2_6_1.x_9_66 + ABCDtemp * t_2_5_1.x_9_55 ;
    x_16_67 = Ptempy * t_2_6_0.x_9_67 + WPtempy * t_2_6_1.x_9_67 + 5 * ABCDtemp * t_2_5_1.x_9_48 ;
    x_16_68 = Ptempy * t_2_6_0.x_9_68 + WPtempy * t_2_6_1.x_9_68 ;
    x_16_69 = Ptempy * t_2_6_0.x_9_69 + WPtempy * t_2_6_1.x_9_69 ;
    x_16_70 = Ptempy * t_2_6_0.x_9_70 + WPtempy * t_2_6_1.x_9_70 + 5 * ABCDtemp * t_2_5_1.x_9_51 ;
    x_16_71 = Ptempy * t_2_6_0.x_9_71 + WPtempy * t_2_6_1.x_9_71 + ABCDtemp * t_2_5_1.x_9_53 ;
    x_16_72 = Ptempy * t_2_6_0.x_9_72 + WPtempy * t_2_6_1.x_9_72 + 2 * ABCDtemp * t_2_5_1.x_9_47 ;
    x_16_73 = Ptempy * t_2_6_0.x_9_73 + WPtempy * t_2_6_1.x_9_73 + 4 * ABCDtemp * t_2_5_1.x_9_42 ;
    x_16_74 = Ptempy * t_2_6_0.x_9_74 + WPtempy * t_2_6_1.x_9_74 ;
    x_16_75 = Ptempy * t_2_6_0.x_9_75 + WPtempy * t_2_6_1.x_9_75 ;
    x_16_76 = Ptempy * t_2_6_0.x_9_76 + WPtempy * t_2_6_1.x_9_76 + 4 * ABCDtemp * t_2_5_1.x_9_45 ;
    x_16_77 = Ptempy * t_2_6_0.x_9_77 + WPtempy * t_2_6_1.x_9_77 + 2 * ABCDtemp * t_2_5_1.x_9_52 ;
    x_16_78 = Ptempy * t_2_6_0.x_9_78 + WPtempy * t_2_6_1.x_9_78 + 3 * ABCDtemp * t_2_5_1.x_9_41 ;
    x_16_79 = Ptempy * t_2_6_0.x_9_79 + WPtempy * t_2_6_1.x_9_79 ;
    x_16_80 = Ptempy * t_2_6_0.x_9_80 + WPtempy * t_2_6_1.x_9_80 + 3 * ABCDtemp * t_2_5_1.x_9_46 ;
    x_16_81 = Ptempy * t_2_6_0.x_9_81 + WPtempy * t_2_6_1.x_9_81 ;
    x_16_82 = Ptempy * t_2_6_0.x_9_82 + WPtempy * t_2_6_1.x_9_82 + 6 * ABCDtemp * t_2_5_1.x_9_54 ;
    x_16_83 = Ptempy * t_2_6_0.x_9_83 + WPtempy * t_2_6_1.x_9_83 ;
    x_17_56 = Ptempx * t_2_6_0.x_7_56 + WPtempx * t_2_6_1.x_7_56 + ABtemp * 2 * ( t_1_6_0.x_1_56 -  CDcom * t_1_6_1.x_1_56 ) + 4 * ABCDtemp * t_2_5_1.x_7_38 ;
    x_17_57 = Ptempx * t_2_6_0.x_7_57 + WPtempx * t_2_6_1.x_7_57 + ABtemp * 2 * ( t_1_6_0.x_1_57 -  CDcom * t_1_6_1.x_1_57 ) + ABCDtemp * t_2_5_1.x_7_48 ;
    x_17_58 = Ptempx * t_2_6_0.x_7_58 + WPtempx * t_2_6_1.x_7_58 + ABtemp * 2 * ( t_1_6_0.x_1_58 -  CDcom * t_1_6_1.x_1_58 ) + ABCDtemp * t_2_5_1.x_7_47 ;
    x_17_59 = Ptempx * t_2_6_0.x_7_59 + WPtempx * t_2_6_1.x_7_59 + ABtemp * 2 * ( t_1_6_0.x_1_59 -  CDcom * t_1_6_1.x_1_59 ) + ABCDtemp * t_2_5_1.x_7_41 ;
    x_17_60 = Ptempx * t_2_6_0.x_7_60 + WPtempx * t_2_6_1.x_7_60 + ABtemp * 2 * ( t_1_6_0.x_1_60 -  CDcom * t_1_6_1.x_1_60 ) + ABCDtemp * t_2_5_1.x_7_42 ;
    x_17_61 = Ptempx * t_2_6_0.x_7_61 + WPtempx * t_2_6_1.x_7_61 + ABtemp * 2 * ( t_1_6_0.x_1_61 -  CDcom * t_1_6_1.x_1_61 ) + 2 * ABCDtemp * t_2_5_1.x_7_40 ;
    x_17_62 = Ptempx * t_2_6_0.x_7_62 + WPtempx * t_2_6_1.x_7_62 + ABtemp * 2 * ( t_1_6_0.x_1_62 -  CDcom * t_1_6_1.x_1_62 ) + 3 * ABCDtemp * t_2_5_1.x_7_36 ;
    x_17_63 = Ptempx * t_2_6_0.x_7_63 + WPtempx * t_2_6_1.x_7_63 + ABtemp * 2 * ( t_1_6_0.x_1_63 -  CDcom * t_1_6_1.x_1_63 ) + 2 * ABCDtemp * t_2_5_1.x_7_39 ;
    x_17_64 = Ptempx * t_2_6_0.x_7_64 + WPtempx * t_2_6_1.x_7_64 + ABtemp * 2 * ( t_1_6_0.x_1_64 -  CDcom * t_1_6_1.x_1_64 ) + 3 * ABCDtemp * t_2_5_1.x_7_37 ;
    x_17_65 = Ptempx * t_2_6_0.x_7_65 + WPtempx * t_2_6_1.x_7_65 + ABtemp * 2 * ( t_1_6_0.x_1_65 -  CDcom * t_1_6_1.x_1_65 ) + 2 * ABCDtemp * t_2_5_1.x_7_35 ;
    x_17_66 = Ptempx * t_2_6_0.x_7_66 + WPtempx * t_2_6_1.x_7_66 + ABtemp * 2 * ( t_1_6_0.x_1_66 -  CDcom * t_1_6_1.x_1_66 ) ;
    x_17_67 = Ptempx * t_2_6_0.x_7_67 + WPtempx * t_2_6_1.x_7_67 + ABtemp * 2 * ( t_1_6_0.x_1_67 -  CDcom * t_1_6_1.x_1_67 ) ;
    x_17_68 = Ptempx * t_2_6_0.x_7_68 + WPtempx * t_2_6_1.x_7_68 + ABtemp * 2 * ( t_1_6_0.x_1_68 -  CDcom * t_1_6_1.x_1_68 ) + ABCDtemp * t_2_5_1.x_7_55 ;
    x_17_69 = Ptempx * t_2_6_0.x_7_69 + WPtempx * t_2_6_1.x_7_69 + ABtemp * 2 * ( t_1_6_0.x_1_69 -  CDcom * t_1_6_1.x_1_69 ) + 5 * ABCDtemp * t_2_5_1.x_7_50 ;
    x_17_70 = Ptempx * t_2_6_0.x_7_70 + WPtempx * t_2_6_1.x_7_70 + ABtemp * 2 * ( t_1_6_0.x_1_70 -  CDcom * t_1_6_1.x_1_70 ) + ABCDtemp * t_2_5_1.x_7_54 ;
    x_17_71 = Ptempx * t_2_6_0.x_7_71 + WPtempx * t_2_6_1.x_7_71 + ABtemp * 2 * ( t_1_6_0.x_1_71 -  CDcom * t_1_6_1.x_1_71 ) + 5 * ABCDtemp * t_2_5_1.x_7_52 ;
    x_17_72 = Ptempx * t_2_6_0.x_7_72 + WPtempx * t_2_6_1.x_7_72 + ABtemp * 2 * ( t_1_6_0.x_1_72 -  CDcom * t_1_6_1.x_1_72 ) ;
    x_17_73 = Ptempx * t_2_6_0.x_7_73 + WPtempx * t_2_6_1.x_7_73 + ABtemp * 2 * ( t_1_6_0.x_1_73 -  CDcom * t_1_6_1.x_1_73 ) ;
    x_17_74 = Ptempx * t_2_6_0.x_7_74 + WPtempx * t_2_6_1.x_7_74 + ABtemp * 2 * ( t_1_6_0.x_1_74 -  CDcom * t_1_6_1.x_1_74 ) + 2 * ABCDtemp * t_2_5_1.x_7_49 ;
    x_17_75 = Ptempx * t_2_6_0.x_7_75 + WPtempx * t_2_6_1.x_7_75 + ABtemp * 2 * ( t_1_6_0.x_1_75 -  CDcom * t_1_6_1.x_1_75 ) + 4 * ABCDtemp * t_2_5_1.x_7_44 ;
    x_17_76 = Ptempx * t_2_6_0.x_7_76 + WPtempx * t_2_6_1.x_7_76 + ABtemp * 2 * ( t_1_6_0.x_1_76 -  CDcom * t_1_6_1.x_1_76 ) + 2 * ABCDtemp * t_2_5_1.x_7_51 ;
    x_17_77 = Ptempx * t_2_6_0.x_7_77 + WPtempx * t_2_6_1.x_7_77 + ABtemp * 2 * ( t_1_6_0.x_1_77 -  CDcom * t_1_6_1.x_1_77 ) + 4 * ABCDtemp * t_2_5_1.x_7_46 ;
    x_17_78 = Ptempx * t_2_6_0.x_7_78 + WPtempx * t_2_6_1.x_7_78 + ABtemp * 2 * ( t_1_6_0.x_1_78 -  CDcom * t_1_6_1.x_1_78 ) ;
    x_17_79 = Ptempx * t_2_6_0.x_7_79 + WPtempx * t_2_6_1.x_7_79 + ABtemp * 2 * ( t_1_6_0.x_1_79 -  CDcom * t_1_6_1.x_1_79 ) + 3 * ABCDtemp * t_2_5_1.x_7_43 ;
    x_17_80 = Ptempx * t_2_6_0.x_7_80 + WPtempx * t_2_6_1.x_7_80 + ABtemp * 2 * ( t_1_6_0.x_1_80 -  CDcom * t_1_6_1.x_1_80 ) + 3 * ABCDtemp * t_2_5_1.x_7_45 ;
    x_17_81 = Ptempx * t_2_6_0.x_7_81 + WPtempx * t_2_6_1.x_7_81 + ABtemp * 2 * ( t_1_6_0.x_1_81 -  CDcom * t_1_6_1.x_1_81 ) + 6 * ABCDtemp * t_2_5_1.x_7_53 ;
    x_17_82 = Ptempx * t_2_6_0.x_7_82 + WPtempx * t_2_6_1.x_7_82 + ABtemp * 2 * ( t_1_6_0.x_1_82 -  CDcom * t_1_6_1.x_1_82 ) ;
    x_17_83 = Ptempx * t_2_6_0.x_7_83 + WPtempx * t_2_6_1.x_7_83 + ABtemp * 2 * ( t_1_6_0.x_1_83 -  CDcom * t_1_6_1.x_1_83 ) ;
    x_18_56 = Ptempy * t_2_6_0.x_8_56 + WPtempy * t_2_6_1.x_8_56 + ABtemp * 2 * ( t_1_6_0.x_2_56 -  CDcom * t_1_6_1.x_2_56 ) + ABCDtemp * t_2_5_1.x_8_50 ;
    x_18_57 = Ptempy * t_2_6_0.x_8_57 + WPtempy * t_2_6_1.x_8_57 + ABtemp * 2 * ( t_1_6_0.x_2_57 -  CDcom * t_1_6_1.x_2_57 ) + 4 * ABCDtemp * t_2_5_1.x_8_39 ;
    x_18_58 = Ptempy * t_2_6_0.x_8_58 + WPtempy * t_2_6_1.x_8_58 + ABtemp * 2 * ( t_1_6_0.x_2_58 -  CDcom * t_1_6_1.x_2_58 ) + ABCDtemp * t_2_5_1.x_8_49 ;
    x_18_59 = Ptempy * t_2_6_0.x_8_59 + WPtempy * t_2_6_1.x_8_59 + ABtemp * 2 * ( t_1_6_0.x_2_59 -  CDcom * t_1_6_1.x_2_59 ) + 2 * ABCDtemp * t_2_5_1.x_8_40 ;
    x_18_60 = Ptempy * t_2_6_0.x_8_60 + WPtempy * t_2_6_1.x_8_60 + ABtemp * 2 * ( t_1_6_0.x_2_60 -  CDcom * t_1_6_1.x_2_60 ) + 3 * ABCDtemp * t_2_5_1.x_8_35 ;
    x_18_61 = Ptempy * t_2_6_0.x_8_61 + WPtempy * t_2_6_1.x_8_61 + ABtemp * 2 * ( t_1_6_0.x_2_61 -  CDcom * t_1_6_1.x_2_61 ) + ABCDtemp * t_2_5_1.x_8_43 ;
    x_18_62 = Ptempy * t_2_6_0.x_8_62 + WPtempy * t_2_6_1.x_8_62 + ABtemp * 2 * ( t_1_6_0.x_2_62 -  CDcom * t_1_6_1.x_2_62 ) + ABCDtemp * t_2_5_1.x_8_44 ;
    x_18_63 = Ptempy * t_2_6_0.x_8_63 + WPtempy * t_2_6_1.x_8_63 + ABtemp * 2 * ( t_1_6_0.x_2_63 -  CDcom * t_1_6_1.x_2_63 ) + 3 * ABCDtemp * t_2_5_1.x_8_37 ;
    x_18_64 = Ptempy * t_2_6_0.x_8_64 + WPtempy * t_2_6_1.x_8_64 + ABtemp * 2 * ( t_1_6_0.x_2_64 -  CDcom * t_1_6_1.x_2_64 ) + 2 * ABCDtemp * t_2_5_1.x_8_38 ;
    x_18_65 = Ptempy * t_2_6_0.x_8_65 + WPtempy * t_2_6_1.x_8_65 + ABtemp * 2 * ( t_1_6_0.x_2_65 -  CDcom * t_1_6_1.x_2_65 ) + 2 * ABCDtemp * t_2_5_1.x_8_36 ;
    x_18_66 = Ptempy * t_2_6_0.x_8_66 + WPtempy * t_2_6_1.x_8_66 + ABtemp * 2 * ( t_1_6_0.x_2_66 -  CDcom * t_1_6_1.x_2_66 ) + ABCDtemp * t_2_5_1.x_8_55 ;
    x_18_67 = Ptempy * t_2_6_0.x_8_67 + WPtempy * t_2_6_1.x_8_67 + ABtemp * 2 * ( t_1_6_0.x_2_67 -  CDcom * t_1_6_1.x_2_67 ) + 5 * ABCDtemp * t_2_5_1.x_8_48 ;
    x_18_68 = Ptempy * t_2_6_0.x_8_68 + WPtempy * t_2_6_1.x_8_68 + ABtemp * 2 * ( t_1_6_0.x_2_68 -  CDcom * t_1_6_1.x_2_68 ) ;
    x_18_69 = Ptempy * t_2_6_0.x_8_69 + WPtempy * t_2_6_1.x_8_69 + ABtemp * 2 * ( t_1_6_0.x_2_69 -  CDcom * t_1_6_1.x_2_69 ) ;
    x_18_70 = Ptempy * t_2_6_0.x_8_70 + WPtempy * t_2_6_1.x_8_70 + ABtemp * 2 * ( t_1_6_0.x_2_70 -  CDcom * t_1_6_1.x_2_70 ) + 5 * ABCDtemp * t_2_5_1.x_8_51 ;
    x_18_71 = Ptempy * t_2_6_0.x_8_71 + WPtempy * t_2_6_1.x_8_71 + ABtemp * 2 * ( t_1_6_0.x_2_71 -  CDcom * t_1_6_1.x_2_71 ) + ABCDtemp * t_2_5_1.x_8_53 ;
    x_18_72 = Ptempy * t_2_6_0.x_8_72 + WPtempy * t_2_6_1.x_8_72 + ABtemp * 2 * ( t_1_6_0.x_2_72 -  CDcom * t_1_6_1.x_2_72 ) + 2 * ABCDtemp * t_2_5_1.x_8_47 ;
    x_18_73 = Ptempy * t_2_6_0.x_8_73 + WPtempy * t_2_6_1.x_8_73 + ABtemp * 2 * ( t_1_6_0.x_2_73 -  CDcom * t_1_6_1.x_2_73 ) + 4 * ABCDtemp * t_2_5_1.x_8_42 ;
    x_18_74 = Ptempy * t_2_6_0.x_8_74 + WPtempy * t_2_6_1.x_8_74 + ABtemp * 2 * ( t_1_6_0.x_2_74 -  CDcom * t_1_6_1.x_2_74 ) ;
    x_18_75 = Ptempy * t_2_6_0.x_8_75 + WPtempy * t_2_6_1.x_8_75 + ABtemp * 2 * ( t_1_6_0.x_2_75 -  CDcom * t_1_6_1.x_2_75 ) ;
    x_18_76 = Ptempy * t_2_6_0.x_8_76 + WPtempy * t_2_6_1.x_8_76 + ABtemp * 2 * ( t_1_6_0.x_2_76 -  CDcom * t_1_6_1.x_2_76 ) + 4 * ABCDtemp * t_2_5_1.x_8_45 ;
    x_18_77 = Ptempy * t_2_6_0.x_8_77 + WPtempy * t_2_6_1.x_8_77 + ABtemp * 2 * ( t_1_6_0.x_2_77 -  CDcom * t_1_6_1.x_2_77 ) + 2 * ABCDtemp * t_2_5_1.x_8_52 ;
    x_18_78 = Ptempy * t_2_6_0.x_8_78 + WPtempy * t_2_6_1.x_8_78 + ABtemp * 2 * ( t_1_6_0.x_2_78 -  CDcom * t_1_6_1.x_2_78 ) + 3 * ABCDtemp * t_2_5_1.x_8_41 ;
    x_18_79 = Ptempy * t_2_6_0.x_8_79 + WPtempy * t_2_6_1.x_8_79 + ABtemp * 2 * ( t_1_6_0.x_2_79 -  CDcom * t_1_6_1.x_2_79 ) ;
    x_18_80 = Ptempy * t_2_6_0.x_8_80 + WPtempy * t_2_6_1.x_8_80 + ABtemp * 2 * ( t_1_6_0.x_2_80 -  CDcom * t_1_6_1.x_2_80 ) + 3 * ABCDtemp * t_2_5_1.x_8_46 ;
    x_18_81 = Ptempy * t_2_6_0.x_8_81 + WPtempy * t_2_6_1.x_8_81 + ABtemp * 2 * ( t_1_6_0.x_2_81 -  CDcom * t_1_6_1.x_2_81 ) ;
    x_18_82 = Ptempy * t_2_6_0.x_8_82 + WPtempy * t_2_6_1.x_8_82 + ABtemp * 2 * ( t_1_6_0.x_2_82 -  CDcom * t_1_6_1.x_2_82 ) + 6 * ABCDtemp * t_2_5_1.x_8_54 ;
    x_18_83 = Ptempy * t_2_6_0.x_8_83 + WPtempy * t_2_6_1.x_8_83 + ABtemp * 2 * ( t_1_6_0.x_2_83 -  CDcom * t_1_6_1.x_2_83 ) ;
    x_19_56 = Ptempz * t_2_6_0.x_9_56 + WPtempz * t_2_6_1.x_9_56 + ABtemp * 2 * ( t_1_6_0.x_3_56 -  CDcom * t_1_6_1.x_3_56 ) + ABCDtemp * t_2_5_1.x_9_52 ;
    x_19_57 = Ptempz * t_2_6_0.x_9_57 + WPtempz * t_2_6_1.x_9_57 + ABtemp * 2 * ( t_1_6_0.x_3_57 -  CDcom * t_1_6_1.x_3_57 ) + ABCDtemp * t_2_5_1.x_9_51 ;
    x_19_58 = Ptempz * t_2_6_0.x_9_58 + WPtempz * t_2_6_1.x_9_58 + ABtemp * 2 * ( t_1_6_0.x_3_58 -  CDcom * t_1_6_1.x_3_58 ) + 4 * ABCDtemp * t_2_5_1.x_9_40 ;
    x_19_59 = Ptempz * t_2_6_0.x_9_59 + WPtempz * t_2_6_1.x_9_59 + ABtemp * 2 * ( t_1_6_0.x_3_59 -  CDcom * t_1_6_1.x_3_59 ) + 3 * ABCDtemp * t_2_5_1.x_9_35 ;
    x_19_60 = Ptempz * t_2_6_0.x_9_60 + WPtempz * t_2_6_1.x_9_60 + ABtemp * 2 * ( t_1_6_0.x_3_60 -  CDcom * t_1_6_1.x_3_60 ) + 2 * ABCDtemp * t_2_5_1.x_9_39 ;
    x_19_61 = Ptempz * t_2_6_0.x_9_61 + WPtempz * t_2_6_1.x_9_61 + ABtemp * 2 * ( t_1_6_0.x_3_61 -  CDcom * t_1_6_1.x_3_61 ) + 3 * ABCDtemp * t_2_5_1.x_9_36 ;
    x_19_62 = Ptempz * t_2_6_0.x_9_62 + WPtempz * t_2_6_1.x_9_62 + ABtemp * 2 * ( t_1_6_0.x_3_62 -  CDcom * t_1_6_1.x_3_62 ) + 2 * ABCDtemp * t_2_5_1.x_9_38 ;
    x_19_63 = Ptempz * t_2_6_0.x_9_63 + WPtempz * t_2_6_1.x_9_63 + ABtemp * 2 * ( t_1_6_0.x_3_63 -  CDcom * t_1_6_1.x_3_63 ) + ABCDtemp * t_2_5_1.x_9_45 ;
    x_19_64 = Ptempz * t_2_6_0.x_9_64 + WPtempz * t_2_6_1.x_9_64 + ABtemp * 2 * ( t_1_6_0.x_3_64 -  CDcom * t_1_6_1.x_3_64 ) + ABCDtemp * t_2_5_1.x_9_46 ;
    x_19_65 = Ptempz * t_2_6_0.x_9_65 + WPtempz * t_2_6_1.x_9_65 + ABtemp * 2 * ( t_1_6_0.x_3_65 -  CDcom * t_1_6_1.x_3_65 ) + 2 * ABCDtemp * t_2_5_1.x_9_37 ;
    x_19_66 = Ptempz * t_2_6_0.x_9_66 + WPtempz * t_2_6_1.x_9_66 + ABtemp * 2 * ( t_1_6_0.x_3_66 -  CDcom * t_1_6_1.x_3_66 ) + 5 * ABCDtemp * t_2_5_1.x_9_47 ;
    x_19_67 = Ptempz * t_2_6_0.x_9_67 + WPtempz * t_2_6_1.x_9_67 + ABtemp * 2 * ( t_1_6_0.x_3_67 -  CDcom * t_1_6_1.x_3_67 ) + ABCDtemp * t_2_5_1.x_9_54 ;
    x_19_68 = Ptempz * t_2_6_0.x_9_68 + WPtempz * t_2_6_1.x_9_68 + ABtemp * 2 * ( t_1_6_0.x_3_68 -  CDcom * t_1_6_1.x_3_68 ) + 5 * ABCDtemp * t_2_5_1.x_9_49 ;
    x_19_69 = Ptempz * t_2_6_0.x_9_69 + WPtempz * t_2_6_1.x_9_69 + ABtemp * 2 * ( t_1_6_0.x_3_69 -  CDcom * t_1_6_1.x_3_69 ) + ABCDtemp * t_2_5_1.x_9_53 ;
    x_19_70 = Ptempz * t_2_6_0.x_9_70 + WPtempz * t_2_6_1.x_9_70 + ABtemp * 2 * ( t_1_6_0.x_3_70 -  CDcom * t_1_6_1.x_3_70 ) ;
    x_19_71 = Ptempz * t_2_6_0.x_9_71 + WPtempz * t_2_6_1.x_9_71 + ABtemp * 2 * ( t_1_6_0.x_3_71 -  CDcom * t_1_6_1.x_3_71 ) ;
    x_19_72 = Ptempz * t_2_6_0.x_9_72 + WPtempz * t_2_6_1.x_9_72 + ABtemp * 2 * ( t_1_6_0.x_3_72 -  CDcom * t_1_6_1.x_3_72 ) + 4 * ABCDtemp * t_2_5_1.x_9_41 ;
    x_19_73 = Ptempz * t_2_6_0.x_9_73 + WPtempz * t_2_6_1.x_9_73 + ABtemp * 2 * ( t_1_6_0.x_3_73 -  CDcom * t_1_6_1.x_3_73 ) + 2 * ABCDtemp * t_2_5_1.x_9_48 ;
    x_19_74 = Ptempz * t_2_6_0.x_9_74 + WPtempz * t_2_6_1.x_9_74 + ABtemp * 2 * ( t_1_6_0.x_3_74 -  CDcom * t_1_6_1.x_3_74 ) + 4 * ABCDtemp * t_2_5_1.x_9_43 ;
    x_19_75 = Ptempz * t_2_6_0.x_9_75 + WPtempz * t_2_6_1.x_9_75 + ABtemp * 2 * ( t_1_6_0.x_3_75 -  CDcom * t_1_6_1.x_3_75 ) + 2 * ABCDtemp * t_2_5_1.x_9_50 ;
    x_19_76 = Ptempz * t_2_6_0.x_9_76 + WPtempz * t_2_6_1.x_9_76 + ABtemp * 2 * ( t_1_6_0.x_3_76 -  CDcom * t_1_6_1.x_3_76 ) ;
    x_19_77 = Ptempz * t_2_6_0.x_9_77 + WPtempz * t_2_6_1.x_9_77 + ABtemp * 2 * ( t_1_6_0.x_3_77 -  CDcom * t_1_6_1.x_3_77 ) ;
    x_19_78 = Ptempz * t_2_6_0.x_9_78 + WPtempz * t_2_6_1.x_9_78 + ABtemp * 2 * ( t_1_6_0.x_3_78 -  CDcom * t_1_6_1.x_3_78 ) + 3 * ABCDtemp * t_2_5_1.x_9_42 ;
    x_19_79 = Ptempz * t_2_6_0.x_9_79 + WPtempz * t_2_6_1.x_9_79 + ABtemp * 2 * ( t_1_6_0.x_3_79 -  CDcom * t_1_6_1.x_3_79 ) + 3 * ABCDtemp * t_2_5_1.x_9_44 ;
    x_19_80 = Ptempz * t_2_6_0.x_9_80 + WPtempz * t_2_6_1.x_9_80 + ABtemp * 2 * ( t_1_6_0.x_3_80 -  CDcom * t_1_6_1.x_3_80 ) ;
    x_19_81 = Ptempz * t_2_6_0.x_9_81 + WPtempz * t_2_6_1.x_9_81 + ABtemp * 2 * ( t_1_6_0.x_3_81 -  CDcom * t_1_6_1.x_3_81 ) ;
    x_19_82 = Ptempz * t_2_6_0.x_9_82 + WPtempz * t_2_6_1.x_9_82 + ABtemp * 2 * ( t_1_6_0.x_3_82 -  CDcom * t_1_6_1.x_3_82 ) ;
    x_19_83 = Ptempz * t_2_6_0.x_9_83 + WPtempz * t_2_6_1.x_9_83 + ABtemp * 2 * ( t_1_6_0.x_3_83 -  CDcom * t_1_6_1.x_3_83 ) + 6 * ABCDtemp * t_2_5_1.x_9_55 ;
}
