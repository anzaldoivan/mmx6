#include "common.h"

s32 func_8003A814(void* arg0, s32 arg1) {
    s32 v;

    switch (arg1 & 0xFF) {
    case 0x2D:
        v = 0;
        break;
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
        v = 1;
        if (((u8*)arg0)[0x15] == 0) {
            v = 2;
        }
        break;
    default:
        v = 2;
        if (((u8*)arg0)[0x15] == 0) {
            v = 1;
        }
        break;
    }
    return v;
}
