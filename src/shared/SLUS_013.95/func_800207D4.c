#include "common.h"
#include "mmx6/x4.h"

extern u8 D_8009C9B0[];
extern struct X4_EngineObj g_playthrough_state;

#define SP_OBJ_CUR (*(s8**)SP(0x068))
#define SP_OBJ_FUNCS (*(void (***)())SP(0x098))

void func_800207D4(void) {
    for (SP_OBJ_CUR = (s8*)D_8009C9B0; SP_OBJ_CUR < (s8*)D_8009C9B0 + 0x1800;
         SP_OBJ_CUR += 0x60) {
        if (g_playthrough_state.unk18 == 0) {
            if (SP_OBJ_CUR[0]) {
                SP_OBJ_FUNCS[SP_OBJ_CUR[1]](SP_OBJ_CUR);
            }
        } else if (SP_OBJ_CUR[0] && (u8)SP_OBJ_CUR[0] & 8) {
            SP_OBJ_FUNCS[SP_OBJ_CUR[1]](SP_OBJ_CUR);
        }
    }
}

#undef SP_OBJ_CUR
#undef SP_OBJ_FUNCS
