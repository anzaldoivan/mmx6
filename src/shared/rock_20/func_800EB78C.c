#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, M2C_UNK);
s32 func_8001C5EC(u8);
M2C_UNK reset_level();
void* alloc_sprite_slot();
struct X4_QuadObj* alloc_class6_slot(void);
M2C_UNK func_800F03B8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
extern u8 D_80097427;
extern u16 g_pad1_buttons[];
extern struct X4_EngineObj g_playthrough_state;
extern struct X4_MiscObj D_800E2F90;
extern u8 D_800F366C[];

void func_800EB78C(u8* arg0) {
    s32 ret;
    s32 done;
    s32 n;
    u8* p;
    u8* obj;
    struct X4_QuadObj* q;

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
            *p = 0;
            p++;
        } while (n--);
        if (g_playthrough_state.unkA == 0) {
            s32 k = 0x10;

            ((void (*)())reset_level)();
            func_800F03B8(0x26, 0, 0x130, 0x30);
            q = alloc_class6_slot();
            if (q != 0) {
                q->active = 1;
                q->id = k;
                q->unk2 = k;
            }
            obj = alloc_sprite_slot();
            if (obj != 0) {
                obj[0] = 1;
                *(s16*)(obj + 0xA) = 0xE0;
                *(s16*)(obj + 0xE) = 0x58;
                obj[1] = 0x2E;
                ((s8*)obj)[2] = -0x10;
            }
            arg0[3] = 0xE;
            D_800E2F90.x_pos.bytes[2] = 3;
            arg0[2] = arg0[2] + 1;
            return;
        }
        ((void (*)())reset_level)();
        arg0[1] = 6;
        arg0[2] = 6;
        arg0[3] = 0;
    }
}
