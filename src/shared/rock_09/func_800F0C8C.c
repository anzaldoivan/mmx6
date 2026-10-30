#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
void func_800F0434(s8* self, u32 arg1);
extern s32 D_800F651C;
extern s16 D_800F6BEA;
extern s16 D_800F6BF0;

#define F(T, p, o) (*(T*)((u8*)(p) + (o)))

void func_800F0C8C(void* arg0) {
    s16 t;

    if (F(void*, arg0, 0x68) == 0) {
        if (F(s16, arg0, 0xE) >= (D_800F6BEA + D_800F6BF0) / 2) {
            F(void*, arg0, 0x68) = &D_800F651C;
        }
    }
    if ((F(u8, arg0, 0x70) & 8) && F(u8, arg0, 0x47) == 0x11) {
        func_800F0434(arg0, 4);
        F(s32, arg0, 0x24) = 0;
        F(u16, arg0, 0x7C) = 0;
        F(u8, arg0, 6)++;
    } else {
        t = ++F(s16, arg0, 0x7C);
        if ((s16)(t % 20) == 0) {
            play_sound(2, 0x38, arg0);
        }
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x80, 0x80);
}
