#include "common.h"
#include "psyq/libcard.h"
#include "psyq/libetc.h"
#include "psyq/libgpu.h"
#include "psyq/libgte.h"
#include "psyq/libpad.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

void func_80012FA0(void* arg0);
void func_80013008(void);
void func_80013128(void);
M2C_UNK create_task(M2C_UNK, M2C_UNK*);
void load_rock_dat_file_table(void);
void func_800163A4(void);
void load_rock_bin_file_table(void);
void func_80016950(void);
void func_8001C024(void);
void func_800698C4(void);
#include "psyq/libapi.h"
void func_8001CB3C(void);

extern X4_RECT D_8006D87C;

#define SCRATCH0 (*(s32*)0x1F800000)

// 0x80012658 init_system: resets callbacks, starts GPU, GTE, memory card and pads, sets both draw buffers, loads the rock file tables and creates the first task.
// basis: xref load_rock_dat_file_table (docs/leads/derived.tsv:5)
// callers: func_800120A0
void init_system(void) {
    s16 r[4];
    s16 t[4];
    u8* p;
    void* a;
    void* b;

    g_wide_mode = 0;
    g_screen_width = 0x140;
    ResetCallback();
    StopCallback();
    ResetGraph(0);
    InitGeom();
    SetGeomOffset(g_screen_width >> 1, 0x78);
    SetGeomScreen(0x200);
    InitCARD(0);
    StartCARD();
    p = D_800C458C;
    a = p - 0x14;
    func_800698C4();
    func_8001C024();
    PadInitDirect(D_800CF920, D_800CF870);
    PadStartCom();
    func_80016950();
    func_800163A4();
    ChangeClearPAD(0);
    ClearImage(&D_8006D87C, 0, 0, 0);
    DrawSync(0);
    SetDefDrawEnv(p, 0, 0, g_screen_width, 0xF0);
    SetDefDispEnv(a, 0, 0xF0, g_screen_width, 0xF0);
    SetDefDrawEnv(p + 0xF0, 0, 0xF0, g_screen_width, 0xF0);
    b = p + 0xDC;
    SetDefDispEnv(b, 0, 0, g_screen_width, 0xF0);
    r[0] = 0;
    r[1] = 0;
    r[3] = 0xF0;
    r[2] = g_screen_width;
    SetDrawArea(D_800CF948, r);
    r[0] = 0;
    r[1] = 0xF0;
    r[3] = 0xF0;
    r[2] = g_screen_width;
    SetDrawArea(D_800CF948 + 0xC, r);
    t[0] = 0;
    t[1] = 0;
    t[2] = 0;
    t[3] = 0xF0;
    SetDrawOffset(D_800CF908, &t[0]);
    SetDrawOffset(D_800CF908 + 0xC, &t[2]);
    func_80012FA0(a);
    func_80012FA0(b);
    func_80013128();
    g_cur_draw_info = a;
    SCRATCH0 = 0;
    D_80090E70 = 0xD37;
    load_rock_dat_file_table();
    load_rock_bin_file_table();
    func_80013008();
    D_8008EC0C = 0;
    D_8009741A = 0x3C;
    create_task(0, (M2C_UNK*)func_8001CB3C);
}
