#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139A0(s8);
void func_80025F34();
void func_800280F4(void);
void func_80029B8C(void);
s32 func_8002B2F8(s32);
M2C_UNK func_8002B838();
void func_8002C2B8();
struct X4_QuadObj* func_8002C7F0(void);
extern s8 D_80090D56;
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_8009742C;
extern s8 D_800CCF08;
extern s8 D_800CF850;
extern u8 D_800EA510[];
extern u8 D_800FA930[];
extern u8 func_800FA92C[];

void func_800FA0E8(u8* arg0) {
    struct X4_QuadObj* q;
    s32 i;
    s32 ta;
    s32 tb;
    u8* dst;

    func_8002B838();
    func_8002C2B8();
    func_80029B8C();
    func_800280F4();
    func_80025F34();
    D_80090D56 = 0;
    D_8009742C = 0;
    D_800CF850 = 0;
    ((void (*)(s32))func_8002B2F8)(0);
    background_objects[0].unk3 = 0;
    background_objects[1].unk3 = 0;
    q = func_8002C7F0();
    if (q != 0) {
        q->active = 1;
        q->id = 0xA;
        q->unk36 = 0x11;
        q->unk2 = 1;
    }
    func_800139A0(8);
    i = 0;
    ta = (s32)func_800FA92C;
    tb = (s32)D_800FA930;
    dst = D_800EA510;
    arg0[1]++;
    do {
        if (D_800CCF08 == 0) {
            *dst = *(u8*)(i + ta);
        } else {
            *dst = *(u8*)(i + tb);
        }
        i++;
        dst++;
    } while (i < 4);
}
