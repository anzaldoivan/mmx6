#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80037A60(void* arg0);
void func_8003B114(s32 arg0);
void func_8003C4EC(struct X4_PlayerObj* self);
void func_8003CF54(struct X4_PlayerObj*, s32);
void func_8003D014(void* arg0);

void func_80037880(void* arg0) {
    s8* p = arg0;

    func_80037A60(p);
    if (p[2] == 0) {
        if (((u8*)p)[0x47] == 0xD0) {
            func_8003CF54((struct X4_PlayerObj*)p, 0x52);
        } else {
            func_8003C4EC((struct X4_PlayerObj*)p);
        }
    }
    if (p[0x61] == 0x3C) {
        ((void (*)(s32))func_8003B114)((s32)p);
        if (p[0xD3] != 0) {
            p[0xA4] = 0;
            p[0x61] = 0;
            return;
        }
        func_8003D014(p);
        p[0xA4] = -1;
    }
}
