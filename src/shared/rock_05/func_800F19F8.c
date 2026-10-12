#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SCRATCH_4C (*(u8**)0x1F80004C)

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
extern struct X4_BackgroundObj D_800971F8[3];
extern s16 D_800F4484;

void func_800F19F8(u8* arg0) {
    register s32 t asm("$4");
    register s32 k asm("$3");

    ((M2C_UNK(*)())func_80017A04)();
    {
        register u8* p asm("$2") = SCRATCH_4C;
        t = p[0x8B];
    }
    k = 2;
    if (t == k) {
        D_800971F8[1].y_pos.u.hi -= 2;
        if ((s16)D_800971F8[1].y_pos.u.hi > D_800F4484 + 0xB30) {
            return;
        }
        goto hit;
    } else if (t == 1) {
        D_800971F8[1].y_pos.u.hi += 2;
        if ((s16)D_800971F8[1].y_pos.u.hi >= D_800F4484 + 0x990) {
        hit:
            func_80016C48(2, 3, arg0);
            arg0[5] = 7;
            arg0[6] = 0;
        }
    }
}
