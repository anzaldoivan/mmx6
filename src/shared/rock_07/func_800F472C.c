#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern struct X4_EngineObj g_playthrough_state;

void func_800F472C(struct X4_PlayerObj* arg0) {
    if (arg0->unk70 & 8) {
        ((void (*)(s32, s32, void*))play_sound)(2, 0x5C, arg0);
        ((void (*)(void*, s32))set_animation)(arg0, 7);
        {
            struct X4_EngineObj* e = &g_playthrough_state;
            if (e->stage != 0xC) {
                ((void (*)(s32, s32, s32))open_text_box)(
                    0, 0xFF, (u8)e->character_state.bytes[8]);
                e->character_state.bytes[8] = 1;
            }
        }
        arg0->unk6++;
        return;
    }
    func_8002D230(arg0);
}
