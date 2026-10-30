#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002F288(M2C_UNK*);
M2C_UNK func_80030ECC();
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(struct X4_BaseObj* arg0, s8 arg1);
void func_800EA704(struct X4_BaseObj* self);
void func_800EA840(struct X4_BaseObj* self);
void func_800EA9E0(struct X4_BaseObj* self);

extern M2C_UNK D_800F37D4;
extern void (*D_800F37D8[])(struct X4_BaseObj*);

void func_800EAE48(struct X4_BaseObj* self) {
    s32 r;
    u8 f;
    s32 v;

    M2C_FIELD(self, s32*, 0x18) = M2C_FIELD(self, s32*, 0x8);
    M2C_FIELD(self, s32*, 0x1C) = M2C_FIELD(self, s32*, 0xC);
    func_800EA840(self);
    func_800EA704(self);
    func_800EA9E0(self);
    D_800F37D8[self->unk5](self);
    ((void (*)(void*))func_80030ECC)(self);
    r = check_enemy_hits(self);
    if (r < 0) {
        ((void (*)(void*))func_80049E50)(self);
        ((void (*)(s32, s32*, void*))func_800477E4)(4, &D_800F37D4, self);
        if (r != -0x38) {
            func_8004E654(self, 0x12);
        }
        v = M2C_FIELD(self, u8*, 4) + 1;
        goto set_state;
    }
    if (func_8002CBFC(self, 0x40, 0x40) != 0) {
        self->state = 4;
        return;
    }
    ((void (*)(void*, s32, s32))func_8002CCB0)(self, 0x25, 0x25);
    f = M2C_FIELD(self, u8*, 0x70);
    if ((f & 0xC) == 0xC || (f & 3) == 3) {
        ((void (*)(void*))func_80049E50)(self);
        ((void (*)(s32, s32*, void*))func_800477E4)(4, &D_800F37D4, self);
        self->on_screen = 0;
        v = M2C_FIELD(self, u8*, 4) + 1;
    set_state:
        self->state = v;
        return;
    }
    ((void (*)(void*))func_8002F288)(self);
}
