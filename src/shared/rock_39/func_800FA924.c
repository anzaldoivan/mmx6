#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002D2B0();
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
M2C_UNK func_800FBAAC(void*, M2C_UNK);
void func_800FF9AC(struct X4_AnimatedObj*);
extern struct X4_BackgroundObj D_800971F8[3];

#define OFS_X M2C_FIELD(arg0, s16*, 0x84)
#define OFS_Y M2C_FIELD(arg0, s16*, 0x86)
#define U6 M2C_FIELD(arg0, u8*, 6)
#define U7 M2C_FIELD(arg0, u8*, 7)
#define ABS(x) ((x) < 0 ? -(x) : (x))

void func_800FA924(struct X4_AnimatedObj* arg0) {
    s32 angle;
    s32 cnt;
    register s32 st asm("$2");

    angle =
        func_80065B74(arg0->y_pos.i.hi - (D_800971F8[0].y_pos.i.hi + OFS_Y),
                      (D_800971F8[0].x_pos.i.hi + OFS_X) - arg0->x_pos.i.hi);
    arg0->x_vel.val = (func_80065A14(angle) << 4) * (arg0->unk7 / 2 + 6);
    arg0->y_vel.val = (func_80065944(angle) << 4) * (arg0->unk7 / 2 + 6);
    if (arg0->x_vel.val >= 0) {
        arg0->unk15 = 0x40;
    } else {
        arg0->unk15 = 0;
    }
    ((void (*)(struct X4_AnimatedObj*))func_8002D2B0)(arg0);
    if (ABS(OFS_X - (arg0->x_pos.i.hi - D_800971F8[0].x_pos.i.hi)) < 6) {
        if (ABS(OFS_Y - (arg0->y_pos.i.hi - D_800971F8[0].y_pos.i.hi)) < 6) {
            func_80016C48(2, 0x55, arg0);
            func_80012D9C(6);
            arg0->x_pos.i.hi = D_800971F8[0].x_pos.i.hi + OFS_X;
            arg0->y_pos.i.hi = D_800971F8[0].y_pos.i.hi + OFS_Y;
            cnt = U7 + 1;
            arg0->unk7 = cnt;
            if ((s8)cnt >= 8) {
                func_800FBAAC(arg0, 0);
                func_800FF9AC(arg0);
                func_800179A4(arg0, 0x14);
                arg0->unk7 = 0;
                st = U6 + 1;
            } else {
                if ((s8)cnt == 3) {
                    func_800179A4(arg0, 0);
                }
                st = U6 - 1;
            }
            arg0->unk6 = st;
        }
    }
}

#undef OFS_X
#undef OFS_Y
#undef U6
#undef U7
#undef ABS
