#include "common.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_8001447C(void);
void func_80017488(void);
void func_8001CBE0(void);
M2C_UNK func_80013DE8();
void func_8001344C();
void func_8001D0E4(void);
extern s32 D_8008EC0C;
extern struct X4_EngineObj g_playthrough_state;
extern M2C_UNK D_800CD3F8;

void func_8001CB3C(void) {
    s8* p;
    s32 i;
    s32 z;

    SetDispMask(0);
    func_8001447C();
    func_80017488();
    func_8001CBE0();
    z = 0;
    p = (s8*)&D_800CD3F8;
    i = 15;
    do {
        *p++ = z;
    } while (i-- != 0);
    D_8008EC0C = 0;
    g_playthrough_state.stage = 0xE;
    g_playthrough_state.substage = 0;
    func_80013DE8();
    M2C_FIELD(&D_800CD3F8, s8*, 0) = 0;
    M2C_FIELD(&D_800CD3F8, s8*, 1) = 0;
    M2C_FIELD(&D_800CD3F8, s8*, 2) = 0;
    M2C_FIELD(&D_800CD3F8, s8*, 3) = 0;
    func_8001344C(func_8001D0E4);
}
