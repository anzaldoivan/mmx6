#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
extern M2C_UNK g_Player;
#define PL_150 (*(s8*)(pl + 0x150))
#define PL_FC (*(s32*)(pl + 0xFC))

s32 func_8002CFB0(void* arg) {
    struct X4_PlayerObj* arg0 = arg;
    s32 vx;
    s32 vy;
    u8* pl = (u8*)&g_Player;

    if ((PL_150 != 0) && (arg0->unk15 != 0)) {
        vx = arg0->x_vel.val;
        vy = arg0->y_vel.val;
        arg0->y_pos.val = arg0->y_pos.val - vy;
        arg0->x_vel.val = vx + arg0->unk28;
        arg0->y_vel.val = vy - arg0->unk2C;
        arg0->x_pos.val = arg0->x_pos.val + ((vx * 0x56) / 100);
        vy = arg0->y_vel.val;
        if (vy < PL_FC) {
            arg0->y_vel.val = PL_FC;
        }
    } else {
        arg0->x_pos.val = arg0->x_pos.val + arg0->x_vel.val;
        arg0->y_pos.val = arg0->y_pos.val - arg0->y_vel.val;
        if (arg0->unk15 != 0) {
            arg0->x_vel.val = arg0->x_vel.val + arg0->unk28;
        } else {
            arg0->x_vel.val = arg0->x_vel.val - arg0->unk28;
        }
        arg0->y_vel.val = arg0->y_vel.val - arg0->unk2C;
        {
            u8* pl = (u8*)&g_Player;
            if (arg0->y_vel.val < PL_FC) {
                arg0->y_vel.val = PL_FC;
            }
        }
    }
}
