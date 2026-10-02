/* Adapted from sozud/mmx4 @29b62af src/main/1CF60.c:func_8002CDD4, AGPL-3.0; proven shared with X6 by exact signature 35842cc5ea2e (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern s16 D_800E4192;
extern s16 D_800E4194;
extern s16 D_800E419E;
extern s16 D_800E41A0;
s32 func_8002F9DC(struct X4_PlayerObj*, u8, s16, s16);
u8 func_80030304(struct X4_PlayerObj*, s16, s16);

void func_8002F840(struct X4_PlayerObj* arg0) {
    u8 temp_s3;
    u8 temp_s4;
    u8 temp_s5;
    u8 temp_v0_4;
    s32 var_s0;
    s16 temp_v0 = D_800E41A0 + D_800E4194;

    temp_s3 = func_80030304(arg0, D_800E419E - D_800E4192, temp_v0);
    temp_s4 = func_80030304(arg0, D_800E419E + D_800E4192 - 1, temp_v0);
    temp_s5 = func_80030304(arg0, D_800E419E, temp_v0);

    if (func_8002F9DC(arg0, temp_s5, D_800E419E, temp_v0) == 0) {
        if (arg0->air_state == 0) {
            var_s0 = 0;
            if (temp_s3 > 0 && temp_s3 < 0x20) {
                var_s0 = 1;
            }
            if (temp_s4 > 0 && temp_s4 < 0x20) {
                var_s0 = 1;
            }

            temp_v0_4 = func_80030304(arg0, D_800E419E, (temp_v0 + 0x10));
            if (temp_v0_4 > 0 && temp_v0_4 < 0x20) {
                var_s0 = 1;
            }

            if (var_s0) {
                arg0->y_pos.i.hi += 0x10;
                if (func_8002F9DC(arg0, temp_v0_4, D_800E419E,
                                  temp_v0 + 0x10)) {
                    return;
                }
            }
        }

        if (func_800308B8(arg0, temp_s3, temp_v0) == 0) {
            func_800308B8(arg0, temp_s4, temp_v0);
        }
    }
}
