#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
M2C_UNK func_80030ECC(void*);

void func_800EBE60(void* arg0) {
    switch (M2C_FIELD(M2C_FIELD(arg0, void**, 0x80), s8*, 0x7)) {
    case 3:
        if (M2C_FIELD(arg0, u8*, 0x17) != 6) {
            set_animation(arg0, 6);
        }
        break;
    case 2:
        if (M2C_FIELD(arg0, u8*, 0x17) != 7) {
            set_animation(arg0, 7);
        }
        break;
    case 1:
        if (M2C_FIELD(arg0, u8*, 0x17) != 8) {
            set_animation(arg0, 8);
        }
        break;
    case 0:
        M2C_FIELD(arg0, u8*, 0x4) = 2;
        return;
    }
    func_80030ECC(arg0);
    if (is_off_screen(arg0, 0x30, 0x40) == 0) {
        func_8002CCB0(arg0, 0x30, 0x40);
    }
    apply_object_motion(arg0);
    animate_object(arg0);
}
