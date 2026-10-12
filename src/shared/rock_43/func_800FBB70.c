#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04(void*);
void* func_8002C458();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D2B0(void*);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_80049E50(void*);
extern s32 D_800FDE30;
extern s32 D_800FE208;
extern s32 D_800FE20C;
extern s16 D_800FE28E;
extern s32 D_800FE290;
extern s32 D_800FE294;

void func_800FBB70(struct X4_MainObj* self) {
    if (D_800FE290 != 0 || D_800FE294 != 0) {
        self->state++;
        return;
    }
    if (func_80031474(self) < 0) {
        func_80049E50(self);
        self->state++;
        return;
    }
    func_80030ECC(self);
    switch (self->unk5) {
    case 0:
        if (--M2C_FIELD(self, s32*, 0x90) == 0) {
            struct X4_MainObj* o = func_8002C458();
            if (o != 0) {
                u8 a = self->active;
                o->id = 0x13;
                o->unk2 = 7;
                o->active = a;
                M2C_FIELD(o, s32*, 0x7C) = M2C_FIELD(self, s32*, 0x7C);
                o->x_pos.i.hi = self->x_pos.i.hi;
                o->y_pos.i.hi = self->y_pos.i.hi + 0xC;
            }
            M2C_FIELD(self, s32*, 0x90) = 0;
            self->unk5++;
        }
        break;
    case 1:
        if (++M2C_FIELD(self, s32*, 0x90) == 4) {
            func_800179A4(self, 0xD);
            {
                register void* a asm("$2") = &D_800FE208;
                register void* b asm("$3") = &D_800FE20C;
                self->attack_box = a;
                self->hurt_box = b;
            }
            self->y_speed = 0x60000;
            self->unk5++;
        }
        break;
    case 2:
        if (self->y_pos.i.hi < D_800FE28E) {
            self->state++;
        }
        func_8002CCB0(self, 0x20, 0x30);
        break;
    }
    func_80017A04(self);
    func_8002D2B0(self);
}
