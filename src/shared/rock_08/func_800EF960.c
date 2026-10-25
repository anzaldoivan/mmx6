#include "common.h"
#include "mmx6/x4.h"

#define OUB(p, o) (*(u8*)((u8*)(p) + (o)))
#define OH(p, o) (*(s16*)((u8*)(p) + (o)))
#define OW(p, o) (*(s32*)((u8*)(p) + (o)))

s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern struct X4_PlayerObj g_Player;

void func_800EF960(void* arg0) {
    struct X4_PlayerObj* pl = &g_Player;
    s32 limit;
    s32 angle;

    limit = 0x14;
    if (pl->unk2 != 0) {
        limit = 0x28;
    }
    if (limit < ++OUB(arg0, 0x88)) {
        angle = func_80065B74(pl->y_pos.i.hi - OH(arg0, 0xE),
                              pl->x_pos.i.hi - OH(arg0, 0xA));
        OW(arg0, 0x20) = func_80065A14(angle) << 5;
        OW(arg0, 0x24) = -func_80065944(angle) << 5;
        OUB(arg0, 0x6) = 5;
    }
}
