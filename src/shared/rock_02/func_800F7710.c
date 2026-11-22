// rolefeed (3.1 T4): func_800F7710 of src/rock_02/E9860.c

#include "common.h"
#include "mmx6/rock_02.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK animate_object();
M2C_UNK func_800F82C0();

void func_800F7710(void* arg0) {
    u8* sp;
    u8 v;

    func_800F82C0();
    animate_object(arg0);
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        sp = SPAD;
        v = D_800FB810[(sp[0x85] & 3) + sp[0x84] * 4];
        M2C_FIELD(arg0, u8*, 6) = 0;
        M2C_FIELD(arg0, u8*, 5) = v;
    }
}
