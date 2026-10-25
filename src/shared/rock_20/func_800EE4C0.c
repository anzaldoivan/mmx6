#include "common.h"

extern u8 D_800E9860[];
/* linker symbol at the same address as D_800E9860: a distinct symbol keeps cse from
   deriving the second table address from the first (the original had two rodata labels) */
extern u8 rock_20_RODATA_START[];
int func_80060964(int mode);
void func_80069D94(void* dst, s32 c, s32 n);
s32 func_80069EF4(u8* name, s32 mode);
s32 func_80069F04(s32 fd, u8* buf, s32 n);
s32 func_80069F14(s32 fd, u8* buf, u32 n);
void func_80069F24(s32 fd);

s32 func_800EE4C0(u8* arg0, s32 arg1, u32 arg2) {
    u8 name[24];
    u8 buf[0x200];
    s32 fd;
    s32 n;
    s32 i;
    u32 tries;

    __builtin_memcpy(name, D_800E9860 + 0x1C, 18);
    func_80069D94(name + 18, 0, 2);
    arg0[3] = (arg2 >> 13) + ((arg2 % 0x2000) != 0);
    __builtin_memcpy(arg0 + 4, rock_20_RODATA_START + 0x30, 19);
    name[2] += arg1;
    func_80069F24(func_80069EF4(name, (arg0[3] << 16) | 0x200));
    tries = 0;
    do {
        i = 30;
        do {
            fd = func_80069EF4(name, 2);
            if (fd != -1) {
                goto opened;
            }
            func_80060964(2);
        } while (--i != 0);
        return 1;
    opened:
        i = 30;
        do {
            if (func_80069F14(fd, arg0, arg2) == arg2) {
                goto written;
            }
            func_80060964(2);
        } while (--i != 0);
        func_80069F24(fd);
        return 2;
    written:
        func_80069F24(fd);
        fd = func_80069EF4(name, 1);
        if (fd == -1) {
            break;
        }
        n = func_80069F04(fd, buf, 0x200);
        func_80069F24(fd);
        {
            // !FAKE: depin: dropping it breaks the match (139/141)
            register s32 k asm("$3") = 0x200;
            if (n == k) {
                return 0;
            }
        }
        tries++;
    } while (tries < 3);
    return 2;
}
