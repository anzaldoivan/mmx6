#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK animate_object();
s32 func_80040498();
extern struct X4_BackgroundObj background_objects[3];
extern s16 D_800F6AF8;

void func_800F2C74(struct X4_MainObj* arg0) {
    animate_object(arg0);
    if (func_80040498() == 0) {
        arg0->unk7E = 3;
        background_objects[0].unk26 = D_800F6AF8 + 0x640;
        background_objects[0].unk24 = D_800F6AF8 + 0x680;
        arg0->action_phase++;
    }
}
