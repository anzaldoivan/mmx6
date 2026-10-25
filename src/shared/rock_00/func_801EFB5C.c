#include "common.h"

void* func_8002C32C();
void set_velocity_from_angle(void*, s32);

#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F_S32(p, o) (*(s32*)((u8*)(p) + (o)))
#define F_PTR(p, o) (*(void**)((u8*)(p) + (o)))

void func_801EFB5C(void* arg0, u8 arg1, u8 arg2) {
    u8* obj;

    obj = func_8002C32C();
    if (obj != 0) {
        obj[0] = 1;
        obj[1] = 0x34;
        obj[2] = arg1;
        F_U8(obj, 0x14) = F_U8(arg0, 0x14);
        F_S32(obj, 0x8) = F_S32(arg0, 0x8);
        F_S32(obj, 0xC) = F_S32(arg0, 0xC);
        F_U8(obj, 0x15) = F_U8(arg0, 0x15);
        F_PTR(obj, 0x7C) = arg0;
        set_velocity_from_angle(obj, arg2);
        F_S32(obj, 0x20) = F_S32(obj, 0x20) * 250 / 100;
        F_S32(obj, 0x24) = F_S32(obj, 0x24) * 250 / 100;
        F_U16(arg0, 0x8A)++;
    }
}
