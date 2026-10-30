#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj g_playthrough_state;

void func_800F4B2C(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        if (g_playthrough_state.stage != 0xC) {
            ((void (*)(s32, s32, s32))open_text_box)(
                0, 0xFF, M2C_FIELD(&g_playthrough_state, u8*, 0x2E));
            M2C_FIELD(&g_playthrough_state, u8*, 0x2E) = 1;
        }
        M2C_FIELD(arg0, u8*, 6)++;
    }
}
