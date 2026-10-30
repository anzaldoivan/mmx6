#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK end_dash(s32);

void func_801EBCF4(s8* arg0) {
    s32 var_a0;

    func_80017A04((struct X4_AnimatedObj*)arg0);
    var_a0 = 0;
    if ((arg0[0x99] == 0) || (arg0[0x93] != 3)) {
        var_a0 = 1;
    }
    if ((arg0[0x46] == 0) && (arg0[6] == 1)) {
        var_a0 = 1;
    }
    if (var_a0 != 0) {
        end_dash((s32)arg0);
    }
}
