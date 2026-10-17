#include "common.h"

extern s32 D_800970A8;

#define F(T, p, o) (*(T*)((u8*)(p) + (o)))

void func_800EB16C(void* arg0) {
    s32 d = D_800970A8 - F(s32, arg0, 8);

    if (d >= 0) {
        if (d <= 0x18000) {
            // !FAKE: retail tests the first arm inverted, jumping straight to the shared store block
            goto body;
        }
        return;
    }
    if (F(s32, arg0, 8) - D_800970A8 > 0x18000) {
        return;
    }
body:
    F(s32, arg0, 0x20) = 0;
    F(s32, arg0, 0x24) = 0xFFFC4000;
    F(u8, arg0, 6) += 1;
}
