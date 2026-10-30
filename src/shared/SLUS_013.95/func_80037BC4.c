#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_8003AF1C(void*);
void func_8003B870(struct X4_PlayerObj* self);
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003CCBC();
extern struct X4_EngineObj g_playthrough_state;

void func_80037BC4(void* arg0) {
    struct X4_EngineObj* e = &g_playthrough_state;

    if (e->unkF != 0) {
        ((void (*)())func_8003B870)();
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0xD5) == 0) {
        func_8003CCBC(arg0);
        ((void (*)(void*))func_8003AF1C)(arg0);
        M2C_FIELD(arg0, u8*, 0x86) = 1;
        e->gameplay_locked = 0;
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x6) == 0) {
        ((void (*)(void*, s32))func_8003BA04)(arg0, M2C_FIELD(arg0, u8*, 0xD8));
        M2C_FIELD(arg0, u8*, 0x6) += 1;
    }
    func_80017A04(arg0);
}
