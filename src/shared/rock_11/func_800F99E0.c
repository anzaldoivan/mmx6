#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void* func_8002C3F8();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s8 D_800970A5;
extern struct X4_EngineObj D_800CCED0;
extern s8* D_800FDA74;

void func_800F99E0(u8* arg0) {
    s8 s;
    s8* p;

    if (D_800CCED0.unkF == 0) {
        s = D_800970A5;
        if (s == 0x14) {
            if (D_800CCED0.stage != 0xC) {
                func_8003D308(0x1D, 0x40);
            }
            p = func_8002C3F8();
            if (p != 0) {
                p[0] = 1;
                p[1] = 0x18;
                D_800FDA74 = p;
            }
            *(s16*)(arg0 + 0x7C) = s;
            arg0[6]++;
        }
    }
}
