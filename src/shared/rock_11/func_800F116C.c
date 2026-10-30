#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800F4588(void* arg0, s32 arg1);
extern s16 D_800971EC;
extern s16 D_800FD516;
extern s16 D_800FD518;
extern s8 D_800FD51A;
extern s8 D_800FD51B;

#define F(type, off) M2C_FIELD(arg0, type*, off)
#define SH(off) (((X4_f32*)arg0)[((off) - 2) / 4].i.hi)
#define PF(off) M2C_FIELD(parent, s16*, off)

void func_800F116C(void* arg0) {
    void* parent;
    s8 t;

    parent = F(void*, 0x5C);
    if (D_800971EC != 0) {
        play_sound(2, 0x32, arg0);
    }
    SH(0x16) = PF(0xA) - 2;
    SH(0x1A) = PF(0xE) - 0xE;
    SH(0x1E) = PF(0xA) + 2;
    SH(0x22) = PF(0xE) - 0xE;
    SH(0x26) = D_800FD516 - 2;
    SH(0x2A) = D_800FD518;
    SH(0x2E) = D_800FD516 + 2;
    SH(0x32) = D_800FD518;
    t = D_800FD51B;
    if (t == 0) {
        // !FAKE: keeps the two equality tests apart instead of a range test
        goto on;
    }
    if (t == 1) {
    on:
        F(s8, 0x3) = D_800FD51A;
        if (F(s8, 0x3) != 0) {
            func_800F4588(arg0, 1);
        }
    } else {
        F(u8, 0x3) = 0;
        F(u8, 0x4) += 1;
    }
}
