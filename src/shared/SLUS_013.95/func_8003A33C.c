#include "common.h"

void func_8003B440(void* arg0);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))

s32 func_8003A33C(void* arg0) {
    if (F_S8(arg0, 0xD3) != 0) {
        return 0;
    }
    if (!(F_U16(arg0, 0x80) & 0x80)) {
        return 0;
    }
    if (F_S8(arg0, 0x4A) <= 0) {
        return 0;
    }
    func_8003B440(arg0);
    return 1;
}

#undef F_S8
#undef F_U16
