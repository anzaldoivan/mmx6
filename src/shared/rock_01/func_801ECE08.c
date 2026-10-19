#include "common.h"
#define M2C_UNK s32

s32 func_80039C9C(void*);
s32 func_80039CFC(void*);
s32 func_8003A3DC(void*);
M2C_UNK func_8003AE8C(void*);

s32 func_801ECE08(void* arg0) {
    if (func_8003A3DC(arg0) != 0) {
        return 1;
    }
    if (func_80039C9C(arg0) != 0) {
        return 1;
    }
    if (func_80039CFC(arg0) == 0) {
        return 0;
    }
    func_8003AE8C(arg0);
    return 1;
}
