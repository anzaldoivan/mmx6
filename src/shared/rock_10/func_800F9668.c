#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80021760(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj D_800CCED0;

void func_800F9668(struct X4_MainObj* self) {
    s8 st;

    st = M2C_FIELD(self, s8*, 0x45);
    if (st == 1) {
        struct X4_EngineObj* e = &D_800CCED0;

        if (e->stage != 0xC) {
            func_80021760(0, 0xFF, M2C_FIELD(e, u8*, 0x2E));
            M2C_FIELD(e, u8*, 0x2E) = st;
        }
        self->unk6++;
    }
}
