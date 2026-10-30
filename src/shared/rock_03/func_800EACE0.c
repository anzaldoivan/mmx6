#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04();
s32 func_8002CBFC(s32, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(s32);
M2C_UNK func_8002EE10(void*);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_80049D90(void*);
M2C_UNK func_80049E50(void*);

void func_800EACE0(u8* arg0) {
    func_80017A04();
    move_object((s32)arg0);
    if (check_enemy_hits(arg0) < 0) {
        func_80049E50(arg0);
        {
            // !FAKE: depin: dropping it breaks the match (56/59)
            register s32 t asm("$2") = arg0[4] + 1;
            arg0[4] = t;
        }
    } else {
        *(u16*)(arg0 + 0x42) &= 0x7FFF;
    }
    func_80030ECC(arg0);
    {
        // !FAKE: depin: dropping it breaks the match (57/59)
        register s32 f asm("$2") = arg0[0x70];
        if (f != 0) {
            goto H;
        }
    }
    func_8002EE10(arg0);
    if (arg0[0x70] != 0) {
    H:
        func_80049D90(arg0);
        arg0[4]++;
        return;
    }
    if (func_8002CBFC((s32)arg0, 0x20, 0x20) == 0) {
        func_8002CCB0(arg0, 0x10, 0x10);
        return;
    }
    arg0[4]++;
}
