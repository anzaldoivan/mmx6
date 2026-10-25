#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80017A04(struct X4_AnimatedObj*);
void* func_8002C32C();
M2C_UNK func_8003B114(s32);
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK player_spawn_weapon(M2C_UNK, s8, M2C_UNK, void*);

void func_801EB02C(u8* arg0) {
    u8* obj;
    s32 kind;
    // !FAKE: depin: dropping it breaks the match (81/87)
    register s32 one asm("$2");

    if (M2C_FIELD(arg0, s16*, 0x14C) == 2) {
        func_8003B114((s32)arg0);
        return;
    }
    if (((s8*)arg0)[6] == 0) {
        arg0[6]++;
    } else {
        func_80017A04((struct X4_AnimatedObj*)arg0);
    }
    if (((s8*)arg0)[0x45] & 0x80) {
        player_spawn_weapon(1, 0x38, 0, 0);
    }
    if (arg0[0x17] == 0xB7) {
        if (((s8*)arg0)[0x45] & 0x80) {
            arg0[0x45] &= 0x7F;
            obj = func_8002C32C();
            if (obj != 0) {
                one = 1;
                kind = 0x32;
                goto block_14;
            }
        }
    } else if (((s8*)arg0)[0x45] & 0x80) {
        arg0[0x45] &= 0x7F;
        obj = func_8002C32C();
        if (obj != 0) {
            one = 1;
            kind = 0x33;
        block_14:
            obj[0] = one;
            obj[1] = kind;
            obj[0x14] = arg0[0x14];
            M2C_FIELD(obj, s32*, 0x84) = arg0[0x17];
            obj[0x15] = arg0[0x15];
        }
    }
    if (((s8*)arg0)[0x46] == 0) {
        if (((s8*)arg0)[7] == 2) {
            ((void (*)(void*, s32))func_8003BA04)(arg0, 0xF);
            arg0[5] = 0xB;
            arg0[6] = 0;
            return;
        }
        func_8003B114((s32)arg0);
    }
}
