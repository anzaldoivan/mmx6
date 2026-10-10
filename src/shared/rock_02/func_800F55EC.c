#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800F55EC (*(s32*)0x1F800020)
#define SPAD4C_800F55EC (*(u8**)0x1F80004C)

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
s32 func_8002A47C(s32);
void* func_8002C458();

void func_800F55EC(void* self) {
    s32 i;
    void* obj;
    s32 idx;
    s32 base;
    u16 ang;

    ((M2C_UNK(*)())func_80017A04)();
    if (M2C_FIELD(self, s8*, 0x45) == 1) {
        func_80016C48(2, 0x1E, self);
        i = 0;
        do {
            obj = func_8002C458();
            if (obj != 0) {
                M2C_FIELD(obj, u8*, 0x0) = 0x41;
                M2C_FIELD(obj, u8*, 0x1) = 0x15;
                M2C_FIELD(obj, u8*, 0x2) = i + 9;
                M2C_FIELD(obj, s32*, 0x8) = M2C_FIELD(self, s32*, 0x8);
                M2C_FIELD(obj, s32*, 0xC) = M2C_FIELD(self, s32*, 0xC);
                M2C_FIELD(obj, u16*, 0x42) =
                    M2C_FIELD(self, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(obj, s32*, 0x30) = M2C_FIELD(self, s32*, 0x30);
                idx = func_8002A47C(0x37);
                base = SPAD20_800F55EC;
                M2C_FIELD(obj, s32*, 0x3C) =
                    base + M2C_FIELD(base, s32*, idx * 4 + 4);
                ang = M2C_FIELD(self, u16*, 0x40);
                M2C_FIELD(obj, void**, 0x7C) = self;
                M2C_FIELD(obj, u16*, 0x40) = ang;
            }
            i++;
            SPAD4C_800F55EC[0x8A] = 0x11;
        } while (i < 2);
        M2C_FIELD(self, s16*, 0x7C) = 0;
        M2C_FIELD(self, u8*, 0x6)++;
    }
}

#undef SPAD20_800F55EC
#undef SPAD4C_800F55EC
