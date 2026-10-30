#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern u8** D_8007A01C[];
extern u8* D_80079F64[];
extern u8 D_800C4560;
extern struct X4_EngineObj g_playthrough_state;
extern s8 D_800E4480;
M2C_UNK func_8002C9D4();

#define SCRATCH_28 (*(s32**)0x1F800028)
#define SCRATCH_30 (*(s32**)0x1F800030)
#define F_U8(o) (*(u8*)(arg0 + (o)))
#define F_S8(o) (*(s8*)(arg0 + (o)))
#define F_PTR(o) (*(u8**)(arg0 + (o)))
#define F_WPTR(o) (*(s32**)(arg0 + (o)))

void func_80052610(u8* arg0) {
    u8* p;
    s32* dst;
    s32* src;
    u32 i;

    i = F_U8(2);
    F_U8(0) = 9;
    F_PTR(0x1C) = D_8007A01C[g_playthrough_state.stage * 2 +
                             g_playthrough_state.substage][i];
    if (F_PTR(0x1C) == 0) {
        func_8002C9D4(arg0);
        return;
    }
    i = (u8)(i - 1);
    p = D_80079F64[g_playthrough_state.stage * 2 +
                   g_playthrough_state.substage];
    while (i != 0xFF) {
        i = (u8)(i - 1);
        p += 2;
    }
    F_WPTR(0x18) = SCRATCH_28 + p[0] * 8;
    dst = F_WPTR(0x18);
    F_WPTR(0x14) = SCRATCH_30 + F_PTR(0x1C)[0] * 8;
    src = F_WPTR(0x14);
    F_U8(0x21) = F_PTR(0x1C)[1];
    F_U8(0x20) = p[1];
    for (i = 0; i < F_S8(0x20) * 8; i++) {
        *dst++ = *src++;
    }
    D_800C4560 |= 1;
    F_U8(4)++;
    if (g_playthrough_state.stage == 8 && g_playthrough_state.checkpoint == 0) {
        D_800E4480 = 1;
    } else {
        D_800E4480 = 0;
    }
}
