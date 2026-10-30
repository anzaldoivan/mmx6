#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
void func_800F9E04(struct X4_AnimatedObj*);
extern M2C_UNK D_800FC734;
extern M2C_UNK D_800FC738;

void func_800F89BC(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        play_sound(2, 0x56, arg0);
        set_animation(arg0, 0x17);
        func_800F9E04(arg0);
        M2C_FIELD(arg0, M2C_UNK**, 0x50) = &D_800FC734;
        M2C_FIELD(arg0, M2C_UNK**, 0x54) = &D_800FC738;
        M2C_FIELD(arg0, u8*, 6)++;
    }
}
