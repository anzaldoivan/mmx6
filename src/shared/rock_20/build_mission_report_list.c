#include "common.h"
#include "mmx6/x4.h"

s32 func_800F054C(void);
extern u8 D_80097169;
extern struct X4_EngineObj g_playthrough_state;

#define ENG ((u8*)&g_playthrough_state)

// 0x800EE6F4 build_mission_report_list: end of Mission Report; Gate check.
// basis: community tweaks-index.tsv:344
// callers: func_800EAC28
void build_mission_report_list(u8* arg0) {
    s32 flag;
    s32 n;
    u8* p;

    n = 0;
    {
        u8* e = ENG;
        if (!(*(s32*)(e + 0x24) & 0xFFFF0000)) {
            arg0[0x158] = 1;
            n = 1;
        }
        flag = 0;
        if ((u8)(e[0x26] - 1) < 8 && *(s8*)(e + 0x27) == 0) {
            if (D_80097169 != 0xFF) {
                flag = arg0[0x60] == 0xFF;
            }
        }
    }
    if (*(s16*)(arg0 + 0xD2) >= 3000 || *(s16*)(arg0 + 0xD4) >= 3000) {
        flag = 1;
    }
    {
        u8* e = ENG;
        if (*(s8*)(e + 0x27) == 0 && *(s8*)(e + 0x26) >= 0x13 &&
            arg0[0x43B] == 1) {
            flag = 1;
            arg0[0x43B] = 2;
        }
    }
    p = arg0 + 0x158;
    if (arg0[0x66] < 3) {
        if (flag != 0) {
            u8* e = ENG;
            if (*(s8*)(e + 0x38) == 0) {
                p[n] = 6;
            } else {
                p[n] = 7;
            }
            n++;
        } else if (D_80097169 == 0) {
            if (func_800F054C() != 0) {
                p[n] = 3;
                n++;
            }
        }
    }
    p[n] = 0xFF;
}
