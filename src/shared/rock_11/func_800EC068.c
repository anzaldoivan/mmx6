#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)

M2C_UNK func_800179A4(void*, M2C_UNK);
void func_800EC830(void*, s32, s32);
extern struct X4_PlayerObj g_Player;
extern u8 D_800CCF38;

void func_800EC068(struct X4_BaseObj* self) {
    s8 state = *(s8*)((u8*)self + 0x45);
    s32 v;

    if (state == 1) {
        if (*(s16*)((u8*)self + 0x7C) == 0) {
            s16 px = g_Player.x_pos.i.hi;
            s16 py = g_Player.y_pos.i.hi;
            *(s32*)(SPAD + 0x80) =
                ratan2(self->y_pos.i.hi - py, px - self->x_pos.i.hi);
            func_800EC830(self, 0, *(s32*)(SPAD + 0x80));
        } else {
            func_800EC830(self, 1, *(s32*)(SPAD + 0x80));
        }
    } else if (state == 2) {
        if (D_800CCF38 >= 2 && ++*(s16*)((u8*)self + 0x7C) < 2) {
            v = *(u8*)((u8*)self + 6) - 1;
        } else {
            func_800179A4(self, 2);
            v = *(u8*)((u8*)self + 6);
            v += 1;
        }
        self->unk6 = v;
    }
}
