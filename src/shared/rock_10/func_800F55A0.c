#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK move_object(s32);
extern M2C_UNK D_8007433C;
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800CCF38;

#define OFS_X M2C_FIELD(arg0, s16*, 0x84)
#define OFS_Y M2C_FIELD(arg0, s16*, 0x86)
#define ABS(x) ((x) < 0 ? -(x) : (x))

void func_800F55A0(struct X4_AnimatedObj* arg0) {
    s32 angle;
    s32 s;

    angle =
        ratan2(arg0->y_pos.i.hi - (background_objects[0].y_pos.i.hi + OFS_Y),
               (background_objects[0].x_pos.i.hi + OFS_X) - arg0->x_pos.i.hi);
    arg0->x_vel.val = rcos(angle) << 6;
    s = rsin(angle);
    arg0->y_vel.val = s << 6;
    if (D_800CCF38 >= 2) {
        arg0->x_vel.val = arg0->x_vel.val * 5 / 4;
        arg0->y_vel.val = arg0->y_vel.val * 5 / 4;
    }
    if (arg0->y_vel.val > 0) {
        if (arg0->x_vel.val != 0) {
            func_800179A4(arg0, 0x25);
        } else {
            func_800179A4(arg0, 0x27);
        }
    } else if (arg0->y_vel.val < 0) {
        if (arg0->x_vel.val != 0) {
            func_800179A4(arg0, 0x26);
        } else {
            func_800179A4(arg0, 0x28);
        }
    } else {
        func_800179A4(arg0, 0x25);
    }
    if (arg0->unk17 == 0x27 || arg0->unk17 == 0x28) {
        if (arg0->x_pos.i.hi - background_objects[0].x_pos.i.hi < 0xA0) {
            arg0->unk15 = 0x40;
        } else {
            arg0->unk15 = 0;
        }
    } else if (arg0->x_vel.val >= 0) {
        arg0->unk15 = 0x40;
    } else {
        arg0->unk15 = 0;
    }
    ((void (*)(struct X4_AnimatedObj*))move_object)(arg0);
    if (ABS(OFS_X - (arg0->x_pos.i.hi - background_objects[0].x_pos.i.hi)) <
        4) {
        if (ABS(OFS_Y - (arg0->y_pos.i.hi - background_objects[0].y_pos.i.hi)) <
            4) {
            arg0->x_pos.i.hi = background_objects[0].x_pos.i.hi + OFS_X;
            arg0->y_pos.i.hi = background_objects[0].y_pos.i.hi + OFS_Y;
            M2C_FIELD(arg0, s16*, 0x7E)++;
            if (M2C_FIELD(arg0, s16*, 0x7E) >= 4) {
                ((void (*)(void*, s32))func_800179A4)(arg0, 6);
                M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
                M2C_FIELD(arg0, u8*, 0x8E) = 1;
                arg0->unk7 = 0;
                arg0->unk6++;
                return;
            }
            func_800179A4(arg0, 0x11);
            func_80016C48(2, 0x5A, arg0);
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, s32*, 0x54) = 0;
            arg0->unk6 = 4;
        }
    }
}

#undef OFS_X
#undef OFS_Y
#undef ABS
