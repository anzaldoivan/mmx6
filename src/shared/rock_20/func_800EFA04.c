#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139A0(M2C_UNK);
void func_8001D218();
void func_80025F34();
s32 func_800280F4();
void init_checkpoint_positions(void);
void func_800F02A0(u8, s8, s32, s16);
M2C_UNK func_800F0324(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32);
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_80097427;

void func_800EFA04(struct X4_EngineObj* arg0) {
    func_8001D218();
    init_checkpoint_positions();
    func_800280F4();
    func_80025F34();
    background_objects[2].x_pos.i.hi = 0x200;
    background_objects[2].unk4C = 1;
    func_800F02A0(0x95, 1, 0x11C, 0x40);
    func_800F0324(0xBC, 1, 0x16C, 0x80, 0);
    func_800F0324(0xC1, 1, 0x16C, 0xA0, 1);
    func_800F02A0(0xB9, 1, 0, 0);
    D_80097427 = 1;
    arg0->unk1F = 0;
    arg0->enable_boss = 0;
    ((void (*)(s32))func_800139A0)(8);
    arg0->unk8 = 1;
    arg0->unk2++;
}
