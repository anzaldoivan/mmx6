#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
M2C_UNK move_object(void*);
void set_velocity_from_angle(void*, s32);
extern u32* D_8007789C[];
extern s8 D_80077B20[];
extern struct X4_PlayerObj g_Player;

#define SCRATCH_1C (*(u8**)0x1F80001C)
#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))
#define FP(p, o) (*(void**)((u8*)(p) + (o)))

void func_80047E34(u8* arg0) {
    s32 vx;
    s32 vy;
    s32 anim;
    s8* tbl;
    u8* sp;
    s32 off;
    struct X4_PlayerObj* pl = &g_Player;

    F8(arg0, 3) = 1;
    U8(arg0, 0x14) = U8(pl, 0x14);
    F32(arg0, 0x38) = 0;
    sp = SCRATCH_1C;
    off = *(s32*)(sp + 4);
    FP(arg0, 0x30) = D_8007789C;
    F16(arg0, 0x40) = 0;
    F16(arg0, 0x42) = 0x7802;
    F8(arg0, 0x16) = 0x10;
    F8(arg0, 0x15) = 0;
    FP(arg0, 0x3C) = sp + off;
    F32(arg0, 8) = F32(pl, 8);
    F32(arg0, 0xC) = F32(pl, 0xC);
    set_velocity_from_angle(arg0, U8(arg0, 2) & 0x7F);
    vx = F32(arg0, 0x20);
    vy = F32(arg0, 0x24);
    anim = 7;
    if (F8(arg0, 2) & 0x80) {
        F32(arg0, 0x20) = vx * 8;
        F32(arg0, 0x24) = vy * 8;
    } else {
        s32 h;
        s32 m;
        h = vx / 2;
        m = D_80077B20[U8(arg0, 2) & 3];
        F32(arg0, 0x20) = vx + h * m;
        anim = 6;
        F32(arg0, 0x24) = vy + (vy / 2) * D_80077B20[U8(arg0, 2) & 3];
    }
    set_animation(arg0, anim);
    move_object(arg0);
    U8(arg0, 4) = U8(arg0, 4) + 1;
    func_8002CCB0(arg0, 0x80000, 0x80000);
}
