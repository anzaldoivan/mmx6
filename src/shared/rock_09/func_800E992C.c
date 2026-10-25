#include "common.h"
#include "mmx6/x4.h"

extern s32 g_Player;

void func_800E9970(s8* self, s8* parent);
void func_800E9A60(struct X4_VisualObj* arg0, struct X4_PlayerObj* arg1);

void func_800E992C(s8* arg0) {
    u8* p = (u8*)&g_Player;

    if (arg0[4] == 0) {
        func_800E9970(arg0, (s8*)p);
    } else {
        func_800E9A60((struct X4_VisualObj*)arg0, (struct X4_PlayerObj*)p);
    }
}
