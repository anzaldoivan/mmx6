/* Adapted from sozud/mmx4 @807a01b src/main/player_common.c:player_entry_beam_in, AGPL-3.0; proven shared with X6 by exact signature 6b996a39570c (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
s32 play_sound(s32, s32, void*);
M2C_UNK player_set_animation(void*, M2C_UNK);

void func_8003D850(struct X4_PlayerObj* self) {
    player_set_animation(self, 1);
    ((s32(*)())play_sound)(1, 0xD, self);
    self->x_vel.val = 0;
    self->x_accel = 0;
    self->y_vel.val = FIXED(-8);
    self->gravity = 0;
    self->air_state = -1;
    self->action = PLAYER_BEAM_IN;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void start_pad_vibration(s32);
void silence_sound(u8, u8);
M2C_UNK player_set_animation(void*, M2C_UNK);
extern struct X4_EngineObj g_playthrough_state;

void func_8003D8A8(void* arg0) {
    silence_sound(1, 5);
    silence_sound(1, 7);
    start_pad_vibration(0);
    if (M2C_FIELD(arg0, s8*, 0xD5) != 0) {
        M2C_FIELD(arg0, s8*, 0x3) = 0;
        M2C_FIELD(arg0, s8*, 0xD7) = 1;
    } else {
        struct X4_EngineObj* e = &g_playthrough_state;
        e->unk12 = 1;
        e->unk13 = 1;
        e->unk14 = 1;
        e->unk15 = 1;
        e->unk16 = 1;
        e->unk17 = 1;
        e->unk18 = 1;
        e->unk19 = 1;
        e->unk1A = 1;
        M2C_FIELD(arg0, s8*, 0xD7) = 8;
        player_set_animation(arg0, 0x21);
    }
    M2C_FIELD(arg0, u8*, 0x5) += 1;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_8003D9F8(void* arg0);

void func_8003D954(u8* arg0) {
    if (--((s8*)arg0)[0xD7] == 0) {
        g_playthrough_state.unk12 = 0;
        g_playthrough_state.unk13 = 0;
        g_playthrough_state.unk14 = 0;
        g_playthrough_state.unk15 = 0;
        g_playthrough_state.unk16 = 0;
        g_playthrough_state.unk17 = 0;
        g_playthrough_state.unk18 = 0;
        g_playthrough_state.unk19 = 0;
        g_playthrough_state.unk1A = 0;
        arg0[3] = 0;
        play_sound(3, 0x10, arg0);
        play_sound(3, 0xE, arg0);
        arg0[0xD7] = 0;
        arg0[0xD6] = 0;
        arg0[5]++;
        func_8003D9F8(arg0);
    }
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 random_byte();
void func_8003DAF4(s8 direction);
void func_8003DB44(s8);

void func_8003D9F8(void* arg0) {
    u32 i;

    if (!(M2C_FIELD(arg0, u8*, 0xD7) & 3)) {
        i = 0;
        do {
            i++;
            func_8003DAF4((u8)(random_byte() & 0x1F) | 0x80);
        } while (i < 4);
    }
    if (M2C_FIELD(arg0, s8*, 0xD6) != 3) {
        if (M2C_FIELD(arg0, s8*, 0xD7) == 0) {
            func_8003DB44(M2C_FIELD(arg0, s8*, 0xD6));
            if (M2C_FIELD(arg0, s8*, 0xD6) == 2) {
                func_8003DB44(3);
            }
            M2C_FIELD(arg0, u8*, 0xD7) = 0x12;
            M2C_FIELD(arg0, u8*, 0xD6) = M2C_FIELD(arg0, u8*, 0xD6) + 1;
            return;
        }
        M2C_FIELD(arg0, u8*, 0xD7) = M2C_FIELD(arg0, u8*, 0xD7) - 1;
        return;
    }
    M2C_FIELD(arg0, u8*, 0xD7) = 0x14;
    M2C_FIELD(arg0, u8*, 5) = M2C_FIELD(arg0, u8*, 5) + 1;
}

#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8003DACC(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0xD7) != 0) {
        M2C_FIELD(arg0, s8*, 0xD7) = (s8)((u8)M2C_FIELD(arg0, s8*, 0xD7) - 1);
        return;
    }
    M2C_FIELD(arg0, s8*, 4) = 3;
    M2C_FIELD(arg0, s8*, 5) = 0;
}

/* Adapted from sozud/mmx4 @807a01b src/main/player_common.c:player_spawn_death_orb, AGPL-3.0; proven shared with X6 by exact signature 76c0b9feb772 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void* alloc_sprite_slot();

void func_8003DAF4(s8 direction) {
    struct X4_MiscObj* obj;

    obj = alloc_sprite_slot();
    if (obj != NULL) {
        obj->active = 0x21;
        obj->id = 0x11;
        obj->unk2 = direction;
        obj->state = 0;
        obj->unk5 = 0;
        obj->unk6 = 0;
    }
}

#include "common.h"

void* alloc_sprite_slot();
extern s8 D_80073D30[][8];

void func_8003DB44(s8 arg0) {
    s8(*base)[8];
    s8* tbl;
    u8* obj;
    u32 i;
    s8 v;
    u8 a;
    u8 b;

    base = D_80073D30;
    i = 0;
    a = 0x21;
    tbl = base[arg0];
    b = 0x11;
    do {
        v = *tbl;
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = a;
            obj[1] = b;
            obj[2] = v;
            obj[4] = 0;
            obj[5] = 0;
            obj[6] = 0;
        }
        i++;
        tbl++;
    } while (i < 8);
}
