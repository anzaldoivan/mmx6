#include "common.h"

void func_800F5288(void* arg0, void* arg1) {
    u8* p;

    if (*(s8*)((u8*)arg1 + 7) > 0) {
        *(s16*)((u8*)arg0 + 0x54) = 3;
        *(s16*)((u8*)arg0 + 0x56) = 8;
        *(s16*)((u8*)arg0 + 0x58) = 0xA;
        *(s32*)((u8*)arg0 + 8) = *(s32*)((u8*)arg1 + 8);
        do {
        } while (0);
        {
            s32 c = *(s32*)((u8*)arg1 + 0xC);
            *(u8*)((u8*)arg0 + 4) = 1;
            *(u8*)((u8*)arg0 + 5) = 0;
            *(s32*)((u8*)arg0 + 0xC) = c;
        }
        return;
    }
    if (*(s16*)((u8*)arg0 + 0x56) != 0) {
        if (--*(s16*)((u8*)arg0 + 0x56) & 1) {
            p = *(u8**)((u8*)arg0 + 0x5C);
            *(s32*)((u8*)arg0 + 8) = *(s32*)(p + 0x18);
            *(s32*)((u8*)arg0 + 0xC) = *(s32*)(p + 0x1C);
        }
    } else {
        *(u8*)((u8*)arg0 + 5) += 1;
    }
}
