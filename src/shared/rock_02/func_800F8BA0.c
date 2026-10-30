#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK move_object(s32);
extern u16 D_8009721A;

void func_800F8BA0(void* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    ((void (*)(void*))move_object)(arg0);
    if (M2C_FIELD(arg0, s16*, 0xE) >= (s16)D_8009721A + 0x88) {
        M2C_FIELD(arg0, s16*, 0xE) = D_8009721A + 0x88;
        play_sound(2, 0x80, arg0);
        M2C_FIELD(arg0, u8*, 0x8D) = 0;
        func_80029478(0x1E, 2, 2);
        {
            // !FAKE: depin: dropping it breaks the match (30/33)
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
    }
}
