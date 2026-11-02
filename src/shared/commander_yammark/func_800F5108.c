#include "common.h"

#define F5108_UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define F5108_H(p, o) (*(s16*)((u8*)(p) + (o)))
#define F5108_W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800F5108(u8* arg0) {
    F5108_H(arg0, 0x7E)++;
    F5108_H(arg0, 0x7C)++;
    if (F5108_H(arg0, 0x7C) == 0x32) {
        if (F5108_UB(arg0, 0x15) != 0) {
            F5108_UB(arg0, 0x15) = 0;
            F5108_W(arg0, 0x20) = 0xFFFD8000;
        } else {
            F5108_UB(arg0, 0x15) = 0x40;
            F5108_W(arg0, 0x20) = 0x28000;
        }
        F5108_UB(arg0, 6)--;
    }
}
