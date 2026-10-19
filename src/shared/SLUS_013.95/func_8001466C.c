#include "common.h"

extern u8 D_800A51B8[];
extern u8 D_800C4858[];

void func_80012890(s32 arg0);
void func_80017E6C(void);
void func_800144DC(u8);

#define SCR1466C_BUF (*(s32*)0x1F800000)
#define SCR1466C_PTR(off) (*(u8**)(0x1F800000 + (off)))

void func_8001466C(void) {
    s32 buf;
    u8 i;

    func_80012890(0);
    buf = SCR1466C_BUF;
    SCR1466C_PTR(0x100) = D_800A51B8 + buf * 0xA000;
    SCR1466C_PTR(0x104) = D_800C4858 + buf * 0x2000;
    func_80017E6C();
    for (i = 0; i < 10; i++) {
        func_800144DC(i);
    }
}

#undef SCR1466C_BUF
#undef SCR1466C_PTR
