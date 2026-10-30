#include "common.h"
#include "mmx6/x4.h"

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_8005211C(void* arg0);
extern s32 D_80079D70[];
extern struct X4_EngineObj g_playthrough_state;

void func_80052294(u8* arg0) {
    F8(arg0, 0x14) = 0;
    arg0[4]++;
    F32(arg0, 0x18) = D_80079D70[g_playthrough_state.stage * 2 +
                                 g_playthrough_state.substage] +
                      (arg0[2] & 0x7F) * 0x10;
    func_8005211C(arg0);
}
