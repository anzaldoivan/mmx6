#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C458();

extern s8 D_800CCF08;
extern u8 D_800F606C[];
extern M2C_UNK D_800F6154;

#define U8(p, o) M2C_FIELD(p, u8*, o)
#define S8(p, o) M2C_FIELD(p, s8*, o)
#define U16(p, o) M2C_FIELD(p, u16*, o)
#define S32(p, o) M2C_FIELD(p, s32*, o)
#define PTR(p, o) M2C_FIELD(p, void**, o)

void func_800EC478(void* arg0) {
    void* e;
    s32 t;

    e = func_8002C458();
    if (e != 0) {
        U8(e, 0x0) = 0x41;
        U8(e, 0x1) = 0x25;
        if (S8(arg0, 0x2) == 2) {
            U8(e, 0x2) = D_800F606C[S32(arg0, 0x84)];
        } else {
            U8(e, 0x2) = (u8)D_800CCF08 ^ (U8(arg0, 0x84) & 1);
        }
        if (S32(arg0, 0x84) == 3 && D_800CCF08 == 0) {
            U8(e, 0x2) = U8(e, 0x2) + 1;
        }
        PTR(e, 0x7C) = arg0;
        t = U16(arg0, 0x42);
        PTR(e, 0x30) = &D_800F6154;
        U16(e, 0x42) = t;
        S32(e, 0x3C) = S32(arg0, 0x3C);
        U16(e, 0x40) = U16(arg0, 0x40);
        U8(e, 0x15) = U8(arg0, 0x15);
        t = U8(arg0, 0x14);
        U8(e, 0x16) = 4;
        U8(e, 0x14) = t;
    }
}
