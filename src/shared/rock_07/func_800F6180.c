#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
void func_800F6E78(void*);

#define F(T, p, o) (*(T*)((u8*)(p) + (o)))

void func_800F6180(void* arg0) {
    if (F(s8, arg0, 0x45) == 1) {
        ((void (*)())func_800F6E78)();
        func_800179A4(arg0, 0x12);
        {
            // !FAKE: depin: dropping it breaks the match (18/21)
            register s32 v asm("$2") = F(u8, arg0, 6) + 1;
            F(u8, arg0, 6) = v;
        }
    }
}
