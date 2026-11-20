#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/pilot_globals.h"
#include "mmx6/globals.h"
#include "mmx6/effect.h"
#include "mmx6/sound.h"
#include "mmx6/system.h"

struct X4_QuadObj* alloc_class6_slot(void);

extern HitEntry D_800737D0[];

#define SCRATCH_1C (*(u8**)SP(0x1C))

void func_800319EC(HitSelf* self, s32 mode) {
    struct X4_VisualObj* obj;
    struct X4_QuadObj* q;
    s8 idx;
    u8* tbl;

    idx = self->id;
    if (g_Player.character != 0) {
        switch (idx) {
        case 4:
            idx = 0x50;
            break;
        case 1:
        case 0x36:
            idx = 0x51;
            break;
        case 7:
        case 0x35:
            idx = 0x52;
            break;
        }
    }
    if (D_800737D0[idx].kind == 4) {
        return;
    }
    if (mode < 0) {
        if (idx == 0x17) {
            return;
        }
        if (D_800737D0[idx].flag2 != 0) {
            self->unk98 = -1;
        }
        play_sound(0, 6, self);
        idx = 0;
    } else {
        if (D_800737D0[idx].flag2 != 0) {
            if (mode == 0) {
                self->unk98 = 1;
            } else if (D_800737D0[idx].flag3 == 0) {
                self->unk98 = 1;
            }
        }
        switch (D_800737D0[idx].kind) {
        case 0:
            play_sound(1, D_800737D0[idx].sound, self);
            break;
        case 1:
            if (mode == 0) {
                play_sound(1, 9, self);
            } else {
                play_sound(1, 10, self);
            }
            break;
        case 2:
        case 3:
            play_sound(5, D_800737D0[idx].sound, self);
            break;
        case 4:
            break;
        }
        idx = D_800737D0[idx].next;
    }
    if (mode == 2) {
        return;
    }
    obj = find_free_visual_obj();
    if (obj != 0) {
        obj->active = 0x21;
        obj->id = 3;
        obj->unk2 = idx;
        if (g_Player.character == 0 && (idx == 6 || idx == 7)) {
            obj->unk2 = 3;
        }
        if (self->bg_offset < 0) {
            obj->bg_offset = 0;
        } else {
            obj->bg_offset = self->bg_offset;
        }
        tbl = SCRATCH_1C;
        obj->unk3C = tbl + *(s32*)(tbl + 4);
        obj->animation_table = g_visual_animation_tables;
        obj->unk40 = 0;
        obj->unk42 = 0x7802;
        obj->unk16 = 1;
        obj->x_pos.i.hi = self->unk80;
        obj->y_pos.i.hi = self->unk82;
        obj->unk15 = self->unk15 ^ 0x40;
    }
    if (idx == 6 || idx == 7) {
        q = alloc_class6_slot();
        if (q != 0) {
            q->active = 0x13;
            q->id = 0xF;
            switch (random_byte() % 3) {
            case 0:
                q->ext.unk38 = 0;
                break;
            case 1:
                q->ext.unk38 = 0x400;
                break;
            case 2:
                if (self->unk15 == 0x40) {
                    q->ext.unk38 = 0xE00;
                } else {
                    q->ext.unk38 = 0x200;
                }
                break;
            }
            q->x_pos.i.hi = self->unk80;
            q->y_pos.i.hi = self->unk82;
            q->unk36 = 0;
            if (self->bg_offset < 0) {
                q->bg_offset = 0;
            } else {
                q->bg_offset = self->bg_offset;
            }
            q->unk34 = 0x13;
        }
    }
}
