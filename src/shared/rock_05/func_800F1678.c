#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj g_playthrough_state;

void func_800F1678(void* arg0) {
    struct X4_EngineObj* e;

    ((void (*)())func_80017A04)();
    e = &g_playthrough_state;
    if (e->stage != 0xC) {
        ((void (*)(s32, s32, s32))open_text_box)(0, 0xFF,
                                                 M2C_FIELD(e, u8*, 0x2E));
        M2C_FIELD(e, u8*, 0x2E) = 1;
    }
    M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
}
