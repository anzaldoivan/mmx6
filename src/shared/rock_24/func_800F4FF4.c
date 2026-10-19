#include "common.h"
#define M2C_UNK s32

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern void (*D_800F7664[])(void*);

void func_800F4FF4(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x84) < 0x50) {
        M2C_FIELD(arg0, u8*, 0x84) = 0x64;
    }
    D_800F7664[M2C_FIELD(arg0, s8*, 0x6)](arg0);
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x30, 0x40);
}
