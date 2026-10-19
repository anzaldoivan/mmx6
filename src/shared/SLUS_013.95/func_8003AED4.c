#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002D5D0(void*);
void func_8003F4C4(struct X4_PlayerObj* self, s32 animation);

M2C_UNK func_8003AED4(void* arg0) {
    u8* p = arg0;

    func_8003F4C4(arg0, 8);
    *(s32*)(p + 0x24) = 0;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x2C) = 0;
    func_8002D5D0(p);
    p[5] = 4;
    p[6] = 0;
}
