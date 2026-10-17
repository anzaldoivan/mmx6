#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
void func_800EB284();
extern s16 D_800970AA;

#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))

void func_800EAE1C(void* arg0) {
    s32 d;

    d = D_800970AA - H(arg0, 0xA);
    if (d >= 0) {
        if (d < 0x61) {
            // !FAKE: keeps the two range tests as separate branches
            goto body;
        }
    } else if (H(arg0, 0xA) - D_800970AA < 0x61) {
    body:
        func_800EB284(arg0);
        UB(arg0, 6)++;
        func_800179A4(arg0, 1);
    }
}
