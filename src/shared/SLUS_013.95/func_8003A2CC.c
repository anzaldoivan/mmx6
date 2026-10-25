#include "common.h"

s32 func_8003A33C(void*);
s32 func_8003A394(void*);
void player_enter_wall_cling(void* arg0);

s32 func_8003A2CC(void* arg0) {
    if (*((s8*)arg0 + 0xD3) != 0) {
        return 0;
    }
    if (!(*((u8*)arg0 + 0x89) & 3)) {
        return 0;
    }
    if (func_8003A33C(arg0) != 0) {
        return 1;
    }
    if (func_8003A394(arg0) == 0) {
        return 0;
    }
    player_enter_wall_cling(arg0);
    return 1;
}
