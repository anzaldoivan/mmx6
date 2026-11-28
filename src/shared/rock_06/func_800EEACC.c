// rolefeed (3.1 T4): func_800EEACC of src/rock_06/E9860.c
// clang-format off

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);     /* extern */
M2C_UNK set_animation(void*, M2C_UNK);           /* extern */
M2C_UNK animate_object();                        /* extern */
struct X4_VisualObj* find_free_visual_obj(void); /* extern */
extern struct X4_PlayerObj g_Player;
extern s32 D_800F3A44;
extern s32 D_800F3A4C;

void func_800EEACC(void* arg0) {
    void* o;

    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, s8*, 6) = 1;
        M2C_FIELD(arg0, u8*, 0x94) = 0;
        M2C_FIELD(arg0, u16*, 0xA6) = 0;
        M2C_FIELD(arg0, s32**, 0x68) = &D_800F3A44;
        ((void (*)(void*, s32))set_animation)(arg0, 0x12);
        if (M2C_FIELD(arg0, u8*, 0x8D) == 0) {
            u8* p = (u8*)&g_Player;
            M2C_FIELD(p, u8*, 0xD8) = 0x39;
            M2C_FIELD(p, u8*, 6) = 0;
        }
        play_sound(2, 0x24, 0);
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        if (M2C_FIELD(arg0, u8*, 0x8C) == 0) {
            M2C_FIELD(arg0, u8*, 0x61) = 0;
        }
        M2C_FIELD(arg0, u8*, 5) = 1;
        M2C_FIELD(arg0, u8*, 0x94) = 0;
        M2C_FIELD(arg0, u16*, 0xA6) = 0;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s32**, 0x54) = &D_800F3A4C;
        return;
    }
    if (M2C_FIELD(arg0, u8*, 0x45) & 1) {
        o = find_free_visual_obj();
        if (o != 0) {
            M2C_FIELD(o, u8*, 0) = M2C_FIELD(arg0, u8*, 0);
            M2C_FIELD(o, u8*, 1) = 0xC;
            M2C_FIELD(o, u8*, 2) = 7;
            M2C_FIELD(o, s32*, 8) = M2C_FIELD(arg0, s32*, 8);
            M2C_FIELD(o, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
            M2C_FIELD(o, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(o, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(o, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(o, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
            M2C_FIELD(o, u8*, 0x16) = M2C_FIELD(arg0, u8*, 0x16);
            M2C_FIELD(o, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
            M2C_FIELD(o, void**, 0x50) = arg0;
        }
        play_sound(2, 0x26, 0);
        M2C_FIELD(arg0, u8*, 0x45) = 0;
        return;
    }
    animate_object(arg0);
}
