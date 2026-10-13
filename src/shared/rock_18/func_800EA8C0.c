#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80013300(M2C_UNK, M2C_UNK*);
M2C_UNK func_800133A0();
void func_8001BA1C(u8* arg0);
M2C_UNK func_8002B838();
extern s32 D_8001E6E4;
extern s32 D_80070CC4[];
extern struct X4_BackgroundObj D_800971F8[3];
extern s8 D_80097424;
extern struct X4_EngineObj D_800CCED0;

#define ENG(o) (((u8*)&D_800CCED0)[o])

void func_800EA8C0(u8* arg0) {
    if (D_80097424 == 0) {
        switch (*(s16*)(arg0 + 0xA)) {
        case 0:
            func_8001BA1C((u8*)D_80070CC4);
            {
                struct X4_EngineObj* e = &D_800CCED0;
                u8 v = ((u8*)e)[0x158];
                if (v == 0xFF) {
                    D_800CCED0.state = 3;
                    e->unk1 = 0;
                    e->unk2 = 0;
                    e->unk3 = 0;
                } else {
                    D_800CCED0.state = 0x13;
                    e->unk1 = 0;
                    e->unk2 = 0;
                    e->unk3 = 0;
                    e->checkpoint = v;
                }
            }
            func_80013300(1, &D_8001E6E4);
            func_800133A0();
            return;
        case 1:
            func_8002B838();
            arg0[1] = 5;
            D_800CCED0.unk1 = 0;
            D_800CCED0.unk2 = 0;
            D_800CCED0.unk3 = 0;
            return;
        case 2:
        default:
            D_800971F8[0].x_pos.i.hi = 0;
            D_800971F8[0].y_pos.i.hi = 0;
            D_800971F8[0].unk4C = 1;
            D_800971F8[0].unk3 = 1;
            arg0[0] = 6;
            arg0[1] = 0;
            arg0[2] = 0;
            arg0[3] = 0;
            break;
        }
    }
}
