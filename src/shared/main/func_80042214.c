// rolefeed (3.1 T4): func_80042214 of src/main/40388.c
#include "common.h"
#include "mmx6/x4.h"

#define UNK98(self) (((u8*)(self))[0x98])

#include "common.h"

#define M2C_UNK s32

M2C_UNK func_800429D4();

void func_80042214(void* arg0) {
    if (--*(s16*)((u8*)arg0 + 0x7C) == 0) {
        func_800429D4();
    }
}
