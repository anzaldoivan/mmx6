#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80012890(s32 arg0);
M2C_UNK func_800139A0(M2C_UNK);
void func_800144AC(void);
void func_8001750C(u8, u8);
void func_80017E6C(void);
void func_800186A8(void);
void func_80025F84(void);
void func_8002B838(void);
void func_8002C2B8();
void* func_8002C530();

void func_8001D7AC(void* arg0) {
    u8* obj;

    func_80012890(1);
    M2C_FIELD(arg0, u8*, 0xD) = 1;
    func_80025F84();
    func_800186A8();
    func_8001750C(0xFF, 0);
    func_8002B838();
    func_8002C2B8();
    func_800144AC();
    func_80017E6C();
    obj = func_8002C530();
    if (obj != 0) {
        obj[1] = 0x15;
        obj[0] = 1;
        obj[0x47] = 0;
        obj[2] = 0;
        M2C_FIELD(obj, s16*, 0xA) = 0x80;
        M2C_FIELD(obj, s16*, 0xE) = 0x78;
    }
    obj = func_8002C530();
    if (obj != 0) {
        obj[1] = 0x15;
        obj[0] = 1;
        obj[0x47] = 1;
        obj[2] = 0;
        M2C_FIELD(obj, s16*, 0xA) = 0x180;
        M2C_FIELD(obj, s16*, 0xE) = 0x78;
    }
    M2C_FIELD(arg0, s16*, 4) = 0x12C;
    ((void (*)(s32))func_800139A0)(8);
    M2C_FIELD(arg0, u8*, 1) += 1;
}
