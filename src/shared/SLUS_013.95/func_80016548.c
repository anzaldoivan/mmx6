#include "common.h"

extern s32 rock_dat_file_table[][2];

s32 func_80016548(s32 arg0, s32* arg1) {
    s32* p = rock_dat_file_table[arg0];
    *arg1 = p[1];
    return p[0];
}
