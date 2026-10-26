#include "common.h"
#include "psyq/libgte.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AE;
extern struct X4_BackgroundObj background_objects[3];
extern M2C_UNK D_800F6F58;

void func_800F1CC0(void* arg0) {
    s16 x;
    s16 y;
    s32 angle;

    M2C_FIELD(arg0, void**, 0x50) = &D_800F6F58;
    x = background_objects[0].unk26 + 0x30;
    if (background_objects[0].unk2A + 0x80 < D_800970AE) {
        y = background_objects[0].unk2A + 0xB0;
        M2C_FIELD(arg0, s16*, 0x8C) = 0;
    } else {
        y = background_objects[0].unk2A + 0x60;
        M2C_FIELD(arg0, s16*, 0x8C) = 1;
    }
    angle =
        ratan2(y - M2C_FIELD(arg0, s16*, 0xE), x - M2C_FIELD(arg0, s16*, 0xA));
    {
        s32 a = rcos(angle) * 16;
        M2C_FIELD(arg0, s32*, 0x20) = a * 4 + a;
    }
    {
        s32 b = -rsin(angle) * 16;
        M2C_FIELD(arg0, s32*, 0x24) = b * 4 + b;
    }
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}
