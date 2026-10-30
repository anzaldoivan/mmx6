#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */
M2C_UNK func_80017A04();                     /* extern */
void* func_8002C32C();                       /* extern */
s32 random_byte();
extern M2C_UNK g_Player;
extern struct X4_ObjectHeader D_80097420;
#define D_80097420 (*(s32*)&D_80097420)

void func_800EFDB0(void* arg0) {
    s32 cnt;
    u8 a8;
    u8 f97;
    u16 t;
    u16 g;
    s32 mask;
    s32 mask2;
    void* o;
    s8 st;

    if (!(D_80097420 & 3) && (random_byte() & 1)) {
        random_byte();
    }
    st = M2C_FIELD(arg0, s8*, 6);
    if (st == 0) {
        M2C_FIELD(arg0, s8*, 6) = st + 1;
        o = func_8002C32C();
        if (o != 0) {
            M2C_FIELD(o, u8*, 0) = 0x41;
            M2C_FIELD(o, u8*, 1) = 0x3E;
            M2C_FIELD(o, u8*, 2) = 1;
            M2C_FIELD(o, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(o, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(o, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(o, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(o, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(o, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
            M2C_FIELD(o, u8*, 0x16) = M2C_FIELD(arg0, u8*, 0x16);
            M2C_FIELD(o, void**, 0x7C) = arg0;
            M2C_FIELD(o, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
        }
        ((void (*)(void*, s32))set_animation)(arg0, 9);
        if (M2C_FIELD(arg0, u8*, 0x8D) == 0) {
            void* pl = &g_Player;
            M2C_FIELD(pl, u8*, 0xD8) = 0x37;
            M2C_FIELD(pl, u8*, 0x6) = 0;
        }
        play_sound(2, 0x2C, 0);
    }
    a8 = M2C_FIELD(arg0, u8*, 0xA8);
    cnt = M2C_FIELD(arg0, u8*, 0x90) - 1;
    M2C_FIELD(arg0, u8*, 0x90) = cnt;
    if (!(a8 & 8)) {
        M2C_FIELD(arg0, s8*, 5) = 0xC;
        M2C_FIELD(arg0, s8*, 6) = 0;
        return;
    }
    f97 = M2C_FIELD(arg0, u8*, 0x97);
    if (!(f97 & 2)) {
        if ((a8 & 3) || (M2C_FIELD(arg0, u8*, 0x45) & 1)) {
            if ((s8)cnt >= 0) {
                goto add;
            }
            M2C_FIELD(arg0, s8*, 5) = 8;
            M2C_FIELD(arg0, s8*, 6) = 0;
        } else {
            if (!(f97 & 8)) {
                mask = 2;
                if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                    mask = 1;
                }
                t = M2C_FIELD(arg0, u16*, 0x88) & mask;
            } else {
                mask2 = 2;
                if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                    mask2 = 1;
                }
                g = M2C_FIELD(arg0, u16*, 0x88);
                t = g & mask2;
                if (t == 0) {
                    t = g & 0x100;
                }
            }
            if (t != 0) {
            add:
                M2C_FIELD(arg0, s32*, 8) += M2C_FIELD(arg0, s32*, 0x20);
            }
        }
        ((M2C_UNK(*)())func_80017A04)(arg0);
    } else {
        ((M2C_UNK(*)())func_80017A04)(arg0);
    }
}
#undef D_80097420
