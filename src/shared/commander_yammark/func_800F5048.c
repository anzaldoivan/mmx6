#include "common.h"

extern u8 D_800F7BA0[][6];

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800F5048(void* arg0) {
    s32 v;
    u8 i;
    u8 t;

    v = F32(arg0, 0x20);
    F16(arg0, 0x7E)++;
    if ((v < 0 && (F8(arg0, 0x70) & 2)) || (v > 0 && (F8(arg0, 0x70) & 1))) {
        F32(arg0, 0x20) = 0;
        if ((s16)++F16(arg0, 0x8E) == 3) {
            i = F8(arg0, 0x87)++;
            t = D_800F7BA0[F8(arg0, 0x86)][i];
            F8(arg0, 0x6) = 0;
            F8(arg0, 0x5) = t;
            return;
        }
        F16(arg0, 0x7C) = 0;
        F8(arg0, 0x6)++;
    }
}
