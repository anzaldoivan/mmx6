#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800F0434(s8* self, u32 arg1);
extern s16 D_800970AA;

void func_800F3640(void* arg0) {
    s32 t = D_800970AA;

    if (M2C_FIELD(arg0, s16*, 0xA) < t) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    play_sound(2, 0x23, arg0);
    func_800F0434(arg0, 0xD);
    M2C_FIELD(arg0, s8*, 6) = 1;
}
