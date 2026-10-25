#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20_800F9A54 (*(s32*)0x1F800020)

s32 func_8002A47C(s32);
void* func_8002BBF4();
#define M2C_UNK s32
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s8 D_800CCEF6;

void func_800F9A54(void* arg0) {
    void* obj;
    s32 a;
    s32 base;

    if (g_Player.hp < 2) {
        g_Player.hp = 2;
    }
    obj = func_8002BBF4();
    M2C_FIELD(obj, u8*, 0x0) = 0x41;
    M2C_FIELD(obj, u8*, 0x1) = 0x37;
    M2C_FIELD(obj, u8*, 0x2) = 0;
    M2C_FIELD(obj, u16*, 0xA) = 0x1812;
    M2C_FIELD(obj, u16*, 0xE) = 0x15A;
    M2C_FIELD(obj, u16*, 0x40) = 0x1E0;
    M2C_FIELD(obj, u16*, 0x42) =
        ((func_8002A47C(0x37) * 4 + 0x20) % 16) |
        (((func_8002A47C(M2C_FIELD(obj, s8*, 0x1)) + 8) / 4 + 0x1E0) << 6);
    a = func_8002A47C(M2C_FIELD(obj, s8*, 0x1));
    base = SPAD20_800F9A54;
    M2C_FIELD(obj, s32*, 0x3C) = base + M2C_FIELD(base, s32*, a * 4);
    D_800CCEF6 = 1;
    M2C_FIELD(arg0, u8*, 0x4)++;
}

#undef SPAD20_800F9A54
#undef g_Player
