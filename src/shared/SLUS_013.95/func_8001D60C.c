#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s8 D_80097424;

void func_800139F4(s32);
void func_80021500(void);
void func_8002163C(void);
void func_80025FB0();
void func_8002B29C(void);
s32 func_8002D2D4();

void func_8001D60C(struct X4_EngineObj* arg0) {
    if (D_80097424 == 0) {
        arg0->substage = 0;
    }
    if (--arg0->unk4 == 0 || g_Player.active == 0 || g_Player.state == 3) {
        func_800139F4(8);
        func_8002163C();
        {
            // !FAKE: increment temp lives in the second return register in retail
            register s32 t asm("$3") = (u8)arg0->unk1 + 1;
            arg0->unk1 = t;
        }
    } else {
        func_8002D2D4();
        func_80021500();
    }
    if ((u8)g_Player.pad4B[0xE4 - 0x4B] != 0) {
        func_8002B29C();
    }
    func_80025FB0();
}
#undef g_Player
