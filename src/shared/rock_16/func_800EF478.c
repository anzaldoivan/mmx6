#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj g_playthrough_state;
extern s32 D_800F0E74[];

#define EF478_ENG_2A (g_playthrough_state.character_state.bytes[4])
#define EF478_ENG_70 (*(s32*)((u8*)&g_playthrough_state + 0x70))
#define EF478_U8(o) (*(u8*)((s8*)arg0 + (o)))

void func_800EF478(void* arg0) {
    // !FAKE: depin: dropping it breaks the match (51/54)
    register s32 t asm("$2");
    set_animation_frame(arg0, 4, EF478_ENG_2A);
    t = g_playthrough_state.unk5F;
    if (t & 0x10) {
        if (g_playthrough_state.unk1 == 5) {
            EF478_U8(3) = 0;
        }
        if (g_playthrough_state.unk1 == 6) {
            func_8002CCB0(arg0, 0x60, 0x10);
        }
    } else {
        func_8002CCB0(arg0, 0x60, 0x10);
    }
    if (!(D_800F0E74[EF478_ENG_2A] & EF478_ENG_70)) {
        EF478_U8(3) = 0;
    }
}

#undef EF478_ENG_2A
#undef EF478_ENG_70
#undef EF478_U8
