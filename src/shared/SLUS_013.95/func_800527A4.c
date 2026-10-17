#include "common.h"

extern u8 D_800C4560;
extern s8 D_800E4480;

#define SCRATCH_30 (*(s32**)0x1F800030)
#define F_U8(o) (*(u8*)(arg0 + (o)))
#define F_S8(o) (*(s8*)(arg0 + (o)))
#define F_PTR(o) (*(u8**)(arg0 + (o)))
#define F_SPTR(o) (*(s8**)(arg0 + (o)))
#define F_WPTR(o) (*(s32**)(arg0 + (o)))

void func_800527A4(u8* arg0) {
    s32* dst;
    s32* src;
    u32 i;
    s8 step;

    if (D_800E4480 == 0 && (s8)--F_U8(0x21) == -1) {
        F_PTR(0x1C) += 2;
        step = F_SPTR(0x1C)[1];
        if (step == 0) {
            F_U8(4)++;
            return;
        }
        if (step < 0) {
            F_PTR(0x1C) += step * 2;
        }
        dst = F_WPTR(0x18);
        F_U8(0x21) = F_PTR(0x1C)[1];
        F_WPTR(0x14) = SCRATCH_30 + F_PTR(0x1C)[0] * 8;
        src = F_WPTR(0x14);
        for (i = 0; i < F_S8(0x20) * 8; i++) {
            *dst++ = *src++;
        }
        D_800C4560 |= 1;
    }
}
