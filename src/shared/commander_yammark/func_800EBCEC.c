#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
s32 is_off_screen(s32, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(s32);
M2C_UNK func_8002EE10(void*);
M2C_UNK func_80030ECC(void*);

void func_800EBCEC(u8* arg0) {
    animate_object();
    move_object((s32)arg0);
    func_80030ECC(arg0);
    {
        // !FAKE: depin: dropping it breaks the match (35/37)
        register s32 g asm("$2") = arg0[0x70];
        if (g != 0) {
            arg0[4]++;
            return;
        }
    }
    {
        func_8002EE10(arg0);
        {
            s32 f = arg0[0x70];
            if (f == 0 && is_off_screen((s32)arg0, 0x20, 0x20) == 0) {
                func_8002CCB0(arg0, 0x10, 0x10);
                return;
            }
        }
    }
    arg0[4]++;
}
