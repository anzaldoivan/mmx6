#include "common.h"

s32 func_8003A394(void* arg0) {
    u8* p = arg0;

    if (*(s8*)(p + 0xD3) != 0) {
        return 0;
    }
    if (*(s8*)(p + 0x4A) == 0) {
        return 0;
    }
    return (*(u16*)(p + 0x7C) & 3 & p[0x89]) != 0;
}
