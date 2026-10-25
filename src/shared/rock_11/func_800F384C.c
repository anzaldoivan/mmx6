#include "common.h"
#include "mmx6/x4.h"

s32 func_8002D654(s8*, u8*);
extern struct X4_PlayerObj g_Player;
extern void (*D_800FCB78[])(struct X4_MainObj*);
extern s8 D_800FD51B;

void func_800F384C(struct X4_MainObj* self) {
    s32 r;

    D_800FCB78[self->unk6](self);
    r = func_8002D654((s8*)self, (u8*)&g_Player);
    if (r == 1 && D_800FD51B == 0) {
        D_800FD51B = r;
    }
}
