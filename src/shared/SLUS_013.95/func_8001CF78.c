#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_800139F4(s32);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
void func_800186A8(void);
void func_8001CD5C(struct X4_EngineObj*);
void func_8001CE68(struct X4_EngineObj*);
extern s8 D_80097424;
extern u16 D_800C456C[];

void func_8001CF78(struct X4_EngineObj* arg0) {
    if (D_80097424 == 0) {
        if (D_800C456C[2] & 0x1000) {
            func_80016C48(0, 0xC, 0);
            if (arg0->unk2 == 0) {
                arg0->unk2 = 2;
            } else {
                arg0->unk2--;
            }
        }
        if (D_800C456C[2] & 0x4000) {
            func_80016C48(0, 0xC, 0);
            if (arg0->unk2 == 2) {
                arg0->unk2 = 0;
            } else {
                arg0->unk2++;
            }
        }
        func_8001CD5C(arg0);
        func_8001CE68(arg0);
        if (D_800C456C[2] & 0x840) {
            func_80016C48(0, 0x22, 0);
            func_800139F4(8);
            func_800186A8();
            {
                register s32 t asm("$3") = (u8)arg0->unk1 + 1;
                arg0->unk1 = t;
            }
        }
        if (D_800C456C[2] == 0) {
            if (++arg0->unk4 > 0x4650) {
                func_800186A8();
                func_800139F4(8);
                arg0->unk4 = 0;
                {
                    register s32 t asm("$2") = (u8)arg0->unk1 + 2;
                    arg0->unk1 = t;
                }
            }
        } else {
            arg0->unk4 = 0;
        }
    }
}
