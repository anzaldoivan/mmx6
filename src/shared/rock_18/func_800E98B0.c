#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139A0(M2C_UNK);
M2C_UNK reset_level();
void func_800EA3F0(s32, s32, s32, s32);
void func_800EA470(s32, s32, s32, s32, s32);
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_80097427;

void func_800E98B0(u8* arg0) {
    reset_level();
    func_800EA3F0(0x10, 0, 0x150, 0x20);
    func_800EA470(0x11, 0, 0xD0, 0x40, 0);
    func_800EA3F0(0xF0, 0, 0x1B8, 0x40);
    func_800EA470(0x12, 0, 0xD0, 0x58, 1);
    func_800EA3F0(0xF1, 0, 0x1B8, 0x58);
    func_800EA470(0x13, 0, 0xD0, 0x70, 2);
    func_800EA470(0x14, 0, 0xD0, 0x88, 3);
    func_800EA3F0(0xF2, 0, 0x1B8, 0x88);
    func_800EA470(0x15, 0, 0xD0, 0xA0, 4);
    func_800EA3F0(0xF3, 0, 0x1B8, 0xA0);
    func_800EA3F0(0xF4, 0, 0x1C8, 0xA0);
    func_800EA470(0x26, 0, 0xD0, 0xB8, 5);
    func_800EA3F0(0x33, 0, 0xF0, 0xD3);
    arg0[3] = 0;
    D_80097427 = 0;
    func_800EA3F0(1, 0, 0, 0);
    background_objects[0].unk3 = 1;
    background_objects[0].x_pos.i.hi = 0x200;
    background_objects[0].y_pos.i.hi = 0;
    background_objects[0].unk4C = 1;
    background_objects[1].unk3 = 0;
    background_objects[2].unk3 = 0;
    ((void (*)(s32))func_800139A0)(8);
    arg0[1]++;
}
