#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_800179A4(void*, M2C_UNK);          /* extern */
M2C_UNK func_80017A04(void*);                   /* extern */
M2C_UNK func_8002D230(void*);                   /* extern */
extern s32 D_800FCA84;

void func_800FBF78(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        if (M2C_FIELD(arg0, s32*, 0x24) != 0) {
            func_80016C48(2, 0x42, arg0);
        }
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        u8* p;
        s32 t;
        s32 x;
        u8 v;
        func_800179A4(arg0, 1);
        p = ((u8*)&D_800FCA84 + 0x28C);
        t = (u8)M2C_FIELD(arg0, u8*, 0x8B)++;
        x = M2C_FIELD(arg0, u8*, 0x8A) * 6;
        v = p[t + x];
        M2C_FIELD(arg0, u8*, 0x6) = 0;
        M2C_FIELD(arg0, u8*, 0x5) = v;
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
}
