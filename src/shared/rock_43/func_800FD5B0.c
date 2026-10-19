#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002C9B0();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj D_800CCED0;

void func_800FD5B0(void* arg0) {
    s8* p = M2C_FIELD(arg0, s8**, 0x80);

    if (p[0] != 0) {
        if (p[7] == 0) {
            if (--M2C_FIELD(arg0, s16*, 0x7E) == -1) {
                M2C_FIELD(arg0, u16*, 0x7E) = 5;
                M2C_FIELD(arg0, u16*, 0x42) ^= 0x8000;
            }
            func_8002CCB0(arg0, 0x40, 0x40);
        }
    } else {
        struct X4_EngineObj* e = &D_800CCED0;

        if (M2C_FIELD(e, u8*, 0x8F) == 3) {
            M2C_FIELD(e, u8*, 0x5F) |= 0x20;
        }
        M2C_FIELD(e, u8*, 0xF) = 0x10;
        func_8002C9B0(arg0, e);
    }
}
