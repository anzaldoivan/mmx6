#include "common.h"
#include "mmx6/x4.h"

void func_8002F288();
void func_800F1388();
extern void (*D_800FB198[])(struct X4_MainObj*);

// 0x800EFED0 update_d1000: per-frame state dispatch of the D-1000 intro boss.
// basis: community refs/leads/tweaks/BossHealth.tsv:234 (word 0x800EFF4C = D_800FB198[0])
// callers: none known (object type table, docs/leads/objects.tsv:146)
void update_d1000(struct X4_MainObj* arg0) {
    if (arg0->unk2 == 1) {
        func_800F1388();
        return;
    }
    arg0->unk18.val = arg0->x_pos.val;
    arg0->on_screen = 0;
    arg0->unk1C.val = arg0->y_pos.val;
    D_800FB198[arg0->state](arg0);
    func_8002F288(arg0);
}
