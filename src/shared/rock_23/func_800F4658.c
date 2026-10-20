#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
M2C_UNK func_8002D2B0(void*);

#define F(T, p, o) (*(T*)((u8*)(p) + (o)))

void func_800F4658(void* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    func_8002D2B0((s32)arg0);
    if (F(s8, arg0, 0x45) == 1) {
        if (F(u8, arg0, 0x15) != 0) {
            F(s32, arg0, 0x20) = 0x40000;
        } else {
            F(s32, arg0, 0x20) = 0xFFFC0000;
        }
        F(s32, arg0, 0x28) = 0x100;
        F(s32, arg0, 0x24) = 0;
        F(s32, arg0, 0x2C) = 0;
        F(u8, arg0, 6) = F(u8, arg0, 6) + 1;
    }
}
