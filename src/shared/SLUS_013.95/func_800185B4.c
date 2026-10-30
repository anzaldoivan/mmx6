#include "common.h"
#include "psyq/libcd.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void stop_cd_audio(void);
int func_800617A4(X4_CdlLOC* p);
s32 func_800647F4();
s8 func_80064874(M2C_UNK, u8*);
extern s32 D_800E2E18;
extern u32 D_800E2E24;
extern u32 D_800E2E2C;
extern u8 D_800E2E40;
extern s16 D_800E2E48;
extern s8 D_800E2E50;
extern s32 D_800E2E5C;
#define D_800E2E50 (*(u8*)&D_800E2E50)

void func_800185B4(void) {
    s32 state;
    s32 ret;

    if (D_800E2E5C == 2) {
        state = D_800E2E18;
        if (state == D_800E2E5C) {
            D_800E2E48 = 1;
            ret = func_800647F4();
            if ((ret == 0x1B || ret == 0x11) &&
                func_80064874(1, &D_800E2E40) == state) {
                if (ret == 0x11) {
                    D_800E2E24 = func_800617A4((X4_CdlLOC*)(&D_800E2E40 + 5));
                    if (D_800E2E24 >= D_800E2E2C) {
                        if (D_800E2E50 != 0) {
                            D_800E2E18 = 5;
                        } else {
                            stop_cd_audio();
                        }
                    }
                }
                CdControlF(0x11, 0);
            }
        }
    }
}
#undef D_800E2E50
