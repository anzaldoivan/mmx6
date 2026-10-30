#include "common.h"
#include "mmx6/x4.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

void* alloc_sprite_slot();
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800F1CB0[];

void func_800ECCB4(void* arg0) {
    u8 i;
    u8 v;
    s8* o;

    i = D_800F1CB0[1];
    g_playthrough_state.character_state.bytes[11] = 0;
    g_playthrough_state.character_state.bytes[12] = 0;
    g_playthrough_state.character_state.bytes[10] = i;
    v = D_800F1CB0[(s8)i];
    g_playthrough_state.character_state.bytes[2] = v;
    do {
        o = alloc_sprite_slot(arg0, &g_playthrough_state, v, i);
    } while (0);
    if (o != 0) {
        o[0] = 1;
        o[1] = 0x2B;
        o[2] = 0;
    }
    o = alloc_sprite_slot(o);
    if (o != 0) {
        o[0] = 1;
        o[1] = 0x2B;
        o[2] = 1;
    }
    o = alloc_sprite_slot(o);
    if (o != 0) {
        o[0] = 1;
        o[1] = 0x2B;
        o[2] = 2;
    }
    FX(arg0, u8, 2)++;
}
