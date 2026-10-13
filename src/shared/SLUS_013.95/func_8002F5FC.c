#include "common.h"
#include "mmx6/x4.h"
extern s16 D_800E4192;
extern s16 D_800E4194;
extern s16 D_800E419E;
extern s16 D_800E41A0;
u8 func_80030304(struct X4_PlayerObj*, s16, s16);
s32 func_80030628(struct X4_PlayerObj* arg0, u8 arg1);

void func_8002F5FC(struct X4_PlayerObj* arg0) {
    s16 temp_v0;
    u8 var_v0;

    temp_v0 = D_800E419E - D_800E4192;
    if (func_80030628(arg0, func_80030304(arg0, temp_v0, D_800E41A0)) == 0) {
        if (arg0->unk71 & 8) {
            var_v0 = func_80030304(arg0, temp_v0, D_800E41A0 - D_800E4194 - 1);
        } else {
            var_v0 = func_80030304(arg0, temp_v0, D_800E41A0 - D_800E4194);
        }
        if (func_80030628(arg0, var_v0) == 0) {
            func_80030628(arg0, func_80030304(arg0, temp_v0,
                                              D_800E41A0 + D_800E4194 - 1));
        }
    }
}
