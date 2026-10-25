#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003D330();
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_80097425;
extern s16 D_800FD52A;

void func_800F34A4(void* arg0) {
    if (D_80097425 == 0) {
        func_8003D330();
        background_objects[0].unk24 = 0x1430;
        background_objects[0].unk28 = D_800FD52A;
        M2C_FIELD(arg0, s8*, 0x4) = 3;
        M2C_FIELD(arg0, s8*, 0x5) = 0;
        M2C_FIELD(arg0, s8*, 0x6) = 0;
        M2C_FIELD(arg0, s8*, 0x7) = 0;
    }
}
