#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK clear_object_slot();
extern s32 D_80097420;

void func_800EFE78(struct X4_BaseObj* self) {
    s32 a;
    s32 b;
    s32 c;

    a = *(u16*)((u8*)self + 0x80) + 1;
    b = *(u16*)((u8*)self + 0x82) - 1;
    *(u16*)((u8*)self + 0x80) = a;
    *(u16*)((u8*)self + 0x82) = b;
    if (!(D_80097420 & 1)) {
        *(u16*)((u8*)self + 0xA) = a;
    } else {
        *(u16*)((u8*)self + 0xA) = b;
    }
    c = *(u16*)((u8*)self + 0x7C) - 1;
    *(u16*)((u8*)self + 0x7C) = c;
    if ((c << 16) == 0) {
        clear_object_slot();
    }
}
