#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8003D330();
extern struct X4_BackgroundObj D_800971F8[3];
extern s8 D_800CCF5C;
extern u8 D_800FD598;

void func_800F9308(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        func_80016C48(0, 0xE, 0);
        M2C_FIELD(arg0, s16*, 0x7C) = 2;
    }
    if (++M2C_FIELD(arg0, s8*, 0x5C) == D_800CCF5C) {
        // !FAKE: base built straight in the first arg register
        register struct X4_BackgroundObj* bg asm("$4") = D_800971F8;
        s32 v = D_800FD598;
        bg->unk2A = 0x10;
        bg->unk48 = v;
        func_8003D330(bg, v);
        M2C_FIELD(arg0, u8*, 5) = 0xA;
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
}
