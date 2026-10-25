#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define H(p, o) M2C_FIELD(p, s16*, o)
#define W(p, o) M2C_FIELD(p, s32*, o)

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK move_object();
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);

void func_800F25F0(void* arg0) {
    s32 ang;
    s32 tx;
    s32 ty;
    u8 f;
    u8 dir;

    tx = H(arg0, 0x84);
    ty = H(arg0, 0x86);
    ang = func_80065B74(H(arg0, 0xE) - ty, tx - H(arg0, 0xA));
    W(arg0, 0x20) = func_80065A14(ang) << 7;
    W(arg0, 0x24) = func_80065944(ang) << 7;
    if (W(arg0, 0x20) >= 0) {
        B(arg0, 0x15) = 0x40;
    } else {
        B(arg0, 0x15) = 0;
    }
    move_object(arg0);
    if (((H(arg0, 0x84) - H(arg0, 0xA)) >= 0
             ? (H(arg0, 0x84) - H(arg0, 0xA))
             : (H(arg0, 0xA) - H(arg0, 0x84))) < 9 &&
        ((H(arg0, 0x86) - H(arg0, 0xE)) >= 0
             ? (H(arg0, 0x86) - H(arg0, 0xE))
             : (H(arg0, 0xE) - H(arg0, 0x86))) < 9) {
        goto hit;
    }
    f = B(arg0, 0x70);
    if (f & 4) {
        goto hit;
    }
    dir = B(arg0, 0x15);
    if ((dir == 0 && (f & 2)) || (dir == 0x40 && (f & 1))) {
    hit:
        func_800179A4(arg0, 0xB);
        {
            // !FAKE: depin: dropping it breaks the match (77/82)
            register s32 c asm("$2") = B(arg0, 0x6);
            H(arg0, 0x7C) = 0x1E;
            B(arg0, 0x6) = c + 1;
        }
    }
}
