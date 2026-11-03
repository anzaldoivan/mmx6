// prog SLUS_013.95 | system cling | range 0x80047460-0x80047558
#include "common.h"
#include "mmx6/globals.h"
#include "mmx6/x4.h"
#include "mmx6/movement.h"
#include "mmx6/sound.h"
#define M2C_UNK s32

// 0x80047460 move_ceiling: ceiling movement step.
// basis: community tweaks-index.tsv:253
// callers: none known
void move_ceiling(void* arg0) {
    struct X4_MainObj* self = arg0;

    if (D_800CCEF6 != 0) {
        s32 v;

        func_80029478(0x3C, 2, 2);
        v = self->unk18.val;
        *(s16*)&self->unk16 = 0x500000 / (v < 0 ? -v : v);
        self->action = 5;
        self->unk18.val = -0x10000;
        *(u16*)&self->bg_offset = 0x32;
        self->x_speed = self->unk1C.val;
        return;
    }
    if (--*(s16*)&self->bg_offset == 0) {
        s32 a;

        a = self->unk18.val;
        *(s16*)&self->unk16 = 0x500000 / (a < 0 ? -a : a);
        if (a > 0) {
            self->action = 2;
            return;
        }
        self->action = 3;
        play_sound(2, 0x22, arg0);
    }
}
