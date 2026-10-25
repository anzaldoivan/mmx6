#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;

void func_800EA3F4(struct X4_MainObj* self) {
    // !FAKE: the result lives in the first return register across every arm
    register s32 dir asm("$2");

    if (g_Player.unk2 == 0) {
        s32 px;
        s32 x;
        s32 py;
        s32 y;
        s32 dx;
        s32 ya;
        s32 xb;
        s32 yc;
        s32 ye;
        s32 d_up;
        s32 d_side;
        s32 d_down;

        px = g_Player.x_pos.i.hi;
        x = self->x_pos.i.hi;
        dx = px - 0x10;
        dx -= x;
        dx = dx * dx;
        py = g_Player.y_pos.i.hi;
        y = self->y_pos.i.hi;
        ya = py + 0x20;
        ya -= y;
        ya = ya * ya;
        xb = px + 0x10;
        xb -= x;
        xb = xb * xb;
        yc = py - y;
        yc = yc * yc;
        ye = py - 0x20;
        ye -= y;
        ye = ye * ye;
        d_up = dx + ya;
        d_side = xb + yc;
        d_down = dx + ye;
        if (d_side >= d_up) {
            if (d_down < d_up) {
                // !FAKE: shared result block keeps each arm's compare ahead of the result store
                goto three;
            }
            {
                // !FAKE: a byte-mode view of the result register stops this arm cross-jumping
                register s8 one asm("$2");
                one = 1;
            }
            // !FAKE: explicit join keeps the arm out of the shared result block
            goto end;
        }
        if (d_down < d_side) {
            // !FAKE: shared result block keeps each arm's compare ahead of the result store
            goto three;
        }
        dir = 2;
        // !FAKE: explicit join keeps the arm out of the shared result block
        goto end;
    }
    if (self->x_pos.i.hi >= g_Player.x_pos.i.hi) {
        dir = 2;
        // !FAKE: explicit join keeps the arm out of the shared result block
        goto end;
    }
    if (self->y_pos.i.hi < g_Player.y_pos.i.hi) {
        // !FAKE: shared result block keeps each arm's compare ahead of the result store
        goto three;
    }
    dir = 1;
end:
    self->unk7 = dir;
    // !FAKE: barrier keeps the result store ahead of the counter load
    do {
    } while (0);
    self->unk6++;
    return;
three:
    dir = 3;
    // !FAKE: shared result block rejoins the store
    goto end;
}
