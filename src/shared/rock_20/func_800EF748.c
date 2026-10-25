#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139A0(M2C_UNK);
void func_8001D218();
void func_80025F34();
s32 func_800280F4();
void func_80029B8C(void);
void func_800F02A0(u8, s8, s32, s16);
M2C_UNK func_800F03B8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800F0438(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_80097427;

void func_800EF748(struct X4_EngineObj* arg0) {
    func_8001D218();
    D_80097427 = 0;
    func_80029B8C();
    func_800280F4();
    func_80025F34();
    background_objects[2].x_pos.i.hi = 0x200;
    background_objects[2].unk4C = 1;
    func_800F03B8(0x22, 1, 0x130, 0x30);
    func_800F0438(0x21, 1, 0xF4, 0x7A, 0);
    func_800F0438(0x29, 1, 0x1EC, 0x7A, 0);
    func_800F0438(0x23, 1, 0xF4, 0xAC, 1);
    func_800F02A0(0xBD, 1, 0, 0);
    arg0->unk1F = 0;
    arg0->enable_boss = 0;
    ((void (*)(s32))func_800139A0)(8);
    arg0->unk8 = 1;
    arg0->unk2++;
}
