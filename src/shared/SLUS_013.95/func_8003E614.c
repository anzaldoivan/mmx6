#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8003E9E8();
void use_weapon_energy(void*, s32);
void func_8003F954(void*);
extern u8 D_80073EFC[][2];
extern void (*D_80073F74[])(void*);
extern s8 D_80074074[];
extern s8 D_800740B4[];
extern s8 D_800740F4[];
extern s8 D_80074134[];
extern s8 D_80074174[];
extern s8 D_800741B4[];

void func_8003E614(void* arg0) {
    s32 var_s0;
    s32 var_a0;
    s32 var_v0;
    s8 lim;
    s8 mode;

    if (M2C_FIELD(arg0, u8*, 0x92) == 0) {
        M2C_FIELD(arg0, s8*, 0x96) = -1;
        func_8003E9E8();
        func_8003F954(arg0);
        var_s0 = M2C_FIELD(arg0, s8*, 0x96);
        if (var_s0 == -1) {
            return;
        }
        if ((var_s0 == 0x2E) && (M2C_FIELD(arg0, s8*, 0x86) == 10)) {
            M2C_FIELD(arg0, s8*, 0x96) = -1;
            return;
        }
        if ((var_s0 == 0x2B) && (M2C_FIELD(arg0, u16*, 0x7C) & 4)) {
            if (M2C_FIELD(arg0, s8*, 0x86) == 9) {
                var_s0 = 0x38;
                goto clear;
            }
            M2C_FIELD(arg0, s8*, 0x96) = 0x38;
            M2C_FIELD(arg0, s8*, 0x86) = 9;
            var_s0 = 0x38;
        }
        if (D_800741B4[var_s0] == 0) {
            mode = M2C_FIELD(arg0, s8*, 0xA6);
            var_a0 = 0;
            if (mode == 1) {
                if ((var_s0 == 2) || (var_s0 == 0xB)) {
                    var_a0 = 1;
                }
            } else if (mode == 3) {
                if ((var_s0 == 6) || (var_s0 == 0xF)) {
                    var_a0 = 1;
                }
            } else if (mode == 2) {
                if ((var_s0 == 7) || (var_s0 == 0x10)) {
                    var_a0 = 1;
                }
            }
            if (var_a0 != 0) {
                goto clear;
            }
            lim = D_80074074[var_s0];
            if (M2C_FIELD(arg0, s32*, 0xEC) & 0x40000) {
                lim = D_800740B4[var_s0];
            }
            if ((M2C_FIELD(arg0, s8*, 0x98) < lim) &&
                ((D_800740F4[var_s0] == 0) ||
                 (M2C_FIELD(arg0, s8*, 0x99) == 0))) {
                D_80073F74[var_s0](arg0);
                if ((var_s0 == 7) || (var_s0 == 1) || (var_s0 == 0xA)) {
                    M2C_FIELD(arg0, s8*, 0x8E) = 0;
                    M2C_FIELD(arg0, s8*, 0x8F) = 0;
                } else {
                    M2C_FIELD(arg0, s8*, 0x8E) = 1;
                    M2C_FIELD(arg0, s8*, 0x8F) = 1;
                }
                M2C_FIELD(arg0, s8*, 0xDD) = 1;
                M2C_FIELD(arg0, s8*, 0x97) = var_s0;
                M2C_FIELD(arg0, s8*, 0x90) = 0;
                M2C_FIELD(arg0, u8*, 0x91) = D_80073EFC[var_s0][0];
                M2C_FIELD(arg0, u8*, 0x92) = D_80073EFC[var_s0][1];
                if ((M2C_FIELD(arg0, s32*, 0xEC) & 0x80000) &&
                    (var_s0 != 0xF) && (M2C_FIELD(arg0, s32*, 0x144) != 6) &&
                    ((u32)(var_s0 - 1) >= 7U)) {
                    M2C_FIELD(arg0, u8*, 0x92) = D_80073EFC[var_s0][1] * 4;
                }
                if (D_80074134[var_s0] != 0) {
                    M2C_FIELD(arg0, u8*, 0x98) += 1;
                }
                if (D_80074174[var_s0] != 0) {
                    M2C_FIELD(arg0, u8*, 0x99) += 1;
                }
                M2C_FIELD(arg0, u8*, 0x9A) += 1;
                if (M2C_FIELD(arg0, s8*, 0x9A) == 3) {
                    M2C_FIELD(arg0, u8*, 0x9A) = 0;
                }
                var_a0 = 1;
                if (var_s0 == 7) {
                    var_a0 = 0;
                } else if (var_s0 == 5) {
                    if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                        var_v0 = M2C_FIELD(arg0, u8*, 0x89) & 1;
                    } else {
                        var_v0 = M2C_FIELD(arg0, u8*, 0x89) & 2;
                    }
                    if (var_v0 != 0) {
                        var_a0 = 0;
                    }
                }
                if (var_a0 != 0) {
                    use_weapon_energy(arg0, var_s0);
                }
                if ((M2C_FIELD(arg0, s8*, 0x93) == 0) &&
                    (M2C_FIELD(arg0, s8*, 0xA4) == 0)) {
                    if (var_s0 == 0) {
                        M2C_FIELD(arg0, s8*, 0xA2) = 6;
                    }
                    if (var_s0 == 9) {
                        M2C_FIELD(arg0, s8*, 0xA2) = 5;
                    }
                    if (var_s0 == 0x12) {
                        M2C_FIELD(arg0, s8*, 0xA2) = 7;
                    }
                    if (var_s0 == 0x2D) {
                        M2C_FIELD(arg0, s8*, 0xA2) = 6;
                    }
                }
            }
        } else {
            if (M2C_FIELD(arg0, s8*, 5) == 9) {
            clear:
                M2C_FIELD(arg0, s8*, 0x96) = -1;
                return;
            }
            M2C_FIELD(arg0, s8*, 0xDD) = 1;
            M2C_FIELD(arg0, s8*, 0x8F) = 1;
        }
    }
}
