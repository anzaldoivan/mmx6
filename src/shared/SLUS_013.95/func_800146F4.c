#include "common.h"

extern s32 D_80097420;
extern u8 D_800A51B8[];
extern u8 D_800C4858[];

void func_800139F4(s32);
void set_resolution(s32 arg0);
void task_yield(s32);
void func_80017E6C(void);
void func_800144DC(u8);

#define D_80097420_B ((s8*)&D_80097420)
#define SCR146F4_BUF (*(s32*)0x1F800000)
#define SCR146F4_PTR(off) (*(u8**)(0x1F800000 + (off)))

void func_800146F4(void) {
    s32 buf;
    u8 i;

    func_800139F4(0x10);
    while (1) {
        {
            s8* g = D_80097420_B;
            if (g[4] == 0) {
                break;
            }
        }
        set_resolution(0);
        buf = SCR146F4_BUF;
        SCR146F4_PTR(0x100) = D_800A51B8 + buf * 0xA000;
        SCR146F4_PTR(0x104) = D_800C4858 + buf * 0x2000;
        func_80017E6C();
        for (i = 0; i < 10; i++) {
            func_800144DC(i);
        }
        task_yield(1);
    }
}

#undef D_80097420_B
#undef SCR146F4_BUF
#undef SCR146F4_PTR
