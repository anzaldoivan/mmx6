#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK clear_object_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

void func_800F1F50(void* arg0) {
    s8* p;

    M2C_FIELD(arg0, s8*, 3) = 0;
    p = M2C_FIELD(SPAD4C, s8**, 0x80);
    if (p[0] != 0) {
        if (p[7] == 0) {
            if (--M2C_FIELD(arg0, s16*, 0x7E) == -1) {
                M2C_FIELD(arg0, s16*, 0x7E) = 5;
                M2C_FIELD(arg0, u16*, 0x42) ^= 0x8000;
            }
            func_8002CCB0(arg0, 0x60, 0x60);
        }
    } else {
        if (g_playthrough_state.stage != 0xC) {
            g_playthrough_state.unkF = 0x10;
        } else {
            g_playthrough_state.unkF = -0x80;
            g_playthrough_state.character_state
                .bytes[g_playthrough_state.checkpoint + 6] = 1;
            g_playthrough_state.checkpoint += 9;
        }
        {
            // !FAKE: depin: dropping it breaks the match (59/67)
            register s32 t3 asm("$5");
            g_playthrough_state.enable_boss = 0;
            g_playthrough_state.boss_ptr = 0;
            t3 = background_objects[0].y_pos.u.hi;
            background_objects[0].unk2A = t3;
            clear_object_slot(arg0, t3);
        }
    }
}
