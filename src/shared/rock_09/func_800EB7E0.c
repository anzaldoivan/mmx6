// rolefeed (3.1 T4): func_800EB7E0 of src/rock_09/E9860.c
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_PlayerObj g_Player;

void func_800E9970(s8* self, s8* parent);
void func_800E9A60(struct X4_VisualObj* arg0, struct X4_PlayerObj* arg1);

#include "common.h"

void* enemy_slot_alloc();
extern u8 D_800F4BF0[];

void func_800EB7E0(u8* arg0) {
    s32 i;
    u8* p;

    if ((arg0[0x70] & 8) && (*(s8*)(arg0 + 7) == 5)) {
        i = 1;
        do {
            p = enemy_slot_alloc();
            if (p != 0) {
                p[0] = arg0[0];
                p[1] = arg0[1];
                p[2] = i;
                *(u8**)(p + 0x80) = arg0;
            }
            i++;
        } while (i < 7);
        arg0[7] = 4;
    }
    if (*(s8*)(arg0 + 7) == 0 && *(void**)(arg0 + 0x54) == 0) {
        *(void**)(arg0 + 0x54) = D_800F4BF0 + 0x10C4;
    }
}
