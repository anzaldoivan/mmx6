#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017E24(void);
M2C_UNK func_80018060(M2C_UNK, M2C_UNK);
void func_80025F34();
void func_800280F4(void);
void func_80029B8C(void);
M2C_UNK func_800660B8(M2C_UNK);
extern struct X4_BackgroundObj D_800971F8[3];

void func_800EB7A4(u8* arg0) {
    u8* base;
    u8* p;
    u8 i;

    i = 0;
    base = arg0 + 0x26;
    do {
        base[i] = 0;
        i++;
    } while (i < 0x10);
    ((void (*)())func_80017E24)(base);
    func_80029B8C();
    func_800280F4();
    func_80025F34();
    D_800971F8[0].unk3 = 0;
    D_800971F8[1].unk3 = 0;
    D_800971F8[2].unk3 = 0;
    *(s16*)(arg0 + 4) = 0;
    arg0[2] = 0;
    func_80018060(7, 0x73);
    ((void (*)(M2C_UNK))func_800660B8)(1);
    arg0[1] = arg0[1] + 1;
}
