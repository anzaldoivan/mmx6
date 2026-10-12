#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)
extern s8 D_800950A0[];
void* func_8002C32C();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
#define func_8002CCB0 ((void (*)(void*, s32, s32))func_8002CCB0)
void func_8002D2B0(struct X4_MovingObj*);
M2C_UNK func_8002EE10(void*);
void func_800383F8(void*);

void func_801ED36C(s8* arg0) {
    struct X4_PlayerObj* player = &D_800970A0;
    s8* sub;
    s8* p;
    s8* spawn;
    s32 i;
    s32 count;
    s32 c15;
    s32 c1;
    u32 max;

    sub = arg0 + 0x8C;
    func_8002D2B0((struct X4_MovingObj*)arg0);
    max = 1;
    if (M2C_FIELD(player, u8*, 0xE7) == 4) {
        max = 3;
    }
    if (M2C_FIELD(arg0, s8*, 0x98) != 0) {
        count = 0;
        if (M2C_FIELD(sub, u8*, 2) < max) {
            c15 = 0x15;
            c1 = 1;
            p = D_800950A0;
            i = 0x1F;
            do {
                if ((p[0] != 0) && (p[1] == c15) && (p[4] == c1)) {
                    count++;
                }
                i--;
                p += 0xA0;
            } while (i >= 0);
            if (count < (s32)max) {
                spawn = func_8002C32C();
                if (spawn != 0) {
                    spawn[0] = 0x21;
                    spawn[1] = 0x15;
                    spawn[2] = 0;
                    M2C_FIELD(spawn, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
                    M2C_FIELD(spawn, s32*, 0x8) = M2C_FIELD(arg0, s32*, 0x8);
                    M2C_FIELD(spawn, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0xC);
                    M2C_FIELD(spawn, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
                    M2C_FIELD(sub, u8*, 2)++;
                }
            }
        }
        if (M2C_FIELD(arg0, s8*, 0x98) < 0) {
            arg0[3] = 0;
            arg0[4] = 3;
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, s32*, 0x68) = 0;
            return;
        }
        M2C_FIELD(arg0, s8*, 0x98) = 0;
    }
    if ((M2C_FIELD(arg0, u8*, 0x70) != 0) ||
        (func_8002EE10(arg0), (M2C_FIELD(arg0, u8*, 0x70) != 0))) {
        func_800383F8(arg0);
        arg0[3] = 0;
        arg0[4] = 3;
        M2C_FIELD(arg0, s32*, 0x50) = 0;
        M2C_FIELD(arg0, s32*, 0x68) = 0;
    }
    func_8002CCB0(arg0, 0x2A, 0x22);
}
#undef func_8002CCB0
#undef D_800970A0
