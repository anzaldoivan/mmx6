#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_BackgroundObj D_800971F8[3];
extern struct X4_EngineObj D_800CCED0;

void func_80012890(s32 arg0);
M2C_UNK func_80013DE8();
void func_80017E24(void);
void func_8001D218();
void func_80025F34();
void func_800280F4(void);
void func_80029B8C(void);
void func_8002B838(void);
void func_8002C1DC();
void func_8002C2B8();

void func_8001DE10(void* arg0) {
    M2C_FIELD(arg0, s8*, 0xD) = 2;
    func_8001D218();
    func_8002C1DC();
    D_800CCED0.stage = 0xE;
    D_800CCED0.substage = 0;
    func_80013DE8();
    func_80012890(1);
    func_80017E24();
    func_8002B838();
    func_8002C2B8();
    func_80029B8C();
    func_800280F4();
    func_80025F34();
    D_800971F8[0].unk3 = 1;
    D_800971F8[1].unk3 = 0;
    D_800971F8[2].unk3 = 0;
    M2C_FIELD(arg0, u8*, 1) = (u8)(M2C_FIELD(arg0, u8*, 1) + 1);
}
