#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0();
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern struct X4_PlayerObj D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)

void func_800F7788(void* arg0) {
    s32 ang;

    ((M2C_UNK(*)())func_80017A04)();
    {
        s32 u = M2C_FIELD(arg0, u8*, 7);
        register s32 t asm("$2") = M2C_FIELD(arg0, s8*, 7); // !FAKE: inherited from src/shared/rock_02/func_800F8A80.c
        if (t != 0) {
            s32 c = u - 1;
            M2C_FIELD(arg0, s8*, 7) = c;
            if ((s8)c == 0) {
                ang = func_80065B74(
                    D_800970A0.y_pos.i.hi - M2C_FIELD(arg0, s16*, 0xE),
                    D_800970A0.x_pos.i.hi - M2C_FIELD(arg0, s16*, 0xA));
                {
                    s32 t;
                    s32 w;
                    s32 u;
                    s32 x;
                    t = func_80065A14(ang);
                    w = t << 4;
                    M2C_FIELD(arg0, s32*, 0x20) = (t << 6) + w;
                    u = -func_80065944(ang);
                    x = u << 4;
                    M2C_FIELD(arg0, s32*, 0x24) = (u << 6) + x;
                }
                func_80016C48(2, 0x7D, arg0);
            }
        } else {
            func_8002D2B0((s32)arg0);
        }
    }
}
#undef D_800970A0
