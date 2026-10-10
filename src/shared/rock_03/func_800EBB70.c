#include "common.h"

void* func_8002C458();

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800EBB70(u8* arg0, u8 arg1) {
    u8* obj;

    obj = func_8002C458();
    if (obj != 0) {
        UB(obj, 0) = 0x41;
        UB(obj, 1) = 2;
        UB(obj, 0x15) = UB(arg0, 0x15);
        W(obj, 0x7C) = (s32)arg0;
        UB(obj, 2) = arg1;
        H(obj, 0xA) = H(arg0, 0xA);
        H(obj, 8) = 0;
        H(obj, 0xE) = H(arg0, 0xE);
        H(obj, 0xC) = 0;
        H(obj, 0x42) = H(arg0, 0x42) & 0x7FFF;
        W(obj, 0x30) = W(arg0, 0x30);
        W(obj, 0x3C) = W(arg0, 0x3C);
        H(obj, 0x40) = H(arg0, 0x40);
        UB(obj, 0x14) = UB(arg0, 0x14);
    }
}
