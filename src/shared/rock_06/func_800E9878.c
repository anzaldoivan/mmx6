#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define F(expr, type, offset) (*(type*)((u8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);

extern s32 D_80075B9C;
extern s8 D_800970A5;
extern s32 D_800F35A0;
extern s32 D_800F35A8[];
extern s32 D_800F35D0;
extern s32 D_800F35D4[];
extern struct X4_Unk_unk68 D_800F4018;
extern struct X4_Unk_unk68 D_800F401C;

void func_800E9878(struct X4_PlayerObj* self) {
    u8 raw;
    s32 sh;
    s32 kind;
    s32 hi;
    s32 lo;

    if (D_800970A5 != 0) {
        self->unk5 = 2;
        self->active = 0x41;
        self->invincibility_timer = 0;
        self->unk68 = (struct X4_Unk_unk68*)((s8*)self + 0x7C);
        self->state++;
        F(self, struct X4_Unk_unk68, 0x7C) = D_800F4018;
        self->unk54 = (const u32*)((s8*)self + 0x80);
        F(self, struct X4_Unk_unk68, 0x7C) = D_800F401C;
        raw = F(self, u8, 0x2);
        sh = raw << 24;
        kind = sh >> 24;
        if (kind < 0xA) {
            F(self, void*, 0x68) = &D_800F35D4[kind];
            F(self, void*, 0x54) = &D_800F35A8[kind];
        } else if (kind == 0x70) {
            F(self, s8, 0x7E) = 0x20;
            F(self, s8, 0x7F) = 8;
            F(self, s8, 0x80) = -0x20;
            F(self, s8, 0x81) = -8;
            F(self, s8, 0x82) = 0x40;
            F(self, s8, 0x7C) = 0;
            F(self, s8, 0x7D) = 0;
            F(self, s8, 0x83) = 0x10;
            F(self, void*, 0x50) = &D_800F35D0;
        } else {
            hi = (u32)sh >> 28;
            lo = raw & 0xF;
            F(self, s8, 0x7E) = hi * 8;
            F(self, s8, 0x7F) = lo * 8;
            F(self, s8, 0x7C) = 0;
            F(self, s8, 0x7D) = 0;
            F(self, s8, 0x80) = -(hi * 8);
            F(self, s8, 0x81) = -(lo * 8);
            F(self, s8, 0x82) = hi * 16;
            F(self, s8, 0x83) = lo * 16;
        }
        F(self, void*, 0x58) = &D_80075B9C;
        F(self, void*, 0x30) = &D_800F35A0;
        F(self, s8, 0x60) = 0x7F;
        F(self, s8, 0x15) = 0;
        F(self, s8, 0x65) = 0;
        F(self, s8, 0x76) = 0;
        F(self, s8, 0xA2) = 1;
        F(self, s8, 0x88) = 0;
        F(self, s8, 0x75) = 1;
        F(self, s16, 0x86) = F(self, s16, 0xE);
        set_animation(self, 0);
        F(self, s8, 0x6) = 0;
    }
}

#undef F
