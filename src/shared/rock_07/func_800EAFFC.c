#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002D2B0();
extern struct X4_PlayerObj D_800970A0;

#define B(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800EAFFC(void* arg0) {
    s32 d;
    // !FAKE: depin: dropping it breaks the match (65/70)
    register s32 v asm("$3");
    // !FAKE: depin: dropping it breaks the match (53/70)
    register s32 c asm("$2");

    if (--H(arg0, 0x88) == 0) {
        W(arg0, 0x24) = 0;
        ((void (*)(void*))func_8002D2B0)(arg0);
        UB(arg0, 7)++;
        return;
    }
    d = D_800970A0.y_pos.i.hi - H(arg0, 0xE);
    if (d >= 0) {
        if (d < 3) {
            W(arg0, 0x24) = 0;
        } else {
            goto far;
        }
    } else if (H(arg0, 0xE) - D_800970A0.y_pos.i.hi >= 3) {
    far: {
        // !FAKE: depin: dropping it breaks the match (55/70)
        register struct X4_PlayerObj* pb asm("$2") = &D_800970A0;
        if (pb->y_pos.i.hi >= H(arg0, 0xE)) {
            c = 0xFFFE0000;
        } else {
            c = 0x10000;
        }
        W(arg0, 0x24) = c | 0x8000;
    }
    } else {
        W(arg0, 0x24) = 0;
    }
    if ((B(arg0, 2) & 0xF) == 1) {
        v = D_800970A0.x_pos.i.hi > H(arg0, 0xA);
    } else {
        v = D_800970A0.x_pos.i.hi;
        v = v < H(arg0, 0xA);
    }
    if (v) {
        W(arg0, 0x24) = 0;
        UB(arg0, 7)++;
    }
    func_8002D2B0(arg0);
}
