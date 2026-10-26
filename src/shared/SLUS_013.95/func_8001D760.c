/* Adapted from sozud/mmx4 @807a01b src/main/game_info.c:func_8001D57C, AGPL-3.0; proven shared with X6 by exact signature 57aab085cb3c (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
extern void (*D_800710C0[])(struct X4_GameInfo* arg0);
void func_80022960(void);

void func_8001D760(struct X4_GameInfo* arg0) {
    D_800710C0[arg0->mode](arg0);
    func_800206C0();
    func_80022960();
}
