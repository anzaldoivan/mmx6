#include "common.h"

void func_8003D598(void* arg0) {
    u8* p = arg0;
    s32 k0 = 0x20000;
    // !FAKE: register order of a shared constant
    register s32 k1 asm("$2") = 0x4200;
    s32 k2 = 0x5D000;
    // !FAKE: register order of a shared constant
    register s32 k3 asm("$8") = 0xFFF98000;
    // !FAKE: register order of a shared constant
    register s32 k4 asm("$9") = 0x68000;
    // !FAKE: register order of a shared constant
    register s32 k5 asm("$11") = 0x42000;
    // !FAKE: register order of a shared constant
    register s32 k6 asm("$10") = 0xFFFE9000;
    // !FAKE: register order of a shared constant
    register s32 k7 asm("$7") = 0x5A000;
    s32 k8 = 0x18000;

    *(s32*)(p + 0xF0) = 0x8000;
    *(s32*)(p + 0xF4) = k0;
    *(s32*)(p + 0x134) = k1;
    *(s32*)(p + 0x100) = k1;
    *(s32*)(p + 0x10C) = -0x3000;
    *(s32*)(p + 0xF8) = k2;
    *(s32*)(p + 0xFC) = k3;
    *(s32*)(p + 0x104) = k4;
    *(s32*)(p + 0x108) = k5;
    *(s32*)(p + 0x110) = k6;
    *(s32*)(p + 0x114) = k7;
    *(s32*)(p + 0x118) = 0x10000;
    *(s32*)(p + 0x11C) = k8;
    *(s32*)(p + 0x120) = k0;
    *(s32*)(p + 0x124) = k0;
    *(s32*)(p + 0x128) = k8;
    *(s32*)(p + 0x12C) = k5;
    *(s32*)(p + 0x130) = k5;
}

#include "common.h"
#define M2C_UNK s32

void func_8003D598(void*);

M2C_UNK func_8003D630(void* arg0) {
    u8* p = arg0;

    func_8003D598(p);
    if (*(s32*)(p + 0xEC) & 8) {
        *(s32*)(p + 0x134) -= 0x1080;
    }
    if (*(u8*)(p + 0xE7) == 2) {
        *(s32*)(p + 0x110) = 0;
    }
    if (*(s32*)(p + 0xEC) & 0x10) {
        *(s32*)(p + 0x104) += 0x1A000;
        *(s32*)(p + 0x108) += 0x10800;
        *(s32*)(p + 0x10C) += 0xC00;
        *(s32*)(p + 0x12C) += 0x10800;
        *(s32*)(p + 0x130) += 0x10800;
    }
    if (*(s32*)(p + 0xEC) & 4) {
        *(s32*)(p + 0xF0) += 0x4000;
        *(s32*)(p + 0xF4) += 0x10000;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
void func_8003CF24(s32, s32, s32);
M2C_UNK player_spawn_visual(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2,
                            M2C_UNK arg3);

M2C_UNK func_8003D718(void* arg0) {
    u8* o = arg0;
    u8 m = g_playthrough_state.sub_tanks[2];

    o[0xE7] = m;
    *(s32*)(o + 0xEC) =
        *(s32*)((u8*)&g_playthrough_state + 0x74 + ((s8*)o)[2] * 4);
    if (m == 2) {
        o[0xC9] = 0;
        player_spawn_visual(1, 0x1B, 5, 0);
        func_8003CF24(2, 0x19, 1);
        func_8003CF24(2, 0x18, 1);
        return;
    }
    o[0xC9] = g_playthrough_state.unk60;
}
