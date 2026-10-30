#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern struct X4_EngineObj g_playthrough_state;
extern u8 capsule_parts[];
M2C_UNK set_animation(void*, M2C_UNK);
void func_8003C4EC(struct X4_PlayerObj* self);

// 0x80051ED4 apply_capsule_part: capsule applies part, mugshot, saber palette.
// basis: community tweaks-index.tsv:220
// callers: none known
void apply_capsule_part(struct X4_PlayerObj* arg0) {
    struct X4_PlayerObj* p = &g_Player;
    s8 t;
    s32 x = arg0->x_pos.val;

    *((u8*)p + 0xE2) = 4;
    p->x_pos.val = x;
    set_animation(arg0, 0xD);
    t = arg0->unk2;
    if (t == 8) {
        if (p->unk2 != 0) {
            g_playthrough_state.unk5F |= 0x20;
            func_8003C4EC(p);
        }
    } else {
        u8* e = (u8*)&g_playthrough_state;
        e[0x69] |= capsule_parts[t];
    }
    g_playthrough_state.unk16 = 0;
    g_playthrough_state.unk12 = 0;
    g_playthrough_state.unk13 = 0;
    g_playthrough_state.unk17 = 0;
    arg0->unk5++;
}
