#include "common.h"

void func_80025984(void*, u8);

void func_8002619C(u8* arg0) {
    if (arg0[0xE7] == 4) {
        func_80025984(arg0, arg0[0xDC]);
        return;
    }
    if ((((s8*)arg0)[5] != 1) || (arg0[0x47] != 0x7E)) {
        func_80025984(arg0, arg0[0xDC]);
    }
}
