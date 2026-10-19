#include "common.h"

void func_800ECC78(void* arg0) {
    s32 temp_v0;

    temp_v0 = *(u16*)((u8*)arg0 + 8) + 1;
    *(u16*)((u8*)arg0 + 8) = temp_v0;
    if ((s16)temp_v0 >= 5) {
        *(u16*)((u8*)arg0 + 8) = 0;
        ((u8*)arg0)[2]++;
    }
}
