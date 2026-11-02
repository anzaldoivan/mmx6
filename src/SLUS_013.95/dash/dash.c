#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8003A628(void*);                  /* extern */
M2C_UNK func_8003BB94(void*, M2C_UNK, s8); /* extern */
M2C_UNK func_8003CD9C();                   /* extern */
M2C_UNK func_8003D10C(void*);              /* extern */
void player_set_animation_shooting(struct X4_PlayerObj* self,
                                   s32 animation); /* extern */

// 0x8003B114 end_dash: Mach Dash end.
// basis: community tweaks-index.tsv:248
// callers: func_800365D4, func_80037880, func_800379AC, func_801EAA38 and others
void end_dash(s32 arg0) {
    s32 var_a2;
    u8 temp_v0;
    u8 temp_v1;

    if (M2C_FIELD(arg0, u8*, 0x89) & 8) {
        M2C_FIELD(arg0, s8*, 0x67) = 0;
        M2C_FIELD(arg0, s8*, 0x86) = 0;
        func_8003CD9C(arg0);
        if (func_8003A628((void*)arg0) == 0) {
            M2C_FIELD(arg0, s8*, 5) = 2;
            M2C_FIELD(arg0, s8*, 6) = 0;
            if ((M2C_FIELD(arg0, s8*, 2) == 0) &&
                (M2C_FIELD(arg0, s8*, 0x8E) != 0)) {
                temp_v0 = M2C_FIELD(arg0, u8*, 0x91);
                var_a2 = temp_v0 < 9U;
                if (temp_v0 < 5U) {
                    var_a2 = 2;
                }
                func_8003BB94((void*)arg0, 0x5E, var_a2);
                temp_v1 = M2C_FIELD(arg0, u8*, 0x91);
                if (temp_v1 >= 9U) {
                    M2C_FIELD(arg0, s8*, 0x44) = (s8)(temp_v1 - 8);
                }
            } else {
                func_8003D10C((void*)arg0);
            }
        }
    } else {
        player_set_animation_shooting((struct X4_PlayerObj*)arg0, 0xB);
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s8*, 0x67) = -1;
        M2C_FIELD(arg0, s32*, 0x2C) = M2C_FIELD(arg0, s32*, 0x100);
        if (M2C_FIELD(arg0, s8*, 0x84) != 0) {
            M2C_FIELD(arg0, s8*, 0x84) = 0;
            M2C_FIELD(arg0, s8*, 0x8C) = -1;
        }
        M2C_FIELD(arg0, s8*, 5) = 7;
        M2C_FIELD(arg0, s8*, 6) = 0;
    }
}
