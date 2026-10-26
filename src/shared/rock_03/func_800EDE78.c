#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
extern struct X4_PlayerObj g_Player;

#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800EDE78(void* arg0) {
    s32 ang;
    s32 dx;
    s32 dy;
    s32 m;
    // !FAKE: depin: dropping it breaks the match (39/46)
    register u16 c asm("$2");

    func_80017A04();
    c = F16(arg0, 0x8C);
    F16(arg0, 0x8C) = c + 1;
    if ((s16)c >= 0x5B) {
        dx = g_Player.x_pos.i.hi - F16(arg0, 0xA);
        dy = g_Player.y_pos.i.hi - F16(arg0, 0xE);
        ang = ratan2(dy, dx);
        m = rcos(ang) * 0x10;
        F32(arg0, 0x20) = m * 4 + m;
        m = -rsin(ang) * 0x10;
        F32(arg0, 0x24) = m * 4 + m;
        F16(arg0, 0x8C) = 0;
        FU8(arg0, 0x6)++;
    }
}
