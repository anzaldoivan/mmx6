#include "common.h"

#define M2C_UNK s32

M2C_UNK func_80034830();     /* extern */
M2C_UNK read_player_input(); /* extern */

void func_8001EC40(void) {
    read_player_input();
    func_80034830();
}
