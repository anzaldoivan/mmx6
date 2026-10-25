#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SCRATCH_4C (*(u8**)0x1F80004C)

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
extern struct X4_BackgroundObj background_objects[3];
extern s16 D_800F4484;

void func_800F19F8(u8* arg0) {
    s32 t;
    // !FAKE: depin: dropping it breaks the match (47/51)
    register s32 k asm("$3");

    ((M2C_UNK(*)())func_80017A04)();
    {
        // !FAKE: depin: dropping it breaks the match (48/51)
        register u8* p asm("$2") = SCRATCH_4C;
        t = p[0x8B];
    }
    k = 2;
    if (t == k) {
        background_objects[1].y_pos.u.hi -= 2;
        if ((s16)background_objects[1].y_pos.u.hi > D_800F4484 + 0xB30) {
            return;
        }
        goto hit;
    } else if (t == 1) {
        background_objects[1].y_pos.u.hi += 2;
        if ((s16)background_objects[1].y_pos.u.hi >= D_800F4484 + 0x990) {
        hit:
            func_80016C48(2, 3, arg0);
            arg0[5] = 7;
            arg0[6] = 0;
        }
    }
}
