#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
extern u8 D_80071088;
#define D_80071088 (*(s8*)&D_80071088)
extern void (*D_8007108C[])(struct X4_GameInfo* arg0);
void func_80022960(void);

void func_8001D338(struct X4_GameInfo* arg0) {
    if (arg0->mode == 0) {
        if (D_80071088 != 0) {
            arg0->mode = 6;
        }
    }
    D_8007108C[arg0->mode](arg0);
    if (arg0->mode < 6) {
        func_80022960();
    }
}
#undef D_80071088
