#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D230();
#define SPAD (*(u8**)0x1F80004C)

void func_800EAA04(void* arg0) {
    u8* sp;

    func_8002D230(arg0);
    if (M2C_FIELD(arg0, s8*, 0x45) == 3) {
        sp = SPAD;
        if (--sp[0x86] & 0xFF) {
            M2C_FIELD(arg0, u8*, 0x6) = 0;
            return;
        }
        M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
    }
}
