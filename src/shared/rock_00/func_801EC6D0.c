#include "common.h"

void* func_8002C32C();

void func_801EC6D0(void* arg0, s32 arg1) {
    u8* self = arg0;
    s8 id = arg1;
    u8* obj;

    if (((s8*)self)[0x45] & 0x80) {
        self[0x45] &= 0x7F;
        obj = func_8002C32C();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = id;
            obj[0x14] = self[0x14];
            *(s32*)(obj + 0x84) = self[0x17];
            obj[0x15] = self[0x15];
        }
    }
}
