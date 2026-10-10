#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define FLD(p, type, off) (*(type*)((u8*)(p) + (off)))

void* func_8002BBF4();
M2C_UNK func_8002C9B0();
void func_8002CCB0(struct X4_BaseObj*, s32, s32);
extern struct X4_EngineObj D_800CCED0;
extern s32 D_800F6AF4;

void func_800F063C(void* arg0) {
    s8* p;
    s8* t;

    t = FLD(arg0, s8*, 0x8C);
    FLD(arg0, s8, 0x3) = 0;
    if (t[0] != 0) {
        if (t[7] == 0) {
            if (--FLD(arg0, s16, 0x7E) == -1) {
                FLD(arg0, s16, 0x7E) = 5;
                FLD(arg0, u16, 0x42) ^= 0x8000;
            }
            func_8002CCB0(arg0, 0x60, 0x60);
        }
    } else {
        FLD(arg0, s32, 0x80) = 0;
        FLD(arg0, s32, 0x84) = 0;
        FLD(arg0, s32, 0x88) = 0;
        FLD(arg0, s32, 0x8C) = 0;
        FLD(arg0, s32, 0x90) = 0;
        FLD(arg0, s32, 0x94) = 0;
        D_800CCED0.enable_boss = 0;
        D_800CCED0.boss_ptr = 0;
        if (D_800CCED0.stage != 0xC) {
            if ((u32)D_800F6AF4 < 0x1519) {
                p = func_8002BBF4();
                if (p != 0) {
                    p[0] = 0x41;
                    p[1] = 0xF;
                    p[2] = 0x10;
                }
            } else {
                p = func_8002BBF4();
                if (p != 0) {
                    p[0] = 0x41;
                    p[1] = 0xF;
                    p[2] = 0x11;
                }
            }
        } else {
            D_800CCED0.unkF = -0x80;
            D_800CCED0.character_state.bytes[D_800CCED0.checkpoint + 6] = 1;
            D_800CCED0.checkpoint += 8;
        }
        func_8002C9B0(arg0);
    }
}
