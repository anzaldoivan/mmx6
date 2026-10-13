#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#ifndef M2C_FIELD
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#endif

#define SPAD (*(u8**)0x1F80004C)

s32 func_8002CAB4(struct X4_BaseObj*);
M2C_UNK func_8002CB50();
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void func_8004E680(struct X4_BaseObj* arg0, s8 arg1, s16 arg2, s16 arg3);
extern s32 D_800FC5F8;
extern void (*D_800FC6E4[])(u8*);

void func_800F3444(u8* arg0) {
    s32 r;
    s16 x;
    s16 y;
    u8 v;

    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    D_800FC6E4[M2C_FIELD(arg0, s8*, 0x5)](arg0);
    func_80030ECC(arg0);
    r = func_80031474(arg0);
    if (r < 0) {
        func_80049E50(arg0);
        func_800477E4(8, &D_800FC5F8, arg0);
        {
            register u8* sp asm("$4") = SPAD;
            x = M2C_FIELD(arg0, s16*, 0xA);
            y = M2C_FIELD(arg0, s16*, 0xE);
            v = sp[0x80];
        }
        if (v == 2) {
            goto end;
        }
        switch (v) {
        case 0:
            y += 0x10;
            break;
        case 1:
            x -= 0x10;
            break;
        case 3:
            x += 0x10;
            break;
        }
        func_8004E680((struct X4_BaseObj*)arg0, 0x12, x + 0x10, y);
        goto end;
    }
    if (r != 0) {
        M2C_FIELD(arg0, s8*, 0x5) = 1;
        M2C_FIELD(arg0, s8*, 0x6) = 0;
    }
    if (func_8002CAB4((struct X4_BaseObj*)arg0) == 0) {
        func_8002CB50(arg0);
    } else {
        M2C_FIELD(arg0, s8*, 0x4) = 2;
    }
    if (SPAD[0x82] >= 0x39) {
    end:
        M2C_FIELD(arg0, s8*, 0x4) = 2;
    }
}
