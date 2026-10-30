#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */
M2C_UNK func_80017A04();                     /* extern */
s32 func_8002A47C(s32);                      /* extern */
void* func_8002C32C();                       /* extern */
extern M2C_UNK g_Player;

void func_800F097C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, u8*, 6) = 1;
        if (M2C_FIELD(arg0, u8*, 0x86) < 3) {
            void* o = func_8002C32C();
            if (o != 0) {
                s32 r;
                M2C_FIELD(o, u8*, 0) = 0x41;
                M2C_FIELD(o, u8*, 1) = 0x3B;
                M2C_FIELD(o, u8*, 2) = 0;
                M2C_FIELD(o, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
                M2C_FIELD(o, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
                M2C_FIELD(o, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                M2C_FIELD(o, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                M2C_FIELD(o, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
                r = func_8002A47C(0xE1) & 0xFF;
                M2C_FIELD(o, u16*, 0x42) =
                    ((r * 4 + 0x20) % 16) | (((r + 8) / 4 + 0x1E0) << 6);
                {
                    u8 t = M2C_FIELD(arg0, u8*, 0x16);
                    M2C_FIELD(o, void**, 0x7C) = arg0;
                    M2C_FIELD(o, u8*, 0x16) = t;
                }
                M2C_FIELD(o, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
                M2C_FIELD(arg0, u8*, 0x86)++;
            }
        }
        ((void (*)(void*, s32))set_animation)(arg0, 8);
        if (M2C_FIELD(arg0, u8*, 0x8D) == 0) {
            void* pl = &g_Player;
            M2C_FIELD(pl, u8*, 0xD8) = 0x3F;
            M2C_FIELD(pl, u8*, 0x6) = 0;
        }
        play_sound(2, 7, 0);
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        M2C_FIELD(arg0, s8*, 0x87) = 0;
        M2C_FIELD(arg0, s8*, 5) = 1;
        M2C_FIELD(arg0, s8*, 6) = 0;
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
        s32 cond;
        cond = 0;
        if (M2C_FIELD(arg0, u16*, 0x8A) & 0x30) {
            cond = 1;
            if (M2C_FIELD(arg0, s8*, 2) != 0) {
                cond = M2C_FIELD(arg0, u8*, 0x7E) == 0;
            }
        }
        if (cond && M2C_FIELD(arg0, u8*, 0x86) < 3) {
            M2C_FIELD(arg0, s8*, 5) = 3;
            M2C_FIELD(arg0, s8*, 6) = 0;
        }
    }
    func_80017A04(arg0);
}
