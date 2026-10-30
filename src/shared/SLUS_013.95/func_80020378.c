#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002CD6C(void*);
extern u8 D_80091298[];
extern struct X4_EngineObj g_playthrough_state;

#define CUR (*(s8**)SP(0x54))
#define FTBL (*(void (***)(s8*))SP(0x88))

void func_80020378(void) {
    s8* p;

    for (CUR = (s8*)D_80091298; CUR < (s8*)(D_80091298 + 0x2A00); CUR += 0x70) {
        if (g_playthrough_state.unk14 == 0) {
            p = CUR;
            if (p[0] == 0) {
                continue;
            }
            goto call;
        } else {
            p = CUR;
            if (p[0] != 0) {
                if ((u8)p[0] & 8) {
                call:
                    FTBL[p[1]](p);
                } else if (p[3] != 0) {
                    func_8002CD6C(p);
                }
            }
        }
    }
}
