#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002C9B0();
s32 func_8003EB0C(void* arg0, s32 arg1);
void func_8003F740(void*, s32);
extern struct X4_PlayerObj g_Player;

void func_80045810(u8* arg0) {
    u8* p;
    u8* q;
    s8 idx;
    s16 v;

    if (*(s8*)(arg0 + 2) == 0) {
        if (*(s8*)(arg0 + 0x8C) != 0) {
            return;
        }
        {
            u8* r = (u8*)&g_Player;
            r[0x98]--;
            r[0x99]--;
        }
    } else {
        q = *(u8**)(arg0 + 0x7C);
        if (*(s8*)(q + 0x8C) != 0) {
            q[0x8C]--;
        }
        if (*(s8*)(arg0 + 0x8F) != 0) {
            p = (u8*)&g_Player;
            idx = 4;
            if (*(s8*)(p + 2) == 0) {
                idx = *(s8*)(p + 0x93);
            }
            v = *(s16*)((u8*)&g_Player + (idx << 1) + 0xA8);
            if (v >= func_8003EB0C(p, idx)) {
                if (*(s8*)(p + 2) != 0) {
                    *(s8*)(p + 0x93) = 4;
                    func_8003F740(p, 4);
                } else {
                    func_8003F740(p, *(s8*)(arg0 + 1));
                }
            }
        }
    }
    func_8002C9B0(arg0);
}
