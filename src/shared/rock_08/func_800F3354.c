#include "common.h"
#define M2C_UNK s32

#define OUB(p, o) (*(u8*)((u8*)(p) + (o)))

M2C_UNK animate_object();
M2C_UNK move_object(void*);
M2C_UNK func_8002EE10(void*);
M2C_UNK func_80030ECC(void*);
M2C_UNK func_80049D90(void*);

void func_800F3354(void* arg0) {
    s32 v;

    animate_object();
    move_object(arg0);
    if (func_80030ECC(arg0) != 0) {
        func_80049D90(arg0);
        v = 2;
    } else {
        if (OUB(arg0, 0x70) == 0) {
            func_8002EE10(arg0);
            if (OUB(arg0, 0x70) == 0) {
                return;
            }
        }
        func_80049D90(arg0);
        v = OUB(arg0, 4) + 1;
    }
    OUB(arg0, 4) = v;
}
