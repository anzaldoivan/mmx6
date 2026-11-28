#include "common.h"
#include "mmx6/class4.h"
#include "mmx6/globals.h"

extern s16 D_800E41A6;
extern s16 D_800E41B0[][4];

#define CLASS4_SLOTS ((struct Class4Obj*)g_class4_slots)

/* Collects the world hitbox rect (x0, x1, y0, y1) of every live class-4 slot with a hitbox
   into D_800E41B0, count in D_800E41A6. dir 0x40 mirrors the x offset. The +0x68 hitbox is
   {s8 x, s8 y, u8 w, u8 h}, read through byte casts of terrain_box at each use (C0412). */
void func_8002E84C(void) {
    s32 i;
    s16 x;
    s16 y;

    D_800E41A6 = 0;
    for (i = 0; i < 0x50; i++) {
        if (CLASS4_SLOTS[i].active != 0 && CLASS4_SLOTS[i].alive != 0 &&
            CLASS4_SLOTS[i].terrain_box != NULL) {
            if (CLASS4_SLOTS[i].dir == 0x40) {
                x = CLASS4_SLOTS[i].x - ((s8*)CLASS4_SLOTS[i].terrain_box)[0];
            } else {
                x = CLASS4_SLOTS[i].x + ((s8*)CLASS4_SLOTS[i].terrain_box)[0];
            }
            D_800E41B0[D_800E41A6][0] =
                x - ((u8*)CLASS4_SLOTS[i].terrain_box)[2];
            D_800E41B0[D_800E41A6][1] =
                ((u8*)CLASS4_SLOTS[i].terrain_box)[2] + x - 1;
            y = CLASS4_SLOTS[i].y + ((s8*)CLASS4_SLOTS[i].terrain_box)[1];
            D_800E41B0[D_800E41A6][2] =
                y - ((u8*)CLASS4_SLOTS[i].terrain_box)[3];
            D_800E41B0[D_800E41A6][3] =
                ((u8*)CLASS4_SLOTS[i].terrain_box)[3] + y - 1;
            D_800E41A6++;
        }
    }
}

#undef CLASS4_SLOTS
