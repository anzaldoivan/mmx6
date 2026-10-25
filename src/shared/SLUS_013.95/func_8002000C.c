#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(s8**)0x1F80004C)
#define SPAD_TBL (*(void (***)(s8*))0x1F800080)

M2C_UNK func_8002CD6C(void*);
extern s8 D_8008EF48[];
extern M2C_UNK g_Player;
extern struct X4_EngineObj D_800CCED0;

void func_8002000C(void) {
    s8* p;
    u8 flags;
    s8* pl = (s8*)&g_Player;

    if (pl[0xCC] == 0) {
        for (SPAD = D_8008EF48; SPAD < D_8008EF48 + 0x1D40; SPAD += 0x9C) {
            p = SPAD;
            flags = p[0];
            if (p[0] != 0) {
                s8* pl2 = (s8*)&g_Player;
                if (pl2[0xCC] != 0 || (D_800CCED0.unk12 != 0 && !(flags & 8))) {
                    if (p[3] != 0) {
                        ((void (*)(void*, u8))func_8002CD6C)(p, flags);
                    }
                } else {
                    SPAD_TBL[p[1]](p);
                }
            }
        }
    }
}
