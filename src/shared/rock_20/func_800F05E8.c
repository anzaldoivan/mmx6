#include "common.h"

s32 get_reploid_status(s32);
s32 func_800F06F4(s32);

s32 func_800F05E8(u8 arg0) {
    s32 ret;

    if (func_800F06F4(arg0) == 0) {
        ret = get_reploid_status(arg0) == 2;
    } else {
        ret = 0;
    }
    return ret;
}
