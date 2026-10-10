#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_80065B74(s32, s32);
void func_800EB6C8(struct X4_MainObj*);
extern struct X4_PlayerObj D_800970A0;
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
            px = D_800970A0.x_pos.i.hi;
            py = D_800970A0.y_pos.i.hi;
            a = func_80065B74(self->y_pos.i.hi - py, px - self->x_pos.i.hi);
            a += 0x800;
            tbl = D_800ED748;
            SPAD[0x8C] = tbl[a >> 8];
            func_800179A4(self, SPAD[0x8C]);
        } else {
            func_800179A4(self, SPAD[0x8C]);
        }
        self->unk6++;
    }
}
