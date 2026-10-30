#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */
M2C_UNK func_80017A04();                     /* extern */
s32 random_byte();
extern M2C_UNK g_Player;
extern s8 D_800970FC;
extern struct X4_ObjectHeader D_80097420;
#define D_80097420 (*(s32*)&D_80097420)

void func_800F036C(void* arg0) {
    s32 hit;
    s32 mask;

    if (!(D_80097420 & 3) && (random_byte() & 1)) {
        random_byte();
    }
    if ((M2C_FIELD(arg0, u16*, 0x88) & 7) == 4) {
        if (M2C_FIELD(arg0, u16*, 0x8A) & 0x80) {
            play_sound(2, 0x25, 0);
            hit = 1;
        } else {
            goto clear;
        }
    } else {
        hit = 1;
        if (D_800970FC != -0x80) {
        clear:
            hit = 0;
        }
    }
    if (hit != 0) {
        M2C_FIELD(arg0, u8*, 5) = 0xB;
        M2C_FIELD(arg0, u8*, 6) = 0;
        return;
    }
    if (!(M2C_FIELD(arg0, u8*, 0x97) & 2)) {
        mask = 1;
        if (!(M2C_FIELD(arg0, u8*, 0xA8) & 8)) {
            M2C_FIELD(arg0, u8*, 5) = 0xC;
            M2C_FIELD(arg0, u8*, 6) = 0;
        } else {
            M2C_FIELD(arg0, s32*, 8) += M2C_FIELD(arg0, s32*, 0x20);
            if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                mask = 2;
            }
            if ((M2C_FIELD(arg0, u16*, 0x88) & mask) ||
                --M2C_FIELD(arg0, s8*, 0x90) == 0) {
                M2C_FIELD(arg0, u8*, 6) = 3;
                ((void (*)(void*, s32))set_animation)(arg0, 0x10);
                if (M2C_FIELD(arg0, u8*, 0x8D) == 0) {
                    void* pl = &g_Player;
                    M2C_FIELD(pl, u8*, 0xD8) = 0x29;
                    M2C_FIELD(pl, u8*, 0x6) = 0;
                }
            }
        }
        func_80017A04(arg0);
    } else {
        func_80017A04(arg0);
    }
}
#undef D_80097420
