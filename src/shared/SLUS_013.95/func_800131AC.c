#include "common.h"
#define M2C_UNK s32

s32 func_80069E74(s32, s32, s32);
s32 func_80069E84(s32);
void func_80069E94(s32);
M2C_UNK func_80069ED4();
M2C_UNK func_80069EE4();
extern s32 D_8006D9AC;
extern s32 D_800CF960;

#define SLOT_PTR (*(u8**)0x801F8300)

void func_800131AC(void) {
    u8* p;

    SLOT_PTR = (u8*)0x801F8100;
    do {
        p = SLOT_PTR;
        switch (*(u16*)p) {
        case 1:
            if (--*(s16*)(p + 2) != 0) {
                break;
            }
        case 2:
        case 4:
        case 0x7F:
            *(u16*)SLOT_PTR = 0x7F;
            func_80069E94(*(s32*)(SLOT_PTR + 8));
            if (D_8006D9AC != 0) {
                D_8006D9AC = 0;
                func_80069ED4();
                func_80069E84(*(s32*)(SLOT_PTR + 8));
                *(s32*)(SLOT_PTR + 8) =
                    func_80069E74(D_800CF960, *(s32*)(SLOT_PTR + 0x10),
                                  *(s32*)(SLOT_PTR + 0x44));
                func_80069EE4();
            }
            break;
        }
        SLOT_PTR += 0x80;
    } while ((u32)SLOT_PTR < 0x801F8300U);
}
