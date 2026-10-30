#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */
M2C_UNK func_80017A04();                     /* extern */
void* func_8002C32C();                       /* extern */
extern M2C_UNK g_Player;
#define PLAYER (*(struct X4_PlayerObj*)&g_Player)

void func_800EEFF0(void* arg0) {
    s32 ok;
    u8 n;
    void* o1;
    void* o2;

    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, s8*, 6) = 1;
        if (M2C_FIELD(arg0, u8*, 0x87) == 1) {
            o1 = func_8002C32C();
            if (o1 != 0) {
                M2C_FIELD(o1, u8*, 0) = 0x41;
                M2C_FIELD(o1, u8*, 1) = 0x3E;
                M2C_FIELD(o1, u8*, 2) = 2;
                M2C_FIELD(o1, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
                M2C_FIELD(o1, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
                M2C_FIELD(o1, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                M2C_FIELD(o1, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                M2C_FIELD(o1, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
                M2C_FIELD(o1, u16*, 0x42) =
                    M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(o1, u8*, 0x16) = M2C_FIELD(arg0, u8*, 0x16);
                M2C_FIELD(o1, void**, 0x7C) = arg0;
                M2C_FIELD(o1, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
            }
            ((void (*)(void*, s32))set_animation)(arg0, 0xA);
            if (M2C_FIELD(arg0, u8*, 0x8D) == 0) {
                struct X4_PlayerObj* pl = &PLAYER;
                M2C_FIELD(pl, u8*, 0xD8) = 0x32;
                M2C_FIELD(pl, u8*, 6) = 0;
            }
            play_sound(2, 0x2B, 0);
        } else {
            o2 = func_8002C32C();
            if (o2 != 0) {
                M2C_FIELD(o2, u8*, 0) = 0x41;
                M2C_FIELD(o2, u8*, 1) = 0x3D;
                M2C_FIELD(o2, u8*, 2) = 0;
                M2C_FIELD(o2, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
                M2C_FIELD(o2, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
                M2C_FIELD(o2, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                M2C_FIELD(o2, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                M2C_FIELD(o2, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
                M2C_FIELD(o2, u16*, 0x42) =
                    M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(o2, u8*, 0x16) = M2C_FIELD(arg0, u8*, 0x16);
                M2C_FIELD(o2, void**, 0x7C) = arg0;
                M2C_FIELD(o2, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
            }
            ((void (*)(void*, s32))set_animation)(arg0, 8);
            if (M2C_FIELD(arg0, u8*, 0x8D) == 0) {
                struct X4_PlayerObj* pl = &PLAYER;
                M2C_FIELD(pl, u8*, 0xD8) = 0x31;
                M2C_FIELD(pl, u8*, 6) = 0;
            }
            play_sound(2, 0x2C, 0);
        }
        M2C_FIELD(arg0, u8*, 0x81) = 0;
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        if (M2C_FIELD(arg0, u8*, 0x81) == 0) {
            M2C_FIELD(arg0, u8*, 0x87) = 0;
            M2C_FIELD(arg0, u8*, 0x81) = 0;
            M2C_FIELD(arg0, s8*, 5) = 1;
        } else {
            M2C_FIELD(arg0, s8*, 5) = 3;
        }
        M2C_FIELD(arg0, s8*, 6) = 0;
        return;
    }
    if (M2C_FIELD(arg0, u8*, 0x45) & 1) {
        ok = 0;
        if (M2C_FIELD(arg0, u16*, 0x8A) & 0x30) {
            ok = 1;
            if (M2C_FIELD(arg0, s8*, 2) != 0) {
                ok = M2C_FIELD(arg0, u8*, 0x7E) == 0;
            }
        }
        if (ok != 0 && M2C_FIELD(arg0, u8*, 0x81) == 0) {
            n = M2C_FIELD(arg0, u8*, 0x87);
            if (n < 2) {
                M2C_FIELD(arg0, u8*, 0x87) = n + 1;
                M2C_FIELD(arg0, u8*, 0x81) = 1;
            }
        }
    }
    func_80017A04(arg0);
}
#undef PLAYER
