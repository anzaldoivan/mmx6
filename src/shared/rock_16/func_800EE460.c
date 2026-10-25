#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define S8(o) M2C_FIELD(arg0, s8*, o)
#define U8(o) M2C_FIELD(arg0, u8*, o)
#define U16(o) M2C_FIELD(arg0, u16*, o)
#define S16(o) M2C_FIELD(arg0, s16*, o)
#define PTR(o) M2C_FIELD(arg0, void**, o)
#define SCRATCH_PTR (*(u8**)0x1F800020)

M2C_UNK func_800179A4(void*, M2C_UNK);
extern struct X4_EngineObj D_800CCED0;
extern u8 D_800F1284[];
extern u16 D_800F128C[][2];

void func_800EE460(void* arg0) {
    u8* p;
    s8 v;
    // !FAKE: depin: dropping it breaks the match (80/83)
    register u8 t asm("$3");
    u8* q;

    S16(0x40) = 0x1800;
    p = SCRATCH_PTR;
    v = S8(2);
    q = p + *(s32*)(p + 4);
    S16(0x42) = 0x78C3;
    PTR(0x30) = D_800F1284;
    PTR(0x3C) = q;
    if (v == 0) {
        u16(*tb)[2] = D_800F128C;
        struct X4_EngineObj* e = &D_800CCED0;
        U8(0x16) = 0;
        U16(0xA) = tb[e->character_state.bytes[3]][0];
        U16(0xE) = D_800F128C[e->character_state.bytes[3]][1];
        func_800179A4(arg0, e->character_state.bytes[3]);
        t = e->character_state.bytes[3];
        U8(0x5) = 0;
        U8(0x7) = t;
    } else if (v == 1) {
        u16(*tb)[2] = D_800F128C;
        struct X4_EngineObj* e = &D_800CCED0;
        U8(0x16) = 0;
        U16(0xA) = tb[e->character_state.bytes[3]][0] + 0x600;
        U16(0xE) = D_800F128C[e->character_state.bytes[3]][1];
        func_800179A4(arg0, e->character_state.bytes[3]);
        t = e->character_state.bytes[3];
        U8(0x5) = v;
        U8(0x7) = t;
    }
    U8(0x3) = 1;
    U8(0x14) = 1;
    U8(0x4)++;
}
