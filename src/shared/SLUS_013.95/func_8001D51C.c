#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800139A0(M2C_UNK);
void func_80017E24(void);
void func_8001E730(void);
void func_8001E78C(void);
void func_80021434(void);
void func_80025F34();
void func_800280F4(void);
void func_8002927C(void);
void func_8002935C(void);
M2C_UNK func_800293CC();
void func_80029B8C(void);
void func_8002A33C(void);
void func_8002A3E8(void);
void func_8002B838(void);
void func_8002C2B8();
void* func_8002C530();
void func_8003BD24(void);

void func_8001D51C(u8* arg0) {
    u32 i;
    u8* obj;

    func_8002B838();
    func_8002C2B8();
    func_80017E24();
    func_80021434();
    func_800280F4();
    func_80029B8C();
    func_8002927C();
    func_8002935C();
    func_800293CC();
    func_8003BD24();
    func_8002A33C();
    func_8002A3E8();
    func_80025F34();
    func_8001E730();
    for (i = 2; i < 5; i++) {
        obj = func_8002C530();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x12;
            obj[2] = i;
        }
    }
    func_8001E78C();
    arg0[2] = 0;
    arg0[1]++;
    ((void (*)(s32))func_800139A0)(8);
}
