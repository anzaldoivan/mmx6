#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

int func_80060964(int mode);
void func_80065DD4(s32);
M2C_UNK func_800660B8(M2C_UNK);
M2C_UNK func_80066150(M2C_UNK);
void func_800662D4(X4_RECT*, s32, s32, s32);
void func_80068D94(void*, s32, s32, s32, s32);

extern u8 D_800C4578[];
#define DB_DISP(i) (*(X4_DISPENV*)(D_800C4578 + (i) * 0xF0))
extern X4_DISPENV D_800E2E88[];

void func_8001ACC4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    X4_RECT rect;

    D_800E2E88[0] = DB_DISP(0);
    D_800E2E88[1] = DB_DISP(1);
    func_80065DD4(0);
    rect.x = 0;
    rect.y = 0;
    rect.w = 0x1E0;
    rect.h = 0x1E0;
    func_80060964(0);
    func_800662D4(&rect, 0, 0, 0);
    func_80066150(0);
    func_800660B8(1);
    func_80068D94(D_800C4578, 0, 0, arg0, arg1);
    func_80068D94(D_800C4578 + 0xF0, 0, 0xF0, arg0, arg1);
    {
        // !FAKE: depin: dropping it breaks the match (93/96)
        register s32 one asm("$3") = 1;
        D_800C4578[0x101] = one;
        D_800C4578[0x11] = one;
    }
    D_800C4578[0x100] = 0;
    D_800C4578[0x10] = 0;
}
#undef DB_DISP
