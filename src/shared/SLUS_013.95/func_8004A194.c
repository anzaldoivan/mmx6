#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s32 D_80077D54;
s32 play_sound(s32 a0, s32 a1, void* arg2);
M2C_UNK func_8002CB50();
#define SCRATCH_1C (*(u8**)0x1F80001C)
s32 set_animation();

void func_8004A194(void* arg0) {
    s8 b;
    u8* s;
    s32 o;

    M2C_FIELD(arg0, s8*, 3) = 1;
    b = M2C_FIELD(arg0, s8*, 2);
    M2C_FIELD(arg0, s32*, 0x38) = 0;
    s = SCRATCH_1C;
    o = *(s32*)(s + 8);
    M2C_FIELD(arg0, void**, 0x30) = &D_80077D54;
    M2C_FIELD(arg0, s16*, 0x40) = 0;
    M2C_FIELD(arg0, u8**, 0x3C) = s + o;
    M2C_FIELD(arg0, s16*, 0x42) =
        ((b + 4) % 16) | (((b + 4) / 16 + 0x1E0) << 6);
    set_animation(arg0, 0);
    if (M2C_FIELD(arg0, u8*, 0x5C) != 0xFF) {
        play_sound(0, M2C_FIELD(arg0, u8*, 0x5C), arg0);
    }
    M2C_FIELD(arg0, u8*, 4)++;
    func_8002CB50(arg0);
}
