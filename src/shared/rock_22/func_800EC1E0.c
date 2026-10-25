#include "common.h"

#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003D308(M2C_UNK, u8);
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];

void func_800EC1E0(void* arg0) {
    if (g_Player.x_pos.i.hi >= 0x1C21) {
        background_objects[0].unk26 = 0x1B70;
        background_objects[0].unk2A = 0x1E0;
        background_objects[0].unk28 = 0x1E0;
        func_8003D308(0x14, g_Player.unk15);
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
