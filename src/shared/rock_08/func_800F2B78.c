#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_boss_level();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s8 D_80097240;
extern struct X4_EngineObj g_playthrough_state;

void func_800F2B78(void* arg0) {
    u8* e;

    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        func_8003D308(0x14, 0x40);
    }
    if (*M2C_FIELD(arg0, s8**, 0x8C) == 0) {
        e = (u8*)&g_playthrough_state;
        M2C_FIELD(e, s8*, 0x24) = 1;
        M2C_FIELD(e, s8*, 0x25) = 0;
        M2C_FIELD(e, void**, 0x20) = arg0;
        M2C_FIELD(e, u8*, 0x8C) = 0x28;
        set_boss_level();
        {
            s32 a = M2C_FIELD(e, u8*, 0x8C);
            M2C_FIELD(arg0, s32*, 0x20) = 0xFFFD0000;
            M2C_FIELD(arg0, u8*, 0x85) = a;
            M2C_FIELD(arg0, u8*, 6)++;
        }
        D_80097240 = 2;
    }
}
