#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_800F82C0();
extern struct X4_BackgroundObj background_objects[3];

void func_800F6F40(void* arg0) {
    func_800F82C0();
    ((void (*)(void*))func_80017A04)(arg0);
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0x20000;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        {
            s32 t = background_objects[0].unk1E - 0x140;
            if (M2C_FIELD(arg0, s16*, 0xA) <
                background_objects[0].unk1E +
                    (background_objects[0].unk1C - t) / 2) {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            } else {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            }
        }
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}
