#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002B6B0();
s32 func_8002D654(s8*, u8*);
M2C_UNK func_8003C4EC();
M2C_UNK func_8003CDF0();
M2C_UNK func_8003CE30(void*);
M2C_UNK func_8003F3DC(void*);
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;

void func_800EB298(void* arg0) {
    void* p;
    s32 v;

    p = &g_Player;
    if (func_8002D654(arg0, p) != 0) {
        if (M2C_FIELD(arg0, s8*, 3) != 0) {
            play_sound(1, 1, arg0);
        }
        background_objects[0].unk44 = 0;
        background_objects[1].unk44 = 0;
        background_objects[2].unk44 = 0;
        v = 2;
        g_playthrough_state.unk10 = v;
        g_playthrough_state.unk11 = v;
        g_playthrough_state.unk12 = v;
        g_playthrough_state.unk13 = v;
        g_playthrough_state.unk14 = v;
        g_playthrough_state.unk15 = v;
        g_playthrough_state.unk17 = v;
        g_playthrough_state.unk19 = v;
        M2C_FIELD(arg0, u8*, 0) |= 8;
        M2C_FIELD(arg0, s32*, 0x88) = M2C_FIELD(p, s32*, 0x68);
        M2C_FIELD(p, s32*, 0x68) = 0;
        M2C_FIELD(p, s8*, 5) = 2;
        func_8003F3DC(p);
        func_8003CDF0(p);
        func_8003CE30(p);
        func_8003C4EC(p);
        func_8002B6B0();
        M2C_FIELD(arg0, s16*, 0x80) = 0;
        M2C_FIELD(arg0, s16*, 0x84) = M2C_FIELD(arg0, s16*, 0x82) =
            M2C_FIELD(p, s16*, 0xA);
        M2C_FIELD(arg0, u8*, 7) += 1;
    }
}
