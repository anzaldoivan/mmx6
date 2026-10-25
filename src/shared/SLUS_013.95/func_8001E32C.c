#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80042F7C(s8 arg0, s8* arg1, s8* arg2);
extern u8 D_80071190[];
#define M2C_UNK s32
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s8 D_800970A2;
extern struct X4_EngineObj D_800CCED0;
extern s8 D_800E3140;
extern u8 D_800E3141;

void func_8001E32C(void* arg0) {
    s8 f;
    s8 c;
    u32 i;

    D_800E3141 = M2C_FIELD(arg0, u8*, 0xC);
    if (M2C_FIELD(arg0, s8*, 0xF) > 0) {
        D_800E3140 = 0;
    } else {
        D_800E3140 = 1;
    }
    f = M2C_FIELD(arg0, s8*, 0xF);
    if (f != 0) {
        i = 0;
        if (f > 0) {
            c = M2C_FIELD(arg0, s8*, 0xC);
            M2C_FIELD(arg0, s8*, 0x1E) = 0;
            if (c == 0) {
                M2C_FIELD(arg0, s8*, 0x66) = 1;
                M2C_FIELD(arg0, s8*, 0) = 0xB;
                M2C_FIELD(arg0, s8*, 1) = 0;
                M2C_FIELD(arg0, s8*, 2) = 0;
                M2C_FIELD(arg0, s8*, 3) = 0;
                M2C_FIELD(arg0, s8*, 0xF) = 0;
                return;
            } else if ((u8)(M2C_FIELD(arg0, u8*, 0xC) - 1) < 8) {
                if (f == 0x41) {
                    func_80042F7C(c, (s8*)arg0 + 0xC, (s8*)arg0 + 0xD);
                    M2C_FIELD(arg0, s8*, 0) = 8;
                } else if (D_80071190[c] != 0 ||
                           M2C_FIELD(arg0, s8*, 0xD) != 0) {
                    u8* e = (u8*)&D_800CCED0;
                    M2C_FIELD(arg0, s8*, 0) = 0xB;
                    if (e[0x66] < 3 &&
                        *(s16*)((u8*)&D_800CCED0 + (s8)e[0x38] * 2 + 0xD2) >=
                            3000) {
                        D_800CCED0.state = 0x13;
                        e[0x1D] = 5;
                    }
                } else {
                    M2C_FIELD(arg0, u8*, 0xD) = M2C_FIELD(arg0, u8*, 0xD) + 1;
                    M2C_FIELD(arg0, s8*, 0) = 8;
                }
                M2C_FIELD(arg0, s8*, 1) = 0;
                M2C_FIELD(arg0, s8*, 2) = 0;
                M2C_FIELD(arg0, s8*, 3) = 0;
                M2C_FIELD(arg0, s8*, 0xF) = 0;
                return;
            } else {
                if (c == 0x10) {
                    M2C_FIELD(arg0, s8*, 0) = 0x13;
                    M2C_FIELD(arg0, s8*, 0x1D) = 8;
                    M2C_FIELD(arg0, s8*, 0x66) = 4;
                } else if (c == 0x11) {
                    M2C_FIELD(arg0, s8*, 0xC) = 0x12;
                    M2C_FIELD(arg0, s8*, 0) = 8;
                } else if (c == 0x12) {
                    M2C_FIELD(arg0, s8*, 0) = 0x13;
                    M2C_FIELD(arg0, s8*, 0x1D) = 9;
                    M2C_FIELD(arg0, s8*, 0x66) = 5;
                } else if (M2C_FIELD(arg0, u16*, 0xC) == 0xC) {
                    M2C_FIELD(arg0, s8*, 0) = 8;
                    M2C_FIELD(arg0, u8*, 0xD) = M2C_FIELD(arg0, u8*, 0xD) + 1;
                } else if (c == 0xC && M2C_FIELD(arg0, s8*, 0xD) != 0) {
                    M2C_FIELD(arg0, s8*, 0) = 0x13;
                    if (D_800970A2 != 0) {
                        M2C_FIELD(arg0, s8*, 0x1D) = 0xC;
                    } else if (M2C_FIELD(arg0, u8*, 0x5F) & 0x10) {
                        M2C_FIELD(arg0, s8*, 0x1D) = 0xB;
                    } else {
                        M2C_FIELD(arg0, s8*, 0x1D) = 0xA;
                    }
                } else if (M2C_FIELD(arg0, s8*, 0xC) >= 0x13) {
                    if (M2C_FIELD(arg0, u8*, 0x43B) == 0) {
                        M2C_FIELD(arg0, s8*, 0) = 0x13;
                        M2C_FIELD(arg0, s8*, 0x1D) = 2;
                        M2C_FIELD(arg0, u8*, 0x5F) |= 0x10;
                    } else if (M2C_FIELD(arg0, u8*, 0x43B) == 1) {
                        M2C_FIELD(arg0, s8*, 0) = 0x13;
                        M2C_FIELD(arg0, s8*, 0x1D) = 4;
                    } else {
                        M2C_FIELD(arg0, s8*, 0) = 0xB;
                    }
                }
                M2C_FIELD(arg0, s8*, 1) = 0;
                M2C_FIELD(arg0, s8*, 2) = 0;
                M2C_FIELD(arg0, s8*, 3) = 0;
                M2C_FIELD(arg0, s8*, 0xF) = 0;
                return;
            }
        } else {
            M2C_FIELD(arg0, s8*, 0x1E) = -1;
            M2C_FIELD(arg0, u8*, 0x5A) = g_Player.hp;
            for (i = 0; i < 0x10; i++) {
                ((u16*)((u8*)arg0 + 0x3A))[i] =
                    ((u16*)g_Player.weapon_energy)[i];
            }
            M2C_FIELD(arg0, u8*, 0x5D) = g_Player.weapon;
            M2C_FIELD(arg0, s8*, 0) = 9;
        }
    } else {
        if ((s8)--M2C_FIELD(arg0, u8*, 0x39) < 0) {
            M2C_FIELD(arg0, s8*, 0) = 0xD;
            {
                s32 flag;
                if (M2C_FIELD(arg0, s8*, 0xC) != 0xC ||
                    M2C_FIELD(arg0, s8*, 0x1D) < 2) {
                    flag = 0;
                } else {
                    flag = M2C_FIELD(arg0, s8*, 0x1D) < 10;
                }
                if (flag) {
                    M2C_FIELD(arg0, s8*, 0x1D) = 1;
                }
            }
        } else {
            M2C_FIELD(arg0, s8*, 0x1E) = 0;
            {
                s32 flag;
                if (M2C_FIELD(arg0, s8*, 0xC) != 0xC ||
                    M2C_FIELD(arg0, s8*, 0x1D) < 2) {
                    flag = 0;
                } else {
                    flag = M2C_FIELD(arg0, s8*, 0x1D) < 10;
                }
                if (flag) {
                    M2C_FIELD(arg0, s8*, 0x1D) = 1;
                }
            }
            M2C_FIELD(arg0, s8*, 0) = 9;
        }
    }
    M2C_FIELD(arg0, s8*, 1) = 0;
    M2C_FIELD(arg0, s8*, 0xF) = 0;
}
#undef g_Player
