#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
void* func_8002C32C();
extern struct X4_BackgroundObj D_800971F8[3];

void func_801ECAF4(u8* arg0) {
    u8* obj;
    s32 i;
    s32 dx1;
    register s32 dx2 asm("$20");

    func_80017A04((struct X4_AnimatedObj*)arg0);
    {
        register s32 one asm("$4");
        one = 1;
        if (((s8*)arg0)[0x46] == 0) {
            register s32 k21 asm("$23");
            register s32 k11 asm("$22");
            k21 = 0x21;
            k11 = 0x11;
            arg0[6]++;
            dx2 = -0x40;
            dx1 = -0x40;
            i = 4;
            func_80016C48(one, 0x25, obj);
            do {
                obj = func_8002C32C();
                if (obj != 0) {
                    obj[0] = k21;
                    obj[1] = k11;
                    obj[0x14] = arg0[0x14];
                    *(s16*)(obj + 0xA) = *(s16*)(arg0 + 0xA) + dx1;
                    *(s16*)(obj + 0xE) = D_800971F8[0].y_pos.i.hi + 0x170;
                }
                obj = func_8002C32C();
                if (obj != 0) {
                    obj[0] = k21;
                    obj[1] = k11;
                    obj[2] = 1;
                    obj[0x14] = arg0[0x14];
                    *(s16*)(obj + 0xA) = *(s16*)(arg0 + 0xA) + dx2;
                    *(s16*)(obj + 0xE) = D_800971F8[0].y_pos.i.hi + 0x210;
                }
                dx2 += 0x20;
                i--;
                dx1 += 0x20;
            } while (i >= 0);
        }
    }
}
