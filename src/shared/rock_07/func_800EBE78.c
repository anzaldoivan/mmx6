#include "common.h"
#define M2C_UNK s32

void func_800EAA2C();

#define F7_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F7_S16(p, o) (*(s16*)((u8*)(p) + (o)))

void func_800EBE78(void* arg0) {
    if (--F7_S16(arg0, 0x7C) == 0) {
        func_800EAA2C(arg0, 0);
        if (++F7_S16(arg0, 0x7E) < 4) {
            F7_U8(arg0, 6)--;
        } else {
            F7_U8(arg0, 6)++;
        }
    }
}
