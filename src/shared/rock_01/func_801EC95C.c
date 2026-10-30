#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK end_dash(s32);
void func_801ECE60(void* arg0);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))

M2C_UNK func_801EC95C(void* arg0) {
    if (F_S8(arg0, 0xD3) != 0) {
        F_U8(arg0, 0x8E) = 0;
        ((void (*)())end_dash)();
        return;
    }
    if (F_S8(arg0, 0x6) == 0) {
        F_U8(arg0, 0x6) = F_U8(arg0, 0x6) + 1;
    } else {
        func_80017A04(arg0);
    }
    func_801ECE60(arg0);
}

#undef F_S8
#undef F_U8
