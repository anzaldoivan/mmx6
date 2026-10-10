#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32

M2C_UNK func_8002CA54();
M2C_UNK func_8002CB50();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030234();
void func_80031F4C(struct X4_PlayerObj*);
M2C_UNK func_8003208C(struct X4_PlayerObj*);
s32 func_80032B34(struct X4_PlayerObj*);
void func_80032BE8(struct X4_PlayerObj*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_800ECAB8(struct X4_PlayerObj*, s16, s16);

extern struct X4_EngineObj D_800CCED0;
extern M2C_UNK D_800F3A0C;
extern M2C_UNK D_800F3A10;
extern M2C_UNK D_800F3A1C;
extern void (*D_800F3A2C[])(struct X4_PlayerObj*);

void func_800ECE74(struct X4_PlayerObj* self) {
    s32 x;
    s8 dir;
    s32 r;
    u8 tile;
    struct X4_Unk_unk68* p;

    self->unk42 &= 0x7FFF;
    if (D_800CCED0.stage >= 0x13) {
        x = (s16)(self->x_pos.i.hi - *(u8*)&self->double_tap_direction) - 1;
        r = func_800ECAB8(self, x, self->y_pos.i.hi);
        tile = func_80030234(self, x, self->y_pos.i.hi) & 0xFF;
        if (r == 0 && tile == 0) {
            p = self->unk68;
            if ((func_80030234(self, self->x_pos.i.hi,
                               self->y_pos.i.hi + p->unk3 + p->unk1) &
                 0xFF) == 0x3A) {
                self->x_pos.i.hi--;
            }
        }
    }
    D_800F3A2C[self->unk6](self);
    if ((s8)func_80032B34(self) < 0) {
        if (self->unk2 == 3) {
            self->dash_timer = 0x1E;
            self->unk50 = &D_800F3A1C;
            func_800477E4(3, &D_800F3A10, self);
        } else {
            func_800477E4(3, &D_800F3A0C, self);
        }
        func_80049EBC(self, 1, 0x1F, 0xF);
        self->state = 2;
        return;
    }
    if (func_8002CBFC(self, 0x80, 0x80) == 0) {
        func_8002CB50(self);
    } else if (D_800CCED0.stage != 7 || D_800CCED0.checkpoint != 1) {
        func_8002CA54(self);
    }
    func_80031F4C(self);
    func_80032BE8(self);
    func_8003208C(self);
    if (self->unk70 & 8) {
        self->air_state = 0;
        return;
    }
    if (self->y_vel.val < 0) {
        self->air_state = -1;
    } else {
        self->air_state = 1;
    }
}
