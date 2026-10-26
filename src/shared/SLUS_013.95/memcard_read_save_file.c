// prog SLUS_013.95 | system memcard | range 0x8001C384-0x8001C4BC
// Shared file: included by src/SLUS_013.95/120A0.c, between func_8001C1AC and memcard_list_files.
#include "common.h"
#include "psyq/libetc.h"

extern u8 D_80010098[];
void memset(void* dst, s32 c, s32 n);
s32 open(u8* name, s32 mode);
s32 read(s32 fd, u8* buf, s32 n);
void close(s32 fd);

// 0x8001C384 memcard_read_save_file: reads the 0x2000-byte save file from the memory card in slot arg1.
// basis: string strings.tsv:5:SLUS_013.95:0x80010098
// callers: none known
// str 0x80010098 "bu00:BASLUS-01395" = "save file path on memory card slot 1"
s32 memcard_read_save_file(s32 arg0, s32 arg1, s32 arg2) {
    u8 name[24];
    s32 fd;
    s32 i;

    __builtin_memcpy(name, D_80010098, 18);
    memset(name + 18, 0, 2);
    do {
        name[2] += arg1;
    } while (0);
    i = 30;
    do {
        fd = open(name, 1);
        if (fd != -1) {
            goto opened;
        }
        VSync(2);
    } while (--i != 0);
    return 1;
opened:
    for (i = 30; i != 0; i--) {
        if (read(fd, (u8*)arg0, 0x2000) == 0x2000) {
            goto got_data;
        }
        VSync(2);
    }
    close(fd);
    return 2;
got_data:
    close(fd);
    return 0;
}
