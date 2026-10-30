#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 play_sound(s32 a0, s32 a1, void* arg2); /* extern */
M2C_UNK func_80017A04();                    /* extern */
s32 select_air_dash(void*);                 /* extern */
s32 func_80039984(void*);                   /* extern */
s32 func_8003A2CC(void*);                   /* extern */
s32 func_8003A488(void*);                   /* extern */
void func_8003D18C(void* arg0);             /* extern */
void func_8003D394(void* arg0);             /* extern */
s32 func_8003E174(void*);                   /* extern */
void player_set_animation_shooting(struct X4_PlayerObj* self,
                                   s32 animation); /* extern */
M2C_UNK func_8003F508(void*, M2C_UNK);             /* extern */
s32 func_801EA454(void*);                          /* extern */
s32 func_801EA560(void*);                          /* extern */
s32 func_801EBF94(void*);                          /* extern */

// 0x80035620 handle_jump_rise: jump rising state.
// basis: community tweaks-index.tsv:231
// callers: none known
void handle_jump_rise(void* arg0) {
    s32 var_v0;

    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        M2C_FIELD(arg0, s32*, 0x24) = 0;
    }
    if (M2C_FIELD(arg0, u8*, 0x89) & 4) {
        M2C_FIELD(arg0, s32*, 0x24) = 0;
    }
    if (!(M2C_FIELD(arg0, u16*, 0x7C) & 0x80)) {
        M2C_FIELD(arg0, s32*, 0x24) = 0;
    }
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        var_v0 = func_8003E174(arg0);
        goto block_11;
    }
    if ((func_801EA560(arg0) == 0) && (func_801EA454(arg0) == 0)) {
        var_v0 = func_801EBF94(arg0);
    block_11:
        if (var_v0 == 0) {
            func_80017A04(arg0);
            {
                // !FAKE: depin: dropping it breaks the match (93/98)
                register s32 t asm("$2") = M2C_FIELD(arg0, s8*, 0x45) & 0x80;
                if (t) {
                    M2C_FIELD(arg0, u8*, 0x45) =
                        (u8)(M2C_FIELD(arg0, u8*, 0x45) & 0x3F);
                    play_sound(1, 1, arg0);
                }
            }
            if ((func_8003A488(arg0) == 0) && (func_80039984(arg0) == 0)) {
                if (M2C_FIELD(arg0, s8*, 0x8B) == 0) {
                    if (func_8003A2CC(arg0) != 0) {
                        return;
                    }
                } else {
                    M2C_FIELD(arg0, u8*, 0x8B) =
                        (u8)(M2C_FIELD(arg0, u8*, 0x8B) - 1);
                }
                if (select_air_dash(arg0) == 0) {
                    func_8003D18C(arg0);
                    func_8003D394(arg0);
                    if (M2C_FIELD(arg0, s32*, 0x24) <= 0) {
                        player_set_animation_shooting(arg0, 0xB);
                        {
                            s32 m = -1;
                            s32 n = 7;
                            M2C_FIELD(arg0, s8*, 0x67) = m;
                            M2C_FIELD(arg0, u8*, 5) = n;
                        }
                        M2C_FIELD(arg0, u8*, 6) = 0;
                        return;
                    }
                    func_8003F508(arg0, 0xA);
                }
            }
        }
    }
}
