#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define UB(p, off) (*(u8*)((u8*)(p) + (off)))
#define F32(p, off) (*(s32*)((u8*)(p) + (off)))
#define PTR(p, off) (*(void**)((u8*)(p) + (off)))

extern struct X4_BackgroundObj D_800971F8[3];
extern s32 D_80097420;
M2C_UNK func_80017A04();
s8* func_8002BEC4(s8* p, s32 dir);
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
M2C_UNK func_8002D2B0(void*);

void func_80044D04(struct X4_BaseObj* self) {
    s8* child;
    s16 dx;
    s16 dy;
    s32 out;
    s32 n;
    u8 t;

    if (self->unk2 == 0) {
        UB(self, 0x8D) += 1;
        t = UB(self, 0x8D);
        if (!(t & 7)) {
            child = func_8002BEC4((s8*)self, 0);
            if (child != 0) {
                child[0] = self->active;
                child[1] = self->id;
                child[2] = 1;
                PTR(child, 0x7C) = self;
                child[0x15] = self->unk15;
                UB(self, 0x8C)++;
            }
            if ((UB(self, 0x8D) >> 3) == 8) {
                self->state = 2;
            }
        }
    } else {
        if (!(D_80097420 & 3)) {
            UB(self, 0x64)++;
        }
        func_80017A04(self);
        func_8002D2B0(self);
        out = 0;
        dx = self->x_pos.i.hi - D_800971F8[self->bg_offset].x_pos.i.hi;
        dy = self->y_pos.i.hi - D_800971F8[self->bg_offset].y_pos.i.hi;
        if (self->unk15 != 0) {
            n = dx - 0x20;
            out = n >= 0x141;
        } else if ((dx + 0x20) < 0) {
            out = 1;
        }
        if ((dy - 0x38) >= 0xF1) {
            out = 1;
        }
        if (out != 0) {
            F32(self, 0x50) = 0;
            self->on_screen = 0;
            self->state = 2;
        }
        func_8002CCB0(self, 0x20, 0x20);
    }
}
