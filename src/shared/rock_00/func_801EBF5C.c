#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8003BA04(void*, M2C_UNK);
extern u8 D_801F36C8[];

// str 0x801F36C8 sha1=05619cf61313e05817cc31351c1b4dda443ee78a = "printable byte run: data, not text"
M2C_UNK func_801EBF5C(void* arg0) {
    u8 v;

    v = D_801F36C8[*(s8*)((u8*)arg0 + 0x97)];
    ((void (*)(void*, s32))func_8003BA04)(arg0, v);
    if (v == 0x5D) {
        *(u8*)((u8*)arg0 + 0x44) = *(u8*)((u8*)arg0 + 0x91) - 8;
    }
}
