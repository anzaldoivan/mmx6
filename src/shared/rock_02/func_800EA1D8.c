/* Adapted from sozud/mmx4 @29b62af src/main/layers/layer_02_train_tunnel.c:train_tunnel_update, AGPL-3.0; proven shared with X6 by exact signature 9f9117540cf8 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern void (*D_800FAA64[])(struct X4_LayerObj*);

void func_800EA1D8(struct X4_LayerObj* arg0) {
    D_800FAA64[arg0->state](arg0);
    func_8002F288(arg0);
}
