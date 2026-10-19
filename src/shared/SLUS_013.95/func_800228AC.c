#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj D_800CCED0;

s32 func_800228AC(void) {
    struct X4_EngineObj* p = &D_800CCED0;
    s32 ret;
    u8 v;

    if (*(s8*)&p->unk38 == 0) {
        v = p->unk5C[2];
        if (v == 0) {
            ret = 0;
        } else if (v == 4) {
            ret = 2;
        } else if (v == 1) {
            ret = 3;
        } else if (v == 2) {
            ret = 4;
        } else {
            ret = 5;
        }
    } else {
        ret = 1;
        if (p->unk5F & 0x20) {
            ret = 6;
        }
    }
    return ret;
}
