#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
extern u16 D_8006D9DC[];
extern u16 D_8006D9EC[];
extern s32 D_80097760;
extern M2C_UNK* D_800B91B8;
extern u8 D_800CC868;
#define SCRATCH30 (*(s32*)0x1F800030)

void func_8001494C(void);
M2C_UNK func_80014F70(M2C_UNK, M2C_UNK, M2C_UNK);
void func_80015EC0(s32, s32);
void read_rock_bin_member(s32, s32);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);

void func_80013D10(void) {
    M2C_UNK* saved = D_800B91B8;

    read_rock_bin_member(D_8006D9EC[g_playthrough_state.checkpoint - 2],
                         0x800FA000);
    func_8001494C();
    func_80014F70(D_8006D9DC[g_playthrough_state.checkpoint - 2], 4,
                  D_80097760);
    func_80015EC0(0, 1);
    load_palette(
        0x58,
        (M2C_UNK*)(SCRATCH30 + ((g_playthrough_state.checkpoint - 2) << 8)), 8);
    D_800B91B8 = saved;
    D_800CC868 = g_playthrough_state.checkpoint;
}
#undef SCRATCH30
