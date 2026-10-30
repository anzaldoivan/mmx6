#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);

#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define SB(p, o) (*(s8*)((u8*)(p) + (o)))

void func_800EBBD4(void* arg0) {
    switch (SB(*(void**)((u8*)arg0 + 0x80), 7)) {
    case 3:
        if (B(arg0, 0x17) != 2) {
            set_animation(arg0, 2);
        }
        break;
    case 2:
        if (B(arg0, 0x17) != 3) {
            set_animation(arg0, 3);
        }
        break;
    case 1:
        if (B(arg0, 0x17) != 4) {
            set_animation(arg0, 4);
        }
        break;
    case 0:
        B(arg0, 4) = 2;
        return;
    }
    if (func_8002CBFC(arg0, 0x30, 0x40) == 0) {
        func_8002CCB0(arg0, 0x30, 0x40);
    }
    func_8002D230(arg0);
    func_80017A04(arg0);
}
