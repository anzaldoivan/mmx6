#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
extern s8 D_800CCEF4;
extern s8 D_800CCF5C;
extern u8 D_800FB26C[];
extern s16 D_800FDA72;

void func_800F3D24(u8* self) {
    s8 state = *(s8*)(self + 0x89);

    if (state == 0) {
        return;
    }
    switch (state) {
    case 1:
        D_800CCEF4 = state;
        *(s8*)(self + 0x5C) = state;
        D_800FDA72 = 3;
        *(void**)(self + 0x50) = 0;
        *(void**)(self + 0x54) = 0;
        self[0x89]++;
        break;
    case 2:
        if (--D_800FDA72 == 0) {
            func_80016C48(0, 0xE, 0);
            D_800FDA72 = 3;
        }
        if (++*(s8*)(self + 0x5C) == D_800CCF5C) {
            void* a;
            void* b;
            self[0x89] = 0;
            a = D_800FB26C + 0x1044;
            *(void**)(self + 0x50) = a;
            a = 0;
            b = D_800FB26C + 0x1048;
            *(void**)(self + 0x54) = b;
        }
        break;
    }
}
