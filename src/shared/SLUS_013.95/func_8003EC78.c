#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_8003C4EC(struct X4_PlayerObj* self);
void func_8003CF54(struct X4_PlayerObj*, s32);
s32 func_8003ED98(struct X4_PlayerObj* p);
void func_8003EEE4(void* arg0);
M2C_UNK func_8003F480();
s32 func_8003FF90(struct X4_PlayerObj*, s32);
void func_8003FFF4(struct X4_PlayerObj*);

void func_8003EC78(struct X4_PlayerObj* p) {
    u8* b = (u8*)p;
    s8 t;

    if (p->unk2 != 0) {
        return;
    }
    if (*(s8*)(b + 0xE0) != 0 && b[0xE7] == 4) {
        return;
    }
    t = p->unk5;
    if (t == 0) {
        return;
    }
    if (t == 1) {
        return;
    }
    if (t == 0x19) {
        return;
    }
    if (t == 0x18) {
        return;
    }
    if (*(s8*)(b + 0xD5) != 0) {
        return;
    }
    if (func_8003ED98(p) != 0) {
        func_8003F480(p);
        {
            // !FAKE: depin: dropping it breaks the match (70/72)
            register s32 a asm("$2") = *(s8*)(b + 0xA2);
            if (a != 0) {
                func_8003CF54(p, 0x32);
            } else {
                func_8003C4EC(p);
            }
        }
        if (*(s8*)(b + 0xA6) == 1) {
            b[0xA1] = 0x29;
        }
    } else if (!(*(s32*)(b + 0xEC) & 0x80000)) {
        func_8003EEE4(p);
        func_8003FFF4(p);
        if (func_8003FF90(p, 0) == 0) {
            func_8003FF90(p, 1);
        }
    }
}
