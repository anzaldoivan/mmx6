#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800660B8(M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];

void func_800FA220(u8* arg0) {
    background_objects[2].unk3 = 1;
    background_objects[2].x_pos.val = 0;
    background_objects[2].unk4C = 1;
    *(s16*)(arg0 + 4) = 0;
    func_80016C48(0, 1, 0);
    ((void (*)(M2C_UNK))func_800660B8)(1);
    arg0[1]++;
}
