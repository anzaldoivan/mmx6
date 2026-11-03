// prog SLUS_013.95 | system player | range 0x8002CFB0-0x8002D0D4
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
extern M2C_UNK g_Player;
#define PL_150 (*(s8*)(pl + 0x150))
#define PL_FC (*(s32*)(pl + 0xFC))

s32 apply_player_motion(void* arg) {
    struct X4_PlayerObj* arg0 = arg;
    s32 vx;
    s32 vy;
    u8* pl = (u8*)&g_Player;

    if ((PL_150 != 0) && (arg0->facing != 0)) {
        vx = arg0->x_vel.val;
        vy = arg0->y_vel.val;
        arg0->y_pos.val = arg0->y_pos.val - vy;
        arg0->x_vel.val = vx + arg0->x_accel;
        arg0->y_vel.val = vy - arg0->gravity;
        arg0->x_pos.val = arg0->x_pos.val + ((vx * 0x56) / 100);
        vy = arg0->y_vel.val;
        if (vy < PL_FC) {
            arg0->y_vel.val = PL_FC;
        }
    } else {
        arg0->x_pos.val = arg0->x_pos.val + arg0->x_vel.val;
        arg0->y_pos.val = arg0->y_pos.val - arg0->y_vel.val;
        if (arg0->facing != 0) {
            arg0->x_vel.val = arg0->x_vel.val + arg0->x_accel;
        } else {
            arg0->x_vel.val = arg0->x_vel.val - arg0->x_accel;
        }
        arg0->y_vel.val = arg0->y_vel.val - arg0->gravity;
        {
            u8* pl = (u8*)&g_Player;
            if (arg0->y_vel.val < PL_FC) {
                arg0->y_vel.val = PL_FC;
            }
        }
    }
}
