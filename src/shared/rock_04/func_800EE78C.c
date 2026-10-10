#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230();
M2C_UNK func_8002F288(M2C_UNK*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
extern s32 D_800F6C50[];
extern s32 D_800F6C58[];
extern M2C_UNK D_800F6CE0;

#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800EE78C(void* arg0) {
    register s32 t asm("$2");

    if (H(arg0, 0x7C) != 0) {
        W(arg0, 0x54) = 0;
        W(arg0, 0x50) = 0;
        H(arg0, 0x7C)--;
        UB(arg0, 3) ^= 1;
        return;
    }
    if ((UB(arg0, 0x70) & 1) && W(arg0, 0x20) > 0) {
        goto hit;
    }
    if ((UB(arg0, 0x70) & 2) && W(arg0, 0x20) < 0) {
    hit:
        func_80016C48(2, 0x11, arg0);
        func_800477E4(3, &D_800F6CE0, arg0);
        {
            register s32 c asm("$2") = 2;
            UB(arg0, 4) = c;
        }
    }
    UB(arg0, 3) = 1;
    W(arg0, 0x54) = (s32)&D_800F6C58[UB(arg0, 0x80)];
    W(arg0, 0x50) = (s32)&D_800F6C50[UB(arg0, 0x80)];
    func_80017A04(arg0);
    func_8002D230(arg0);
    t = UB(arg0, 0x70);
    if (t & 8) {
        W(arg0, 0x24) = 0x21000;
        W(arg0, 0x2C) = 0x1080;
        func_8002943C(8, 2, 2);
        func_80016C48(2, 0x11, arg0);
    }
    func_8002F288(arg0);
}
