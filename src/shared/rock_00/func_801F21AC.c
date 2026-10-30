#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_801F21AC(void* arg0, u8 arg1) {
    s32 flag;
    s8* sub;
    s8 kind;

    flag = 0;
    kind = M2C_FIELD(arg0, s8*, 2);
    if (kind == 16) {
        sub = M2C_FIELD(arg0, s8**, 0x7C);
        if (sub[6] != 0) {
            sub[6]--;
        }
    } else if (kind == 0) {
        if (M2C_FIELD(arg0, s8*, 0x8C) == 0) {
            flag = 1;
        }
    } else if (kind == 1) {
        flag = 1;
        if (M2C_FIELD(arg0, s8*, 6) != 0) {
            return;
        }
    }
    if (flag != 0) {
        struct X4_PlayerObj* p = &g_Player;
        if (M2C_FIELD(p, s8*, 0xA6) == 3) {
            M2C_FIELD(p, s8*, 0xA6) = 0;
        }
        M2C_FIELD(p, u8*, 0x98)--;
        M2C_FIELD(p, u8*, 0x99)--;
    }
    clear_object_slot(arg0);
}
#undef g_Player
