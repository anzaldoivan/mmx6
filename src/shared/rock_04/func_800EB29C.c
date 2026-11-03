#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();
s32 is_off_screen(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion();
M2C_UNK func_80030ECC(void*);

void func_800EB29C(void* self) {
    if (M2C_FIELD(M2C_FIELD(self, void**, 0x7C), s8*, 4) != 2) {
        M2C_FIELD(self, u8*, 6)++;
        switch (M2C_FIELD(self, s8*, 5)) {
        case 0:
            if (M2C_FIELD(self, s8*, 0x46) != 0) {
                break;
            }
            ((void (*)(void*, s32))set_animation)(
                self, M2C_FIELD(self, u8*, 0x17) + 1);
            M2C_FIELD(self, u8*, 5)++;
            break;
        case 1:
            func_80030ECC(self);
            if (M2C_FIELD(self, s8*, 6) != 0x5A) {
                break;
            }
            ((void (*)(void*, s32))set_animation)(
                self, M2C_FIELD(self, u8*, 0x17) + 1);
            M2C_FIELD(self, u8*, 5)++;
            break;
        case 2:
            if (M2C_FIELD(self, s8*, 0x46) == 0) {
                M2C_FIELD(self, u8*, 4)++;
                return;
            }
            break;
        }
        animate_object(self);
        apply_object_motion(self);
        if (is_off_screen(self, 0x20, 0x20) == 0) {
            func_8002CCB0(self, 0x20, 0x20);
            return;
        }
    }
    M2C_FIELD(self, u8*, 4)++;
}
