#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
void* func_8002C530();
s32 func_800EC1FC(s32);
extern u16 D_800C4570;
extern struct X4_EngineObj D_800CCED0;
extern s32 D_800F0E74[];
extern s8 D_800F0ED4[];
extern s8 D_800F1C80[];
extern s8 D_800F1CD0[][5];
extern s8 D_800F1CEA;

#define EC35C_ENG_29 (D_800CCED0.character_state.bytes[3])
#define EC35C_ENG_2A (D_800CCED0.character_state.bytes[4])
#define EC35C_F(o, t) (*(t*)((u8*)arg0 + (o)))

void func_800EC35C(void* arg0) {
    s32* p;
    s32* q;
    s32 a;
    s32 b;
    u8* o;
    s32 t;

    if (D_800C4570 & 0x840) {
        func_80016C48(5, 1, 0);
        if ((EC35C_F(0x70, s32) & D_800F0E74[EC35C_ENG_2A]) &&
            func_800EC1FC(EC35C_ENG_2A) == 0) {
            q = (s32*)((u8*)arg0 + 0x74);
            p = q + EC35C_ENG_29;
            a = *p;
            b = D_800F0E74[EC35C_ENG_2A];
            if (a & b) {
                *p = a & ~b;
                D_800F1CEA = 1;
                goto after;
            }
            if (EC35C_ENG_2A >= 0x12
                    ? D_800F1CD0[EC35C_ENG_29][4] == -1
                    : D_800F1C80[EC35C_ENG_29] <
                          D_800F0ED4[((s8*)arg0 + EC35C_ENG_29)[0x8D]]) {
                goto orarm;
            }
        }
        D_800F1CEA = 2;
        goto after;
    orarm:
        *p = a | b;
        D_800F1CEA = 1;
    after:
        t = 1;
        EC35C_F(2, u8) = t;
        if (D_800F1CEA == 2) {
            o = func_8002C530();
            if (o != 0) {
                o[0] = 1;
                o[1] = 0x28;
                o[2] = 0x3D;
            }
        }
    }
}
