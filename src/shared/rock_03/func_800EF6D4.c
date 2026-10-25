#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
s32 func_8002CBFC(s32, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object(s32);
extern struct X4_BackgroundObj background_objects[3];

void func_800EF6D4(void* arg0) {
    func_80017A04();
    ((void (*)(s32))move_object)((s32)arg0);
    if (M2C_FIELD(arg0, s16*, 0xA) >= background_objects[0].x_pos.i.hi - 0x10 &&
        background_objects[0].y_pos.i.hi + 0x100 >=
            M2C_FIELD(arg0, s16*, 0xE) &&
        func_8002CBFC(arg0, 0x150, 0x30) == 0) {
        func_8002CCB0(arg0, 0x20, 0x20);
        return;
    }
    M2C_FIELD(arg0, s8*, 4) = 2;
}
