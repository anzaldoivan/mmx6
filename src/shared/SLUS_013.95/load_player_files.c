#include "common.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
#define ENG ((u8*)&g_playthrough_state)
extern M2C_UNK* D_800B91B8;
extern s32 D_8009B798;
extern s32 D_800CD408;
extern s32 D_800C4564;
extern s32 D_8006D9D4;
#define SCRATCH38 (*(M2C_UNK**)0x1F800038)

void func_800146F4(void);
void func_8001494C(void);
M2C_UNK func_80014F70(M2C_UNK, M2C_UNK, M2C_UNK);
void func_80015EC0(s32, s32);
void read_rock_bin_member(s32, s32);
void func_8001731C(void);

// 0x80013BF0 load_player_files: player file selection on loading screen.
// basis: community tweaks-index.tsv:375
// callers: func_8001D460, func_8001E880
M2C_UNK load_player_files(void) {
    {
        u8* e = ENG;
        if (*(s8*)(e + 0x38) == 0) {
            if (e[0x5E] == 1) {
                func_80014F70(0x57, 0, 0);
            } else if (e[0x5E] == 2) {
                func_80014F70(0x58, 0, 0);
            } else if (e[0x5E] == 3) {
                func_80014F70(0x59, 0, 0);
            } else {
                func_80014F70(0x56, 0, 0);
            }
        } else {
            func_80014F70(0x55, 0, 0);
        }
    }
    func_80015EC0(0, 0);
    func_800146F4();
    LoadImage(&D_8006D9D4, SCRATCH38);
    DrawSync(0);
    D_800CD408 = (s32)D_800B91B8;
    D_800C4564 = D_8009B798;
    func_8001731C();
    {
        // !FAKE: depin: dropping it breaks the match (69/72)
        register u8* e asm("$3") = ENG;
        if (*(s8*)(e + 0x38) == 0) {
            read_rock_bin_member(0, 0x801EA000);
        } else {
            read_rock_bin_member(1, 0x801EA000);
        }
    }
    func_8001494C();
}
#undef ENG
#undef SCRATCH38
