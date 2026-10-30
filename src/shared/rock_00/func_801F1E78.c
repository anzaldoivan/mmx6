#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_801F1E78(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x8C) == 0) {
        struct X4_PlayerObj* p = &g_Player;
        M2C_FIELD(p, u8*, 0x98)--;
        M2C_FIELD(p, u8*, 0x99)--;
    }
    ((M2C_UNK(*)())clear_object_slot)(arg0, arg0);
}
#undef g_Player
