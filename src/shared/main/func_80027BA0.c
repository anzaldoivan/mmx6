#include "common.h"

void func_800262EC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

void func_80027BA0(s32 arg0, s16 arg1, s16 arg2, u16* arg3) {
    s32 var_v1;
    s32 var_s4;
    s32 var_s3;
    s32 var_s2;
    s32 var_s1;
    s32 var_s0;
    s32 sp18;

    var_s4 = arg2;
    var_v1 = 0;
    var_s3 = ((s16*)arg3)[1];
    sp18 = arg1;
    if (arg3[3] != 0) {
        do {
            var_s0 = ((s16*)arg3)[0];
            var_s2 = sp18;
            for (var_s1 = 0; var_s1 < arg3[2];) {
                func_800262EC(arg0, var_s2, var_s4, var_s0, var_s3);
                var_s1++;
                var_s2 += 0x10;
                var_s0 += 0x10;
            }
            var_v1 += 1;
            var_s4 += 0x10;
            var_s3 += 0x10;
        } while (var_v1 < arg3[3]);
    }
}
