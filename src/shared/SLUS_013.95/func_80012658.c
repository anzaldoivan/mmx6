#include "common.h"
#include "psyq/libcard.h"
#include "psyq/libetc.h"
#include "psyq/libgpu.h"
#include "psyq/libgte.h"
#include "psyq/libpad.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80012FA0(void* arg0);
void func_80013008(void);
void func_80013128(void);
M2C_UNK func_80013300(M2C_UNK, M2C_UNK*);
void load_rock_dat_file_table(void);
void func_800163A4(void);
void load_rock_bin_file_table(void);
void func_80016950(void);
void func_8001C024(void);
void func_800698C4(void);
void ChangeClearPAD(s32);
void func_8001CB3C(void);

extern X4_RECT D_8006D87C;
extern s32 D_8008EC0C;
extern u16 D_80090D6A;
extern u16 D_80090E70;
extern s16 D_8009741A;
extern u16 D_8009B79C;
extern struct X4_DrawInfo* D_8009B7A0;
extern u8 D_800C458C[];
extern u8 D_800CF870[];
extern u8 D_800CF908[];
extern u8 D_800CF920[];
extern u8 D_800CF948[];

#define SCRATCH0 (*(s32*)0x1F800000)

void func_80012658(void) {
    s16 r[4];
    s16 t[4];
    u8* p;
    void* a;
    void* b;

    D_80090D6A = 0;
    D_8009B79C = 0x140;
    ResetCallback();
    StopCallback();
    ResetGraph(0);
    InitGeom();
    SetGeomOffset(D_8009B79C >> 1, 0x78);
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
    SetDefDrawEnv(p, 0, 0, D_8009B79C, 0xF0);
    SetDefDispEnv(a, 0, 0xF0, D_8009B79C, 0xF0);
    SetDefDrawEnv(p + 0xF0, 0, 0xF0, D_8009B79C, 0xF0);
    b = p + 0xDC;
    SetDefDispEnv(b, 0, 0, D_8009B79C, 0xF0);
    r[0] = 0;
    r[1] = 0;
    r[3] = 0xF0;
    r[2] = D_8009B79C;
    SetDrawArea(D_800CF948, r);
    r[0] = 0;
    r[1] = 0xF0;
    r[3] = 0xF0;
    r[2] = D_8009B79C;
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
    D_8009B7A0 = a;
    SCRATCH0 = 0;
    D_80090E70 = 0xD37;
    load_rock_dat_file_table();
    load_rock_bin_file_table();
    func_80013008();
    D_8008EC0C = 0;
    D_8009741A = 0x3C;
    func_80013300(0, (M2C_UNK*)func_8001CB3C);
}
