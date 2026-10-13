#include "common.h"

extern u8 D_80010098[];
int func_80060964(int mode);
void func_80069D94(void* dst, s32 c, s32 n);
s32 func_80069EF4(u8* name, s32 mode);
s32 func_80069F04(s32 fd, u8* buf, s32 n);
void func_80069F24(s32 fd);

s32 func_8001C384(s32 arg0, s32 arg1, s32 arg2) {
    u8 name[24];
    s32 fd;
    s32 i;

    __builtin_memcpy(name, D_80010098, 18);
    func_80069D94(name + 18, 0, 2);
    do {
        name[2] += arg1;
    } while (0);
    i = 30;
    do {
        fd = func_80069EF4(name, 1);
        if (fd != -1) {
            goto opened;
        }
        func_80060964(2);
    } while (--i != 0);
    return 1;
opened:
    for (i = 30; i != 0; i--) {
        if (func_80069F04(fd, (u8*)arg0, 0x2000) == 0x2000) {
            goto read;
        }
        func_80060964(2);
    }
    func_80069F24(fd);
    return 2;
read:
    func_80069F24(fd);
    return 0;
}
