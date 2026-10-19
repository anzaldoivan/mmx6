#include "common.h"
#define M2C_UNK s32

void func_8003E614(void* arg0);

M2C_UNK func_8003F700(void* arg0) {
    s8* p = arg0;

    if (p[0xD3] != 0) {
        return 0;
    }
    if (p[2] != 0) {
        return 0;
    }
    return ((s32(*)(void*))func_8003E614)(arg0);
}
