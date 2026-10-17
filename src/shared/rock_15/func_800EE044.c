#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F16(p, o) (*(u16*)((u8*)(p) + (o)))
#define S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CF0C(void*);
extern struct X4_EngineObj D_800CCED0;
extern void* D_800F70E0;

void func_800EE044(void* arg0) {
    F8(arg0, 3) = 0;
    if (S8(D_800F70E0, 0) != 0) {
        if (S8(D_800F70E0, 7) == 0) {
            if (--S16(arg0, 0x7E) == -1) {
                F16(arg0, 0x7E) = 5;
                F16(arg0, 0x42) ^= 0x8000;
            }
            func_8002CCB0(arg0, 0x60, 0x60);
        }
    } else {
        F32(arg0, 0x80) = 0;
        F32(arg0, 0x84) = 0;
        F32(arg0, 0x88) = 0;
        F32(arg0, 0x8C) = 0;
        F32(arg0, 0x90) = 0;
        F32(arg0, 0x94) = 0;
        D_800CCED0.enable_boss = 0;
        F32(&D_800CCED0, 0x20) = 0;
        func_8002CF0C(arg0);
        F8(arg0, 0) = 0x41;
        F8(arg0, 1) = 0x3E;
    }
}
