#include "common.h"

void func_800E9F7C(void);
extern s16 D_80090D5C;
extern s32 D_80097420;
extern s16 D_80097430;
extern s16 D_800CF854;
#define D_80090D5C (*(u16*)&D_80090D5C)
#define D_80097430 (*(u16*)&D_80097430)
#define D_800CF854 (*(u16*)&D_800CF854)

void func_800FA268(u8* arg0) {
    if (*(s16*)(arg0 + 4) != 0) {
        *(s16*)(arg0 + 4) -= 1;
        return;
    }
    if (!(D_80097420 & 3)) {
        D_800CF854 -= 1;
        D_80097430 -= 0x20;
        D_80090D5C -= 0x400;
    }
    if (D_800CF854 == 0) {
        func_800E9F7C();
        {
            s32 t = arg0[1] + 1;
            // !FAKE: constant in the second return register
            register s32 k asm("$3") = 0x78;
            *(s16*)(arg0 + 8) = k;
            *(s16*)(arg0 + 0xA) = 2;
            arg0[1] = t;
        }
    }
}
#undef D_80090D5C
#undef D_80097430
#undef D_800CF854
