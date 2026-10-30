#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049E50(void*);
extern M2C_UNK D_800F7684;

void func_800F31A4(struct X4_BaseObj* self) {
    if (M2C_FIELD(self, struct X4_BaseObj**, 0x80)->state != 1) {
        self->state = 5;
        self->on_screen = 0;
        return;
    }
    func_80017A04(self);
    (*(void (**)(struct X4_BaseObj*))((self->unk5 << 2) + (s32)&D_800F7684))(
        self);
    if (check_enemy_hits(self) < 0) {
        func_80049E50(self);
        self->on_screen = 0;
        self->state = 5;
        self->unk5 = 0;
        return;
    }
    func_80030ECC(self);
    func_8002CCB0(self, 0x20, 0x20);
    {
        // !FAKE: depin: dropping it breaks the match (47/50)
        register struct X4_BaseObj* parent asm("$2") =
            M2C_FIELD(self, struct X4_BaseObj**, 0x80);
        M2C_FIELD(self, u8*, 0x84) = M2C_FIELD(parent, u8*, 0x5);
    }
}
