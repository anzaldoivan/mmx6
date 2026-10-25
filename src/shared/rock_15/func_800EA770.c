#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);

extern M2C_UNK D_800741FC;
extern M2C_UNK D_8007433C;
extern u8 D_800CCF38;
extern u8 D_800F5FC0[];
extern u8 D_800F5FC8[];
extern u8 D_800F5FCC[];
extern u8 D_800F5FD0[];
extern u8 D_800F5FD4[];
extern u8 D_800F5FD8[];
extern u8 D_800F5FDC[];
extern u8 D_800F5FE0[];

void func_800EA770(struct X4_PlayerObj* self) {
    void* tbl;

    if (self->unk2 == 0) {
        // !FAKE: depin: dropping it breaks the match (155/162)
        register void* p asm("$2");
        // !FAKE: depin: dropping it breaks the match (155/162)
        register s32 n asm("$4");
        // !FAKE: depin: dropping it breaks the match (49/162)
        register void* q asm("$3");
        s32 vx;
        s16 x;
        u8 dir;
        // !FAKE: depin: dropping it breaks the match (28/162)
        register s32 t asm("$2");

        func_8002943C(8, 2, 2);
        func_80016C48(2, 0x1D, self);
        func_80012D9C(5);
        func_800179A4(self, 5);
        dir = self->unk15;
        vx = -0x28000;
        if (dir != 0) {
            vx = 0x28000;
        }
        self->y_vel.val = -0x28000;
        self->x_vel.val = vx;
        self->unk28 = 0;
        self->unk2C = 0;
        x = self->x_pos.i.hi;
        t = (dir != 0) ? x + 0x24 : x - 0x24;
        n = 4;
        self->x_pos.i.hi = t;
        p = D_800F5FC8;
        self->unk68 = p;
        p = D_800F5FC0;
        self->unk50 = p;
        self->hp = 0;
        self->unk60 = n;
        self->unk54 = 0;
        q = &D_800741FC;
        self->unk58 = q;
        self->unk16 = n;
        self->y_pos.u.hi += 8;
    } else if (self->unk2 == 1) {
        s32 vx;
        s16 x;
        u8 dir;

        func_80016C48(2, 0x1C, self);
        func_800179A4(self, 6);
        dir = self->unk15;
        vx = -0x30000;
        if (dir != 0) {
            vx = 0x30000;
        }
        self->x_vel.val = vx;
        self->unk28 = 0;
        self->y_vel.val = 0;
        self->unk2C = 0;
        x = self->x_pos.i.hi;
        self->x_pos.i.hi = (dir != 0) ? x + 0x20 : x - 0x20;
        self->hp = 6;
        self->unk60 = 4;
        self->unk68 = D_800F5FD4;
        self->unk54 = D_800F5FD0;
        self->unk50 = D_800F5FCC;
        self->y_pos.u.hi -= 0x10;
        if (D_800CCF38 >= 2) {
            tbl = &D_8007433C;
        } else {
            tbl = &D_800741FC;
        }
        self->unk58 = tbl;
        self->unk16 = 6;
        M2C_FIELD(self, s16*, 0x8C) = 0x32;
    } else {
        s16 x;

        func_80016C48(2, 0x1B, self);
        func_800179A4(self, 6);
        self->x_vel.val = 0;
        self->unk28 = 0;
        self->y_vel.val = 0;
        self->unk2C = 0;
        x = self->x_pos.i.hi;
        self->x_pos.i.hi = (self->unk15 != 0) ? x + 0x30 : x - 0x30;
        self->unk60 = 8;
        self->unk68 = D_800F5FE0;
        self->unk54 = D_800F5FDC;
        self->unk50 = D_800F5FD8;
        self->unk58 = &D_8007433C;
        self->hp = 0;
        self->unk16 = 6;
        self->y_pos.u.hi -= 0x10;
    }
    self->on_screen = 0;
    self->unk70 = 0;
    self->invincibility_timer = 0;
    self->unk42 &= 0x7FFF;
    self->state++;
}
