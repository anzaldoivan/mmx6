#include "common.h"
#include "mmx6/x4.h"

struct X4_QuadObj* func_8002C7F0(void);
extern s8 D_800CCEFC;
extern s8 D_800F1CCA[];

void func_800ED30C(struct X4_EngineObj* arg0) {
    struct X4_QuadObj* q;
    s32 i;

    i = 0;
    if (++arg0->unk8 >= 8) {
        D_800F1CCA[0] = 1;
        D_800F1CCA[1] = 1;
        D_800CCEFC = 0;
        arg0->unk8 = 0;
        arg0->unk2++;
        do {
            q = func_8002C7F0();
            if (q != 0) {
                q->active = 3;
                q->id = 1;
                q->unk2 = i;
                q->unk34 = i + 0x18;
                q->unk36 = 0;
                q->bg_offset = -1;
            }
            i++;
        } while (i < 2);
    }
}
