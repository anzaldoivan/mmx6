// prog SLUS_013.95 | system boot | range 0x800147D0-0x80014948
// Shared file: included by src/SLUS_013.95/120A0.c, between func_800146F4 and func_8001494C.
#include "common.h"
#include "psyq/libcd.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

int func_800617A4(X4_CdlLOC* p);

extern u8 D_80010004[];
extern u8 D_8006CD42[][22];
extern s32 D_800E0398[][2];

// 0x800147D0 load_rock_dat_file_table: reads the ROCK_X6.DAT file table (0xF3 entries) into D_800E0398, plus 4 files.
// basis: string strings.tsv:3:SLUS_013.95:0x80010004
// callers: none known
// str 0x80010004 "\\ROCK_X6.DAT;1" = "CD path of the data archive"
void load_rock_dat_file_table(void) {
    s32 file[6];
    u8 result[8];
    s32(*src)[2];
    s32 base;
    s32 i;

    src = (s32(*)[2])0x80103000;
    while (CdSearchFile(file, D_80010004) == 0) {
    }
    base = func_800617A4((X4_CdlLOC*)file);
    CdControl(2, (s32)file, 0);
    CdRead(2, (s32*)0x80103000, 0x80);
    CdReadSync(0, result);
    while (CdControl(9, 0, 0) == 0) {
    }
    for (i = 0; i < 0xF3; i++) {
        D_800E0398[i][0] = base + src[i][0];
        D_800E0398[i][1] = src[i][1];
    }
    for (i = 0xF3; i < 0xF7; i++) {
        while (CdSearchFile(file, D_8006CD42[i]) == 0) {
        }
        D_800E0398[i][0] = func_800617A4((X4_CdlLOC*)file);
        D_800E0398[i][1] = file[1];
        while (CdControl(9, 0, 0) == 0) {
        }
    }
}
