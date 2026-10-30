#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

s32 play_sound(s32 a0, s32 a1, void* arg2);
M2C_UNK set_animation(void*, M2C_UNK);
#define set_animation ((void (*)(void*, s32))set_animation)
s8* func_8002BEC4(s8* p, s32 dir);
extern s32 D_8007610C;
extern s32 D_80076110;
extern s32 D_80076114;

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F_U16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F_S32(p, o) (*(s32*)((u8*)(p) + (o)))
#define F_PTR(p, o) (*(void**)((u8*)(p) + (o)))

void func_80043B90(s8* arg0, s16 arg1) {
    u8* parent;
    s8* child;
    u8 flags;

    parent = F_PTR(arg0, 0x7C);
    flags = parent[0x93];
    if (!(flags & 1)) {
        return;
    }
    if ((s8)flags == 1) {
        if (F_U8(arg0, 0x8E) != 0) {
            return;
        }
        if (*(s8*)(arg0[2] + (s32)parent + 0x8F) > 0) {
            return;
        }
    }
    child = func_8002BEC4(arg0, 0);
    if (child == 0) {
        return;
    }
    play_sound(1, 0x13, arg0);
    parent[0x8C]++;
    child[0] = 1;
    F_PTR(child, 0x7C) = parent;
    F_S32(child, 0x38) = F_S32(arg0, 0x38);
    F_S32(child, 0x3C) = F_S32(arg0, 0x3C);
    F_S32(child, 0x30) = F_S32(arg0, 0x30);
    F_U16(child, 0x40) = F_U16(arg0, 0x40);
    F_U16(child, 0x42) = F_U16(arg0, 0x42);
    F_U8(child, 0x16) = F_U8(arg0, 0x16);
    F_U16(child, 0xA) = F_U16(arg0, 0xA);
    F_U16(child, 0xE) = F_U16(arg0, 0xE);
    child[4] = 1;
    child[5] = 8;
    F_S32(child, 0x20) = rcos(arg1) * 0x10;
    F_S32(child, 0x24) = -rsin(arg1) * 0x10;
    if (parent[0x93] & 2) {
        child[1] = 0xA;
        child[2] = 7;
        F_PTR(child, 0x50) = &D_80076114;
        F_S32(child, 0x24) *= 8;
        F_S32(child, 0x20) *= 8;
        set_animation(child, 4);
        return;
    }
    child[2] = (u8)arg0[2] + 3;
    F_S32(child, 0x24) *= 6;
    F_PTR(child, 0x50) = &D_8007610C;
    F_PTR(child, 0x68) = &D_80076110;
    child[1] = 0x36;
    F_S32(child, 0x20) *= 6;
    F_U8(arg0, 0x8E) = 6;
    {
        u8* p = (u8*)(arg0[2] + (s32)parent);
        p += 0x8F;
        (*p)++;
    }
    set_animation(child, 3);
}
#undef play_sound
#undef set_animation
