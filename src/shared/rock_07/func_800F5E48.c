// rolefeed (3.1 T4): func_800F5E48 of src/rock_07/E9860.c
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/x4.h"

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];

#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
void func_800F6AD0(u8* arg0, u8 arg1);

#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F8(p, o) (*(u8*)((u8*)(p) + (o)))

void func_800F5E48(void* arg0) {
    if (--F16(arg0, 0x7C) == 0) {
        play_sound(2, 0x62, arg0);
        set_animation_frame(arg0, 0x16, 1);
        func_800F6AD0(arg0, 0x30);
        F8(arg0, 6) += 1;
    }
}
