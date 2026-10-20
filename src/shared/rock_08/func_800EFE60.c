#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
void func_8002CCB0(struct X4_BaseObj*, s32, s32);
M2C_UNK func_8002D2B0(void*);
extern struct X4_BackgroundObj D_800971F8[3];

void func_800EFE60(void* arg0) {
    func_80017A04();
    ((void (*)(s32))func_8002D2B0)((s32)arg0);
    if (M2C_FIELD(arg0, s16*, 0xA) >= D_800971F8[0].x_pos.i.hi - 0x10 &&
        D_800971F8[0].y_pos.i.hi + 0x100 >= M2C_FIELD(arg0, s16*, 0xE) &&
        func_8002CBFC(arg0, 0x150, 0x30) == 0) {
        func_8002CCB0(arg0, 0x20, 0x20);
        return;
    }
    M2C_FIELD(arg0, s8*, 4) = 2;
}
