#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

void func_800F8FB4(void* arg0) {
    void* temp_v1;

    temp_v1 = M2C_FIELD(arg0, void**, 0x80);
    M2C_FIELD(arg0, s8*, 3) = 0;
    if (M2C_FIELD(temp_v1, s8*, 0) != 0) {
        if (M2C_FIELD(temp_v1, s8*, 7) == 0) {
            if (--M2C_FIELD(arg0, s16*, 0x7E) == -1) {
                M2C_FIELD(arg0, s16*, 0x7E) = 5;
                M2C_FIELD(arg0, u16*, 0x42) ^= 0x8000;
            }
            func_8002CCB0(arg0, 0x60, 0x60);
        }
    } else {
        s32 y;
        g_playthrough_state.unkF = 0x10;
        g_playthrough_state.enable_boss = 0;
        g_playthrough_state.boss_ptr = 0;
        y = background_objects[0].y_pos.u.hi;
        background_objects[0].unk2A = y;
        clear_object_slot(arg0);
    }
}
