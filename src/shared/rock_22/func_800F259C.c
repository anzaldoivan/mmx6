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
extern void (*D_800FC68C[])(u8*);

void func_800F259C(u8* arg0) {
    s16 x;
    s16 y;

    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    D_800FC68C[M2C_FIELD(arg0, s8*, 0x5)](arg0);
    func_80030ECC(arg0);
    if (func_80031474(arg0) < 0) {
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        func_80049E50(arg0);
        func_800477E4(8, &D_800FC5F8, arg0);
        {
            // !FAKE: depin: dropping it breaks the match (68/73)
            register u8* sp asm("$2") = SPAD;
            x = M2C_FIELD(arg0, s16*, 0xA);
            y = M2C_FIELD(arg0, s16*, 0xE);
            if (sp[0x81] < 2) {
                // !FAKE: depin: dropping it breaks the match (46/73)
                register u8* a asm("$4") = arg0;
                // !FAKE: depin: dropping it breaks the match (39/73)
                register s32 t asm("$6") = x;
                // !FAKE: depin: dropping it breaks the match (45/73)
                register s32 k asm("$5") = 0x12;
                if (M2C_FIELD(arg0, u8*, 0x15) != 0) {
                    t -= 0x10;
                } else {
                    t += 0x10;
                }
                ((void (*)())func_8004E680)(a, k, (s16)t, y);
            } else {
                func_8004E680((struct X4_BaseObj*)arg0, 0x12, x, y + 0x10);
            }
        }
    } else if (func_8002CAB4((struct X4_BaseObj*)arg0) == 0) {
        func_8002CB50(arg0);
        return;
    }
    M2C_FIELD(arg0, s8*, 0x4) = 2;
}
