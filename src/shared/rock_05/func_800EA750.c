#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_8002CA14();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002F288(M2C_UNK*);
s32 func_80031474(void*);
M2C_UNK func_80031DA8();
M2C_UNK func_80031F4C();
M2C_UNK func_8003208C();
M2C_UNK func_80032BE8();
M2C_UNK func_80049E50(void*);
extern u8 D_80097185;
extern s8 D_800CCEED;
extern s32 D_800F3DB4;
extern void (*D_800F3DCC[])(s8*);

void func_800EA750(s8* arg0) {
    s8 temp_s1;
    s32 var_v0;

    ((void (*)())func_80017A04)();
    if (arg0[0x45] != 0) {
        *(s32**)(arg0 + 0x68) = &D_800F3DB4;
    } else {
        *(s32**)(arg0 + 0x68) = 0;
    }
    *(u16*)(arg0 + 0x42) &= 0x7FFF;
    temp_s1 = arg0[0x5C];
    D_800F3DCC[arg0[5]](arg0);
    if (func_80031474(arg0) < 0) {
        func_80049E50(arg0);
        *(s16*)(arg0 + 0x7C) = 0;
        arg0[4] = 2;
        return;
    }
    if (arg0[0x5C] != temp_s1) {
        *(u16*)(arg0 + 0x42) |= 0x8000;
    }
    func_80032BE8(arg0);
    func_8003208C(arg0);
    if (func_8002CBFC(arg0, 0x40, 0xF0) == 0) {
        func_8002CCB0(arg0, 0x20, 0x20);
    }
    if (D_800CCEED >= arg0[2]) {
        arg0[3] = 0;
        func_8002CA14(arg0);
        return;
    }
    func_8002CCB0(arg0, 0x20, 0x20);
    ((void (*)(M2C_UNK*))func_8002F288)((M2C_UNK*)arg0);
    if (D_80097185 == 0) {
        func_80031DA8(arg0);
    }
    func_80031F4C(arg0);
    if ((u8)arg0[0x70] & 8) {
        arg0[0x67] = 0;
        return;
    }
    var_v0 = *(s32*)(arg0 + 0x24);
    if (var_v0 < 0) {
        var_v0 = -1;
    } else {
        var_v0 = 1;
    }
    arg0[0x67] = var_v0;
}
