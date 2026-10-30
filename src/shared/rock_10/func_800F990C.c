#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
M2C_UNK func_8002F288(void*);

void func_800F990C(void* arg0) {
    s32 v;
    s32 t;

    func_8002D230(arg0);
    v = M2C_FIELD(arg0, s32*, 0x20);
    if ((v < 0 ? -v : v) <= 0x40000) {
        M2C_FIELD(arg0, s32*, 0x28) = 0;
    }
    func_8002F288(arg0);
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        t = M2C_FIELD(arg0, u8*, 0x70) & 1;
    } else {
        t = M2C_FIELD(arg0, u8*, 0x70) & 2;
    }
    if (t != 0) {
        play_sound(2, 0x55, arg0);
        func_80012D9C(6);
        func_80029478(0xA, 4, 2);
        M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
