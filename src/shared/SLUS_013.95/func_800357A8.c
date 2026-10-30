#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 play_sound(s32 a0, s32 a1, void* arg2); /* extern */
M2C_UNK func_8003AF1C(void*);               /* extern */
void player_spawn_dash_spark(void* arg0);   /* extern */
s32 func_8003F13C();                        /* extern */
M2C_UNK func_8003F508(void*, M2C_UNK);      /* extern */
s32 func_801EA560(void*);                   /* extern */
s32 func_801EBE04(void*);                   /* extern */
s32 func_801EBE54(void*);                   /* extern */
s32 func_801EBEDC(void*);                   /* extern */
s32 func_801EC86C(void*);                   /* extern */

void func_800357A8(void* arg0) {
    u8 temp_v1;

    if ((((s32(*)())func_8003F13C)() == 0) &&
        ((M2C_FIELD(arg0, s8*, 2) == 0) ||
         ((func_801EC86C(arg0) == 0) && (func_801EA560(arg0) == 0) &&
          (func_801EBE04(arg0) == 0) && (func_801EBEDC(arg0) == 0)))) {
        if (M2C_FIELD(arg0, u16*, 0x80) & 0x80) {
            func_8003AF1C(arg0);
            return;
        }
        if ((M2C_FIELD(arg0, s8*, 2) == 0) || (func_801EBE54(arg0) == 0)) {
            temp_v1 = M2C_FIELD(arg0, u8*, 0x45);
            if (temp_v1 & 0x20) {
                M2C_FIELD(arg0, u8*, 0x45) = (u8)(temp_v1 & 0xF);
                player_spawn_dash_spark(arg0);
            }
            if ((s8)M2C_FIELD(arg0, u8*, 0x45) & 0x80) {
                M2C_FIELD(arg0, u8*, 0x45) =
                    (u8)(M2C_FIELD(arg0, u8*, 0x45) & 0xF);
                play_sound(1, 5, arg0);
                M2C_FIELD(arg0, s8*, 0x8C) = 1;
                M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
                return;
            }
            func_8003F508(arg0, 0x10);
        }
    }
}
