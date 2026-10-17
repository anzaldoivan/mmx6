#include "common.h"

#define FE(o) (*(s16*)((u8*)(o) + 0xE))
#define F68(o) (*(u8**)((u8*)(o) + 0x68))
#define F66(o) (*(s8*)((u8*)(o) + 0x66))
#define F6E(o) (*(s16*)((u8*)(o) + 0x6E))

void func_8002E0DC(void* arg0, void* arg1) {
    u8* t0;
    u8* t1;
    s16 var_a3;
    s16 var_a2;
    s8 temp_a0;

    t0 = F68(arg0);
    t1 = F68(arg1);
    var_a3 = FE(arg0) + (s8)t0[1];
    var_a2 = FE(arg1) + (s8)t1[1];
    temp_a0 = F66(arg0);
    if (temp_a0 == -2) {
        var_a3 = var_a3 - t0[3];
        var_a2 = t1[3] + var_a2;
    } else if ((temp_a0 != -3) && (var_a2 < var_a3)) {
        var_a3 = var_a3 - t0[3];
        var_a2 = t1[3] + var_a2;
    } else {
        var_a3 = t0[3] + var_a3;
        var_a2 = var_a2 - t1[3];
    }
    F6E(arg1) = var_a3 - var_a2;
}

#undef FE
#undef F68
#undef F66
#undef F6E
