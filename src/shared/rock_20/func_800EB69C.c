#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8001C5EC(u8);
void* alloc_sprite_slot();
extern u8 D_80097427;
extern u16 D_800C4570;
extern struct X4_MiscObj D_800E2F90;
extern u8 D_800F366C[];

void func_800EB69C(u8* arg0) {
    s32 ret;
    s32 done;
    u8* obj;

    ret = func_8001C5EC(D_800E2F90.unk6);
    if (ret != 0) {
        s32 one = 1;
        s32 two = 2;

        if (ret == one) {
            arg0[1] = 0x15;
            D_800E2F90.x_pos.bytes[0] = one;
        } else {
            arg0[1] = 0x15;
            D_800E2F90.x_pos.bytes[0] = two;
        }
        arg0[3] = one;
        do {
            D_80097427 = 0;
        } while (0);
        done = 1;
    } else {
        done = 0;
    }
    if (done != 0) {
        return;
    }
    if (D_800C4570 & 0x40) {
        play_sound(0, 0x22, 0);
        arg0[3] = 7;
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x2D;
            ((s8*)obj)[2] = -0x42;
        }
        *(u8**)(D_800F366C + 0x1290) = obj;
        *(s16*)(arg0 + 0xA) = 1;
        arg0[2] = arg0[2] + 1;
    }
}
