#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void set_boss_level();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern s8* D_800FDA74;
extern s16 D_800FDA80;
extern u8 func_800E9B90[];

#define F(type, off) M2C_FIELD(arg0, type*, off)
#define E(type, off) M2C_FIELD(e, type*, off)
#define B(type, off) M2C_FIELD(b, type*, off)

void func_800F66D8(void* arg0) {
    u8 tbl[4];
    s8 c;
    struct X4_EngineObj* e;
    struct X4_BackgroundObj* b;

    __builtin_memcpy(tbl, func_800E9B90, 4);
    if (--F(s16, 0x7C) == 0) {
        func_8003D308(0x14, 0x40);
    }
    c = *D_800FDA74;
    if (c == 0) {
        e = &g_playthrough_state;
        E(s8, 0x24) = 1;
        E(s8, 0x25) = 0;
        E(void*, 0x20) = arg0;
        set_boss_level();
        E(u8, 0x8C) = tbl[E(u8, 0x8F)] + 0x30;
        b = background_objects;
        F(s16, 0xA) = B(s16, 0x26) + 0xD0;
        {
            u16 y = B(u16, 0x2A);
            F(s16, 0x7C) = 2;
            F(s16, 0x7E) = 0x10;
            F(s16, 0xE) = y + 0xD0;
        }
        D_800FDA80 = 0;
        ((s32(*)(s32, s32, void*, void*))play_sound)(2, 0x42, arg0, b);
        F(u8, 0x6)++;
    }
}
