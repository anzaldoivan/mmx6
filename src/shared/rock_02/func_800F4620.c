#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
extern struct X4_BackgroundObj background_objects[3];
extern u16 D_8009721A;

M2C_UNK move_object(s32);
void func_800F4620(void* arg0) {
    void* parent;
    u8 t;

    parent = M2C_FIELD(arg0, void**, 0x7C);
    ((M2C_UNK(*)())func_80017A04)();
    ((M2C_UNK(*)())move_object)(arg0);
    t = M2C_FIELD(arg0, u8*, 0x8D);
    if (t == 0) {
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        if (M2C_FIELD(parent, s8*, 5) == 0xF) {
            M2C_FIELD(arg0, s32*, 0x54) = 0;
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, u8*, 0x8D) = 0x3C;
            M2C_FIELD(arg0, s16*, 0xE) = D_8009721A + 0x68;
            M2C_FIELD(arg0, u8*, 6) += 1;
            return;
        }
        if (M2C_FIELD(parent, s8*, 5) == 0x10) {
            if (M2C_FIELD(arg0, s8*, 2) == 9) {
                if (M2C_FIELD(parent, u8*, 0x15) != 0) {
                    {
                        s16 v = background_objects[0].unk1E - 0x16;
                        M2C_FIELD(arg0, s32*, 0x20) = 0x30000;
                        M2C_FIELD(arg0, s16*, 0xA) = v;
                    }
                } else {
                    goto right;
                }
            } else if (M2C_FIELD(parent, u8*, 0x15) == 0) {
                {
                    s16 v = background_objects[0].unk1E - 0x16;
                    M2C_FIELD(arg0, s32*, 0x20) = 0x30000;
                    M2C_FIELD(arg0, s16*, 0xA) = v;
                }
            } else {
            right: {
                s16 v = background_objects[0].unk1C + 0x157;
                M2C_FIELD(arg0, s32*, 0x20) = 0xFFFD0000;
                M2C_FIELD(arg0, s16*, 0xA) = v;
            }
            }
            {
                s16 e = background_objects[0].unk22 + 0x68;
                M2C_FIELD(arg0, u8*, 0x8D) = 0x3A;
                M2C_FIELD(arg0, u8*, 6) = 3;
                M2C_FIELD(arg0, s16*, 0xE) = e;
            }
            return;
        }
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        if (M2C_FIELD(parent, s8*, 6) >= 3) {
            {
                // !FAKE: depin: dropping it breaks the match (102/107)
                register s32 vel2 asm("$2");
                // !FAKE: depin: dropping it breaks the match (103/107)
                register s32 c asm("$2") = M2C_FIELD(parent, u8*, 0x15);
                if (c != 0) {
                    vel2 = 0x30000;
                } else {
                    vel2 = 0xFFFD0000;
                }
                M2C_FIELD(arg0, s32*, 0x20) = vel2;
            }
            M2C_FIELD(arg0, u8*, 0x8D) = 0;
            M2C_FIELD(arg0, u8*, 6) = 3;
        }
    } else {
        if (--M2C_FIELD(arg0, u8*, 0x8D) == 0 &&
            M2C_FIELD(parent, s8*, 5) == 0x11) {
            func_80016C48(2, 0x7F, arg0);
        }
    }
}
