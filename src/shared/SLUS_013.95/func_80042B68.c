#include "common.h"

void* func_8002C458();

#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_80042B68(void* arg0, u8 arg1) {
    u8* obj;
    u8 t;

    obj = func_8002C458();
    if (obj != 0) {
        B(obj, 0) = 0x41;
        B(obj, 1) = 0xC;
        t = B(arg0, 0x15);
        *(void**)(obj + 0x7C) = arg0;
        B(obj, 2) = arg1;
        B(obj, 0x15) = t;
        H(obj, 0xA) = H(arg0, 0xA);
        H(obj, 8) = 0;
        H(obj, 0xE) = H(arg0, 0xE);
        H(obj, 0xC) = 0;
        H(obj, 0x42) = H(arg0, 0x42) & 0x7FFF;
        W(obj, 0x30) = W(arg0, 0x30);
        W(obj, 0x3C) = W(arg0, 0x3C);
        H(obj, 0x40) = H(arg0, 0x40);
        B(obj, 0x14) = B(arg0, 0x14);
    }
}
