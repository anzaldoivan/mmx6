#include "common.h"
#include "psyq/libsnd.h"

extern s8 D_80090D50[6];
extern u8* D_80097738[];
extern s32 D_80097758[];
extern s32* D_80097778[];
extern s32 D_8009B7A4;
extern VabSlot* D_8009B7A8;
extern s32 D_800E1550[];

#define ST_STATE (*(u8*)&D_800E1550[0])
#define ST_MODE (((u8*)D_800E1550)[1])
#define ST_REM D_800E1550[1]
#define ST_OFS D_800E1550[2]

s32 func_8001717C(u8 arg0) {
    s8* slot;
    u8* data;
    u32 hdr;
    s32 n;
    s32 ret;
    s8 r;
    s32* st;
    s32 size;
    u8 mode;

    switch (ST_STATE) {
    case 0:
        mode = *(u32*)D_8009B7A8 >> 24;
        hdr = D_8009B7A8->ofs;
        slot = &D_80090D50[arg0];
        ST_OFS = 0;
        size = D_8009B7A8->size;
        data = (u8*)D_8009B7A8 + hdr;
        ST_REM = size;
        ST_MODE = mode;
        SsVabClose(*slot);
        r = SsVabOpenHeadSticky(data, ST_MODE, D_80097758[arg0]);
        if (r == -1) {
            return -1;
        }
        *slot = r;
        D_80097738[arg0] = data;
        D_80097778[arg0] = (s32*)(D_8009B7A8 + 1);
        ST_STATE++;
    case 1:
        n = ST_REM;
        if (n > 0x1000) {
            n = 0x1000;
        }
        ret = SsVabTransBodyPartly((u8*)(D_8009B7A4 + ST_OFS), n, ST_MODE);
        if (ret == -1) {
            return -1;
        }
        SsVabTransCompleted(1);
        ST_REM -= n;
        ST_OFS += n;
    default:
        st = D_800E1550;
        if (ret == ((u8*)st)[1]) {
            ST_STATE = 0;
        }
        return ret;
    }
}

#undef ST_STATE
#undef ST_MODE
#undef ST_REM
#undef ST_OFS
