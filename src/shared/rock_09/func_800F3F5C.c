#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800F0434(s8* self, u32 arg1);
extern s16 D_800970AA;

#define F(T, p, o) (*(T*)((u8*)(p) + (o)))

void func_800F3F5C(void* arg0) {
    if (F(u8, arg0, 0x47) == 0) {
        if (D_800970AA > F(s16, arg0, 0xA)) {
            F(u8, arg0, 0x15) = 0x40;
        } else {
            F(u8, arg0, 0x15) = 0;
        }
        play_sound(2, 0x14, arg0);
        func_800F0434(arg0, 0x1D);
        play_sound(2, 0x40, arg0);
        F(u8, arg0, 6) = 7;
    }
}
