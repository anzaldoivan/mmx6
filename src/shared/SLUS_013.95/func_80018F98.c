#include "common.h"

extern u8 D_800CCEDC;
#define D_800CCEDC (*(s8*)&D_800CCEDC)
void func_8001A330(u8, s32, s32, s32, s32, s32);
s32 get_reploid_status(s32);

void func_80018F98(void) {
    s32 i;
    s32 n;

    if (D_800CCEDC != 0) {
        n = 0;
        i = 0;
        do {
            if (get_reploid_status(i) == 2) {
                n += 1;
            }
            i += 1;
        } while (i < 0x80);
        func_8001A330(0x39, 0xB0, 0x68, 0x21, 1, 0);
        func_8001A330(n / 100 + 0x21, 0xC0, 0x68, 0x21, 1, 0);
        func_8001A330(n % 100 / 10 + 0x21, 0xD0, 0x68, 0x21, 1, 0);
        func_8001A330(n % 10 + 0x21, 0xE0, 0x68, 0x21, 1, 0);
    }
}
#undef D_800CCEDC
