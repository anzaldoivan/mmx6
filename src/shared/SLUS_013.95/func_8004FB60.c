#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
s32 func_8002CAB4(struct X4_BaseObj*);
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
void func_80049E50(struct X4_MainObj*);
void func_8004FF00(u8, s32);
void func_8004FF7C(void*, s32);
extern s32 D_80078CA0[];

void func_8004FB60(u8* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    (*(void (**)(u8*))((((s8)arg0[5]) << 2) + (s32)D_80078CA0))(arg0);
    if (func_80031474(arg0) < 0) {
        func_8004FF7C(arg0, 0x31);
        func_8004FF00(arg0[2], 3);
        arg0[3] = 0;
        func_80049E50((struct X4_MainObj*)arg0);
        {
            // !FAKE: keeps the first arm's state store out of the cross-jump
            register s32 st asm("$3") = 8;
            arg0[4] = st;
        }
    } else {
        func_80030ECC(arg0);
        if (func_8002CAB4((struct X4_BaseObj*)arg0) == 0) {
            func_8002CCB0(arg0, 0x20, 0x20);
            if (arg0[0x83] != 0) {
                *(u16*)(arg0 + 0x42) |= 0x8000;
            }
        } else {
            func_8004FF00(arg0[2], 4);
            arg0[4] = 8;
        }
    }
}
