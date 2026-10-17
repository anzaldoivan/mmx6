#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
void* func_8002C458();
extern s32 D_800FDE30;

void func_800FCFB8(void* arg0) {
    s32 i;
    void* e;

    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        func_80016C48(2, 0x8E, arg0);
        func_80012D9C(3);
        M2C_FIELD(arg0, s8*, 0x45) = 0;
        M2C_FIELD(arg0, s8*, 7) = 0;
        for (i = 0; i < 8; i++) {
            e = func_8002C458();
            if (e != 0) {
                s32 v = M2C_FIELD(arg0, u8*, 0);
                M2C_FIELD(e, u8*, 1) = 0x13;
                M2C_FIELD(e, u8*, 2) = 6;
                M2C_FIELD(e, void**, 0x7C) = arg0;
                M2C_FIELD(e, u8*, 0) = v;
            }
        }
        func_80029478(0x10, 6, 3);
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        func_800179A4(arg0, 0);
        {
            u8* t = (u8*)&D_800FDE30 + 0x284;
            u8* q = t + (M2C_FIELD(arg0, u8*, 0x87)++ +
                         M2C_FIELD(arg0, u8*, 0x86) * 6);
            s32 r = *q;
            M2C_FIELD(arg0, s8*, 6) = 0;
            M2C_FIELD(arg0, u8*, 5) = r;
        }
    }
}
