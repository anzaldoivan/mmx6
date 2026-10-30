#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK create_task(M2C_UNK, M2C_UNK*); /* extern */
M2C_UNK func_800133A0();                  /* extern */
void func_8002C1DC();
extern s8 D_80097424;
extern struct X4_EngineObj g_playthrough_state;
void func_8001E6E4(void);

void func_8001DAF8(s8* arg0) {
    s8 var_v0;

    if (D_80097424 == 0) {
        switch (arg0[2]) {
        case 0:
            func_8002C1DC();
            g_playthrough_state.state = 0;
            g_playthrough_state.unk1 = 0;
            g_playthrough_state.unk2 = 0;
            g_playthrough_state.unk3 = 0;
            create_task(1, &func_8001E6E4);
            func_800133A0();
            break;
        case 1:
            var_v0 = 7;
            // !FAKE: case 1 joins the shared store block
            goto block_9;
        case 2:
            var_v0 = 8;
        block_9:
            arg0[0] = var_v0;
            arg0[1] = 0;
            arg0[2] = 0;
            arg0[3] = 0;
            break;
        }
    }
}
