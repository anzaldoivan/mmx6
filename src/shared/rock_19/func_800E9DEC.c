#include "common.h"

s32 func_8002B2F8(s32);
extern s16 D_80090D5C;
extern s16 D_80097430;
extern s16 D_800CF854;

void func_800E9DEC(u8* arg0) {
    if (*(s16*)(arg0 + 4) != 0) {
        D_800CF854 = 0x1F;
        D_80097430 = 0x3E0;
        D_80090D5C = 0x7C00;
        *(s16*)(arg0 + 4) -= 1;
        return;
    }
    arg0[1]++;
    func_8002B2F8(0);
}
