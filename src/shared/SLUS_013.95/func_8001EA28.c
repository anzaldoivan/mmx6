#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_80097420;
extern u16 D_800C4570;
extern u8 D_800CF920[];

void func_80013008(void);
void func_800139F4(s32);
void func_80020C40(void);
void func_80025FB0();
void func_8002B29C(void);
s32 random_byte();

void func_8001EA28(void* arg0) {
    s8* p;

    if (M2C_FIELD(arg0, s8*, 0x1C) == 0) {
        p = (s8*)&D_80097420;
        if (p[4] == 0 &&
            ((D_800C4570 & 0x800) || (p[6] == 0 && D_800CF920[0] == 0xFF)) &&
            M2C_FIELD(arg0, s8*, 0x10) == 0 && M2C_FIELD(arg0, s8*, 0xF) == 0) {
            func_80013008();
            M2C_FIELD(arg0, u8*, 1) = 2;
            func_80025FB0();
            return;
        }
    }
    if (g_Player.state == 3) {
        M2C_FIELD(arg0, u8*, 1) = M2C_FIELD(arg0, u8*, 1) + 1;
        func_800139F4(8);
    }
    random_byte();
    func_80020C40();
    if (M2C_FIELD(&g_Player, u8*, 0xE4) != 0) {
        func_8002B29C();
    }
    func_80025FB0();
}
#undef g_Player
