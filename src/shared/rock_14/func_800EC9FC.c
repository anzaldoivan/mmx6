#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_8003D330();
extern s8 D_80097170;
extern struct X4_EngineObj g_playthrough_state;

void func_800EC9FC(void* arg0) {
    s32 i;
    s8* p;

    ((void (*)())func_80017A04)();
    if ((M2C_FIELD(arg0, s16*, 0x7C) == 0 ||
         --M2C_FIELD(arg0, s16*, 0x7C) == 0) &&
        D_80097170 < 0) {
        ((void (*)())func_8003D330)();
        if (M2C_FIELD(arg0, s8*, 2) != 0xA) {
            g_playthrough_state.checkpoint = M2C_FIELD(arg0, u8*, 2) & 0xF;
            g_playthrough_state.unkF = -0x40;
        } else {
            g_playthrough_state.unkF = 0x40;
            i = 0xF;
            p = &g_playthrough_state.character_state.bytes[0xF];
            do {
                *p = 0;
                i--;
                p--;
            } while (i >= 0);
        }
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
