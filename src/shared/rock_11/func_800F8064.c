#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_80049E50(void*);
extern void (*D_800FD438[])(void*);

void func_800F8064(struct X4_BaseObj* self) {
    s32 v = M2C_FIELD(M2C_FIELD(self, void**, 0x80), s8*, 4);

    if (v != 1) {
        self->state = 6;
        self->on_screen = 0;
        return;
    }
    func_80017A04(self);
    (*(void (**)(void*))((self->unk5 << 2) + (s32)D_800FD438))(self);
    if (func_80031474(self) < 0) {
        func_80049E50(self);
        self->on_screen = 0;
        self->state = 6;
        self->unk5 = 0;
        return;
    }
    func_80030ECC(self);
    if (func_8002CBFC(self, 0x20, 0x20) == v) {
        self->on_screen = 0;
        self->state = 6;
    }
}
