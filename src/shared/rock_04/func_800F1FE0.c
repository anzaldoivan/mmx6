#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK move_object(void*);
void func_800F5088(struct X4_AnimatedObj* arg0, u8 arg1);

void func_800F1FE0(void* arg0) {
    s32 var_v0;
    u8 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8*, 0x70);
    if (temp_v1 & 8) {
        play_sound(2, 0x12, arg0);
        func_80012D9C(8);
        set_animation(arg0, 9);
        {
            // !FAKE: depin: dropping it breaks the match (51/56)
            register s32 t asm("$2") = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
            M2C_FIELD(arg0, u8*, 6) = t;
        }
        return;
    }
    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
        var_v0 = temp_v1 & 1;
    } else {
        var_v0 = temp_v1 & 2;
    }
    if (var_v0 != 0) {
        play_sound(2, 0x12, arg0);
        func_80012D9C(8);
        set_animation(arg0, 0xB);
        func_800F5088(arg0, 0x20);
        func_800F5088(arg0, 0x21);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x1E;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) - 1);
        return;
    }
    move_object(arg0);
}
