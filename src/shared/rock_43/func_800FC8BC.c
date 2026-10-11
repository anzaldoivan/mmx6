#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*);                   /* extern */
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D230(void*);                   /* extern */
extern s32 D_800FDE30;

void func_800FC8BC(void* arg0) {
    ((void (**)(void*))((u8*)&D_800FDE30 + 0x374))[M2C_FIELD(arg0, s8*, 6)](
        arg0);
    func_8002CCB0(arg0, 0x40, 0x40);
    func_80017A04(arg0);
    func_8002D230(arg0);
}
