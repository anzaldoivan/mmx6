#include "common.h"
#define M2C_UNK s32

extern s32 D_8006D894;
extern s32 D_8006D9A4;
extern s8 D_8006D9A8;
extern s32 D_8008EC0C;
extern s16 D_8009741A;
extern s8 D_80097424;
extern u16 D_800C456C[];
extern u8 D_800E4188;

M2C_UNK func_800133F4(M2C_UNK);
void func_80016B3C();
void func_8001D218();
void func_8001D25C(void);
void func_8002C1DC();
M2C_UNK func_800660B8(M2C_UNK);

void func_80012EB4(void) {
    if (D_8008EC0C != 0 && D_80097424 == 0) {
        if ((D_800C456C[0] & 0x900) == 0x900) {
            if (--D_8009741A == 0) {
                D_8006D894 = 0;
                D_8006D9A4 = 0;
                D_8006D9A8 = 0;
                D_8008EC0C = 0;
                D_800E4188 = 0;
                func_800660B8(0);
                func_800133F4(0);
                func_800133F4(1);
                func_800133F4(2);
                func_800133F4(3);
                D_8009741A = 0x3C;
                func_8001D218();
                func_80016B3C();
                func_8002C1DC();
                func_8001D25C();
            }
        } else {
            D_8009741A = 0x3C;
        }
    }
}
