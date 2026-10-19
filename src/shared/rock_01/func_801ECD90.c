#include "common.h"
#define M2C_UNK s32

void* func_8002C32C();

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))

M2C_UNK func_801ECD90(void* arg0, M2C_UNK arg1) {
    s8 id = arg1;
    u8* obj;

    obj = func_8002C32C();
    {
        // !FAKE: keeps the constant 1 in the branch delay slot
        register s32 one asm("$2") = 1;
        if (obj != 0) {
            obj[0] = one;
            obj[1] = id;
            obj[2] = F_U8(arg0, 0xCB);
            obj[0x14] = F_U8(arg0, 0x14);
            *(s32*)(obj + 0x84) = F_U8(arg0, 0x17);
            obj[0x15] = F_U8(arg0, 0x15);
        }
    }
}
