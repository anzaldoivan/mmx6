/* Adapted from sozud/mmx4 @29b62af src/main/195B4.c:func_80028F58, AGPL-3.0; proven shared with X6 by exact signature a578409ab919 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_BackgroundObj D_800971F8[3];
extern struct X4_EngineObj D_800CCED0;
extern struct X4_StageObjectRecord* D_80073554[13][2];
void func_80029F38(s16, s16, s16, s16, u8);
void func_8002A4E4(struct X4_StageObjectRecord*);

void func_8002A3E8(void) {
    func_80029F38(
        D_800971F8[0].x_pos.i.hi - 0x30, D_800971F8[0].x_pos.i.hi + 0x170,
        D_800971F8[0].y_pos.i.hi - 0x30, D_800971F8[0].y_pos.i.hi + 0x120, 0);
    func_8002A4E4(D_80073554[D_800CCED0.stage][D_800CCED0.substage]);
}
