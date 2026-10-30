#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800139A0(s8);
void func_80013D10(void);
void func_80017E24(void);
void func_8001E730(void);
void func_8001E78C(void);
s32 func_8001EC0C();
void func_80025F34();
void func_800280F4(void);
void func_8002927C(void);
void func_8002935C(void);
M2C_UNK func_800293CC();
void init_checkpoint_positions(void);
void func_8002A33C(void);
void func_8002A3E8(void);
void reset_level(void);
void func_8002C2B8();
void func_8003BD24(void);
extern u8 D_8006D5F9;
extern struct X4_AbcObj D_8008EAF0;
extern s32 D_8008EC0C;
extern s16 D_8009741A;
extern u8 D_800CC868;
extern s8 D_800CCEED;

void func_8001E1BC(u8* arg0) {
    u8* p;
    u32 i;

    if (func_8001EC0C() != 0 && D_800CC868 != D_800CCEED) {
        func_80013D10();
    }
    i = 0;
    p = arg0 + 0x26;
    do {
        p[i] = 0;
        i++;
    } while (i < 8);
    D_8008EAF0.unkC = 0;
    D_8008EAF0.unk10 = 0;
    reset_level();
    func_8002C2B8();
    func_80017E24();
    func_800280F4();
    init_checkpoint_positions();
    func_8002927C();
    func_8002935C();
    func_800293CC();
    func_8003BD24();
    func_8002A33C();
    func_8002A3E8();
    arg0[0x1C] = 1;
    arg0[0x1F] = 0;
    arg0[0x24] = 0;
    arg0[0x10] = 0;
    arg0[0x11] = 0;
    arg0[0x12] = 0;
    arg0[0x13] = 0;
    arg0[0x14] = 0;
    arg0[0x15] = 0;
    arg0[0x16] = 0;
    arg0[0x17] = 0;
    arg0[0x18] = 0;
    arg0[0x19] = 0;
    arg0[0x1A] = 0;
    arg0[0xF] = 0;
    arg0[0x67] = D_8006D5F9;
    func_80025F34();
    func_8001E730();
    if (arg0[0x1B] != 0) {
        arg0[0x1B] = 0;
    } else {
        func_8001E78C();
    }
    func_800139A0(8);
    {
        // !FAKE: depin: dropping it breaks the match (85/92)
        register s32 a asm("$2") = 10;
        s32 b = 1;
        arg0[0] = a;
        D_8008EC0C = b;
    }
    D_8009741A = 0x3C;
}
