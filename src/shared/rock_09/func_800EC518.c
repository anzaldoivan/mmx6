/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_32_bomb_bat.c:bomb_bat_drop_release, AGPL-3.0; proven shared with X6 by exact signature b8c90aca8278 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void func_800ECAA0(struct X4_MainObj*);

#define M2C_UNK s32
M2C_UNK func_80017A04();
void func_800EC518(struct X4_MainObj* self) {
    ((void (*)())func_80017A04)(ANIMATED_OBJECT(self));
    if (--self->ext.main_32.unk80 == 0) {
        self->ext.main_32.unk88 = 1;
        func_800ECAA0(self);
        self->ext.main_32.unk80 = 13;
        self->unk6++;
    }
}
