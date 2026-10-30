#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern struct X4_EngineObj g_playthrough_state;
extern u16* D_800F7DF0;
#define D_800F7DF0 (*(s16**)&D_800F7DF0)
extern s16 D_800F7E0C;
extern s16 D_800F7E0E;

void func_800F43F4(struct X4_MainObj* self) {
    if (D_800F7E0C == *D_800F7DF0 * 2) {
        struct X4_EngineObj* e = &g_playthrough_state;
        if (e->stage != 0xC) {
            open_text_box(0, 0xFF, e->character_state.bytes[8]);
            e->character_state.bytes[8] = 1;
        }
        D_800F7E0E = 2;
        self->unk7C = 0;
        self->unk6++;
    }
    func_80017A04(self);
    func_8002D230(self);
    func_8002CCB0(self, 0x40, 0x40);
}
#undef D_800F7DF0
