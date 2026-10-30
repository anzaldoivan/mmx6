#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;
extern struct X4_PlayerObj g_Player;
extern void (*D_80078DE0[])(struct X4_PlayerObj*, struct X4_EngineObj*,
                            struct X4_PlayerObj*);

void func_80050E58(struct X4_PlayerObj* arg0) {
    struct X4_EngineObj* e = &g_playthrough_state;
    struct X4_PlayerObj* p = &g_Player;
    D_80078DE0[arg0->unk5](arg0, e, p);
}
