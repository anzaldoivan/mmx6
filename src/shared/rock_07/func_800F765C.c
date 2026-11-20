// rolefeed (3.1 T4): func_800F765C of src/rock_07/E9860.c
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/x4.h"

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];

#include "common.h"
#include "psyq/libgte.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define W(p, o) M2C_FIELD(p, s32*, o)

extern s32 D_800F978C;
extern s32 D_800F9790;

void func_800F765C(void* arg0) {
    s32 m;

    B(arg0, 0x3) = 1;
    W(arg0, 0x50) = (s32)&D_800F978C;
    W(arg0, 0x68) = (s32)&D_800F9790;
    m = rcos(W(arg0, 0x84)) * 0x10;
    W(arg0, 0x20) = (m * 2 + m) * 2;
    m = rsin(W(arg0, 0x84)) * 0x10;
    W(arg0, 0x24) = (m * 2 + m) * 2;
    B(arg0, 0x6)++;
}
