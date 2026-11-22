// rolefeed (3.1 T4): func_800EC518 of src/rock_09/E9860.c
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_PlayerObj g_Player;

void func_800E9970(s8* self, s8* parent);
void func_800E9A60(struct X4_VisualObj* arg0, struct X4_PlayerObj* arg1);

/* Adapted from sozud/mmx4 @4e16dfc src/main/mains/main_32_bomb_bat.c:bomb_bat_drop_release, AGPL-3.0; proven shared with X6 by exact signature b8c90aca8278 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void func_800ECAA0(struct X4_MainObj*);

#define M2C_UNK s32
M2C_UNK animate_object();
void func_800EC518(struct X4_MainObj* self) {
    ((void (*)())animate_object)(ANIMATED_OBJECT(self));
    if (--self->ext.main_32.unk80 == 0) {
        self->ext.main_32.unk88 = 1;
        func_800ECAA0(self);
        self->ext.main_32.unk80 = 13;
        self->action_phase++;
    }
}
