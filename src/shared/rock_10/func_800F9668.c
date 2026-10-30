#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj g_playthrough_state;

void func_800F9668(struct X4_MainObj* self) {
    s8 st;

    st = M2C_FIELD(self, s8*, 0x45);
    if (st == 1) {
        struct X4_EngineObj* e = &g_playthrough_state;

        if (e->stage != 0xC) {
            open_text_box(0, 0xFF, M2C_FIELD(e, u8*, 0x2E));
            M2C_FIELD(e, u8*, 0x2E) = st;
        }
        self->unk6++;
    }
}
