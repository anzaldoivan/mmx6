#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04(void*);
void* func_8002C458();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern u8 D_800CCF5F;
extern u8 D_800FA000[];
extern s32 D_800FDE30;

void func_800FACFC(struct X4_MainObj* self) {
    u8 tbl[4];

    __builtin_memcpy(tbl, D_800FA000 + 8, 4);
    if (M2C_FIELD(self, s8*, 0x45) == 1) {
        struct X4_MainObj* o;
        M2C_FIELD(self, s8*, 0x45) = 0;
        o = func_8002C458();
        if (o != 0) {
            u8 a = self->active;
            o->id = 0x13;
            o->unk2 = 9;
            M2C_FIELD(o, void**, 0x7C) = self;
            o->active = a;
        }
    }
    if (M2C_FIELD(self, s8*, 0x45) == 2) {
        struct X4_MainObj* o;
        M2C_FIELD(self, s8*, 0x45) = 0;
        o = func_8002C458();
        if (o != 0) {
            u8 a = self->active;
            o->id = 0x13;
            o->unk2 = 8;
            M2C_FIELD(o, void**, 0x7C) = self;
            o->active = a;
        }
    }
    if (M2C_FIELD(self, s8*, 0x46) == 0) {
        set_animation(self, 0);
    }
    if (self->unk7C == 0) {
        if (++self->unk7E == tbl[D_800CCF5F]) {
            set_animation(self, 0);
            {
                u8* b = ((u8*)&D_800FDE30 + 0x284);
                u8 i = M2C_FIELD(self, u8*, 0x87)++;
                s32 m = M2C_FIELD(self, u8*, 0x86) * 6;
                u8 v = b[i + m];
                self->unk6 = 0;
                self->unk5 = v;
            }
        } else {
            set_animation(self, 7);
            if (self->unk7E == 2) {
                self->unk7C = 0x78;
            } else {
                self->unk7C = 0x3C;
            }
        }
    }
    self->unk7C--;
    func_8002CCB0(self, 0x40, 0x40);
    func_80017A04(self);
    func_8002D230(self);
}
