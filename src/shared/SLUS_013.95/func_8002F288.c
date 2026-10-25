#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern u8 D_800E4190;
extern u8 D_800E4191;
extern s16 D_800E41A4;
void func_8002F418(struct X4_PlayerObj* arg0);
void func_8002F5FC(struct X4_PlayerObj* arg0);
void func_8002F71C(struct X4_PlayerObj* arg0);
void func_8002F840(struct X4_PlayerObj* arg0);
s32 func_8002FBEC(struct X4_PlayerObj* arg0);
void func_800304D8();
void func_8003056C(s32 arg0);
void func_800305B0(s32 arg0);
void func_800306F4(struct X4_PlayerObj* arg0);
s32 func_8003091C();

void func_8002F288(struct X4_PlayerObj* arg0) {
    s32 temp_v1;

    arg0->unk70 = 0;
    arg0->touching_spikes = 0;
    if (arg0->unk68 != 0) {
        func_800304D8();
        D_800E4190 = 0;
        D_800E4191 = 0;
        temp_v1 = arg0->x_pos.val - arg0->unk18.val;
        if (temp_v1 != 0) {
            if (temp_v1 > 0) {
                func_8002F71C(arg0);
            } else {
                func_8002F5FC(arg0);
            }
        }
        if ((arg0->y_pos.val - arg0->unk1C.val) >= 0) {
            if ((arg0 != &g_Player) || !(arg0->unk72 & 8)) {
                func_8002F840(arg0);
                if (D_800E4190 != 0) {
                    return;
                }
            }
        } else {
            func_800306F4(arg0);
        }
        if (D_800E4191 & 0xC) {
            if (D_800E4191 & 4) {
                D_800E4191 |= 4;
            }
            if (D_800E4191 & 3) {
                if ((D_800E4191 & 4) || (D_800E41A4 >= -8)) {
                    func_8003056C((s32)arg0);
                } else {
                    func_800305B0((s32)arg0);
                }
            } else {
                func_8003091C(arg0);
            }
        } else if (D_800E4191 & 3) {
            func_8002FBEC(arg0);
        }
        func_8002F418(arg0);
    }
}

#undef g_Player
