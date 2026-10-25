#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002C9B0();
extern struct X4_PlayerObj g_Player;

void func_800450E0(void* arg0) {
    struct X4_PlayerObj* p = &g_Player;

    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    if (p->unk2 == 0) {
        M2C_FIELD(p, u8*, 0x98) -= 1;
        M2C_FIELD(p, u8*, 0x99) -= 1;
    }
    func_8002C9B0(arg0);
}
