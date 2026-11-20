// rolefeed (3.1 T4): func_800F856C of src/rock_11/E9860.c
#include "common.h"
#include "mmx6/rock_11.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
s32 is_text_box_seen(M2C_UNK);
M2C_UNK set_text_box_seen(M2C_UNK);

#define F(type, off) M2C_FIELD(self, type*, off)

#include "common.h"
#include "mmx6/x4.h"

s32 func_80027BA0(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
void func_800FA31C(void* arg0);
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800FD464[];
extern u8 D_800FDA78[];

#define F856C(o, type, off) (*(type*)((u8*)(o) + (off)))

void func_800F856C(void* arg0) {
    s32 i;

    if (--F856C(arg0, s16, 0x7C) == 0) {
        for (i = 0; i < 0x13; i++) {
            func_80027BA0(0, background_objects[0].unk26 + 0x10 + i * 0x10,
                          F856C(arg0, s16, 0xE) & 0xFFF0, D_800FD464);
        }
        D_800FDA78[F856C(arg0, u8, 0x2) & 0xF] = 0;
        F856C(arg0, u8, 0x4) = 6;
        return;
    }
    if (F856C(arg0, s16, 0x7C) & 1) {
        func_800FA31C(arg0);
    }
}
