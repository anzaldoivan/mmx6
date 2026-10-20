#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D2B0();
extern u16 D_8009721A;

void func_801014C8(void* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    ((void (*)(void*))func_8002D2B0)(arg0);
    if (M2C_FIELD(arg0, s16*, 0xE) >= (s16)D_8009721A + 0x88) {
        M2C_FIELD(arg0, s16*, 0xE) = D_8009721A + 0x88;
        func_80016C48(2, 0x80, arg0);
        M2C_FIELD(arg0, u8*, 0x8D) = 0;
        func_80029478(0x1E, 2, 2);
        {
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1; // !FAKE: inherited from src/shared/rock_02/func_800F8BA0.c
            M2C_FIELD(arg0, u8*, 6) = t;
        }
    }
}
