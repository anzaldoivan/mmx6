#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139A0(s8);
void func_80025F34();
void func_800280F4(void);
void init_checkpoint_positions(void);
s32 func_8002B2F8(s32);
M2C_UNK reset_level();
void func_8002C2B8();
struct X4_QuadObj* alloc_class6_slot(void);
extern s8 D_80090D56;
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_8009742C;
extern s8 D_800CF850;
extern u8 D_800EA510[];
extern u8 func_800FA450[];

void func_800FA0E8(u8* arg0) {
    struct X4_QuadObj* q;
    s32 i;

    reset_level();
    func_8002C2B8();
    init_checkpoint_positions();
    func_800280F4();
    func_80025F34();
    D_80090D56 = 0;
    D_8009742C = 0;
    D_800CF850 = 0;
    ((void (*)(s32))func_8002B2F8)(0);
    background_objects[0].unk3 = 0;
    background_objects[1].unk3 = 0;
    q = alloc_class6_slot();
    if (q != 0) {
        q->active = 1;
        q->id = 0xA;
        q->unk36 = 0x11;
        q->unk2 = 1;
    }
    func_800139A0(8);
    i = 0;
    arg0[1]++;
    do {
        D_800EA510[i] = func_800FA450[i];
        i++;
    } while (i < 4);
}
