#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80012890(s32 arg0);
s32 func_8001A6CC(s32 arg0);
extern s32 D_800CD408;

void func_8001D3C0(void* arg0) {
    M2C_FIELD(arg0, s8*, 0xD) = 1;
    D_800CD408 = 0x80103000;
    func_80012890(0);
    ((void (*)(s32))func_8001A6CC)(1);
    M2C_FIELD(arg0, u8*, 0x1) += 1;
}
