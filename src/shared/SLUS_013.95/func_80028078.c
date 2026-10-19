#include "common.h"

extern u16 D_8008EC10;
extern u8 D_800CD338;
extern u8 D_800CD339;

#define SCRATCH_04 (*(u8**)0x1F800004)

s32 func_80028078(s32 arg0, s32 arg1, u32 arg2) {
    u32 x = arg1;

    if ((x >= D_800CD338) || (arg2 >= D_800CD339)) {
        return 0;
    }
    return *(SCRATCH_04 + (arg0 * D_8008EC10) + (D_800CD338 * arg2) + x);
}
