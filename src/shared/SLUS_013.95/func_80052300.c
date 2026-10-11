#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CA14();
extern u8* D_80079ED4[];
extern s32 D_80079EDC[][16];
extern s32 D_80090C90[];
extern s8 D_80090D56;
extern s16 D_80090D5C;
extern s8 D_8009742C;
extern s16 D_80097430;
extern struct X4_EffectObj D_8009B7B0[0x20];
extern s8 D_800CF850;
extern s16 D_800CF854;

void func_80052300(void* arg0) {
    u8 i;
    u16 c;
    u8* p;

    i = 0;
    if (M2C_FIELD(arg0, s8*, 2) != -1) {
        M2C_FIELD(arg0, u8**, 0x14) = D_80079ED4[M2C_FIELD(arg0, s8*, 2)];
        M2C_FIELD(arg0, u8*, 0x18) = M2C_FIELD(arg0, u8**, 0x14)[2];
        do {
            D_80090C90[i] = D_80079EDC[M2C_FIELD(arg0, s8*, 2)][i];
            i++;
        } while (i < 0x10);
        D_800CF850 = M2C_FIELD(arg0, u8**, 0x14)[3] & 1;
        D_8009742C = M2C_FIELD(arg0, u8**, 0x14)[3] & 2;
        D_80090D56 = M2C_FIELD(arg0, u8**, 0x14)[3] & 4;
        c = *(u16*)M2C_FIELD(arg0, u8**, 0x14);
        D_800CF854 = c & 0x1F;
        D_80097430 = c & 0x3E0;
        D_80090D5C = c & 0x7C00;
        M2C_FIELD(arg0, u8*, 4)++;
        return;
    }
    D_80090D5C = 0;
    D_80097430 = 0;
    D_800CF854 = 0;
    D_80090D56 = 0;
    D_8009742C = 0;
    D_800CF850 = 0;
    for (p = (u8*)D_8009B7B0; p < (u8*)D_8009B7B0 + 0x1200; p += 0x30) {
        if (M2C_FIELD(p, s8*, 2) == 2 && p != arg0) {
            func_8002CA14(p);
        }
    }
    func_8002CA14(arg0);
}
