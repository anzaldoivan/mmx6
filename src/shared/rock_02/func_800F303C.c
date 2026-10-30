#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_800970AA;
extern struct X4_BackgroundObj background_objects[3];

#define SPAD (*(u8**)0x1F80004C)
#define CENTER                                                                 \
    ({                                                                         \
        s32 l_ = background_objects[0].unk1E - 320;                            \
        background_objects[0].unk1E + (background_objects[0].unk1C - l_) / 2;  \
    })

void func_800F303C(void* arg0) {
    u8* sp = SPAD;
    u16 x;
    s32 c;
    s32 t;

    if (M2C_FIELD(sp, s8*, 0x89) == 0) {
        M2C_FIELD(sp, s8*, 0x89) = 120;
    }
    x = M2C_FIELD(arg0, u16*, 0xA);
    if ((t = D_800970AA > (c = CENTER)) && c < (s16)x) {
        M2C_FIELD(arg0, s32*, 0x20) = -0x60000;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, u8*, 0x6)++;
        return;
    } else if (!t && (s16)x <= CENTER) {
        M2C_FIELD(arg0, s32*, 0x20) = 0x60000;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, u8*, 0x6)++;
        return;
    }
    play_sound(2, 0x23, arg0);
    ((void (*)(void*, s32))set_animation)(arg0, 0x12);
    M2C_FIELD(arg0, u8*, 0x6) = 2;
}
