#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern struct X4_PlayerObj g_Player;
extern u8 D_800CCF38;

void func_800EDD88(void* arg0) {
    s32 angle;
    s32 v;
    s32 t;
    u16 c;

    func_80017A04();
    {
        // !FAKE: depin: dropping it breaks the match (53/60)
        register s32 cc asm("$2") = M2C_FIELD(arg0, u16*, 0x8C);
        M2C_FIELD(arg0, u16*, 0x8C) = cc + 1;
        c = cc;
    }
    if ((s16)c >= 0x5B) {
        {
            s32 sy = M2C_FIELD(arg0, s16*, 0xE);
            s32 dx = g_Player.x_pos.i.hi - M2C_FIELD(arg0, s16*, 0xA);
            s32 dy;
            M2C_FIELD(arg0, u16*, 0x8E) = g_Player.x_pos.i.hi;
            {
                // !FAKE: depin: dropping it breaks the match (55/60)
                register s32 py asm("$3") = g_Player.y_pos.i.hi;
                dy = py - sy;
            }
            M2C_FIELD(arg0, u16*, 0x90) = g_Player.y_pos.i.hi;
            angle = func_80065B74(dy, dx);
        }
        v = func_80065A14(angle);
        t = v * 16;
        M2C_FIELD(arg0, s32*, 0x20) = v * 64 + t;
        v = -func_80065944(angle);
        t = v * 16;
        M2C_FIELD(arg0, s32*, 0x24) = v * 64 + t;
        M2C_FIELD(arg0, u16*, 0x8C) = 0;
        if (D_800CCF38 >= 2) {
            M2C_FIELD(arg0, u8*, 0x6) += 1;
        } else {
            M2C_FIELD(arg0, u8*, 0x6) += 3;
        }
    }
}
