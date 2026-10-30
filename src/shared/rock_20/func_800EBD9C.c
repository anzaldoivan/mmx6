#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8001C5EC(u8);
void* alloc_sprite_slot();
void func_800ED45C();
extern u8 D_80097427;
extern u16 g_pad1_buttons[];
extern struct X4_EngineObj g_playthrough_state;
extern struct X4_MiscObj D_800E2F90;
extern u8 D_800F366C[];

void func_800EBD9C(u8* arg0) {
    s32 ret;
    s32 done;
    s32 n;
    u8* p;
    u8* obj;
    u8 idx;

    if (D_800E2F90.x_pos.bytes[2] != 0) {
        D_800E2F90.x_pos.bytes[2]--;
        return;
    }
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
    if (g_pad1_buttons[2] & 0xA000) {
        play_sound(0, 0xC, 0);
        g_playthrough_state.unkA ^= 1;
    }
    if (g_pad1_buttons[2] & 0x40) {
        play_sound(0, 0x22, 0);
        p = *(u8**)(D_800F366C + 0x1290);
        n = 0x5F;
        do {
            *p++ = 0;
        } while (n--);
        if (g_playthrough_state.unkA == 0) {
            idx = *(u8*)D_800E2F90.y_pos.val;
            if (idx != 0xFF) {
                obj = alloc_sprite_slot(idx);
                if (obj != 0) {
                    obj[0] = 1;
                    obj[1] = 0x2D;
                    ((s8*)obj)[2] = -0x41;
                }
                *(u8**)(D_800F366C + 0x1290) = obj;
                D_800E2F90.x_pos.bytes[2] = 3;
                *(s16*)(arg0 + 0xA) = 1;
                arg0[1] = arg0[1] + 1;
                func_800ED45C();
                arg0[3] = 0xA;
                return;
            }
            D_800E2F90.x_pos.bytes[2] = 3;
            arg0[3] = 0xB;
            arg0[1] = arg0[1] + 2;
            return;
        }
        arg0[3] = 8;
        arg0[1] = arg0[1] - 1;
        func_800ED45C();
    }
}
