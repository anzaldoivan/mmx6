#include "common.h"
#include "mmx6/x4.h"

extern u8 D_80075FE8[];
extern struct X4_EngineObj D_800CCED0;

void func_80042D3C(void* arg0) {
    u16 id;
    u8* p;

    id = *(u16*)((s8*)arg0 + 0x88);
    p = (id >> 3) +
        (D_80075FE8[D_800CCED0.substage + D_800CCED0.stage * 2] << 5) +
        ((u8*)&D_800CCED0 + 0x178);
    *p |= 1 << (id & 7);
}
