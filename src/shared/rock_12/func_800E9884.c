#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C850(void*, s32);
extern u16 D_800EA774[][10];

void func_800E9884(void* arg0) {
    void* child;
    s32 idx;

    M2C_FIELD(arg0, s8*, 0x37) = -1;
    M2C_FIELD(arg0, s8*, 0x3) = 1;
    M2C_FIELD(arg0, s32*, 0x8) = 0;
    M2C_FIELD(arg0, s32*, 0xC) = 0;
    M2C_FIELD(arg0, u8*, 0x4)++;
    idx = M2C_FIELD(arg0, s8*, 0x2);
    M2C_FIELD(arg0, u16*, 0x16) = D_800EA774[idx][0];
    M2C_FIELD(arg0, u16*, 0x1A) = D_800EA774[idx][1];
    M2C_FIELD(arg0, u16*, 0x1E) = D_800EA774[idx][2];
    M2C_FIELD(arg0, u16*, 0x22) = D_800EA774[idx][3];
    M2C_FIELD(arg0, u16*, 0x26) = D_800EA774[idx][4];
    M2C_FIELD(arg0, u16*, 0x2A) = D_800EA774[idx][5];
    M2C_FIELD(arg0, u16*, 0x2E) = D_800EA774[idx][6];
    M2C_FIELD(arg0, u16*, 0x32) = D_800EA774[idx][7];
    switch (idx) {
    case 0:
        child = func_8002C850(arg0, 0);
        if (child != 0) {
            M2C_FIELD(child, u8*, 0x0) = 1;
            M2C_FIELD(child, u8*, 0x1) = 9;
            M2C_FIELD(child, u8*, 0x36) = M2C_FIELD(arg0, u8*, 0x36);
            M2C_FIELD(child, u8*, 0x2) = 4;
            M2C_FIELD(child, u16*, 0x34) = M2C_FIELD(arg0, u16*, 0x34);
            M2C_FIELD(child, s32*, 0x38) = M2C_FIELD(arg0, s32*, 0x38);
        }
    case 4:
        M2C_FIELD(arg0, s32*, 0x40) = 0xA00000 / M2C_FIELD(arg0, s32*, 0x38);
        M2C_FIELD(arg0, u8*, 0x5) = 0;
        break;
    case 1:
        child = func_8002C850(arg0, 0);
        if (child != 0) {
            M2C_FIELD(child, u8*, 0x0) = 1;
            M2C_FIELD(child, u8*, 0x1) = 9;
            M2C_FIELD(child, u8*, 0x36) = M2C_FIELD(arg0, u8*, 0x36);
            M2C_FIELD(child, u8*, 0x2) = 5;
            M2C_FIELD(child, s32*, 0x38) = M2C_FIELD(arg0, s32*, 0x38);
            M2C_FIELD(child, u16*, 0x34) = M2C_FIELD(arg0, u16*, 0x34);
        }
    case 5:
        M2C_FIELD(arg0, s32*, 0x44) = 0x400000 / M2C_FIELD(arg0, s32*, 0x38);
        M2C_FIELD(arg0, u8*, 0x5) = 1;
        break;
    case 2:
    case 6:
        M2C_FIELD(arg0, s32*, 0x40) = 0x1400000 / M2C_FIELD(arg0, s32*, 0x38);
        M2C_FIELD(arg0, u8*, 0x5) = 2;
        break;
    case 3:
    case 7:
        M2C_FIELD(arg0, s32*, 0x44) = 0x800000 / M2C_FIELD(arg0, s32*, 0x38);
        M2C_FIELD(arg0, u8*, 0x5) = 3;
        break;
    }
}
