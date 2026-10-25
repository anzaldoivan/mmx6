#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK move_object(void*);
void func_800F2B4C();

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800F272C(void* arg0) {
    // !FAKE: the selected velocity lives in the first return register
    register s32 v asm("$2");

    ((void (*)())move_object)();
    func_80017A04(arg0);
    func_800F2B4C(arg0);
    {
        // !FAKE: the tested byte shares the first return register with v
        register s32 t asm("$2") = UB(arg0, 0x15);
        if (t == 0) {
            v = 0xFFFC0000;
        } else {
            v = 0x40000;
        }
    }
    do {
        W(arg0, 0x20) = v;
    } while (0);
    func_800179A4(arg0, 2);
    H(arg0, 0x7C) = 0xB4;
    {
        // !FAKE: byte increment temp lands in the first return register
        register s32 c asm("$2") = UB(arg0, 6) + 1;
        UB(arg0, 6) = c;
    }
}
