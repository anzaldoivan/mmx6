#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(u16*)((u8*)(p) + (o)))
#define S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define FP(p, o) (*(void**)((u8*)(p) + (o)))

void set_boss_level();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
void func_800EF164();

extern u8 D_800E9860[];
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern void* D_800F70E0;

void func_800ED124(void* arg0) {
    u8 tbl[4];
    s8 v;
    u8 add;

    __builtin_memcpy(tbl, D_800E9860 + 4, 4);
    if (--S16(arg0, 0x7C) == 0) {
        func_8003D308(0x14, 0x40);
    }
    v = *(s8*)D_800F70E0;
    if (v == 0) {
        g_playthrough_state.enable_boss = 1;
        g_playthrough_state.unk25 = 1;
        FP(&g_playthrough_state, 0x20) = arg0;
        F8(&g_playthrough_state, 0x8C) = 0x30;
        set_boss_level();
        {
            u8 c = F8(&g_playthrough_state, 0x8C);
            add = tbl[F8(&g_playthrough_state, 0x8F)];
            F8(&g_playthrough_state, 0x8C) = c + add;
        }
        F16(arg0, 0xA) = background_objects[0].unk26 + 0xF0;
        {
            u16 y = background_objects[0].unk2A;
            F8(arg0, 7) = 0;
            F16(arg0, 0xE) = y + 0x50;
        }
        func_800EF164(arg0, 0, background_objects, add);
        func_800EF164(arg0, 1);
        F8(arg0, 6)++;
    }
}
