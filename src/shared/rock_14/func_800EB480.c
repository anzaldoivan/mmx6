// rolefeed (3.1 T4): func_800EB480 of src/rock_14/E9860.c
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
extern struct X4_PlayerObj g_Player;

// clang-format on

#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
void func_800EB6C8(struct X4_MainObj*);
extern struct X4_PlayerObj g_Player;
extern u8 D_800ED700[];
extern u8 D_800ED748[];

void func_800EB480(struct X4_BaseObj* self) {
    s8 state = *(s8*)((u8*)self + 0x45);

    if (state == 1) {
        *(u8**)((u8*)self + 0x54) = D_800ED700;
    } else if (state == 2) {
        if (*(s16*)((u8*)self + 0x7C) == 0) {
            s16 px, py;
            s32 a;
            u8* tbl;
            func_800EB6C8((struct X4_MainObj*)self);
            px = g_Player.x_pos.i.hi;
            py = g_Player.y_pos.i.hi;
            a = ratan2(self->y_pos.i.hi - py, px - self->x_pos.i.hi);
            a += 0x800;
            tbl = D_800ED748;
            SPAD[0x8C] = tbl[a >> 8];
            set_animation(self, SPAD[0x8C]);
        } else {
            set_animation(self, SPAD[0x8C]);
        }
        self->action_phase++;
    }
}
