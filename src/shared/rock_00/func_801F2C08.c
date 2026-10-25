#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_80077AB0;
extern s32 D_801F3AF0;
extern s16 D_801F3AF4[];
M2C_UNK func_800179A4(void*, M2C_UNK);
#define func_800179A4 ((void (*)(void*, s32))func_800179A4)
void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK func_8002C9B0();
void func_8003CF24(s32, s32, s32);
#define SCRATCH_1C (*(u8**)0x1F80001C)

void func_801F2C08(u8* arg0) {
    struct X4_PlayerObj* player = &g_Player;
    u8* scr;
    s32 i;

    if (M2C_FIELD(player, s8*, 5) != 0x4A) {
        func_8002C9B0(arg0);
        return;
    }
    if (M2C_FIELD(arg0, s8*, 4) == 0) {
        if (M2C_FIELD(player, s8*, 0x7A) == 0) {
            return;
        }
        if (!(M2C_FIELD(player, s8*, 0x45) & 0x80)) {
            return;
        }
        M2C_FIELD(arg0, s8*, 6) = M2C_FIELD(player, u8*, 0xD9) / 30;
        M2C_FIELD(arg0, u8*, 0x64) = 1;
        M2C_FIELD(arg0, s32**, 0x50) = &D_801F3AF0;
        scr = SCRATCH_1C;
        scr += M2C_FIELD(scr, s32*, 0x18);
        M2C_FIELD(arg0, s32**, 0x30) = &D_80077AB0;
        M2C_FIELD(arg0, s16*, 0x40) = 0;
        M2C_FIELD(arg0, s16*, 0x42) = 0x784A;
        M2C_FIELD(arg0, u8*, 0x16) = 0;
        M2C_FIELD(arg0, u8**, 0x3C) = scr;
        func_8003CF24(0x54, 0x1A, 1);
        if (M2C_FIELD(player, s32*, 0x24) != 0) {
            if (M2C_FIELD(player, s32*, 0x24) > 0) {
                func_800179A4(arg0, 0);
                M2C_FIELD(arg0, s8*, 5) = 0;
            } else {
                func_800179A4(arg0, 1);
                M2C_FIELD(arg0, s8*, 5) = 1;
            }
        } else {
            func_800179A4(arg0, 2);
            M2C_FIELD(arg0, s8*, 5) = 2;
            if (M2C_FIELD(player, u8*, 0x15) != 0) {
                M2C_FIELD(arg0, s8*, 5) = 3;
            }
        }
        M2C_FIELD(arg0, u8*, 3) = 1;
        M2C_FIELD(arg0, s8*, 4)++;
    } else {
        if (M2C_FIELD(player, s8*, 0x7A) == 0) {
            func_8002C9B0(arg0);
            return;
        }
        func_80017A04((struct X4_AnimatedObj*)arg0);
        if (M2C_FIELD(arg0, u8*, 0x8C) == 0) {
            M2C_FIELD(arg0, u8*, 0x8C) = 4;
            M2C_FIELD(arg0, u8*, 0x64)++;
        } else {
            M2C_FIELD(arg0, u8*, 0x8C)--;
        }
    }
    i = M2C_FIELD(arg0, s8*, 5) * 4;
    M2C_FIELD(arg0, s16*, 0xA) =
        M2C_FIELD(player, s16*, 0xA) + *(s16*)(i + (u8*)D_801F3AF4);
    M2C_FIELD(arg0, s16*, 0xE) =
        M2C_FIELD(player, s16*, 0xE) + ((s16*)((u8*)D_801F3AF4 + i))[1];
    M2C_FIELD(arg0, u8*, 0x15) = M2C_FIELD(player, u8*, 0x15);
}
#undef g_Player
#undef func_800179A4
