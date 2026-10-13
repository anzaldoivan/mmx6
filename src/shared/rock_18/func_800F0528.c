#include "common.h"

extern u8 D_800CD3FB;

void func_800F0528(u8* arg0) {
    arg0[3] = 1;
    if ((arg0[2] & 0xF) == 3) {
        arg0[0x47] = (s8)D_800CD3FB / 10 + 0xC;
        return;
    }
    arg0[0x47] = (s8)D_800CD3FB % 10 + 0xC;
}
