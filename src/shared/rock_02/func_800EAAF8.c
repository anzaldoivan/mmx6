#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

#define AAF8_SP64 (*(u8**)(0x1F800064))
#define AAF8_UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define AAF8_P(p, o) (*(u8**)((u8*)(p) + (o)))

void func_800EAAF8(u8* arg0) {
    u8 mode;

    mode = AAF8_UB(AAF8_P(arg0, 0x50), 0x82);
    if (AAF8_UB(AAF8_SP64, 0x54) != mode) {
        switch (mode) {
        case 0:
            AAF8_UB(arg0, 3) = 0;
            break;
        case 1:
            AAF8_UB(arg0, 0x16) = 0x22;
            AAF8_UB(arg0, 3) = mode;
            set_animation(arg0, 1);
            break;
        case 2:
            AAF8_UB(arg0, 0x16) = 0x20;
            AAF8_UB(arg0, 3) = 1;
            set_animation(arg0, 4);
            break;
        }
    }
    AAF8_UB(AAF8_SP64, 0x54) = mode;
}
