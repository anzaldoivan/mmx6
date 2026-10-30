#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_resolution(s32 arg0); /* extern */
M2C_UNK load_player_files();   /* extern */
void reset_level(void);        /* extern */

void func_8001E880(void* arg0) {
    set_resolution(0);
    reset_level();
    load_player_files();
    M2C_FIELD(arg0, s8*, 0) = 8;
    M2C_FIELD(arg0, s8*, 1) = 0;
    M2C_FIELD(arg0, s8*, 2) = 0;
    M2C_FIELD(arg0, s8*, 3) = 0;
}
