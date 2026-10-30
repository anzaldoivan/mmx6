#include "common.h"
#include "psyq/libcd.h"
#define M2C_UNK s32

void func_80014E60(s32, s32);
u8 func_80016570(void);
s32 func_80064894(s32, s32);
extern u8 D_8009509C;
extern M2C_UNK* D_800B91B8;
extern s32 D_800E01A8;
extern u8* D_800E01AC;
extern s32 D_800E01B0;
extern s32 D_800E01B4;
extern s32 D_800E01C0;
extern s32 D_800E0374;
extern u8 D_800E0379;
extern s32 D_800E037C;
extern u32 D_800E0380;
extern u8 rock_bin_file_table[];
extern M2C_UNK* D_800E0D30;
extern s32 D_800E0D34;

// 0x80016858 read_rock_bin_member: reads ROCK_X6.BIN member arg0 into buffer arg1 from rock_bin_file_table[arg0] (lba, size).
// basis: oracle assets.tsv:3:iso/ROCK_X6.BIN
// callers: load_player_files, func_80013D10, func_80052E44
void read_rock_bin_member(s32 arg0, s32 arg1) {
    s32 off;

    D_800E0D30 = D_800B91B8;
    D_800E0D34 = D_800E0374;
    if (func_80064894(1, 0) != 0) {
        CdControlB(9, 0, 0);
    }
    if (D_8009509C != 0x80) {
        D_800E0380 = 0;
    }
    off = arg0 * 8;
    D_8009509C = 0;
    D_800E0379 = arg0;
    D_800E037C = arg1;
    do {
    } while (func_80016570() & 0x40);
    {
        // !FAKE: pin the table word for the second call arg
        register s32 b asm("$5") = *(s32*)(off + rock_bin_file_table);
        // !FAKE: pin the table word for the first call arg
        register s32 a asm("$4") = *(s32*)(rock_bin_file_table + off + 4);
        D_800E01C0 = 0;
        D_800E01AC = (u8*)arg1;
        D_800E01B4 = b;
        D_800E01B0 = a;
        D_800E01A8 = a;
        func_80014E60(a, b);
    }
}
