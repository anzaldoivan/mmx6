#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
void* alloc_class4_slot();
M2C_UNK func_8002CA14();
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
void func_8002F288(struct X4_PlayerObj*);
void func_80051828(struct X4_PlayerObj* arg0, s8 arg1, s8 arg2);
extern s32 D_80075B9C;
extern s32 D_80078DF8;
extern s32 D_80078E00;
extern u8 capsule_parts[];
extern s8 D_80078E10[];
extern s32 D_800791A0;
extern u32* D_80095098;
extern struct X4_PlayerObj g_Player;
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800CCF2F;

// 0x80051158 init_capsule: capsule appearance checks parts.
// basis: community tweaks-index.tsv:219
// callers: func_800515B4
void init_capsule(struct X4_MainObj* self) {
    struct X4_PlayerObj* p;
    s32 f;
    s32 i;
    s8 t;
    void* c;

    p = &g_Player;
    f = 0;
    if (self->unk2 == 8) {
        if (p->unk2 == 0) {
            if (D_800CCF2F & 8) {
                f = 1;
            }
            if (M2C_FIELD(p, u8*, 0xE7) != 0) {
                f = 1;
            }
        } else if (D_800CCF2F & 0x20) {
            f = 1;
        }
    } else {
        {
            struct X4_EngineObj* e = &g_playthrough_state;
            if (M2C_FIELD(e, u8*, 0x5F) & 4) {
                if (capsule_parts[self->unk2] & 0xF) {
                    f = 1;
                }
            }
        }
        {
            struct X4_EngineObj* e = &g_playthrough_state;
            if ((M2C_FIELD(e, u8*, 0x5F) & 2) &&
                (capsule_parts[(s8)M2C_FIELD(self, u8*, 2)] & 0xF0)) {
                f = 1;
            }
        }
        {
            struct X4_EngineObj* e = &g_playthrough_state;
            if (M2C_FIELD(e, u8*, 0x69) &
                capsule_parts[(s8)M2C_FIELD(self, u8*, 2)]) {
                f = 1;
            }
        }
    }
    if (f != 0) {
        func_8002CA14(self);
        return;
    }
    M2C_FIELD(self, u8*, 0xA2) = 1;
    self->collision_data = &D_80075B9C;
    self->on_screen = 1;
    self->active |= 8;
    self->bg_offset = g_Player.bg_offset;
    self->terrain_box = (struct X4_Unk_unk68*)&D_80078DF8;
    self->hurt_box = &D_80078E00;
    self->animation_table = (const u8* const*)&D_800791A0;
    i = func_8002A47C(0x80);
    self->sprite_frames = (const u8*)SPAD20 + SPAD20[i];
    self->unk40 = D_80095098[i] >> 7;
    self->unk42 = ((i * 4 + 0x20) % 16) | (((i + 8) / 4 + 0x1E0) << 6);
    self->unk16 = 4;
    self->unk15 = 0;
    self->unk75 = 1;
    M2C_FIELD(&g_Player, u8*, 0xE2) = 0;
    ((void (*)(void*, s32))set_animation)(self, 0);
    {
        // !FAKE: depin: dropping it breaks the match (202/206)
        register void* a asm("$4");

        a = self;
        while (func_8002F288(a), a = self, !(self->collision_flags & 8)) {
            M2C_FIELD(self, u16*, 0xE) += 0x10;
        }
        c = alloc_class4_slot(a);
    }
    if (c != 0) {
        M2C_FIELD(c, u8*, 0) = 9;
        M2C_FIELD(c, u8*, 1) = 0x1A;
        M2C_FIELD(c, u8*, 2) = 0x10;
        M2C_FIELD(c, u8*, 0x14) = self->bg_offset;
        M2C_FIELD(c, void**, 0x7C) = self;
    }
    t = self->unk2;
    if (t == 8) {
        if (g_Player.unk2 == 0) {
            func_80051828(self, 0x23, 0x10);
        } else {
            func_80051828(self, 0x23, 0x11);
        }
    } else {
        func_80051828(self, 0x23, D_80078E10[t]);
    }
    self->unk5 = 0;
    self->state++;
    func_8002CCB0(self, 0x88, 0x88);
}
