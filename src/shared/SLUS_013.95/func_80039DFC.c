#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8003AFF4(s32);
M2C_UNK func_8003CCBC();
M2C_UNK func_8003CDBC();

void func_80039DFC(void* arg0) {
    s8* p = (s8*)arg0;
    s8 temp_v1;

    temp_v1 = p[5];
    if (temp_v1 == 0) {
        return;
    }
    if (temp_v1 == 1) {
        return;
    }
    if ((p[0x67] == 0) && (p[0xA4] <= 0) && (p[0xD5] >= 0) && (p[0xD4] == 0) &&
        !(((u8*)p)[0x89] & 8)) {
        if (p[2] != 0) {
            func_8003CDBC();
        }
        func_8003AFF4((s32)arg0);
        func_8003CCBC(arg0);
    }
}
