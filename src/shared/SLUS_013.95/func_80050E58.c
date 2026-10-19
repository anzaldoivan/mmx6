#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj D_800CCED0;
extern struct X4_PlayerObj D_800970A0;
extern void (*D_80078DE0[])(struct X4_PlayerObj*, struct X4_EngineObj*,
                            struct X4_PlayerObj*);

void func_80050E58(struct X4_PlayerObj* arg0) {
    struct X4_EngineObj* e = &D_800CCED0;
    struct X4_PlayerObj* p = &D_800970A0;
    D_80078DE0[arg0->unk5](arg0, e, p);
}
