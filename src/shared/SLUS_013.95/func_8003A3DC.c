#include "common.h"

s32 func_8002FD3C(void* arg0);
s32 func_80030068(void* arg0);
void func_8003B63C(void*);
void func_8003B708(void*);

s32 func_8003A3DC(void* arg0) {
    u8* p = arg0;

    if (*(s8*)(p + 0xD3) != 0) {
        return 0;
    }
    if (p[0x92] != 0) {
        return 0;
    }
    if ((*(u16*)(p + 0x7C) & 4) && func_8002FD3C(p) == 0x20) {
        func_8003B63C(p);
        return 1;
    }
    if (!(*(u16*)(p + 0x7C) & 8)) {
        return 0;
    }
    if (func_80030068(p) != 0x21) {
        return 0;
    }
    func_8003B708(p);
    return 1;
}
