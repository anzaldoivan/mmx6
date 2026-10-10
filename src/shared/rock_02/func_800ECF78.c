#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK func_80017A04();
s32 func_8002CAB4(struct X4_BaseObj*);
M2C_UNK func_8002CB50();
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
void func_8004E654(void*, s8);
void func_800EC784(void*);
extern s32 D_800970A8;
extern M2C_UNK D_800FAE0C;
extern void (*D_800FAE48[])(void*);

void func_800ECF78(void* arg0) {
    s8 v;

    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    if (func_80031474(arg0) < 0) {
        func_80049E50(arg0);
        func_8004E654(arg0, 0x12);
        func_800477E4(5, &D_800FAE0C, arg0);
        v = 2;
        goto end;
    }
    if (M2C_FIELD(arg0, s8*, 2) == 3) {
        if (M2C_FIELD(arg0, s32*, 8) > D_800970A8) {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        }
    }
    func_800EC784(arg0);
    if (SPAD[0x89] < 0x3C) {
        D_800FAE48[M2C_FIELD(arg0, s8*, 5)](arg0);
    } else {
        func_80017A04(arg0);
    }
    func_80030ECC(arg0);
    if (func_8002CAB4(arg0) != 0) {
        v = 4;
        goto end;
    }
    func_8002CB50(arg0);
    return;
end:
    M2C_FIELD(arg0, u8*, 4) = v;
}
