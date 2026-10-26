#include "common.h"

#define SLOT_PTR (*(u8**)0x801F8300)

void ChangeTh(s32);

void func_80013360(s32 arg0) {
    *(s16*)(SLOT_PTR + 2) = arg0;
    *(s16*)(SLOT_PTR + 0) = 1;
    ChangeTh(0xFF000000);
}

#undef SLOT_PTR
