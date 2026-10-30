#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_80097420;

void func_800EBF6C(void* arg0) {
    s32 temp_v0;

    if (!(D_80097420 & 1)) {
        background_objects[1].unk42 = background_objects[1].unk42 - 1;
    }
    temp_v0 = M2C_FIELD(arg0, u16*, 0x7E) - 1;
    M2C_FIELD(arg0, u16*, 0x7E) = temp_v0;
    if ((temp_v0 << 0x10) == 0) {
        func_8002943C(0xA, 2, 2);
        M2C_FIELD(arg0, u16*, 0x7E) = 0xA;
    }
    if ((s16)background_objects[1].unk42 < -0x1F) {
        *(s16*)&background_objects[1].unk42 = -0x20;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        play_sound(5, 3, arg0);
    }
}
