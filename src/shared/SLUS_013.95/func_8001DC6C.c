#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80012890(s32 arg0);                   /* extern */
M2C_UNK func_80014F70(M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
void func_80016178(void);                          /* extern */
void func_8002B838(void);                          /* extern */

void func_8001750C(u8, u8);
void func_80017E6C(void);
void func_800186A8(void);
void func_80025F84();
void func_8002C2B8();
void func_8001DC6C(void* arg0) {
    M2C_FIELD(arg0, s8*, 0xD) = 1;
    ((M2C_UNK(*)())func_80025F84)();
    ((M2C_UNK(*)())func_800186A8)();
    func_8001750C(0xFF, 0);
    func_8002B838();
    ((M2C_UNK(*)())func_8002C2B8)();
    func_80014F70(0xA2, 0, 0);
    func_80016178();
    func_80012890(1);
    ((M2C_UNK(*)())func_80017E6C)();
    M2C_FIELD(arg0, s16*, 4) = 4;
    M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
}
