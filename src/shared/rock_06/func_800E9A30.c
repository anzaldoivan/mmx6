#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80031DA8();
void func_80031F4C(struct X4_PlayerObj*);
M2C_UNK func_8003208C();
s32 func_80032B34(struct X4_PlayerObj*);
void func_80032BE8(struct X4_PlayerObj*);

extern M2C_UNK D_800970A0;
#define PLAYER (*(struct X4_PlayerObj*)&D_800970A0)
extern struct X4_EngineObj D_800CCED0;
extern void (*D_800F3608[])(struct X4_PlayerObj*);

#define ABS(v) ((v) < 0 ? -(v) : (v))
#define PL_E5 M2C_FIELD(&PLAYER, u8*, 0xE5)

#define GROUND(self)                                                           \
    {                                                                          \
        struct X4_PlayerObj* pl = &PLAYER;                                     \
        if (M2C_FIELD(pl, u8*, 0xE5) == 0) {                                   \
            func_80031DA8(self);                                               \
            if (D_800CCED0.character_state.fields.flags != 0 &&                \
                (self->unk72 & 4) && (pl->unk70 & 8)) {                        \
                pl->unk71 = 0;                                                 \
            }                                                                  \
            if (self->unk76 != 0 && (self->unk72 & 3)) {                       \
                y = PLAYER.y_pos.val;                                          \
                PLAYER.y_pos.val = y - PLAYER.y_vel.val;                       \
                func_80031DA8(self);                                           \
                if (self->unk76 == 0) {                                        \
                    PLAYER.y_pos.val -= PLAYER.y_vel.val;                      \
                } else {                                                       \
                    PLAYER.y_pos.val = y;                                      \
                }                                                              \
            }                                                                  \
        }                                                                      \
    }

void func_800E9A30(struct X4_PlayerObj* self) {
    s32 y;

    if (D_800CCED0.stage == 4) {
        if (self->y_pos.i.hi >= 0x2A0 && D_800CCED0.checkpoint == 0 &&
            D_800CCED0.substage == 0) {
            return;
        }
    } else if (D_800CCED0.stage < 0x13 && D_800CCED0.checkpoint != 2) {
        return;
    }
    {
        func_80032B34(self);
        if (PLAYER.nova_strike_active != 2) {
            D_800F3608[self->unk6](self);
        }
        func_8002CCB0(self, 0xA0, 0xA0);
        if (D_800CCED0.substage == 0 && self->unk2 == 0) {
            GROUND(self)
            func_80032BE8(self);
            func_8003208C(self);
            ((void (*)())func_80031F4C)(self);
            self->on_screen = 0;
            return;
        }
        if (ABS(PLAYER.x_pos.i.hi - self->x_pos.i.hi) < 0xA0 &&
            self->on_screen == 1) {
            GROUND(self)
        }
        func_80032BE8(self);
        func_8003208C(self);
        ((M2C_UNK(*)())func_80031F4C)(self);
        self->on_screen = 0;
    }
}
