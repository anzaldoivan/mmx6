#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj D_800971F8[3];
extern void (*D_800F6DF0[])(u8*);

void func_800EE300(u8* arg0) {
    D_800F6DF0[(s8)arg0[4]](arg0);
    if (*(u16*)(arg0 + 0x1E) != 0) {
        u16 v;
        *(u16*)(arg0 + 0x14) = *(u16*)(arg0 + 0x14) + 1;
        v = *(u16*)(arg0 + 0x14);
        if (!(v & 3)) {
            if ((v >> 2) >= 5) {
                *(u16*)(arg0 + 0x14) = 0;
            }
            {
                u8* bg = (u8*)D_800971F8;
                u16 x = *(u16*)(arg0 + 0x14);
                bg[0xA0] = 1;
                *(u16*)(bg + 0x62) = (x >> 2) << 8;
            }
        }
    }
}
