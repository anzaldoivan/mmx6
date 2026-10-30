#include "common.h"
#define M2C_UNK s32
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800F0434(s8* self, u32 arg1);
extern s16 D_800970AA;

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define FS8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))

void func_800F3DF0(void* arg0) {
    if (D_800970AA > F16(arg0, 0xA)) {
        F8(arg0, 0x15) = 0x40;
    } else {
        F8(arg0, 0x15) = 0;
    }
    if (FS8(arg0, 0x46) == 0) {
        play_sound(2, 0x3E, arg0);
        func_800F0434(arg0, 0x1E);
        F16(arg0, 0x7C) = 0;
    }
    if (++F16(arg0, 0x7C) == 0x3C) {
        F16(arg0, 0x7E) = 0;
        F8(arg0, 6) = 3;
    }
}
#undef F8
#undef FS8
#undef F16
