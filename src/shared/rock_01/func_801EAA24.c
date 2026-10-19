#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void* func_8002C32C();
struct X4_VisualObj* func_8002C398(void);

#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define H(p, o) (*(u16*)((u8*)(p) + (o)))

void func_801EAA24(u8* arg0, s8 arg1) {
    u8* v;
    u8* w;

    if (SB(arg0, 7) == 0) {
        w = func_8002C32C();
        if (w != 0) {
            B(w, 0) = 0x21;
            B(w, 1) = 0x2C;
            H(w, 0xA) = H(arg0, 0xA);
            B(w, 0x14) = B(arg0, 0x14);
        }
        v = (u8*)func_8002C398();
        if (v != 0) {
            B(v, 0) = 0x21;
            B(v, 1) = 0x1A;
            H(v, 0xA) = H(arg0, 0xA);
            B(v, 0x14) = B(arg0, 0x14);
        }
    } else {
        w = func_8002C32C();
        if (w != 0) {
            B(w, 0) = 0x21;
            B(w, 1) = 0x2C;
            H(w, 0xA) = H(arg0, 0xA) - (arg1 << 5);
            B(w, 0x14) = B(arg0, 0x14);
        }
        v = (u8*)func_8002C398();
        if (v != 0) {
            B(v, 0) = 0x21;
            B(v, 1) = 0x1A;
            H(v, 0xA) = H(arg0, 0xA) - (arg1 << 5);
            B(v, 0x14) = B(arg0, 0x14);
        }
        w = func_8002C32C();
        if (w != 0) {
            B(w, 0) = 0x21;
            B(w, 1) = 0x2C;
            H(w, 0xA) = H(arg0, 0xA) + (arg1 << 5);
            B(w, 0x14) = B(arg0, 0x14);
        }
        v = (u8*)func_8002C398();
        if (v != 0) {
            B(v, 0) = 0x21;
            B(v, 1) = 0x1A;
            H(v, 0xA) = H(arg0, 0xA) + (arg1 << 5);
            B(v, 0x14) = B(arg0, 0x14);
        }
    }
}
