#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EffectObj D_8009B7B0[0x20];
extern struct X4_EngineObj g_playthrough_state;

#define SPAD5C (*(s8**)0x1F80005C)
#define SPAD8C (*(s32*)0x1F80008C)

void func_8002048C(void) {
    s8* p;

    for (SPAD5C = (s8*)D_8009B7B0; SPAD5C < (s8*)&D_8009B7B0[0x60];
         SPAD5C += 0x30) {
        if (g_playthrough_state.unk15 == 0) {
            p = SPAD5C;
            if (p[0] != 0) {
                void* fn = *(void**)((p[1] << 2) + SPAD8C);
                ((void (*)())fn)(p);
            }
        } else {
            p = SPAD5C;
            if ((u8)p[0] & 8) {
                void* fn = *(void**)((p[1] << 2) + SPAD8C);
                ((void (*)())fn)(p);
            }
        }
    }
}
