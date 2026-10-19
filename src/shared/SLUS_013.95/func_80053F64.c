#include "common.h"

void func_80013A48(s8 arg0);

void func_80053F64(void* arg0) {
    u8* p = (u8*)arg0;
    s32 temp_v0;

    temp_v0 = *(u16*)(p + 0x14) - 1;
    *(u16*)(p + 0x14) = temp_v0;
    if ((temp_v0 & 0xFFFF) == 0xFFFF) {
        func_80013A48(0x19);
        p[4] = p[4] + 1;
    }
}
