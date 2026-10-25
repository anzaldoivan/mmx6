#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK move_object(void*);

#define F32(p, o) (*(s32*)((u8*)(p) + (o)))
#define F8(p, o) (*(u8*)((u8*)(p) + (o)))

void func_800F56F0(void* arg0) {
    if (F8(arg0, 0x70) & 8) {
        func_80016C48(2, 0x5E, arg0);
        func_80012D9C(5);
        func_800179A4(arg0, 0x20);
        {
            // !FAKE: pin the byte increment temp to the first return register
            register s32 t asm("$2") = F8(arg0, 6);
            F32(arg0, 0x20) = 0;
            F32(arg0, 0x24) = 0;
            F8(arg0, 6) = t + 1;
        }
        return;
    }
    move_object(arg0);
}
