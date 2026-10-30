#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK silence_sound(M2C_UNK, M2C_UNK);
M2C_UNK func_80017A04();
void stop_cd_audio();
s32 func_8002D30C();
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_8004A0C0(M2C_UNK, s16, s16, s32);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_800759BC;
extern s8 D_8009711A;
extern M2C_UNK D_800F67C0;
extern void (*D_800F6E24[])(void*);

void func_800EFED0(void* arg0) {
    s32 v;
    s32 i;
    s32 x;
    void* p;
    u16 t;

    if (!(M2C_FIELD(arg0, s8*, 2) & 0xF0)) {
        M2C_FIELD(arg0, void**, 0x50) = &D_800F67C0;
        ((void (*)())func_80017A04)();
        if ((u32)(M2C_FIELD(arg0, u8*, 0x47) - 3) < 0xBU) {
            p = &D_800759BC;
        } else {
            p = &D_8007433C;
        }
        M2C_FIELD(arg0, void**, 0x58) = p;
    }
    D_800F6E24[M2C_FIELD(arg0, s8*, 5)](arg0);
    v = check_enemy_hits(arg0);
    if (v < 0) {
        i = 7;
        stop_cd_audio();
        silence_sound(0xFF, 0);
        D_8009711A = 1;
        do {
            x = M2C_FIELD(arg0, s16*, 0xA) + func_8002D30C() % 32;
            ((void (*)(s32, s32, s32, s32))func_8004A0C0)(
                0, x, M2C_FIELD(arg0, s16*, 0xE) + func_8002D30C() % 48, 0xFF);
        } while (--i >= 0);
        M2C_FIELD(arg0, s8*, 4) = 2;
        M2C_FIELD(arg0, s8*, 5) = 0;
        return;
    }
    if (v > 0 && v != 0x7F && M2C_FIELD(arg0, s16*, 0x84) == 0) {
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        if ((u32)(v - 0x19) < 2U) {
            M2C_FIELD(arg0, s16*, 0x84) = 0xA;
        } else {
            M2C_FIELD(arg0, s16*, 0x84) = 0x1E;
        }
        if (v == 6 || v == 0xF || v == 0x25) {
            M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
            M2C_FIELD(arg0, s16*, 0x84) = 0x2710;
            M2C_FIELD(arg0, s8*, 5) = 4;
            M2C_FIELD(arg0, s8*, 6) = 0;
            return;
        }
    }
    if (M2C_FIELD(arg0, s16*, 0x84) != 0) {
        t = M2C_FIELD(arg0, u16*, 0x84);
        M2C_FIELD(arg0, u16*, 0x84) = t - 1;
        if (t & 2) {
            M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
        if (M2C_FIELD(arg0, s16*, 0x84) == 0) {
            M2C_FIELD(arg0, void**, 0x58) = &D_800759BC;
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
    }
    ((void (*)(void*, s32))func_80030ECC)(arg0, v);
}
