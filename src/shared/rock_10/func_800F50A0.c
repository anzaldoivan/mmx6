#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK move_object(s32);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern M2C_UNK D_8007433C;
extern struct X4_PlayerObj g_Player;
extern s32 D_800FD004;

void func_800F50A0(void* arg0) {
    s32 ang;
    s32 d;

    {
        s32 px = g_Player.x_pos.i.hi;
        s32 py = g_Player.y_pos.i.hi;
        ang = func_80065B74(M2C_FIELD(arg0, s16*, 0xE) - py,
                            px - M2C_FIELD(arg0, s16*, 0xA));
    }
    M2C_FIELD(arg0, s32*, 0x20) = func_80065A14(ang) << 4;
    M2C_FIELD(arg0, s32*, 0x24) = func_80065944(ang) << 4;
    d = g_Player.x_pos.i.hi - M2C_FIELD(arg0, s16*, 0xA);
    if (d >= 0) {
        d = d < 7;
    } else {
        d = M2C_FIELD(arg0, s16*, 0xA) - g_Player.x_pos.i.hi < 7;
    }
    if (d != 0) {
        d = g_Player.y_pos.i.hi - M2C_FIELD(arg0, s16*, 0xE);
        if (d >= 0) {
            if (d >= 7) {
                goto block7;
            }
        } else {
            if (M2C_FIELD(arg0, s16*, 0xE) - g_Player.y_pos.i.hi < 7) {
                goto end;
            }
            goto block7;
        }
        goto end;
    }
block7:
    if (M2C_FIELD(arg0, s32*, 0x20) >= 0) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    if (D_800FD004 != 0) {
        D_800FD004--;
    } else {
        move_object(arg0);
    }
end:
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        func_800179A4(arg0, 6);
        {
            // !FAKE: depin: dropping it breaks the match (83/90)
            register void* p asm("$2") = &D_8007433C;
            M2C_FIELD(arg0, void**, 0x58) = p;
        }
        M2C_FIELD(arg0, u8*, 0x8E) = 1;
        M2C_FIELD(arg0, u8*, 7) = 0;
        M2C_FIELD(arg0, u8*, 6)++;
    }
}
