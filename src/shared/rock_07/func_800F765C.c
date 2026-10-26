#include "common.h"
#include "psyq/libgte.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define W(p, o) M2C_FIELD(p, s32*, o)

extern s32 D_800F978C;
extern s32 D_800F9790;

void func_800F765C(void* arg0) {
    s32 m;

    B(arg0, 0x3) = 1;
    W(arg0, 0x50) = (s32)&D_800F978C;
    W(arg0, 0x68) = (s32)&D_800F9790;
    m = rcos(W(arg0, 0x84)) * 0x10;
    W(arg0, 0x20) = (m * 2 + m) * 2;
    m = rsin(W(arg0, 0x84)) * 0x10;
    W(arg0, 0x24) = (m * 2 + m) * 2;
    B(arg0, 0x6)++;
}
