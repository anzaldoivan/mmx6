#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "psyq/libgpu.h"

void func_8001494C(void);
M2C_UNK func_80014F70(M2C_UNK, M2C_UNK, M2C_UNK);
void wait_for_file_load(s32, s32);
void pump_file_loads(void);
void read_dat_file();
void read_rock_bin_member(s32, s32);
void func_80017CD8(void);
s32 get_player_mugshot(void);

extern s32 D_80010000;
extern u16 D_8006D9FC[][2];
extern u16 D_8006DA58[];
extern u16 D_8006DA5C[];
extern u16 D_8006DA6C[];
extern u16 D_8006DA88[][2];
extern u16 D_8006DAB4;
extern u16 D_8006DABE;
extern u16 D_8006DAE4[][2];
extern u16 D_8006DB10;
extern u16 D_8006DB1A;
extern u16 D_8006DB40[];
extern u16 D_8006DB50[];
extern u16 D_8006DB78[][2];
extern u16 D_8006DBD4[][2];
extern u16 D_8006DC30[][2];
extern u16 D_8006DC50[];
extern s32 D_8006DC6C[][2];
extern s32 D_8006DD24[][2];
extern s32 D_8006DDDC[][2];
extern s32 D_8006DE94[][2];
extern s32 D_8006DF4C[][2];
extern s32 D_8006E004[][2];
extern s32 D_8006E0BC[][2];
extern s8 D_8006E174[][2];
extern u16 D_8006E1A4[];
extern u8 D_80076398[];
extern u16 g_tilemap_layer_stride;
#define D_80097420_6 (D_80097420.transition.suspended)
extern u16* D_800A21B0;
extern M2C_UNK* D_800B91B8;
extern u8 D_800C4560;
extern struct X4_EngineObj g_playthrough_state;
#define ENG_38 (e->player_initial_data[0x38 - 0x49])
#define ENG_43B (e->pad61[0x43B - 0x61])
extern u8 g_tilemap_width;
extern u8 g_tilemap_height;
extern u8 D_800EA548[];

#define SCR_08 (*(u16**)0x1F800008)
#define SCR_0C (*(s32*)0x1F80000C)
#define SCR_80 ((s32*)0x1F800080)
#define SCR_A8 (*(s32*)0x1F8000A8)

M2C_UNK func_80013DE8(void) {
    struct X4_EngineObj* e = &g_playthrough_state;
    s16 rect[4];
    u16* src;
    u16* dst;
    s32 n;
    s32 idx;
    s32 addr;
    s32 i;

    if (e->stage == 0xB) {
        read_rock_bin_member(D_8006DC50[e->checkpoint], 0x800FA000);
        func_8001494C();
    }
    read_rock_bin_member(D_8006DB78[e->stage][e->substage], D_80010000);
    func_8001494C();
    SCR_80[0] = D_8006DC6C[e->stage][e->substage];
    SCR_80[1] = D_8006DD24[e->stage][e->substage];
    SCR_80[2] = D_8006DDDC[e->stage][e->substage];
    SCR_80[3] = D_8006DE94[e->stage][e->substage];
    SCR_80[4] = D_8006E004[e->stage][e->substage];
    SCR_80[5] = D_8006DF4C[e->stage][e->substage];
    SCR_80[6] = D_8006E0BC[e->stage][e->substage];
    D_8006D9FC[15][0] = D_8006DA58[ENG_38];
    if (e->stage == 0xD && e->substage != 0) {
        D_8006D9FC[13][1] = D_8006DA5C[e->unk36.timer - 1];
        D_8006DABE = D_8006DB40[e->unk36.timer - 1];
        D_8006DB1A = D_8006DB40[e->unk36.timer - 1];
    }
    if (e->stage == 0xB) {
        D_8006D9FC[11][0] = D_8006DA6C[e->checkpoint];
        D_8006DB10 = D_8006DAB4 = D_8006DB50[e->checkpoint];
    }
    if ((e->stage >= 0xD && e->stage < 0x10) || e->stage == 0xB) {
        func_80014F70(D_8006D9FC[e->stage][e->substage], 0, 0);
    } else {
        func_80014F70(D_8006D9FC[e->stage][e->substage], 3, 0);
    }
    wait_for_file_load(0, 0);
    if (ENG_38 == 0) {
        func_80014F70(D_8006DA88[e->stage][e->substage], 1, 0);
    } else {
        func_80014F70(D_8006DAE4[e->stage][e->substage], 1, 0);
    }
    if (e->stage >= 0x13) {
        D_8006DBD4[e->stage][ENG_38] =
            D_8006DC30[(e->stage - 0x13) * 2 + e->substage][ENG_38];
    }
    if (D_8006DBD4[e->stage][ENG_38] != 0) {
        wait_for_file_load(0, 0);
        func_80014F70(D_8006DBD4[e->stage][ENG_38], 1, 0);
        wait_for_file_load(0, 1);
    } else {
        wait_for_file_load(0, 1);
    }
    src = SCR_08;
    D_800A21B0 = (u16*)D_800B91B8;
    dst = (u16*)D_800B91B8;
    n = ((u32)SCR_0C - (u32)src) >> 1;
    while (n > 0) {
        *dst++ = *src++;
        n--;
    }
    D_800B91B8 = (M2C_UNK*)dst;
    if (e->stage == 0xB) {
        g_tilemap_width = D_800EA548[e->checkpoint * 2];
        g_tilemap_height = D_800EA548[e->checkpoint * 2 + 1];
    } else {
        n = e->stage * 4 + e->substage * 2;
        g_tilemap_width = D_80076398[n];
        g_tilemap_height = D_80076398[n + 1];
    }
    g_tilemap_layer_stride = g_tilemap_width * g_tilemap_height;
    func_80017CD8();
    D_800C4560 |= 1;
    if (D_80097420_6 == 0 && D_8006E174[e->stage][e->substage] != 0) {
        idx = get_player_mugshot();
        addr = 0x801F6000;
        read_dat_file(idx * 2 + 0xA3, 0x801F6000);
        pump_file_loads();
        rect[0] = 0x180;
        rect[1] = 0;
        rect[2] = 0x40;
        rect[3] = 0x10;
        for (i = 0; i < 4; i++) {
            LoadImage((struct RECT*)rect, (unsigned long*)addr);
            addr += 0x800;
            rect[0] += 0x40;
        }
        read_dat_file(idx * 2 + 0xA4, SCR_A8);
        pump_file_loads();
        if (e->stage >= 0x13) {
            if (ENG_43B == 0) {
                D_8006E1A4[e->stage] = 0xC1;
            } else if (ENG_43B == 1) {
                D_8006E1A4[e->stage] = 0xC5;
            } else {
                D_8006E1A4[e->stage] = 0xC3;
            }
        }
        idx = D_8006E1A4[e->stage] & 0xFF;
        if (idx != 0) {
            read_dat_file(idx, 0x801F6000);
            pump_file_loads();
            read_dat_file(idx + 1, SCR_A8 + 0x400);
            pump_file_loads();
        }
    }
    D_800B91B8 = (M2C_UNK*)dst;
}
#undef ENG_38
#undef ENG_43B
#undef D_80097420_6
