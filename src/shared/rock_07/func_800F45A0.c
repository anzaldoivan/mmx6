#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_boss_level();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800E9A6C[];

void func_800F45A0(void* arg0) {
    u8 buf[4];

    __builtin_memcpy(buf, D_800E9A6C, 4);
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        func_8003D308(0x14, 0x40);
    }
    if (*M2C_FIELD(arg0, s8**, 0x80) == 0) {
        g_playthrough_state.enable_boss = 1;
        g_playthrough_state.unk25 = 0;
        g_playthrough_state.boss_ptr = arg0;
        set_boss_level();
        {
            // !FAKE: depin: dropping it breaks the match (45/53)
            register s32 k asm("$3") =
                M2C_FIELD(&g_playthrough_state, u8*, 0x8F);
            M2C_FIELD(&g_playthrough_state, s8*, 0x8C) = buf[k] + 0x30;
        }
        M2C_FIELD(arg0, u16*, 0x7C) = 0x78;
        M2C_FIELD(arg0, u8*, 0x7) = 0;
        M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
    }
}
