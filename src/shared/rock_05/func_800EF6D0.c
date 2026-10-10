#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SCRATCH_4C (*(u8**)0x1F80004C)

void func_80025FD8();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_EngineObj D_800CCED0;

void func_800EF6D0(void* arg0) {
    u8 v;
    u8* e;
    register s32 t asm("$4");
    register u8* q asm("$3");

    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        func_8003D308(0x14, 0x40);
    }
    if (*M2C_FIELD(SCRATCH_4C, s8**, 0x80) == 0) {
        e = (u8*)&D_800CCED0;
        M2C_FIELD(e, s8*, 0x24) = 1;
        M2C_FIELD(e, s8*, 0x25) = 0;
        M2C_FIELD(e, void**, 0x20) = arg0;
        func_80025FD8();
        {
            register s32 k asm("$3") = 0x30;
            M2C_FIELD(e, u8*, 0x8C) = k;
        }
        t = M2C_FIELD(e, u8*, 0x8F);
        if (t == 2) {
            M2C_FIELD(e, u8*, 0x8C) = 0x34;
        } else if (t == 3) {
            M2C_FIELD(e, u8*, 0x8C) = 0x38;
        }
        q = (u8*)&D_800CCED0;
        {
            register u8* w asm("$4") = SCRATCH_4C;
            register s32 r asm("$2") = M2C_FIELD(q, u8*, 0x8C);
            M2C_FIELD(w, u8*, 0x87) = r;
        }
        {
            register s32 k asm("$2") = 0xFFFF0000;
            M2C_FIELD(arg0, s32*, 0x24) = k;
        }
        M2C_FIELD(arg0, s8*, 0x15) = 0;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        M2C_FIELD(arg0, s8*, 3) = 1;
        M2C_FIELD(arg0, s8*, 6) = M2C_FIELD(arg0, s8*, 6) + 1;
    }
}
