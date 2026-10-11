#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D230(void*);
M2C_UNK func_80049E50(void*);

void func_800F72BC(void* arg0) {
    u8 f;

    ((void (*)())func_8002D230)();
    if (M2C_FIELD(arg0, u8*, 0x70) != 0) {
        if ((s16)--M2C_FIELD(arg0, u16*, 0x88) == -1) {
            func_80049E50(arg0);
            M2C_FIELD(arg0, u8*, 4) = 2;
            return;
        }
        f = M2C_FIELD(arg0, u8*, 0x95);
        if (f & 4) {
            M2C_FIELD(arg0, s32*, 0x24) = 0xFFFCCCCD;
        } else if (f & 8) {
            M2C_FIELD(arg0, s32*, 0x24) = 0x66666;
            M2C_FIELD(arg0, s32*, 0x2C) = 0x4189;
        } else if (f & 2) {
            M2C_FIELD(arg0, s32*, 0x20) = 0x147AE;
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else if (f & 1) {
            M2C_FIELD(arg0, s32*, 0x20) = 0xFFFEB852;
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        M2C_FIELD(arg0, s32*, 8) = M2C_FIELD(arg0, s32*, 0x18);
        M2C_FIELD(arg0, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0x1C);
        func_8002D230(arg0);
    }
}
