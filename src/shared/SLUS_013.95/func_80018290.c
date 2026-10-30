#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80018524(u8);
void stop_cd_audio();
M2C_UNK func_80064C94(M2C_UNK*, u32);
#define func_80064C94 ((M2C_UNK(*)(M2C_UNK*, u8))func_80064C94)
extern s32 D_80070A24;
extern void (*D_80070A28[])(void);
extern s8 D_80097418;
#define D_80097418 (*(u8*)&D_80097418)
extern s8 D_800CC869;
#define D_800CC869 (*(u8*)&D_800CC869)
extern u32 D_800E2E00;
extern M2C_UNK D_800E2E10;
extern u8 D_800E2E14;
extern u8 D_800E2E15;
extern s8 D_800E2E16;
#define D_800E2E16 (*(u8*)&D_800E2E16)
extern s32 D_800E2E18;
extern s32 D_800E2E1C;
extern u8 D_800E2E51;
extern s32 D_800E2E5C;

s32 func_80018290(void) {
    u32 temp_v1;
    u8 temp_a1;
    u8 temp_v1_2;
    s32 temp_s;

    if (D_800E2E5C == 2) {
        if (D_800E2E16 == 0) {
            D_80070A28[D_800E2E18]();
            if (D_80097418 != 0) {
                if (D_800E2E00 < 4U) {
                    D_800E2E00 = 0;
                    D_80070A24 = 1;
                    stop_cd_audio();
                    D_80097418 = 0;
                } else if (D_80070A24 != 0) {
                    D_80070A24 = 0;
                    D_800E2E00 = D_800E2E15 - D_800E2E1C;
                } else {
                    D_80070A24 = 1;
                }
                temp_a1 = D_800E2E00;
                D_800E2E15 = temp_a1;
                if (D_800CC869 == 1) {
                    ((u8*)&D_800E2E10)[0] = temp_a1;
                    ((s8*)&D_800E2E10)[1] = 0;
                    ((u8*)&D_800E2E10)[2] = temp_a1;
                    ((s8*)&D_800E2E10)[3] = 0;
                } else {
                    temp_v1 = temp_a1 >> 1;
                    ((u8*)&D_800E2E10)[0] = temp_v1;
                    ((u8*)&D_800E2E10)[1] = temp_v1;
                    ((u8*)&D_800E2E10)[2] = temp_v1;
                    ((u8*)&D_800E2E10)[3] = temp_v1;
                }
                func_80064C94(&D_800E2E10, temp_a1);
            }
            temp_s = D_800CC869;
            temp_v1_2 = temp_s & 0xFF;
            if (D_800E2E51 != temp_v1_2) {
                D_800E2E51 = temp_s;
                if (temp_v1_2 == 1) {
                    D_800CC869 = temp_v1_2;
                    func_80018524(D_800E2E14);
                } else {
                    D_800CC869 = 0;
                    func_80018524(D_800E2E14);
                }
            }
            return 0;
        }
        return -1;
    }
    return -1;
}
#undef D_800CC869
#undef D_80097418
#undef func_80064C94
#undef D_800E2E16
