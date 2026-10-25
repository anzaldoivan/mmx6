#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C3F8();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj g_Player;
extern s16 D_8009721E;

void func_800F3390(u8* arg0) {
    u8* temp_v0;

    if (g_Player.unk5 == 0x14) {
        temp_v0 = func_8002C3F8();
        if (temp_v0 != 0) {
            temp_v0[0] = 1;
            temp_v0[1] = 0x18;
            M2C_FIELD(arg0, u8**, 0x80) = temp_v0;
        }
    }
    if (g_Player.x_pos.i.hi > (D_8009721E + 0x40)) {
        ((void (*)(s32, s32))func_8003D308)(0x1D, 0);
    }
    arg0[6] = arg0[6] + 1;
}
