#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
M2C_UNK move_object(void*);
extern s16 D_800F4480;

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))

void func_800F21AC(void* arg0) {
    if (H(arg0, 0xE) >= D_800F4480 + 0x468) {
        set_animation(arg0, 0);
        H(arg0, 0x7C) = 0x32;
        {
            // !FAKE: byte increment temp lands in the first return register
            register s32 c asm("$2") = UB(arg0, 6) + 1;
            UB(arg0, 6) = c;
        }
        return;
    }
    move_object(arg0);
    func_80017A04(arg0);
}
