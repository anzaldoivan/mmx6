#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80025F34();
s32 func_800280F4();
void func_80029B8C(void);
M2C_UNK func_8002B838();
void func_8002C2B8();
extern struct X4_PlayerObj g_Player;
extern struct X4_EngineObj D_800CCED0;
extern u8 D_800E3140;
extern u8 D_800E3141;
extern u8 D_800F366C[];

void func_800EEA1C(u8* arg0) {
    struct X4_EngineObj* e = &D_800CCED0;
    u8 a = D_800E3141;
    u8 b = D_800E3140;

    e->character_state.bytes[0] = a;
    e->character_state.bytes[1] = b;
    *(u8*)(D_800F366C + 0x128A) = *(u8*)&e->unk38;
    do {
        func_8002B838(arg0, a, b);
    } while (0);
    func_8002C2B8();
    func_80029B8C();
    func_800280F4();
    func_80025F34();
    e->character_state.bytes[2] = 0;
    {
        struct X4_PlayerObj* pl = &g_Player;
        ((u8*)pl)[0xC9] = arg0[0x60];
        pl->unk2 = *(u8*)(D_800F366C + 0x128A);
    }
    arg0[2]++;
}
