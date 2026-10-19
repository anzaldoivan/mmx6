#include "common.h"

void func_800EA70C(void* arg0) {
    if ((*(u16*)((u8*)arg0 + 0x16))++ >= 0x79) {
        *(u16*)((u8*)arg0 + 0x16) = 0;
        *((u8*)arg0 + 5) = 0;
    }
}
