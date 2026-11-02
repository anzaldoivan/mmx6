#include "common.h"

extern u8 D_800A51B8[];
extern u8 D_800C4858[];

void set_resolution(s32 arg0);
void func_80017E6C(void);
void func_800144DC(u8);

#define SCR1466C_BUF (*(s32*)0x1F800000)
#define SCR1466C_PTR(off) (*(u8**)(0x1F800000 + (off)))

// 0x8001466C init_loading_screen: loading screen per-call step.
// basis: community tweaks-index.tsv:40
// callers: none known
void init_loading_screen(void) {
    s32 buf;
    u8 i;

    set_resolution(0);
    buf = SCR1466C_BUF;
    SCR1466C_PTR(0x100) = D_800A51B8 + buf * 0xA000;
    SCR1466C_PTR(0x104) = D_800C4858 + buf * 0x2000;
    func_80017E6C();
    for (i = 0; i < 10; i++) {
        func_800144DC(i);
    }
}

#undef SCR1466C_BUF
#undef SCR1466C_PTR
