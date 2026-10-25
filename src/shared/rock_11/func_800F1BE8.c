#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F1DC4(void* arg0, s32 arg1);
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCEED;
extern void* D_800FD510;
extern s8 D_800FD514;
extern s8 D_800FD51D;
extern s16 D_800FD526;
extern s16 D_800FD52A;

void func_800F1BE8(void* arg0) {
    switch (D_800FD514) {
    case 0:
        if (background_objects[0].x_pos.i.hi >= 0x800) {
            D_800FD514++;
            background_objects[0].unk26 = 0x800;
            D_800FD52A = background_objects[0].unk28;
            background_objects[0].unk2A = 0x180;
            background_objects[0].unk28 = 0x180;
            M2C_FIELD(arg0, s8*, 0x89) = 1;
            M2C_FIELD(arg0, s8*, 0x5C) = 1;
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, s32*, 0x54) = 0;
        } else if (M2C_FIELD(arg0, s8*, 0x5) != 2) {
            func_800F1DC4(arg0, 0);
        }
        break;
    case 1:
        if (M2C_FIELD(D_800FD510, s8*, 0x5C) == 0) {
            D_800FD514++;
            D_800FD51D = 1;
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, s32*, 0x54) = 0;
            M2C_FIELD(arg0, s8*, 0x5) = 8;
            M2C_FIELD(arg0, s8*, 0x6) = 0;
        }
        func_800F1DC4(arg0, 1);
        break;
    case 2:
        if (background_objects[0].x_pos.i.hi >= 0x1080) {
            D_800FD514++;
            D_800FD526 = 0;
            background_objects[0].unk26 = 0x1080;
            D_800FD52A = background_objects[0].unk28;
            background_objects[0].unk2A = 0x300;
            background_objects[0].unk28 = 0x300;
            M2C_FIELD(arg0, s8*, 0x89) = 1;
            M2C_FIELD(arg0, s8*, 0x5C) = 1;
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, s32*, 0x54) = 0;
        }
        func_800F1DC4(arg0, 0);
        break;
    case 3:
        D_800FD526++;
        if (M2C_FIELD(D_800FD510, s8*, 0x5C) == 0) {
            D_800CCEED = 2;
            D_800FD514++;
            D_800FD51D = 1;
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, s32*, 0x54) = 0;
            M2C_FIELD(arg0, s8*, 0x5) = 9;
            M2C_FIELD(arg0, s8*, 0x6) = 0;
        }
        break;
    }
}
