#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80025F34();
void func_800280F4(void);
void func_80029B8C(void);
s32 func_8002B2F8(s32);
M2C_UNK func_8002B838();
void func_8002C2B8();
struct X4_QuadObj* func_8002C7F0(void);
void func_800E9ED4(void);
extern s8 D_80090D56;
extern s8 D_800970A2;
extern struct X4_BackgroundObj D_800971F8[3];
extern s8 D_8009742C;
extern struct X4_EngineObj D_800CCED0;
extern s8 D_800CF850;
extern u8 D_800EA510[];
extern u8 D_800FA7C8[];
extern u8 func_800FA7C4[];

void func_800FA004(u8* arg0) {
    struct X4_QuadObj* q;
    s32 i;

    func_8002B838();
    func_8002C2B8();
    func_80029B8C();
    func_800280F4();
    func_80025F34();
    D_800970A2 = 1;
    D_80090D56 = 0;
    D_8009742C = 0;
    D_800CF850 = 0;
    func_8002B2F8(0);
    D_800971F8[0].unk3 = 0;
    D_800971F8[1].unk3 = 1;
    if ((s8)(s32)D_800CCED0.unk38 != 0) {
        D_800971F8[1].y_pos.i.hi = 0x100;
        D_800971F8[0].y_pos.i.hi = 0x100;
    }
    D_800971F8[1].x_pos.i.hi = 0x120;
    D_800971F8[1].unk4C = 1;
    D_800971F8[1].unk3 = 1;
    D_800971F8[0].x_pos.i.hi = 0;
    D_800971F8[0].unk4C = 1;
    D_800971F8[0].unk3 = 1;
    q = func_8002C7F0();
    if (q != 0) {
        q->active = 1;
        q->id = 0xA;
        q->unk36 = 0x11;
        q->unk2 = 1;
    }
    arg0[1]++;
    for (i = 0; i < 4; i++) {
        if ((s8)(s32)D_800CCED0.unk38 == 0) {
            D_800EA510[i] = func_800FA7C4[i];
        } else {
            D_800EA510[i] = D_800FA7C8[i];
        }
    }
    func_800E9ED4();
}
