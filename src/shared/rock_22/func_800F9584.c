#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK move_object(s32);

void func_800F9584(void* arg0) {
    void* parent;

    parent = M2C_FIELD(arg0, void**, 0x84);
    ((void (*)())func_80017A04)();
    ((void (*)(s32))move_object)((s32)arg0);
    if (M2C_FIELD(arg0, u8*, 0x70) & 2) {
        M2C_FIELD(parent, u8*, 0x6)++;
        M2C_FIELD(arg0, u8*, 0x5) = 5;
        M2C_FIELD(arg0, u8*, 0x6) = 0;
    }
}
