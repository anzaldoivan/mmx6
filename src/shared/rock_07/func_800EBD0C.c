#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
extern struct X4_BackgroundObj background_objects[3];

void func_800EBD0C(void* arg0) {
    struct X4_BackgroundObj* bg = background_objects;

    M2C_FIELD(bg, s32*, 0x60) = (s32)(M2C_FIELD(bg, s32*, 0x60) + 0x18000);
    if (M2C_FIELD(bg, s16*, 0x62) >= 0x368) {
        M2C_FIELD(bg, s16*, 0x62) = 0x368;
        play_sound(2, 0x45, arg0);
        M2C_FIELD(arg0, u8*, 0x90) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x14;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
