#include "common.h"

void func_8001A330(u8, s32, s32, s32, s32, s32);
extern s32 D_800CCF60;

void func_80018CBC(void) {
    u8 d[6];
    s32 x;
    s32 h;
    s32 m;
    s32 s;

    if (D_800CCF60 > 0x57E3F) {
        d[0] = 9;
        d[1] = 9;
        d[2] = 5;
        d[3] = 9;
        d[4] = 9;
        d[5] = 9;
    } else {
        x = D_800CCF60;
        d[0] = x / 36000;
        h = x / 3600;
        d[1] = h % 60 % 10;
        m = x / 60 - h * 60;
        d[2] = m / 10;
        d[3] = m % 10;
        s = (x - x / 60 * 60) * 100 / 60;
        d[4] = s / 10;
        d[5] = s % 10;
    }
    func_8001A330(0x3C, 0xA8, 0xD8, 0x21, 1, 0);
    func_8001A330(d[0] + 0x21, 0xB8, 0xD8, 0x21, 1, 0);
    func_8001A330(d[1] + 0x21, 0xC8, 0xD8, 0x21, 1, 0);
    func_8001A330(0x2B, 0xD8, 0xD8, 0x21, 1, 0);
    func_8001A330(d[2] + 0x21, 0xE8, 0xD8, 0x21, 1, 0);
    func_8001A330(d[3] + 0x21, 0xF8, 0xD8, 0x21, 1, 0);
    func_8001A330(0x2C, 0x108, 0xD8, 0x21, 1, 0);
    func_8001A330(d[4] + 0x21, 0x118, 0xD8, 0x21, 1, 0);
    func_8001A330(d[5] + 0x21, 0x128, 0xD8, 0x21, 1, 0);
}
