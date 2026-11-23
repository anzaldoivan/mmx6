#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK apply_player_motion(void*);          /* extern */
s32 try_enter_ladder();                      /* extern */
void func_8003AD18(void*);                   /* extern */
s32 try_start_attack(void*);                 /* extern */
M2C_UNK func_8003F508(void*, M2C_UNK);       /* extern */
s32 func_801EA560(void*);                    /* extern */
s32 func_801EBE04(void*);                    /* extern */
s32 func_801EBE54(void*);                    /* extern */
s32 func_801EBEDC(void*);                    /* extern */
s32 func_801EC86C(void*);                    /* extern */

s32 player_check_dash_jump_walk(struct X4_PlayerObj* self);
void func_80035A2C(void* arg0) {
    s32 var_v1;

    if ((((s32(*)())try_enter_ladder)() == 0) &&
        (try_start_attack(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) ||
         ((func_801EC86C(arg0) == 0) && (func_801EA560(arg0) == 0) &&
          (func_801EBE04(arg0) == 0))) &&
        (((s32(*)())player_check_dash_jump_walk)(arg0) == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) ||
         ((func_801EBE54(arg0) == 0) && (func_801EBEDC(arg0) == 0)))) {
        if (M2C_FIELD(arg0, s8*, 0x45) & 0x80) {
            M2C_FIELD(arg0, s8*, 0x45) =
                (s8)((u8)M2C_FIELD(arg0, s8*, 0x45) & 0x7F);
            play_sound(1, 6, arg0);
        }
        if (((u8)M2C_FIELD(arg0, s8*, 0x45) & 0x40) &&
            (M2C_FIELD(arg0, s8*, 0x85) == 0)) {
            var_v1 = 2;
            if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                var_v1 = 1;
            }
            if (M2C_FIELD(arg0, u8*, 0x89) & var_v1) {
                M2C_FIELD(arg0, s32*, 0x20) = 0;
            }
            if (M2C_FIELD(arg0, s32*, 0x20) != 0) {
                apply_player_motion(arg0);
                if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                    if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
                        M2C_FIELD(arg0, s32*, 0x20) = 0;
                    }
                } else if (M2C_FIELD(arg0, s32*, 0x20) > 0) {
                    M2C_FIELD(arg0, s32*, 0x20) = 0;
                }
            }
        }
        if (M2C_FIELD(arg0, s8*, 0x46) < 0) {
            func_8003AD18(arg0);
            return;
        }
        func_8003F508(arg0, 0x11);
    }
}
