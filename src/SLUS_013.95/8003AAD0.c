// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/32208", func_8003AAD0);
// clang-format on

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8003A628(void*);                               /* extern */
M2C_UNK player_set_animation_frame(void*, M2C_UNK, s8); /* extern */
void player_clear_dash();                               /* extern */
M2C_UNK set_stand_animation_by_hp(void*);               /* extern */

void func_8003AD18(void* arg0) {
    s32 var_a2;
    u8 temp_v0;
    u8 temp_v1;

    player_clear_dash();
    if (func_8003A628(arg0) == 0) {
        M2C_FIELD(arg0, s8*, 5) = 2;
        M2C_FIELD(arg0, s8*, 6) = 0;
        if ((M2C_FIELD(arg0, s8*, 2) == 0) &&
            (M2C_FIELD(arg0, s8*, 0x8E) != 0)) {
            temp_v0 = M2C_FIELD(arg0, u8*, 0x91);
            var_a2 = temp_v0 < 9U;
            if (temp_v0 < 5U) {
                var_a2 = 2;
            }
            player_set_animation_frame(arg0, 0x5E, var_a2);
            temp_v1 = M2C_FIELD(arg0, u8*, 0x91);
            if (temp_v1 >= 9U) {
                M2C_FIELD(arg0, s8*, 0x44) = (s8)(temp_v1 - 8);
            }
        } else {
            set_stand_animation_by_hp(arg0);
        }
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8003A628(void*);                               /* extern */
M2C_UNK player_set_animation(void*, M2C_UNK);           /* extern */
M2C_UNK player_set_animation_frame(void*, M2C_UNK, s8); /* extern */
void player_clear_dash();                               /* extern */
M2C_UNK set_stand_animation_by_hp(void*);               /* extern */

void func_8003ADB4(void* arg0) {
    s32 var_a2;
    u8 temp_v0;
    u8 temp_v1;

    if (func_8003A628(arg0) == 0) {
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            player_clear_dash(arg0);
            if (func_8003A628(arg0) == 0) {
                M2C_FIELD(arg0, s8*, 5) = 2;
                M2C_FIELD(arg0, s8*, 6) = 0;
                if ((M2C_FIELD(arg0, s8*, 2) == 0) &&
                    (M2C_FIELD(arg0, s8*, 0x8E) != 0)) {
                    temp_v0 = M2C_FIELD(arg0, u8*, 0x91);
                    var_a2 = temp_v0 < 9U;
                    if (temp_v0 < 5U) {
                        var_a2 = 2;
                    }
                    player_set_animation_frame(arg0, 0x5E, var_a2);
                    temp_v1 = M2C_FIELD(arg0, u8*, 0x91);
                    if (temp_v1 >= 9U) {
                        M2C_FIELD(arg0, s8*, 0x44) = (s8)(temp_v1 - 8);
                    }
                } else {
                    set_stand_animation_by_hp(arg0);
                }
            }
        } else {
            ((void (*)(void*, s32))player_set_animation)(arg0, 9);
            M2C_FIELD(arg0, s8*, 5) = 5;
            M2C_FIELD(arg0, s8*, 6) = 0;
        }
    }
}
