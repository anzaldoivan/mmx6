#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
M2C_UNK clear_object_slot();
s32 is_off_screen();
void func_8002CCB0();
#define set_animation ((void (*)(void*, s32))set_animation)
#define animate_object ((void (*)(void*))animate_object)
extern u8 D_80077C18[];
extern s32 D_80077C2C[][2];
extern s16 D_80077CB4[][2];
extern struct X4_PlayerObj g_Player;

#define PLAYER_B(o) (((s8*)player)[o])

void func_80049A14(struct X4_MainObj* self) {
    struct X4_PlayerObj* player = &g_Player;
    s32 flag;
    u8 side;

    if (player->action == 0x14) {
        ((M2C_UNK(*)())clear_object_slot)();
        return;
    }
    if (self->unk2 == 0x10) {
        flag = player->hp == 0;
        if (PLAYER_B(0xD3) != 0) {
            flag = 1;
        }
        if (PLAYER_B(0xCF) != 0) {
            flag = 1;
        }
        if (self->hp != player->unk17) {
            flag = 1;
        }
        if (self->unk15 != player->facing && (u8)self->unk5D - 0x18 < 3U) {
            flag = 1;
        }
        if (self->state == 0) {
            set_animation(self, D_80077C18[self->unk2]);
            self->on_screen = 1;
            self->state++;
        }
        animate_object(self);
        if (self->animation_step.fields.relative_step == 0) {
            flag = 1;
        }
        if (flag != 0) {
            ((M2C_UNK(*)())clear_object_slot)(self);
            return;
        }
        side = player->facing;
        self->unk15 = side;
        if (side == 0) {
            self->x_pos.i.hi =
                player->x_pos.i.hi - D_80077CB4[self->unk5D - 0x18][0];
        } else {
            self->x_pos.i.hi =
                player->x_pos.i.hi + D_80077CB4[self->unk5D - 0x18][0];
        }
        self->y_pos.i.hi =
            player->y_pos.i.hi + D_80077CB4[self->unk5D - 0x18][1];
        return;
    }
    switch (self->state) {
    case 0:
        self->on_screen = 1;
        set_animation(self, D_80077C18[self->unk2]);
        self->state++;
        if ((u8)self->unk2 - 8 < 2U) {
            self->unk16 = 0x11;
        }
        func_8002CCB0(self, D_80077C2C[self->unk2][0],
                      D_80077C2C[self->unk2][1]);
        break;
    case 1:
        if (is_off_screen(self, D_80077C2C[self->unk2][0],
                          D_80077C2C[self->unk2][1]) == 0) {
            animate_object(self);
            if (self->unk2 == 9 && self->animation_step.fields.event != 0) {
                self->animation_step.fields.event = 0;
                player->unkDF = 0;
            }
            if (self->unk2 == 0xE) {
                self->x_pos.val = player->x_pos.val;
                self->y_pos.val = player->y_pos.val;
                if (player->action != 0x3E ||
                    (player->animation_step.fields.event & 0x80)) {
                    self->state = 2;
                    self->on_screen = 0;
                }
            } else if (self->animation_step.fields.relative_step < 0) {
                // !FAKE: joins the set2 block shared with the earlier arm
                goto set2;
            }
        } else {
        set2:
            self->state = 2;
        }
        func_8002CCB0(self, D_80077C2C[self->unk2][0],
                      D_80077C2C[self->unk2][1]);
        break;
    case 2:
        ((M2C_UNK(*)())clear_object_slot)(self);
        break;
    }
}
#undef PLAYER_B
#undef animate_object
#undef set_animation
