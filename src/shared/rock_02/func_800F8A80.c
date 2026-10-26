#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
M2C_UNK move_object(s32);
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_800F8A80(void* arg0) {
    s32 ang;

    ((M2C_UNK(*)())func_80017A04)();
    {
        s32 u = M2C_FIELD(arg0, u8*, 7);
        // !FAKE: depin: dropping it breaks the match (45/49)
        register s32 t asm("$2") = M2C_FIELD(arg0, s8*, 7);
        if (t != 0) {
            s32 c = u - 1;
            M2C_FIELD(arg0, s8*, 7) = c;
            if ((s8)c == 0) {
                ang = ratan2(g_Player.y_pos.i.hi - M2C_FIELD(arg0, s16*, 0xE),
                             g_Player.x_pos.i.hi - M2C_FIELD(arg0, s16*, 0xA));
                {
                    s32 t;
                    s32 w;
                    s32 u;
                    s32 x;
                    t = rcos(ang);
                    w = t << 4;
                    M2C_FIELD(arg0, s32*, 0x20) = (t << 6) + w;
                    u = -rsin(ang);
                    x = u << 4;
                    M2C_FIELD(arg0, s32*, 0x24) = (u << 6) + x;
                }
                func_80016C48(2, 0x7D, arg0);
            }
        } else {
            move_object((s32)arg0);
        }
    }
}
#undef g_Player
