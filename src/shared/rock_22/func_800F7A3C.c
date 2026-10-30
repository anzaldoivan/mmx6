#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);

#define F(type, off) M2C_FIELD(self, type*, off)

#define HIT()                                                                  \
    {                                                                          \
        F(u8, 6)++;                                                            \
        func_80012D9C(5);                                                      \
        play_sound(0, 4, self);                                                \
        func_8002943C(0x5A, 5, 2);                                             \
    }

void func_800F7A3C(void* self) {
    func_80017A04();
    func_8002D230(self);
    if (F(s32, 0x20) > 0) {
        if (F(s32, 0x20) > 0x40000) {
            F(s32, 0x20) = 0x40000;
        }
        if (F(u8, 0x70) & 1) {
            HIT();
        }
    } else if (F(s32, 0x20) < 0) {
        if (F(s32, 0x20) < -0x40000) {
            F(s32, 0x20) = -0x40000;
        }
        if (F(u8, 0x70) & 2) {
            HIT();
        }
    } else if (F(s32, 0x24) > 0) {
        if (F(s32, 0x24) > 0x40000) {
            F(s32, 0x24) = 0x40000;
        }
        if (F(u8, 0x70) & 4) {
            HIT();
        }
    } else if (F(s32, 0x24) < 0) {
        if (F(s32, 0x24) < -0x40000) {
            F(s32, 0x24) = -0x40000;
        }
        if (F(u8, 0x70) & 8) {
            HIT();
        }
    }
}

#undef F
#undef HIT
