#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define H(p, o) M2C_FIELD(p, s16*, o)
#define W(p, o) M2C_FIELD(p, s32*, o)

M2C_UNK move_object(void*);

void func_800F3B9C(void* arg0) {
    s32 ang;
    s32 tx;
    s32 ty;

    tx = H(arg0, 0x90);
    ty = H(arg0, 0x92);
    ang = ratan2(H(arg0, 0xE) - ty, tx - H(arg0, 0xA));
    W(arg0, 0x20) = rcos(ang) << 7;
    W(arg0, 0x24) = rsin(ang) << 7;
    move_object(arg0);
    if (((H(arg0, 0x90) - H(arg0, 0xA)) >= 0
             ? (H(arg0, 0x90) - H(arg0, 0xA))
             : (H(arg0, 0xA) - H(arg0, 0x90))) < 9 &&
        ((H(arg0, 0x92) - H(arg0, 0xE)) >= 0
             ? (H(arg0, 0x92) - H(arg0, 0xE))
             : (H(arg0, 0xE) - H(arg0, 0x92))) < 9) {
        B(arg0, 0x4) = 2;
    }
}
