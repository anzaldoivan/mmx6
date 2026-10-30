#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80025F34();
void func_800280F4(void);
void init_checkpoint_positions(void);
s32 func_8002B2F8(s32);
M2C_UNK reset_level();
void func_8002C2B8();
struct X4_QuadObj* alloc_class6_slot(void);
void func_800E9ED4(void);
extern s8 D_80090D56;
extern s8 D_800970A2;
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_8009742C;
extern struct X4_EngineObj g_playthrough_state;
extern s8 D_800CF850;
extern u8 D_800EA510[];
extern u8 D_800FA7C8[];
extern u8 func_800FA7C4[];

void func_800FA004(u8* arg0) {
    struct X4_QuadObj* q;
    s32 i;

    reset_level();
    func_8002C2B8();
    init_checkpoint_positions();
    func_800280F4();
    func_80025F34();
    D_800970A2 = 1;
    D_80090D56 = 0;
    D_8009742C = 0;
    D_800CF850 = 0;
    func_8002B2F8(0);
    background_objects[0].unk3 = 0;
    background_objects[1].unk3 = 1;
    if ((s8)(s32)g_playthrough_state.controlled_player != 0) {
        background_objects[1].y_pos.i.hi = 0x100;
        background_objects[0].y_pos.i.hi = 0x100;
    }
    background_objects[1].x_pos.i.hi = 0x120;
    background_objects[1].unk4C = 1;
    background_objects[1].unk3 = 1;
    background_objects[0].x_pos.i.hi = 0;
    background_objects[0].unk4C = 1;
    background_objects[0].unk3 = 1;
    q = alloc_class6_slot();
    if (q != 0) {
        q->active = 1;
        q->id = 0xA;
        q->unk36 = 0x11;
        q->unk2 = 1;
    }
    arg0[1]++;
    for (i = 0; i < 4; i++) {
        if ((s8)(s32)g_playthrough_state.controlled_player == 0) {
            D_800EA510[i] = func_800FA7C4[i];
        } else {
            D_800EA510[i] = D_800FA7C8[i];
        }
    }
    func_800E9ED4();
}
