// prog SLUS_013.95 | system boot | range 0x80016780-0x80016854
// Shared file: included by src/SLUS_013.95/120A0.c, between func_80016704 and read_rock_bin_member.
#include "common.h"
#include "psyq/libcd.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

int func_800617A4(X4_CdlLOC* p);

extern u8 D_80010014[];
extern u8 rock_bin_file_table[];
#define rock_bin_file_table (*(s32(*)[][2]) & rock_bin_file_table)

// 0x80016780 load_rock_bin_file_table: reads the ROCK_X6.BIN file table (0x3B entries) into rock_bin_file_table.
// basis: string strings.tsv:4:SLUS_013.95:0x80010014
// callers: none known
// str 0x80010014 "\\ROCK_X6.BIN;1" = "CD path of the overlay archive"
void load_rock_bin_file_table(void) {
    s32 file[6];
    u8 result[8];
    s32(*src)[2];
    s32 base;
    s32 i;

    src = (s32(*)[2])0x80103000;
    while (CdSearchFile(file, D_80010014) == 0) {
    }
    base = func_800617A4((X4_CdlLOC*)file);
    CdControl(2, (s32)file, 0);
    CdRead(2, (s32*)0x80103000, 0x80);
    CdReadSync(0, result);
    while (CdControl(9, 0, 0) == 0) {
    }
    for (i = 0; i < 0x3B; i++) {
        rock_bin_file_table[i][0] = base + src[i][0];
        rock_bin_file_table[i][1] = src[i][1];
    }
}
#undef rock_bin_file_table
