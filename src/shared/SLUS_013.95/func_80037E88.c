#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
M2C_UNK func_8002D5D0(void*);
void func_8003A678(void* arg0);
void func_8003B870(struct X4_PlayerObj* self);
extern s8 D_800CCEDF;

void func_80037E88(void* arg0) {
    u8* p = arg0;

    if (D_800CCEDF != 0) {
        func_8003B870(arg0);
        return;
    }
    if (*(s8*)(p + 0x45) == 0) {
        *(s32*)(p + 0x20) = *(s32*)(p + 0xF0);
    } else {
        *(s32*)(p + 0x20) = *(s32*)(p + 0xF4);
    }
    if (*(u8*)(p + 0x15) == 0) {
        *(s32*)(p + 0x20) = -*(s32*)(p + 0x20);
    }
    func_8002D5D0(arg0);
    ((void (*)(void*))func_80017A04)(arg0);
    if (*(u8*)(p + 0xD2) == 0) {
        func_8003A678(arg0);
    }
}
