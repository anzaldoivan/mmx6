#include "common.h"

void func_80017A04();
void func_8002C9B0();
s32 func_8002CBFC();
s32 func_8002CCB0();

void func_800EC084(u8* arg0) {
    s8* s1;

    s1 = *(s8**)(arg0 + 0x50);
    if (s1[5] != 3) {
        arg0[4] = 1;
    }
    func_80017A04(arg0);
    if (func_8002CBFC(arg0, 0x80, 0x80) == 0) {
        func_8002CCB0(arg0, 0x60, 0x60);
    } else {
        func_8002C9B0(arg0);
    }
    if (s1[4] == 2) {
        func_8002C9B0(arg0);
    }
}
