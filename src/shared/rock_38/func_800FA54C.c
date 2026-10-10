#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);

extern M2C_UNK D_8007433C;
extern s32 D_800755FC;
extern s8 D_8009711A;
extern s32 D_800FE830;
extern s32 D_800FE834;
extern s32 D_800FE838;
extern s32 D_800FE83C;
extern s32 D_800FE840;
extern void (*D_800FECC0[])(struct X4_MainObj*);
extern s32 D_800FEEC4;
extern s32 D_800FEEC8;
extern u16 D_800FEECC;
extern s16 D_800FEED0;
extern s32 D_800FEED8;

#define TIMER M2C_FIELD(self, u8*, 0x84)

void func_800FA54C(struct X4_MainObj* self) {
    s32 r;
    u8 t;

    if (self->unk5 == 9) {
        self->hurt_box = &D_800FE840;
        self->collision_data = &D_8007433C;
        r = func_80031474(self);
    } else if (D_800FEED0 == 3) {
        self->hurt_box = &D_800FE840;
        if (TIMER == 0) {
            self->collision_data = &D_800755FC;
        }
        r = func_80031474(self);
    } else if ((t = self->unk17) == 0x1E || t == 0x1C || t == 0x1D ||
               t == 0xD || t == 0x10) {
        self->hurt_box = &D_800FE840;
        self->collision_data = &D_8007433C;
        r = func_80031474(self);
    } else {
        self->hurt_box = &D_800FE838;
        self->collision_data = &D_8007433C;
        r = func_80031474(self);
        if (r == 0) {
            if (TIMER != 0) {
                self->collision_data = &D_8007433C;
            } else {
                self->collision_data = &D_800755FC;
            }
            self->hurt_box = &D_800FE83C;
            r = func_80031474(self);
        } else {
            TIMER = 1;
        }
    }
    if (r < 0) {
        func_80016C48(2, 0x14, self);
        func_80016C48(2, 0x20, self);
        self->state = 2;
        self->x_speed = 0;
        self->y_speed = 0;
        self->x_accel = 0;
        self->gravity = 0;
        self->unk5 = 0;
        self->unk6 = 0;
        self->unk42 &= 0x7FFF;
        {
            register s32 one asm("$3");
            D_800FEEC4 = one = 1;
            D_8009711A = one;
        }
        func_8002CCB0(self, 0x80, 0x80);
        return;
    }
    if (self->unk5 != 9) {
        if (self->unk17 == 0x1E) {
            self->attack_box = &D_800FE834;
        } else {
            self->attack_box = &D_800FE830;
        }
        func_80030ECC(self);
    }
    if (r > 0 && r != 0x7F) {
        if ((u32)(r - 0x19) < 2) {
            TIMER = 2;
        } else {
            TIMER = 0x1E;
        }
        self->collision_data = &D_8007433C;
    }
    if (r == 3 || r == 0xC || r == 0x22) {
        func_80016C48(2, 0x14, self);
        func_80016C48(2, 0x21, self);
        func_80016C48(2, 0x78, self);
        D_800FEEC8 = 1;
        self->unk5 = 9;
        self->unk6 = 0;
    }
    t = TIMER;
    if (t != 0) {
        TIMER = t + 0xFF;
        if (t & 2) {
            self->unk42 |= 0x8000;
        } else {
            self->unk42 &= 0x7FFF;
        }
        if (TIMER == 0) {
            self->collision_data = &D_800755FC;
            self->unk42 &= 0x7FFF;
        }
    }
    D_800FEECC = self->unk42 & 0x8000;
    D_800FECC0[self->unk5](self);
    if (self->unk5 != 2) {
        D_800FEED8++;
    }
    if (D_800FEECC != 0) {
        self->unk42 |= D_800FEECC;
    } else {
        self->unk42 &= 0x7FFF;
    }
}
#undef TIMER
