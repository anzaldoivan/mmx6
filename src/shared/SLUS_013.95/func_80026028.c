#include "common.h"
#define M2C_UNK s32

extern u8 D_800A51B8[];
extern u8 D_800C4858[];
extern M2C_UNK D_800CD3F0;
#define D_800CD3F0 (*(s8(*)[4]) & D_800CD3F0)

void func_800192CC(void);
void func_8001A278(void);
void func_80022E44(void);
void func_80026128(void);

#define SCR_BUF (*(s32*)0x1F800000)
#define SCR_PTR(off) (*(u8**)(0x1F800000 + (off)))
#define SCR_COUNT (*(s32*)0x1F800124)

M2C_UNK func_80026028(void) {
    s32 i;
    u8* a;
    u8* b;
    s8 saved;

    i = SCR_BUF;
    SCR_COUNT = 0;
    a = D_800A51B8 + i * 0xA000;
    b = D_800C4858 + (i << 13);
    SCR_PTR(0x100) = a;
    SCR_PTR(0x104) = b;
    SCR_PTR(0x110) = a;
    func_80026128();
    saved = D_800CD3F0[0];
    D_800CD3F0[0] = 0xF;
    func_800192CC();
    D_800CD3F0[0] = saved;
    func_8001A278();
    func_80022E44();
}

#undef D_800CD3F0
