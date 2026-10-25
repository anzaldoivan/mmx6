#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#include "mmx6/x4.h"

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
void func_800F6880(void* arg0, u8 arg1, s16 arg2, s16 arg3);
extern struct X4_BackgroundObj background_objects[3];

void func_800F2D98(void* arg0) {
    s32 n;
    s32 d;

    if (!(--M2C_FIELD(arg0, u16*, 0x7C) & 3)) {
        func_800F6880(arg0, 0x10, background_objects[0].unk26 + 0xF0,
                      background_objects[0].unk2A + 0xE0);
    }
    if (!(M2C_FIELD(arg0, u16*, 0x7C) & 0xF)) {
        func_80016C48(2, 0x5E, arg0);
        func_80012D9C(5);
    }
    if (M2C_FIELD(arg0, s16*, 0x7C) < 0x3D) {
        if (!(M2C_FIELD(arg0, u16*, 0x7C) & 3)) {
            func_8002943C(2, 4, 2);
        }
        if (M2C_FIELD(arg0, s16*, 0x7C) == 0) {
            func_800179A4(arg0, 0);
            n = 0xB00000;
            d = 0xC80;
            M2C_FIELD(arg0, u8*, 3) = 1;
            M2C_FIELD(arg0, s16*, 0xA) = background_objects[0].unk26 + 0xF0;
            M2C_FIELD(arg0, s16*, 0xE) = background_objects[0].unk2A + 0x110;
            M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
            M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
            M2C_FIELD(arg0, s32*, 0x2C) = n / d;
            M2C_FIELD(arg0, s32*, 0x24) = 0x46640;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x28) = 0;
            M2C_FIELD(arg0, u8*, 6) += 1;
        }
    }
}
