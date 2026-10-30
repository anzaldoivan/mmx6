// prog rock_20 | system memcard | range 0x800EE4C0-0x800EE6F0
// Shared file: included by src/rock_20/E9860.c, between func_800EE19C and build_mission_report_list.
#include "common.h"
#include "psyq/libapi.h"
#include "psyq/libetc.h"

extern u8 D_800E9860[];
/* linker symbol at the same address as D_800E9860: a distinct symbol keeps cse from
   deriving the second table address from the first (the original had two rodata labels) */
extern u8 rock_20_RODATA_START[];
void memset(void* dst, s32 c, s32 n);

// 0x800EE4C0 memcard_write_save_file: creates and writes the save file, then reads it back to verify (3 tries).
// basis: string strings.tsv:403:rock_20:0x800E987C
// callers: none known
// str 0x800E987C "bu00:BASLUS-01395" = "save file path on memory card slot 1"
s32 memcard_write_save_file(u8* arg0, s32 arg1, u32 arg2) {
    u8 name[24];
    u8 buf[0x200];
    s32 fd;
    s32 n;
    s32 i;
    u32 tries;

    __builtin_memcpy(name, D_800E9860 + 0x1C, 18);
    memset(name + 18, 0, 2);
    arg0[3] = (arg2 >> 13) + ((arg2 % 0x2000) != 0);
    __builtin_memcpy(arg0 + 4, rock_20_RODATA_START + 0x30, 19);
    name[2] += arg1;
    close(open(name, (arg0[3] << 16) | 0x200));
    tries = 0;
    do {
        i = 30;
        do {
            fd = open(name, 2);
            if (fd != -1) {
                goto opened;
            }
            VSync(2);
        } while (--i != 0);
        return 1;
    opened:
        i = 30;
        do {
            if (write(fd, arg0, arg2) == arg2) {
                goto written;
            }
            VSync(2);
        } while (--i != 0);
        close(fd);
        return 2;
    written:
        close(fd);
        fd = open(name, 1);
        if (fd == -1) {
            break;
        }
        n = read(fd, buf, 0x200);
        close(fd);
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
