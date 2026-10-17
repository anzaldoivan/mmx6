#include "common.h"
#include "mmx6/x4.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

void* func_8002C530();
extern struct X4_EngineObj D_800CCED0;
extern u8 D_800F1CB0[];

void func_800ECCB4(void* arg0) {
    u8 i;
    u8 v;
    s8* o;

    i = D_800F1CB0[1];
    D_800CCED0.character_state.bytes[11] = 0;
    D_800CCED0.character_state.bytes[12] = 0;
    D_800CCED0.character_state.bytes[10] = i;
    v = D_800F1CB0[(s8)i];
    D_800CCED0.character_state.bytes[2] = v;
    do {
        o = func_8002C530(arg0, &D_800CCED0, v, i);
    } while (0);
    if (o != 0) {
        o[0] = 1;
        o[1] = 0x2B;
        o[2] = 0;
    }
    o = func_8002C530(o);
    if (o != 0) {
        o[0] = 1;
        o[1] = 0x2B;
        o[2] = 1;
    }
    o = func_8002C530(o);
    if (o != 0) {
        o[0] = 1;
        o[1] = 0x2B;
        o[2] = 2;
    }
    FX(arg0, u8, 2)++;
}
