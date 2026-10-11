#include "common.h"
#include "mmx6/x4.h"

void func_8001A330(u8, s32, s32, s32, s32, s32);
extern s8 D_800970A2;
extern struct X4_EngineObj D_800CCED0;

void func_800190FC(void) {
    s32 v;

    if (D_800CCED0.stage != 0) {
        v = *(s16*)((u8*)&D_800CCED0 + D_800970A2 * 2 + 0xD2);
        if (v >= 10000) {
            v = 9999;
        }
        func_8001A330(0x3B, 0xF0, 0x68, 0x21, 1, 0);
        func_8001A330(v / 1000 + 0x21, 0x100, 0x68, 0x21, 1, 0);
        func_8001A330(v % 1000 / 100 + 0x21, 0x110, 0x68, 0x21, 1, 0);
        func_8001A330(v % 100 / 10 + 0x21, 0x120, 0x68, 0x21, 1, 0);
        func_8001A330(v % 10 + 0x21, 0x130, 0x68, 0x21, 1, 0);
    }
}
