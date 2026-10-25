#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80025F34();
void func_800280F4(void);
void func_80029B8C(void);
s32 func_8002B2F8(s32);
M2C_UNK func_8002B838();
void func_8002C2B8();
M2C_UNK func_800660B8(M2C_UNK);
void func_800E9ED4(void);
extern s32 D_80090C90[];
extern s8 D_80090D56;
extern s16 D_80090D5C;
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_8009742C;
extern s16 D_80097430;
extern s8 D_800CF850;
extern s16 D_800CF854;
extern u8 D_800EA510[];
extern u8 func_800FA5F4[];

void func_800FA004(u8* arg0) {
    s32 i;

    func_8002B838();
    func_8002C2B8();
    func_80029B8C();
    func_800280F4();
    func_80025F34();
    func_8002B2F8(0);
    background_objects[0].unk3 = 0;
    background_objects[1].unk3 = 0;
    background_objects[2].unk3 = 0;
    func_800660B8(1);
    D_8009742C = 0;
    D_80090D56 = 0;
    D_800CF850 = 0;
    D_80090C90[0] = 0;
    D_80090C90[1] = -1;
    D_80090C90[2] = -1;
    D_80090C90[3] = -1;
    D_80090C90[4] = -1;
    D_80090C90[5] = -1;
    D_80090C90[6] = -1;
    D_80090C90[7] = -1;
    D_80090C90[8] = -1;
    D_80090C90[9] = -1;
    D_800CF854 = 0x1F;
    D_80097430 = 0x3E0;
    D_80090D5C = 0x7C00;
    arg0[1]++;
    for (i = 0; i < 4; i++) {
        D_800EA510[i] = func_800FA5F4[i];
    }
    func_800E9ED4();
}
