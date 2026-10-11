#include "common.h"

void* func_8002BBF4();

void func_800F54B8(s32 arg0, void* arg1) {
    u8 v = arg0;
    u8* p = func_8002BBF4();

    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0xF;
        p[2] = v;
    }
}
