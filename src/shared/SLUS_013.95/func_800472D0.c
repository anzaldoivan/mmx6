#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj D_800CCED0;

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800472D0(struct X4_MainObj* arg0) {
    s16 var_v0;
    s16 var_v0_3;

    F32(arg0, 0x1C) = 0;
    F32(arg0, 0x18) = 0x20000;
    if (D_800CCED0.stage >= 0x13) {
        var_v0 = 0x10;
        // !FAKE: shared store block placed between the two tests, as retail orders it
        goto block_4;
    }
    if (D_800CCED0.stage == 4) {
        var_v0 = 8;
    block_4:
        F16(arg0, 0x16) = var_v0;
        F16(arg0, 0x14) = 0;
        F8(arg0, 5) = 0;
    } else {
        background_objects[1].unk4 = 9;
        background_objects[1].unk4C = 1;
        if (F8(&D_800CCED0, 0x68) >= 2U) {
            F32(arg0, 0x18) = 0xFFFEC000;
        } else {
            F32(arg0, 0x18) = 0xFFFF0000;
        }
        var_v0_3 = 0x32;
        if (D_800CCED0.checkpoint == 0) {
            var_v0_3 = 0x78;
        }
        F16(arg0, 0x14) = var_v0_3;
        F8(arg0, 5) = 1;
        F16(arg0, 0x16) = 0;
    }
    F8(arg0, 4) = F8(arg0, 4) + 1;
}
