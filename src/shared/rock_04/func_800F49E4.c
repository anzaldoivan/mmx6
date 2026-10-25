#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_80090D5C;
extern struct X4_BackgroundObj background_objects[3];
extern s16 D_80097430;
extern u8 D_800C4560;
extern s16 D_800CF854;

void func_800F49E4(void* arg0) {
    s32 n;

    if ((s16)--M2C_FIELD(arg0, u16*, 0x7C) == -1) {
        M2C_FIELD(arg0, u16*, 0x7C) = 3;
        n = (u16)D_800CF854 + 1;
        D_800CF854 = n;
        D_80097430 += 0x20;
        D_80090D5C += 0x400;
        D_800C4560 |= 1;
        if ((u16)n >= 0x1F) {
            M2C_FIELD(arg0, s16*, 0xA) = background_objects[0].unk26 + 0xF0;
            M2C_FIELD(arg0, s16*, 0xE) = background_objects[0].unk2A + 0x90;
            M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
            M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
            M2C_FIELD(arg0, s32*, 0x2C) = 0xBB8;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        }
    }
}
