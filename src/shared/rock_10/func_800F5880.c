#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_boss_level();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
void func_800F74D8(void* arg0, s16 arg1, s16 arg2, u8 arg3);
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800E9E28[];

void func_800F5880(struct X4_AnimatedObj* arg0) {
    u8 sp10[4];
    s32 x;
    s32 y;

    __builtin_memcpy(sp10, D_800E9E28, 4);
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        func_8003D308(0x14, 0x40);
    }
    if (*M2C_FIELD(arg0, s8**, 0x80) == 0) {
        g_playthrough_state.enable_boss = 1;
        g_playthrough_state.unk25 = 0;
        g_playthrough_state.boss_ptr = (struct X4_MainObj*)arg0;
        set_boss_level();
        M2C_FIELD(&g_playthrough_state, u8*, 0x8C) =
            sp10[M2C_FIELD(&g_playthrough_state, u8*, 0x8F)] + 0x20;
        x = (u16)background_objects[0].x_pos.i.hi + 0xF0;
        arg0->x_pos.i.hi = x;
        y = (u16)background_objects[0].y_pos.i.hi + 0x90;
        arg0->y_pos.i.hi = y;
        arg0->unk18.val = arg0->x_pos.val;
        arg0->unk1C.val = arg0->y_pos.val;
        func_800F74D8(arg0, x, y, 0);
        arg0->unk7 = 0;
        arg0->unk6++;
    }
}
