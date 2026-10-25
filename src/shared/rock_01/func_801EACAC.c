#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
void* func_8002C32C();
s32 player_check_dash_jump_walk(struct X4_PlayerObj* self);
void func_801ECE60(void* arg0);

void func_801EACAC(u8* arg0) {
    u8* obj;
    s8 flag;
    s8 state;

    state = ((s8*)arg0)[6];
    if (state == 0) {
        arg0[6]++;
    } else if (state == 1) {
        ((void (*)())func_80017A04)(arg0);
        if (((s8*)arg0)[0x45] & 0x80) {
            obj = func_8002C32C();
            if (obj != 0) {
                obj[0] = 0x21;
                obj[1] = 0x3A;
                obj[0x14] = arg0[0x14];
                obj[0x15] = arg0[0x15];
            }
            if (*(s32*)(arg0 + 0x144) != 6) {
                arg0[6] += 2;
            } else {
                arg0[7] = 0;
                arg0[6]++;
            }
            func_80016C48(1, 0xE, arg0);
        }
    } else if (state == 2) {
        arg0[7]++;
        if ((s8)(((s8)arg0[7]) % 3) == 0) {
            obj = func_8002C32C();
            if (obj != 0) {
                obj[0] = 0x21;
                obj[1] = 0x3A;
                obj[0x14] = arg0[0x14];
                obj[0x15] = arg0[0x15];
                func_80016C48(1, 0xE, arg0);
            }
        }
        if (((s8*)arg0)[7] >= 0xC) {
            arg0[6]++;
        }
    } else {
        flag = ((s8*)arg0)[0x45];
        if (flag == 1 && ((s8*)arg0)[0xD3] == 0) {
            arg0[0x8E] = 0;
            if (player_check_dash_jump_walk((struct X4_PlayerObj*)arg0) != 0) {
                return;
            }
            arg0[0x8E] = flag;
        }
        func_80017A04(arg0);
        func_801ECE60(arg0);
    }
}
