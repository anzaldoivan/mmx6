/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_32_bomb_bat.c:bomb_bat_hover, AGPL-3.0; proven shared with X6 by exact signature 404516d3d41d (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern void (*D_801F3738[])(struct X4_MainObj*);
void func_80017A04(struct X4_AnimatedObj*);

void func_801EB968(struct X4_MainObj* self) {
    func_80017A04(self);
    D_801F3738[self->unk6](self);
}
