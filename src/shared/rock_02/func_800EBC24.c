#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8002F288();
void func_800EBF68(void* arg0);
extern void (*D_800FAD04[])(void*);

void func_800EBC24(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    if (M2C_FIELD(arg0, u8*, 0x70) & 8) {
        M2C_FIELD(arg0, s32*, 0x24) = 0;
    }
    D_800FAD04[M2C_FIELD(arg0, s8*, 0x4)](arg0);
    func_8002F288(arg0);
    func_800EBF68(arg0);
}
