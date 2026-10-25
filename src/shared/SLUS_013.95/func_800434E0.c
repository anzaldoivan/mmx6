#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
s32 func_80016C48(s32 a0, s32 a1, void* arg2);
M2C_UNK func_8003F0BC(void*);
M2C_UNK func_8003F480();
extern struct X4_PlayerObj g_Player;
extern void (*D_80076118[])(void*);

#define B(o) (*(s8*)((u8*)p + (o)))
#define UB(o) (*(u8*)((u8*)p + (o)))
#define UH(o) (*(u16*)((u8*)p + (o)))
#define SB(o) (*(s8*)((u8*)self + (o)))

void func_800434E0(void* self) {
    struct X4_PlayerObj* p = &g_Player;
    s32 f;

    f = B(0xD3) != 0;
    if (B(0xD4) != 0) {
        f = 1;
    }
    if (B(0x2) == 1 && B(0xA6) != B(0x2)) {
        f = 1;
    }
    if (UB(0x2) == 0 && B(0x93) != 1) {
        f = 1;
    }
    if (B(0xD5) != 0) {
        f = 1;
    }
    if (B(0x5C) == 0) {
        f = 1;
    }
    if (f == 0) {
        if (SB(0x2) == 0 && UB(0x2) == 0 && SB(0x8C) == 3) {
            s32 a = UH(0x7C) & 0x600;
            s32 m = UH(0x80) & 0x600;
            if (a == 0x600 || m == 0x600) {
                UB(0x93) = 0;
                func_8003F480(p);
                func_80016C48(0, 0xC, 0);
                func_8003F0BC(p);
                f = 1;
            }
        }
    }
    if (f != 0) {
        SB(0x4) = 2;
    }
    D_80076118[SB(0x4)](self);
}
