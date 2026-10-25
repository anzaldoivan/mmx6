#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002C9B0();
M2C_UNK func_80030ECC(void*, s16);
#define func_80030ECC ((M2C_UNK(*)())func_80030ECC)
extern s16 D_800970AA;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj D_800CCED0;

void func_800EC9B4(u8* self) {
    *(s16*)(self + 0xE) =
        *(s16*)(self + 0x86) +
        (background_objects[0].y_pos.i.hi - background_objects[1].y_pos.i.hi);
    if (D_800CCED0.stage == 4) {
        if (D_800CCED0.substage == 0) {
            if (*(s8*)(self + 2) == 0) {
                if (D_800CCED0.checkpoint <= 0) {
                    return;
                }
            } else if (D_800CCED0.checkpoint < 2) {
                return;
            }
        } else {
            if (*(s8*)(self + 2) == 0x70 && (self[0x72] & 4)) {
                func_80030ECC(self);
            }
            if (D_800970AA < 0x1180 && D_800CCED0.checkpoint <= 0) {
                return;
            }
        }
        func_8002C9B0(self);
    } else if (D_800CCED0.stage >= 0x13 && D_800CCED0.checkpoint > 0) {
        func_8002C9B0(self);
    }
}
#undef func_80030ECC
