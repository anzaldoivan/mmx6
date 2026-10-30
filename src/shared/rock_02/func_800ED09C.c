#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
M2C_UNK func_8002CA14();
M2C_UNK func_8002CA54();

#define SPAD (*(u8**)0x1F80004C)

void func_800ED09C(void* arg0) {
    SPAD[0x80] = 0;
    SPAD[0x81] = 0;
    SPAD[0x82] = 0;
    SPAD[0x83] = 0;
    SPAD[0x84] = 0;
    SPAD[0x85] = 0;
    SPAD[0x86] = 0;
    SPAD[0x87] = 0;
    SPAD[0x88] = 0;
    if (M2C_FIELD(arg0, s8*, 2) & 0x80) {
        clear_object_slot(arg0);
    } else if (M2C_FIELD(arg0, s8*, 4) == 2) {
        func_8002CA14(arg0);
    } else {
        func_8002CA54(arg0);
    }
}
