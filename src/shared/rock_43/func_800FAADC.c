#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern s16 D_800970AA;
extern s32 D_800FDE30;
extern s16 D_800FE284;
extern s16 D_800FE286;

void func_800FAADC(struct X4_MainObj* self) {
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
            // !FAKE: depin: dropping it breaks the match (78/136)
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
            play_sound(2, 0x99, self);
            if (D_800970AA > (D_800FE284 + D_800FE286) / 2) {
                self->unk15 = 0x40;
                M2C_FIELD(self, u16*, 0x88) = (u16)D_800FE284 + 0x20;
            } else {
                self->unk15 = 0;
                M2C_FIELD(self, u16*, 0x88) = (u16)D_800FE286 - 0x20;
            }
        }
        {
            u8* b;
            s32 i;
            i = self->unk7C - 0x7E;
            b = (u8*)&D_800FDE30 + 0x2E4;
            {
                // !FAKE: depin: dropping it breaks the match (37/136)
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
                // !FAKE: depin: dropping it breaks the match (134/136)
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
        set_animation(self, 7);
        self->unk7C = 0x3C;
        self->unk7E = 0;
        self->unk6++;
        func_8002CCB0(self, 0x40, 0x40);
        func_80017A04(self);
        func_8002D230(self);
    }
    self->unk7C++;
}
