#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void* func_8002BBF4();
M2C_UNK func_8002C9B0();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern struct X4_EngineObj D_800CCED0;
extern u32 D_800F7DE0;

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define P(p, o) (*(void**)((u8*)(p) + (o)))

void func_800F1904(void* arg0) {
    void* parent;
    u8* p;

    parent = P(arg0, 0x80);
    if (SB(parent, 0) != 0) {
        if (SB(parent, 7) == 0) {
            if ((s16)--UH(arg0, 0x7E) == -1) {
                UH(arg0, 0x7E) = 5;
                UH(arg0, 0x42) ^= 0x8000;
            }
            func_8002CCB0(arg0, 0x40, 0x40);
        }
    } else {
        if (D_800CCED0.stage != 0xC) {
            if (D_800F7DE0 < 0x1519) {
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
