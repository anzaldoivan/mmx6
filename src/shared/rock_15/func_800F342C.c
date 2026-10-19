#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s16 D_800970AA;
extern s16 D_8009721E;

void func_800F342C(void* arg0) {
    if (D_800970AA <= (D_8009721E + 0x40)) {
        func_8003D308(0x14, 0x40);
        ((u8*)arg0)[6]++;
    }
}
