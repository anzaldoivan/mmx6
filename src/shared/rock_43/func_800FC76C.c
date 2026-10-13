#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04(void*);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern s32 D_800FDE30;

void func_800FC76C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        register s32 i asm("$3");
        register s32 t asm("$4");
        func_800179A4(arg0, 0);
        t = (s32)((u8*)&D_800FDE30 + 0x284);
        i = M2C_FIELD(arg0, u8*, 0x87)++;
        i = i + M2C_FIELD(arg0, u8*, 0x86) * 6 + t;
        M2C_FIELD(arg0, u8*, 5) = *(u8*)i;
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
    func_8002CCB0(arg0, 0x40, 0x40);
    func_80017A04(arg0);
    func_8002D230(arg0);
}
