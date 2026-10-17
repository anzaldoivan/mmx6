#include "common.h"
#include "mmx6/x4.h"

s32 func_8001C5EC(u8);
void func_800ED45C();
void func_800EE19C(void);
void func_800EE878(struct X4_MiscObj*);
extern u8 D_8006D620;
extern u8 D_80097427;
extern struct X4_MiscObj D_800E2F90;

void func_800EC104(u8* arg0) {
    s32 ret;
    s32 done;

    if (D_800E2F90.x_pos.bytes[2] != 0) {
        D_800E2F90.x_pos.bytes[2]--;
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
    func_800EE19C();
    func_800EE878(&D_800E2F90);
    if ((s8)arg0[1] != 0x15) {
        D_8006D620 = D_80097427;
        arg0[3] = 0xC;
        arg0[1] = arg0[1] + 1;
        func_800ED45C();
    }
}
