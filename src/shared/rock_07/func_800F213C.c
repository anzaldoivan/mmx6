// rolefeed (3.1 T4): func_800F213C of src/rock_07/E9860.c
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/x4.h"

M2C_UNK start_pad_vibration(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80029478(M2C_UNK, M2C_UNK, M2C_UNK);
extern struct X4_BackgroundObj background_objects[3];

#undef D_800CCEDC

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
s32 func_80030ECC();
s32 check_enemy_hits(void*);
void func_800F66FC(void*);
extern M2C_UNK D_8007433C;
extern void (*D_800F95E0[])(void*);
extern s32 D_800F9874;

void func_800F213C(void* arg0) {
    s32 r;
    s8 st;
    u16 t;

    animate_object();
    D_800F95E0[M2C_FIELD(arg0, s8*, 5)](arg0);
    func_800F66FC(arg0);
    if (M2C_FIELD(arg0, s8*, 5) != 2 && M2C_FIELD(arg0, s8*, 2) == 0) {
        D_800F9874++;
    }
    r = check_enemy_hits(arg0);
    if (r < 0) {
        D_8009711A = 1;
        M2C_FIELD(arg0, s8*, 4) = 2;
        M2C_FIELD(arg0, s8*, 5) = 0;
        return;
    }
    if (r > 0 && r != 0x7F) {
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        if ((u32)(r - 0x19) < 2) {
            M2C_FIELD(arg0, s16*, 0x88) = 2;
        } else {
            M2C_FIELD(arg0, s16*, 0x88) = 0x1E;
        }
        st = M2C_FIELD(arg0, s8*, 5);
        if (st == 8) {
            if (r == 7 || r == 0x10 || r == 0x2B) {
                M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
                M2C_FIELD(arg0, s16*, 0x88) = 0x78;
            }
        } else if (st == 7) {
            if (r == 7 || r == 0x10 || r == 0x2B) {
                M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
                M2C_FIELD(arg0, s16*, 0x88) = 0x78;
            } else if (M2C_FIELD(arg0, s8*, 0x8D) == 1 && r == 0x24) {
                M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
                M2C_FIELD(arg0, s16*, 0x88) = 0x2710;
                M2C_FIELD(arg0, s8*, 5) = 9;
                M2C_FIELD(arg0, s8*, 6) = 0;
            }
        } else if (r == 7 || r == 0x10 || r == 0x2B) {
            M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
            M2C_FIELD(arg0, s16*, 0x88) = 0x2710;
            M2C_FIELD(arg0, s8*, 5) = 3;
            M2C_FIELD(arg0, s8*, 6) = 0;
        }
    }
    t = M2C_FIELD(arg0, u16*, 0x88);
    if (M2C_FIELD(arg0, s16*, 0x88) != 0) {
        M2C_FIELD(arg0, s16*, 0x88) = t - 1;
        if (t & 2) {
            M2C_FIELD(arg0, u16*, 0x42) |= 0x8000;
        } else {
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
        if (M2C_FIELD(arg0, s16*, 0x88) == 0) {
            M2C_FIELD(arg0, void**, 0x58) = &D_8007555C;
            M2C_FIELD(arg0, u16*, 0x42) &= 0x7FFF;
        }
    }
    func_80030ECC(arg0);
}
