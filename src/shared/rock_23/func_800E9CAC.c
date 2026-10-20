#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8002D2B0(void*);

#define F32(p, o) (*(s32*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F8(p, o) (*(u8*)((u8*)(p) + (o)))

void func_800E9CAC(void* arg0) {
    s32 v;

    v = F32(arg0, 0x20);
    F32(arg0, 0x80) = v;
    if (v > 0) {
        if (F16(arg0, 0xA) >= F16(arg0, 0x7C) + 0x60) {
            F32(arg0, 0x20) = -v;
        }
    } else if (F16(arg0, 0x7C) - 0x60 >= F16(arg0, 0xA)) {
        F32(arg0, 0x20) = -v;
    }
    if (F32(arg0, 0x20) != F32(arg0, 0x80)) {
        F8(arg0, 0x84) = 0x28;
    }
    if (F8(arg0, 0x84) == 0) {
        func_8002D2B0((s32)arg0);
        return;
    }
    F8(arg0, 0x84)--;
}
