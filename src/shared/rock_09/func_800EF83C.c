#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_8002B6B0();
M2C_UNK func_8003C4EC(void*);
M2C_UNK func_8003CDF0(void*);
M2C_UNK func_8003CE30(void*);
M2C_UNK func_8003F3DC(void*);
extern s32 D_800970A0;
extern struct X4_BackgroundObj D_800971F8[3];
extern struct X4_EngineObj D_800CCED0;

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define FU16(p, o) (*(u16*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800EF83C(u8* arg0) {
    struct X4_PlayerObj* p = &D_800970A0;
    u8* q;
    u16 a;
    s32 two;

    if (F8(p, 0x5C) != 0) {
        D_800971F8[0].unk44 = 0;
        D_800971F8[1].unk44 = 0;
        D_800971F8[2].unk44 = 0;
        two = 2;
        q = (u8*)&D_800CCED0;
        q[0x10] = two;
        q[0x11] = two;
        q[0x12] = two;
        q[0x13] = two;
        q[0x14] = two;
        q[0x15] = two;
        q[0x16] = two;
        q[0x17] = two;
        q[0x19] = two;
        arg0[0] |= 8;
        F32(arg0, 0x88) = F32(p, 0x68);
        F32(p, 0x68) = 0;
        FU8(p, 0x5) = 2;
        func_8003F3DC(p);
        func_8003CDF0(p);
        func_8003CE30(p);
        func_8003C4EC(p);
        func_8002B6B0();
        F16(arg0, 0x7C) = 0;
        a = FU16(p, 0xA);
        FU16(arg0, 0x80) = a;
        FU16(arg0, 0x82) = a;
        arg0[6]++;
        func_80016C48(1, 1, arg0);
    }
}
