#include "common.h"
#define M2C_UNK s32

M2C_UNK func_801ECD3C(void*);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))

s32 func_801ECCD4(void* arg0) {
    if (F_S8(arg0, 0x2) == 0) {
        return 0;
    }
    if (F_S8(arg0, 0xD3) != 0) {
        return 0;
    }
    if (!(F_U16(arg0, 0x80) & 0x10)) {
        return 0;
    }
    if (F_S8(arg0, 0x8E) != 0) {
        return 0;
    }
    func_801ECD3C(arg0);
    return 1;
}

#undef F_S8
#undef F_U16
