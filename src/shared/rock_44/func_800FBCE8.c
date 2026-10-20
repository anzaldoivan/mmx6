#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002D2B0(void*);
extern struct X4_BackgroundObj D_800971F8[3];

void func_800FBCE8(void* arg0) {
    register s32 x asm("$5"); // !FAKE: inherited from src/shared/rock_02/func_800F33C0.c
    register s32 l asm("$4"); // !FAKE: inherited from src/shared/rock_02/func_800F33C0.c

    ((void (*)(void*))func_8002D2B0)(arg0);
    if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
        x = D_800971F8[0].unk1E;
        l = x - 0x140;
        if (M2C_FIELD(arg0, s16*, 0xA) >= x + (D_800971F8[0].unk1C - l) / 2) {
            return;
        }
    } else {
        x = D_800971F8[0].unk1E;
        l = x - 0x140;
        if (x + (D_800971F8[0].unk1C - l) / 2 >= M2C_FIELD(arg0, s16*, 0xA)) {
            return;
        }
    }
    func_80016C48(2, 0x23, arg0);
    func_800179A4(arg0, 7);
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    {
        register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1; // !FAKE: inherited from src/shared/rock_02/func_800F33C0.c
        M2C_FIELD(arg0, u8*, 6) = t;
    }
}
