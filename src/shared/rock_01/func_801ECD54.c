#include "common.h"
#define M2C_UNK s32

M2C_UNK func_801ECD90(void*, M2C_UNK);

M2C_UNK func_801ECD54(void* arg0, M2C_UNK arg1) {
    s8 b = arg1;

    if (((s8*)arg0)[0x45] & 0x80) {
        ((u8*)arg0)[0x45] = ((u8*)arg0)[0x45] & 0x7F;
        func_801ECD90(arg0, b);
    }
}
