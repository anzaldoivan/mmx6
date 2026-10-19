#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

struct X4_VisualObj* func_8002C398(void);
extern u8 D_800970B4;

M2C_UNK func_8003D510(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3) {
    s8 a0 = arg0;
    s8 a1 = arg1;
    s8 a2 = arg2;
    u8* obj;

    obj = (u8*)((struct X4_VisualObj * (*)())
                    func_8002C398)(arg0 << 24, arg1 << 24, arg2 << 24);
    if (obj != 0) {
        obj[0] = a0;
        obj[1] = a1;
        obj[2] = a2;
        obj[0x14] = D_800970B4;
        if (arg3 != 0) {
            *(s32*)(obj + 0x50) = arg3;
        }
        return (s32)obj;
    }
    return 0;
}
