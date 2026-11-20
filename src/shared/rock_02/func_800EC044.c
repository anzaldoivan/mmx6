#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CB50();

void func_800EC044(struct ObjectHeader* arg0) {
    arg0->on_screen = 1;
    M2C_FIELD(arg0, u8*, 0x16) = 5;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    arg0->state++;
    func_8002CB50(arg0);
}
