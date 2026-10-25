#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
extern s16 D_800970AA;
extern s16 D_800FCE4C;
extern s16 D_800FCE4E;
extern s16 D_800FCE50;

void func_800FA5A0(void* arg0) {
    s16 d;
    s32 a;

    func_800179A4(arg0, 5);
    if (D_800970AA < D_800FCE50) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        {
            // !FAKE: depin: dropping it breaks the match (78/83)
            register s32 t asm("$3") = (u16)D_800FCE4E;
            d = t - M2C_FIELD(arg0, s16*, 0xA);
        }
        a = (d < 0) ? -d : d;
        if (a < 0x20) {
            goto near;
        }
        goto far;
    }
    M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    {
        // !FAKE: depin: dropping it breaks the match (77/83)
        register s32 t asm("$3") = (u16)D_800FCE4C;
        d = t - M2C_FIELD(arg0, s16*, 0xA);
    }
    a = (d < 0) ? -d : d;
    if (a < 0x20) {
    near:
        func_800179A4(arg0, 6);
        func_80016C48(2, 0x44, arg0);
        func_80012D9C(6);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        {
            // !FAKE: depin: dropping it breaks the match (53/83)
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 2;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
        return;
    }
far:
    func_80016C48(2, 0x35, arg0);
    {
        s32 q = (d << 16) / 42;
        do {
        } while (0);
        M2C_FIELD(arg0, s32*, 0x20) = q;
    }
    M2C_FIELD(arg0, s32*, 0x24) = 0x30000;
    M2C_FIELD(arg0, s32*, 0x2C) = 0x2666;
    M2C_FIELD(arg0, u8*, 6) += 1;
}
