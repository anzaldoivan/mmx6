#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern struct X4_PlayerObj g_Player;
extern s32 D_800FDE30;

void func_800FA8B4(struct X4_MainObj* self) {
    s16 t;

    t = self->unk7C;
    if (t < 0x32) {
        if (!(self->unk7C & 1)) {
            func_8002CCB0(self, 0x40, 0x40);
        }
        func_8002D230(self);
    } else if ((u16)(self->unk7C - 0x32) < 0x10) {
        if (t == 0x32) {
            set_animation(self, 2);
            play_sound(2, 0x99, self);
            M2C_FIELD(self, u16*, 0x88) = M2C_FIELD(self, u16*, 0xA);
        }
        {
            u8* b;
            s32 i;
            // !FAKE: depin: dropping it breaks the match (73/138)
            register s32 k asm("$3") = self->unk7C;
            b = (u8*)&D_800FDE30 + 0x2E4;
            i = 0x41 - k;
            {
                s32 u = M2C_FIELD(self, u16*, 0x88);
                s32 w = *(u16*)(b + i * 2);
                M2C_FIELD(self, u16*, 0xA) = u + w;
            }
        }
        func_8002CCB0(self, 0x40, 0x40);
        func_80017A04(self);
        func_8002D230(self);
    } else if (t < 0x7E) {
    } else if ((u16)(self->unk7C - 0x7E) < 0x10) {
        if (t == 0x7E) {
            if (g_Player.x_pos.i.hi > M2C_FIELD(self, s16*, 0xA)) {
                self->unk15 = 0x40;
            } else {
                self->unk15 = 0;
            }
            play_sound(2, 0x99, self);
            M2C_FIELD(self, u16*, 0x88) = g_Player.x_pos.i.hi;
        }
        {
            u8* b;
            s32 i;
            i = self->unk7C - 0x7E;
            b = (u8*)&D_800FDE30 + 0x2E4;
            {
                // !FAKE: depin: dropping it breaks the match (38/138)
                register s32 u asm("$3") = M2C_FIELD(self, u16*, 0x88);
                s32 w = *(u16*)(b + i * 2);
                M2C_FIELD(self, u16*, 0xA) = u + w;
            }
        }
        func_8002CCB0(self, 0x40, 0x40);
        func_80017A04(self);
        func_8002D230(self);
    } else if (t < 0xC0) {
        if (t == 0x8E) {
            set_animation(self, 0);
            {
                // !FAKE: depin: dropping it breaks the match (136/138)
                register s32 c asm("$2") = M2C_FIELD(self, u16*, 0x88);
                M2C_FIELD(self, u16*, 0xA) = c;
            }
        }
        if (!(self->unk7C & 1)) {
            func_8002CCB0(self, 0x40, 0x40);
        }
        func_8002D230(self);
    } else {
        M2C_FIELD(self, s16*, 0x8A) = 0;
        {
            u8* tb = (u8*)&D_800FDE30 + 0x284;
            u8* q = tb + (M2C_FIELD(self, u8*, 0x87)++ +
                          M2C_FIELD(self, u8*, 0x86) * 6);
            self->unk5 = *q;
        }
        self->unk6 = 0;
        func_8002CCB0(self, 0x40, 0x40);
        func_80017A04(self);
        func_8002D230(self);
    }
    self->unk7C++;
}
