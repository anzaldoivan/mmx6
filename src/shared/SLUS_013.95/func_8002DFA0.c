#include "common.h"

#define F15(o) (*(u8*)((u8*)(o) + 0x15))
#define FA(o) (*(s16*)((u8*)(o) + 0xA))
#define F68(o) (*(u8**)((u8*)(o) + 0x68))
#define F66(o) (*(s8*)((u8*)(o) + 0x66))
#define F6C(o) (*(s16*)((u8*)(o) + 0x6C))

void func_8002DFA0(void* arg0, void* arg1) {
    s16 var_a3;
    s16 var_a2;
    s8 temp_a0;

    if (F15(arg0) == 0x40) {
        var_a3 = FA(arg0) - (s8)*F68(arg0);
    } else {
        var_a3 = FA(arg0) + (s8)*F68(arg0);
    }
    if (F15(arg1) == 0x40) {
        var_a2 = FA(arg1) - (s8)*F68(arg1);
    } else {
        var_a2 = FA(arg1) + (s8)*F68(arg1);
    }
    temp_a0 = F66(arg0);
    if (temp_a0 == 2) {
        var_a3 = var_a3 - F68(arg0)[2];
        var_a2 = F68(arg1)[2] + var_a2;
    } else if ((temp_a0 != 3) && (var_a2 < var_a3)) {
        var_a3 = var_a3 - F68(arg0)[2];
        var_a2 = F68(arg1)[2] + var_a2;
    } else {
        var_a3 = F68(arg0)[2] + var_a3;
        var_a2 = var_a2 - F68(arg1)[2];
    }
    F6C(arg1) = var_a3 - var_a2;
}

#undef F15
#undef FA
#undef F68
#undef F66
#undef F6C
