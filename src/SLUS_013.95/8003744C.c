#include "../shared/entity/state_dispatch.c"

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();               /* extern */
M2C_UNK func_8002D5D0(void*);          /* extern */
M2C_UNK func_8003B7B4(void*);          /* extern */
M2C_UNK func_8003BA04(void*, M2C_UNK); /* extern */

void func_80037488(void* arg0) {
    func_80017A04();
    func_8002D5D0(arg0);
    if (M2C_FIELD(arg0, s8*, 0x46) < 0) {
        func_8003BA04(arg0, 0x1F);
        func_8003B7B4(arg0);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();        /* extern */
void func_8003ADB4(void* arg0); /* extern */
M2C_UNK func_8003CCBC();        /* extern */

void func_800374D8(void* arg0) {
    ((void (*)())func_80017A04)();
    if (M2C_FIELD(arg0, s8*, 0x45) & 0x80) {
        M2C_FIELD(arg0, s8*, 0x45) = 0;
        M2C_FIELD(arg0, s16*, 0xE) -= 0x10;
        M2C_FIELD(arg0, s16*, 0x1E) = M2C_FIELD(arg0, s16*, 0xE) - 0x10;
        func_8003CCBC(arg0);
    }
    if (M2C_FIELD(arg0, s8*, 0x46) < 0) {
        M2C_FIELD(arg0, u8*, 0x67) = 0;
        func_8003ADB4(arg0);
    }
}
