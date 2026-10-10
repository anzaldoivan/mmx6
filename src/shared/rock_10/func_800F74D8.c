#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD9C_800F74D8 (*(s32**)0x1F80009C)
#define SPAD20_800F74D8 (*(s32**)0x1F800020)

s32 func_8002A47C(s32);
struct X4_VisualObj* func_8002C398(void);

extern s8 D_800CCEDC;
#define D_800CCEDC (*(s8*)&D_800CCEDC)

#define O(type, off) M2C_FIELD(o, type*, off)
#define P(type, off) M2C_FIELD(arg0, type*, off)

void func_800F74D8(void* arg0, s16 arg1, s16 arg2, u8 arg3) {
    struct X4_VisualObj* o;
    s32 a;
    s32 b;
    u8 t14;

    o = func_8002C398();
    if (o != 0) {
        O(u8, 0x0) = 0x41;
        O(u8, 0x1) = 5;
        O(u8, 0x2) = arg3;
        O(u8, 0x15) = P(u8, 0x15);
        O(s32, 0x30) = P(s32, 0x30);
        t14 = P(u8, 0x14);
        O(u16, 0x40) = 0x140;
        O(s16, 0xA) = arg1;
        O(s16, 0x8) = 0;
        O(s16, 0xE) = arg2;
        O(s16, 0xC) = 0;
        O(void*, 0x50) = arg0;
        O(u8, 0x14) = t14;
        if (D_800CCEDC == 0xC) {
            O(u16, 0x42) = 0x7948;
            O(u8*, 0x3C) = (u8*)SPAD9C_800F74D8 + *SPAD9C_800F74D8;
        } else {
            a = func_8002A47C(P(s8, 0x1));
            b = func_8002A47C(P(s8, 0x1));
            O(s16, 0x42) = ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
            O(u8*, 0x3C) = (u8*)SPAD20_800F74D8 +
                           SPAD20_800F74D8[func_8002A47C(P(s8, 0x1))];
        }
        if (O(s8, 0x2) == 0x20) {
            O(s32, 0x50) = P(s32, 0x80);
        }
    }
}
#undef D_800CCEDC
