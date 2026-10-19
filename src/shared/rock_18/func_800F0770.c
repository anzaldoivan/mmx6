#include "common.h"

extern u8 D_8006D5F7;
extern u8 D_8007360C[];

void func_800F0770(u8* arg0) {
    arg0[3] = 1;
    if (D_8006D5F7 & D_8007360C[arg0[2] & 0xF]) {
        arg0[0x47] = 0x21;
        return;
    }
    arg0[0x47] = 0x22;
}
