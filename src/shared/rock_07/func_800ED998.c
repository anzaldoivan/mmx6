#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002C9B0();
u8 func_80030234(struct X4_PlayerObj*, s16, s16);
void func_800ED4D0(void);
void func_800ED764(void);
void func_800ED8AC(void);
extern struct X4_PlayerObj D_800970A0;
extern struct X4_BackgroundObj D_800971F8[3];
extern s32 D_80097420;
extern struct X4_EngineObj D_800CCED0;
extern u16 D_800E3142;
extern u16 D_800F985C;

#define PL_14C (*(s16*)((u8*)&D_800970A0 + 0x14C))

void func_800ED998(s8* arg0) {
    s8 temp_s1;

    if (arg0[4] == 0) {
        D_800F985C = D_800E3142;
        func_800ED4D0();
        func_800ED8AC();
        arg0[4]++;
    }
    if (D_800970A0.nova_strike_active != 2) {
        temp_s1 = D_800970A0.state;
        if (temp_s1 == 1 && D_800970A0.hp != 0) {
            if (D_800970A0.unk5 == 0x14) {
                if (arg0[0x14] != 0) {
                    func_80016C48(5, 3, 0);
                    arg0[0x14] = 0;
                }
            } else if (D_800970A0.unk5 != 0 && D_800970A0.unk5 != 0x14) {
                if (D_800CCED0.checkpoint == 0) {
                    D_800971F8[0].unk26 = D_800971F8[0].x_pos.i.hi;
                    D_800971F8[0].unk1E = D_800971F8[0].x_pos.i.hi;
                }
                if (D_800970A0.unk68 != 0) {
                    if (D_800CCED0.checkpoint >= 2) {
                        func_80016C48(5, 3, 0);
                        func_8002C9B0(arg0);
                        return;
                    }
                    if (arg0[0x14] == 0 || PL_14C != 0) {
                        func_80016C48(5, 6, 0);
                        arg0[0x14] = temp_s1;
                    }
                    func_800ED764();
                    if ((u32)D_80097420 % 5 == 0) {
                        D_800F985C++;
                        func_800ED8AC();
                    }
                    if (func_80030234(&D_800970A0, D_800970A0.x_pos.i.hi,
                                      D_800970A0.unk68->unk1 +
                                          (D_800970A0.y_pos.i.hi +
                                           D_800970A0.unk68->unk3)) == 0x3A) {
                        D_800970A0.x_pos.i.hi--;
                    }
                }
            }
        }
    }
}
