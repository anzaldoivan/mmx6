#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s8 func_8001C1AC(u8);
s32 func_8001C5EC(u8);
s32 memcard_format(s32 device_num);
M2C_UNK func_8002B838();
extern u8 D_80097427;
extern struct X4_MiscObj D_800E2F90;
extern s8 D_800E30EA;

void func_800EB964(u8* arg0) {
    s32 ret;
    s32 done;
    u32 sel;

    if (D_800E2F90.x_pos.bytes[2] != 0) {
        D_800E2F90.x_pos.bytes[2] = D_800E2F90.x_pos.bytes[2] - 1;
        return;
    }
    ret = func_8001C5EC(D_800E2F90.unk6);
    if (ret != 0) {
        s32 one = 1;
        s32 two = 2;

        if (ret == one) {
            arg0[1] = 0x15;
            D_800E2F90.x_pos.bytes[0] = one;
        } else {
            arg0[1] = 0x15;
            D_800E2F90.x_pos.bytes[0] = two;
        }
        arg0[3] = one;
        do {
            D_80097427 = 0;
        } while (0);
        done = 1;
    } else {
        done = 0;
    }
    if (done != 0) {
        return;
    }
    sel = (u8)func_8001C1AC(D_800E2F90.unk6);
    if (sel != 0 && sel != 2) {
        ((void (*)())func_8002B838)();
        D_80097427 = 0;
        arg0[1] = 0x15;
        arg0[2] = 0;
        if (sel == 1) {
            D_800E2F90.x_pos.bytes[0] = 0;
            arg0[3] = 1;
            return;
        }
        D_800E2F90.x_pos.bytes[0] = 4;
        arg0[3] = 1;
        return;
    }
    if (memcard_format((u8)D_800E2F90.unk6) == 0) {
        s32 ff = 0xFF;

        arg0[2] = arg0[2] + 1;
        ((u8*)D_800E2F90.y_pos.val)[0] = ff;
        ((u8*)D_800E2F90.y_pos.val)[0x3BC] = ff;
        ((u8*)D_800E2F90.y_pos.val)[0x778] = ff;
        ((u8*)D_800E2F90.y_pos.val)[0xB34] = ff;
        ((u8*)D_800E2F90.y_pos.val)[0xEF0] = ff;
        ((u8*)D_800E2F90.y_pos.val)[0x12AC] = ff;
        ((u8*)D_800E2F90.y_pos.val)[0x1668] = ff;
        ((u8*)D_800E2F90.y_pos.val)[0x1A24] = ff;
        D_800E30EA = 0;
        arg0[3] = 0xF;
    } else {
        ((void (*)())func_8002B838)();
        D_800E2F90.x_pos.bytes[0] = 4;
        arg0[1] = 0x15;
        arg0[2] = 0;
        arg0[3] = 0x10;
    }
}
