#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);

extern s8 D_800950A0[];
extern struct X4_PlayerObj g_Player;

#define ABS(v) ((v) < 0 ? -(v) : (v))
#define OBJ(p) ((struct X4_BaseObj*)(p))

void func_800F13A4(struct X4_BaseObj* self) {
    s8* p;

    if (M2C_FIELD(self, s8*, 0x67) != 0) {
        return;
    }
    if (M2C_FIELD(self, u8*, 0x80) & 1) {
        return;
    }
    if (M2C_FIELD(self, u8*, 0x82) != 0) {
        M2C_FIELD(self, u8*, 0x82)--;
        return;
    }
    for (p = D_800950A0; p < D_800950A0 + 0x1400; p += 0xA0) {
        if (OBJ(p)->active == 0 || OBJ(p)->id != 0) {
            continue;
        }
        if (self->unk15 != 0) {
            struct X4_PlayerObj* pl = &g_Player;
            if (pl->unk15 == 0 && self->x_pos.val < pl->x_pos.val &&
                ABS(OBJ(p)->y_pos.i.hi - self->y_pos.i.hi) < 0x18 &&
                OBJ(p)->x_pos.i.hi < self->x_pos.i.hi + 0x80) {
                M2C_FIELD(self, u8*, 0x80) |= 1;
            }
        } else {
            struct X4_PlayerObj* pl = &g_Player;
            if (pl->unk15 != 0 && self->x_pos.val > pl->x_pos.val &&
                ABS(OBJ(p)->y_pos.i.hi - self->y_pos.i.hi) < 0x18 &&
                self->x_pos.i.hi - 0x80 < OBJ(p)->x_pos.i.hi) {
                M2C_FIELD(self, u8*, 0x80) |= 1;
            }
        }
        if (M2C_FIELD(self, u8*, 0x80) & 1) {
            self->unk5 = 3;
            self->unk6 = 0;
            func_800179A4(self, 5);
            return;
        }
    }
}
