#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
extern s32 D_80097420;
void func_8001750C(u8, u8);
void func_800186A8();
void func_80025F84(void);
void func_80025FB0();
void func_8002B838(void);
void func_8002C1DC();
void func_8002C2B8();

void func_8001D6D8(struct X4_GameInfo* arg0) {
    s8* p = (s8*)&D_80097420;

    if (p[4] == 0) {
        arg0->unkD = 1;
        p[6] = 0;
        func_80025F84();
        func_800186A8();
        func_8001750C(0xFF, 0);
        func_8002B838();
        func_8002C2B8();
        func_8002C1DC();
        arg0->unk0 = 3;
        arg0->mode = 0;
        return;
    }
    func_80025FB0();
}
