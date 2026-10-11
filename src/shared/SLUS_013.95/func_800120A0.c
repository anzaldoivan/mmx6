#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_800123D0(void);
void func_80012658(void);
void func_80012A34(void);
void func_80012C54(void);
void func_80012EB4(void);
void func_800131AC(void);
void func_8001651C(void);
void func_80017A48(void);
void func_80017A88(void);
void func_80017C40(void);
s32 func_80018290(void);
void func_800185B4(void);
void func_80027A50(void);
void func_80054AD0(void);
int func_80060964(int mode);
M2C_UNK func_80066150(M2C_UNK);
M2C_UNK func_8006663C(s32, M2C_UNK);
void func_80066744(void*);
void func_800667B4(void*);
void func_80066980(void*);

extern s32 D_80097420;
extern struct X4_DrawInfo* D_8009B7A0;
extern u8 D_800C4578[];
extern u8 D_800CF908[];
extern u8 D_800CF948[];

#define SCRATCH0 (*(s32*)0x1F800000)
#define SCRATCH70 (*(s32*)0x1F800070)
#define SCRATCH74 (*(s32*)0x1F800074)
#define SCRATCH7C (*(s32*)0x1F80007C)
#define SETADDR(p, a) (((X4_P_TAG*)(p))->addr = (u32)(a))
#define GETADDR(p) (((X4_P_TAG*)(p))->addr)
#define OT_E4 ((u8*)D_8009B7A0 + 0xE4)

void func_800120A0(void) {
    u8* p;

    func_80054AD0();
    func_80012658();
    while (1) {
        func_80060964(0);
        func_80066980(D_8009B7A0);
        func_800667B4((u8*)D_8009B7A0 + 0x14);
        func_80066744((u8*)D_8009B7A0 + 0xEC);
        SCRATCH0 ^= 1;
        D_8009B7A0 = (struct X4_DrawInfo*)(D_800C4578 + SCRATCH0 * 0xF0);
        func_8006663C((s32)((u8*)D_8009B7A0 + 0x70), 0x20);
        func_800123D0();
        SETADDR(D_800CF948 + SCRATCH0 * 0xC, GETADDR(OT_E4));
        SETADDR(OT_E4, D_800CF948 + SCRATCH0 * 0xC);
        SETADDR(D_800CF908 + SCRATCH0 * 0xC, GETADDR(OT_E4));
        SETADDR(OT_E4, D_800CF908 + SCRATCH0 * 0xC);
        func_800185B4();
        func_80018290();
        func_80012A34();
        func_80017A48();
        D_80097420++;
        func_800131AC();
        func_8001651C();
        SCRATCH70 = func_80060964(1);
        func_80066150(0);
        func_80017A88();
        func_80017C40();
        func_80027A50();
        func_80066150(0);
        SCRATCH7C = SCRATCH74;
        func_80012C54();
        func_80012EB4();
    }
}
