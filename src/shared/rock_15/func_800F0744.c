#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8002B2F8(s32);
void func_800F08C4(void* arg0);
void func_800F0A78(void* arg0);
extern s16 D_80090D5C;
extern s32 D_80097420;
extern s16 D_80097430;
extern u8 D_800C4560;
extern struct X4_EngineObj g_playthrough_state;
extern s16 D_800CF854;

void func_800F0744(void* arg0) {
    s16 t;
    s32 c;

    if (M2C_FIELD(arg0, s16*, 0x7E) != 0) {
        if (!(M2C_FIELD(arg0, u16*, 0x7E) & 1)) {
            ((void (*)())func_800F0A78)();
        }
        M2C_FIELD(arg0, s16*, 0x7E)--;
        return;
    }
    if ((u16)D_800CF854 >= 9) {
        if (!(*(u8*)&D_80097420 & 3)) {
            func_800F08C4(arg0);
        }
    }
    t = ++M2C_FIELD(arg0, s16*, 0x7C);
    if ((s16)(t % 5) == 0) {
        if ((u16)D_800CF854 >= 8) {
            func_80029478(0x1E, 8, 1);
        }
        c = (u16)D_800CF854 - 1;
        D_800CF854 = c;
        D_80097430 -= 0x20;
        D_80090D5C -= 0x400;
        D_800C4560 |= 1;
        if ((u16)c == 0) {
            func_8002B2F8(0);
            g_playthrough_state.enable_boss = 1;
            g_playthrough_state.unk25 = 1;
            g_playthrough_state.boss_ptr = arg0;
            M2C_FIELD(&g_playthrough_state, u8*, 0x8C) = 0x7F;
            M2C_FIELD(arg0, s16*, 0x7C) = 2;
            M2C_FIELD(arg0, u8*, 6)++;
        }
    }
}
