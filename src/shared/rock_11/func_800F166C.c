#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80065944(s32);
s32 func_80065A14(s32);
extern s32 D_80097420;
extern u8 D_800E99F4[];

void func_800F166C(void* self) {
    s8 tbl[20][2];
    s16 s;
    s32 c;
    s16 t;
    s32 m;
    s16 x40;
    s16 x42;
    s16 x44;
    s16 x46;
    s32 v;

    __builtin_memcpy(tbl, D_800E99F4, sizeof(tbl));
    switch (M2C_FIELD(self, u8*, 2) & 0xF) {
    case 0:
        s = (func_80065A14((M2C_FIELD(self, s32*, 0x3C) - 0x400) & 0xFFF) *
             tbl[M2C_FIELD(self, s16*, 0x48)][0] * 16) >>
            16;
        c = func_80065944((M2C_FIELD(self, s32*, 0x3C) - 0x400) & 0xFFF);
        M2C_FIELD(self, s16*, 0x16) = s + M2C_FIELD(self, s16*, 0x44);
        M2C_FIELD(self, s16*, 0x1E) = M2C_FIELD(self, s16*, 0x44);
        M2C_FIELD(self, s16*, 0x22) = M2C_FIELD(self, s16*, 0x46);
        M2C_FIELD(self, s16*, 0x2A) = M2C_FIELD(self, s16*, 0x42);
        M2C_FIELD(self, s16*, 0x26) = M2C_FIELD(self, s16*, 0x40);
        M2C_FIELD(self, s16*, 0x2E) = s + M2C_FIELD(self, s16*, 0x40);
        t = (-c * tbl[M2C_FIELD(self, s16*, 0x48)][0] * 16) >> 16;
        M2C_FIELD(self, s16*, 0x1A) = t + M2C_FIELD(self, s16*, 0x46);
        M2C_FIELD(self, s16*, 0x32) = t + M2C_FIELD(self, s16*, 0x42);
        break;
    case 1:
        s = (func_80065A14((M2C_FIELD(self, s32*, 0x3C) + 0x400) & 0xFFF) *
             tbl[M2C_FIELD(self, s16*, 0x48)][0] * 16) >>
            16;
        c = func_80065944((M2C_FIELD(self, s32*, 0x3C) + 0x400) & 0xFFF);
        t = (-c * tbl[M2C_FIELD(self, s16*, 0x48)][0] * 16) >> 16;
        M2C_FIELD(self, s16*, 0x1A) = M2C_FIELD(self, s16*, 0x46);
        M2C_FIELD(self, s16*, 0x16) = M2C_FIELD(self, s16*, 0x44);
        M2C_FIELD(self, s16*, 0x1E) = s + M2C_FIELD(self, s16*, 0x44);
        M2C_FIELD(self, s16*, 0x26) = s + M2C_FIELD(self, s16*, 0x40);
        M2C_FIELD(self, s16*, 0x2E) = M2C_FIELD(self, s16*, 0x40);
        M2C_FIELD(self, s16*, 0x22) = t + M2C_FIELD(self, s16*, 0x46);
        M2C_FIELD(self, s16*, 0x2A) = t + M2C_FIELD(self, s16*, 0x42);
        M2C_FIELD(self, s16*, 0x32) = M2C_FIELD(self, s16*, 0x42);
        break;
    case 2:
        s = (func_80065A14((M2C_FIELD(self, s32*, 0x3C) - 0x400) & 0xFFF) *
             tbl[M2C_FIELD(self, s16*, 0x48)][1] * 16) >>
            16;
        c = func_80065944((M2C_FIELD(self, s32*, 0x3C) - 0x400) & 0xFFF);
        M2C_FIELD(self, s16*, 0x16) = s + M2C_FIELD(self, s16*, 0x44);
        M2C_FIELD(self, s16*, 0x1E) = M2C_FIELD(self, s16*, 0x44);
        M2C_FIELD(self, s16*, 0x22) = M2C_FIELD(self, s16*, 0x46);
        M2C_FIELD(self, s16*, 0x2A) = M2C_FIELD(self, s16*, 0x42);
        M2C_FIELD(self, s16*, 0x26) = M2C_FIELD(self, s16*, 0x40);
        M2C_FIELD(self, s16*, 0x2E) = s + M2C_FIELD(self, s16*, 0x40);
        t = (-c * tbl[M2C_FIELD(self, s16*, 0x48)][1] * 16) >> 16;
        M2C_FIELD(self, s16*, 0x1A) = t + M2C_FIELD(self, s16*, 0x46);
        M2C_FIELD(self, s16*, 0x32) = t + M2C_FIELD(self, s16*, 0x42);
        break;
    case 3:
        s = (func_80065A14((M2C_FIELD(self, s32*, 0x3C) + 0x400) & 0xFFF) *
             tbl[M2C_FIELD(self, s16*, 0x48)][1] * 16) >>
            16;
        c = func_80065944((M2C_FIELD(self, s32*, 0x3C) + 0x400) & 0xFFF);
        t = (-c * tbl[M2C_FIELD(self, s16*, 0x48)][1] * 16) >> 16;
        M2C_FIELD(self, s16*, 0x1A) = M2C_FIELD(self, s16*, 0x46);
        M2C_FIELD(self, s16*, 0x16) = M2C_FIELD(self, s16*, 0x44);
        M2C_FIELD(self, s16*, 0x1E) = s + M2C_FIELD(self, s16*, 0x44);
        M2C_FIELD(self, s16*, 0x26) = s + M2C_FIELD(self, s16*, 0x40);
        M2C_FIELD(self, s16*, 0x2E) = M2C_FIELD(self, s16*, 0x40);
        M2C_FIELD(self, s16*, 0x22) = t + M2C_FIELD(self, s16*, 0x46);
        M2C_FIELD(self, s16*, 0x2A) = t + M2C_FIELD(self, s16*, 0x42);
        M2C_FIELD(self, s16*, 0x32) = M2C_FIELD(self, s16*, 0x42);
        break;
    }
    switch ((u32)D_80097420 % 3) {
    case 0:
        M2C_FIELD(self, u8*, 3) = 1;
        M2C_FIELD(self, u8*, 0) = 3;
        break;
    case 1:
        M2C_FIELD(self, u8*, 3) = 0;
        break;
    case 2:
        M2C_FIELD(self, u8*, 3) = 1;
        M2C_FIELD(self, u8*, 0) = 0x13;
        break;
    }
    if (++M2C_FIELD(self, s16*, 0x48) >= 21) {
        M2C_FIELD(self, u8*, 3) = 0;
        M2C_FIELD(self, u8*, 4)++;
    }
}
