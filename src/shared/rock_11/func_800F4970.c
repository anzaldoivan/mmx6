#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern void (*D_800FCBF4[])(void*);
extern s8 D_800FD51D;
extern s8 D_800FD51E;

void func_800F4970(void* arg0) {
    s8 v;

    if ((D_800FD51D != 0 && (v = M2C_FIELD(arg0, s8*, 0x2), v < 5) && v >= 3) ||
        (D_800FD51E != 0 && M2C_FIELD(arg0, s8*, 0x2) == 4)) {
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        M2C_FIELD(arg0, u8*, 0x4)++;
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x2) != 3 && M2C_FIELD(arg0, s8*, 0x5) != 4) {
        func_80017A04(arg0);
    }
    func_8002CCB0(arg0, 0x20, 0x20);
    (*(void (**)(void*))((M2C_FIELD(arg0, s8*, 0x5) << 2) + (s32)D_800FCBF4))(
        arg0);
}
