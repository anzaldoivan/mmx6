#include "common.h"
#include "mmx6/x4.h"

#define F(p, T, o) (*(T*)((u8*)(p) + (o)))

struct X4_QuadObj* func_8002C7F0(void);
extern u16 D_800EA814[][8];
extern u16 D_800EA844[];

void func_800E9A98(void* arg0) {
    struct X4_QuadObj* child;
    s32 idx;

    F(arg0, s8, 0x37) = -1;
    F(arg0, u8, 0x3) = 1;
    F(arg0, s32, 0x8) = 0;
    F(arg0, s32, 0xC) = 0;
    F(arg0, u8, 0x4)++;
    if (F(arg0, s8, 0x2) == 0) {
        child = func_8002C7F0();
        F(arg0, void*, 0x38) = child;
        if (child != 0) {
            F(child, u8, 0x0) = 1;
            F(F(arg0, void*, 0x38), u8, 0x1) = 0xA;
            F(F(arg0, void*, 0x38), u8, 0x36) = F(arg0, u8, 0x36);
            F(F(arg0, void*, 0x38), u8, 0x2) = 1;
        }
    }
    idx = F(arg0, s8, 0x2);
    F(arg0, u16, 0x16) = D_800EA814[idx][0];
    F(arg0, u16, 0x1A) = D_800EA814[idx][1];
    F(arg0, u16, 0x1E) = D_800EA814[idx][2];
    F(arg0, u16, 0x22) = D_800EA814[idx][3];
    F(arg0, u16, 0x26) = D_800EA814[idx][4];
    F(arg0, u16, 0x2A) = D_800EA814[idx][5];
    F(arg0, u16, 0x2E) = D_800EA814[idx][6];
    F(arg0, u16, 0x32) = D_800EA814[idx][7];
    F(arg0, u16, 0x34) = D_800EA844[idx];
}
