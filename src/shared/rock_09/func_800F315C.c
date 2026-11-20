// rolefeed (3.1 T4): func_800F315C of src/rock_09/E9860.c

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
M2C_UNK func_80040488(M2C_UNK);
void func_800F0434(s8* self, u32 arg1);

void func_800F315C(void* arg0) {
    if (++M2C_FIELD(arg0, s16*, 0x7C) == 0xD) {
        play_sound(2, 0x39, arg0);
        func_80029478(0x3C, 2, 2);
        start_pad_vibration(5);
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        func_800F0434(arg0, 0xA);
        func_80040488(0);
        D_800CCEF4 = 1;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x3C;
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
    animate_object(arg0);
    apply_object_motion(arg0);
    func_8002CCB0(arg0, 0x80, 0x80);
}
