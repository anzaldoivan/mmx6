#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80020378(void);
void func_8002048C(void);
void func_800206C0(void);
void func_800207D4(void);
void func_80025FB0();
void func_8002ACA8();
extern struct X4_BackgroundObj D_800971F8[3];
extern s16 D_800EA2C8[];

void func_800E9A88(struct X4_MainObj* arg0) {
    D_800971F8[0].unk14 = D_800971F8[0].x_pos;
    D_800971F8[0].unk18 = D_800971F8[0].y_pos;
    ((void (**)(struct X4_MainObj*)) & D_800EA2C8[0x130])[arg0->id](arg0);
    func_8002048C();
    func_80020378();
    func_800206C0();
    func_800207D4();
    func_8002ACA8();
    func_80025FB0();
}
