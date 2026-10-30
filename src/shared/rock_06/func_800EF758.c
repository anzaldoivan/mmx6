#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK set_animation(void*, M2C_UNK);       /* extern */
M2C_UNK func_80017A04();                     /* extern */
void* func_8002C32C();                       /* extern */
M2C_UNK func_8002D230(void*);                /* extern */
extern M2C_UNK g_Player;

void func_800EF758(void* arg0) {
    s32 var_v0;
    s8 var_v1;
    u16 temp_v1;
    void* o;

    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        M2C_FIELD(arg0, u8*, 6) = 1;
        o = func_8002C32C();
        if (o != 0) {
            M2C_FIELD(o, u8*, 0) = 0x41;
            M2C_FIELD(o, u8*, 1) = 0x3E;
            M2C_FIELD(o, u8*, 2) = 3;
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
        ((void (*)(void*, s32))set_animation)(arg0, 0xB);
        if (M2C_FIELD(arg0, u8*, 0x8D) == 0) {
            void* pl = &g_Player;
            M2C_FIELD(pl, u8*, 0xD8) = 0x33;
            M2C_FIELD(pl, u8*, 0x6) = 0;
        }
        play_sound(2, 0x2B, 0);
    }
    if (M2C_FIELD(arg0, u8*, 0xA8) & 8) {
        M2C_FIELD(arg0, u8*, 5) = 5;
        M2C_FIELD(arg0, u8*, 6) = 0;
        return;
    }
    if (!(M2C_FIELD(arg0, u8*, 0x97) & 2)) {
        temp_v1 = M2C_FIELD(arg0, u16*, 0x88);
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        if (temp_v1 & 3) {
            var_v0 = M2C_FIELD(arg0, s16*, 0x98) << 8;
            if (!(temp_v1 & 1)) {
                var_v0 = -var_v0;
            }
            M2C_FIELD(arg0, s32*, 0x20) = var_v0;
        }
        if ((M2C_FIELD(arg0, s32*, 0x24) >= 0) &&
            ((M2C_FIELD(arg0, u8*, 0xA8) & 4) ||
             !(M2C_FIELD(arg0, u16*, 0x88) & 0x80))) {
            M2C_FIELD(arg0, s32*, 0x24) = 0;
        }
        if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
            var_v1 = 4;
            if (M2C_FIELD(arg0, s32*, 0x24) < 0) {
                var_v1 = 0xC;
            }
            M2C_FIELD(arg0, u8*, 5) = var_v1;
        } else {
            if (M2C_FIELD(arg0, s32*, 0x24) < -0x5E000) {
                M2C_FIELD(arg0, s32*, 0x24) = -0x5E000;
            }
            func_8002D230(arg0);
        }
        ((void (*)(void*))func_80017A04)(arg0);
        return;
    }
    ((void (*)(void*))func_80017A04)(arg0);
}
