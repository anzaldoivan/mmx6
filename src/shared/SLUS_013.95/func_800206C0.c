#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define CUR (*(struct X4_MiscObj**)0x1F800064)
#define FTBL (*(void (***)(struct X4_MiscObj*))0x1F800090)

extern struct X4_EngineObj g_playthrough_state;
extern struct X4_MiscObj g_displayed_sprites[];

M2C_UNK func_8002CD6C(void*);

void func_800206C0(void) {
    struct X4_MiscObj* p;

    for (CUR = g_displayed_sprites; CUR < g_displayed_sprites + 0x60; CUR++) {
        if (g_playthrough_state.unk17 == 0) {
            p = CUR;
            if (p->active == 0) {
                continue;
            }
            goto call;
        } else {
            p = CUR;
            if (p->active != 0) {
                if ((u8)p->active & 8) {
                call:
                    FTBL[p->id](p);
                } else if (p->on_screen != 0) {
                    func_8002CD6C(p);
                }
            }
        }
    }
}
