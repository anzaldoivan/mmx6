#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s8 func_8001C1AC(u8);
s32 memcard_read_save_file(s32, u8, s32);
s32 memcard_list_files(u8, void*, void*);
s32 func_8001C5EC(u8);
s32 func_8001C8C4(void*);
M2C_UNK reset_level();
void* alloc_sprite_slot();
void func_800EC114(void);
void func_800ED3F4(s32, s32, s32, s32);
void func_800ED478(u8 arg0, s8 arg1, s16 arg2, s16 arg3, u8 arg4);
void func_800ED6D4(void*);
extern u8 D_8006D620;
extern struct X4_EngineObj D_80097420;
extern u8 D_80097427;
extern struct X4_MiscObj D_800E2F90;
extern u8 D_800E2FA0[];
extern u8 D_800E9864[];

#define AB_B(p, o) (*(u8*)((u8*)(p) + (o)))
#define AB_H(p, o) (*(s16*)((u8*)(p) + (o)))
#define AB_SB(p, o) (*(s8*)((u8*)(p) + (o)))

// str 0x800E9864 "BASLUS-01395" = "save file name (product code)"
void func_800EAAC0(u8* arg0) {
    // !FAKE: depin: dropping it breaks the match (147/183)
    register u8* self asm("$17") = arg0;
    u32 r;
    s32 t;
    s32 f;
    s16 i;
    u8* obj;
    u8* e;

    arg0 = 0;
    if (D_800E2F90.x_pos.bytes[2] != 0) {
        D_800E2F90.x_pos.bytes[2]--;
        return;
    }
    t = func_8001C5EC((u8)D_800E2F90.unk6);
    if (t != 0) {
        s32 one = 1;
        s32 two = 2;
        if (t == one) {
            AB_B(self, 1) = 5;
            D_800E2F90.x_pos.bytes[0] = one;
        } else {
            AB_B(self, 1) = 5;
            D_800E2F90.x_pos.bytes[0] = two;
        }
        AB_B(self, 3) = one;
        do {
            D_80097427 = 0;
        } while (0);
        f = 1;
    } else {
        f = 0;
    }
    if (f != 0) {
        return;
    }
    r = func_8001C1AC((u8)D_800E2F90.unk6);
    switch (r) {
    case 1:
        AB_B(self, 1) = 5;
        D_800E2F90.x_pos.bytes[0] = 0;
        AB_B(self, 3) = 1;
        return;
    case 2:
        AB_B(self, 1) = 5;
        D_800E2F90.x_pos.bytes[0] = 1;
        AB_B(self, 3) = r;
        return;
    case 3:
        AB_B(self, 1) = 5;
        D_800E2F90.x_pos.bytes[0] = 1;
        AB_B(self, 3) = 0x12;
        return;
    case 0:
        if (memcard_list_files((u8)D_800E2F90.unk6, D_800E2FA0, D_800E9864) !=
            0) {
            return;
        }
        if (D_800E2FA0[0x14A] != 0) {
            if (memcard_read_save_file(*(s32*)&D_800E2F90, (u8)D_800E2F90.unk6,
                                       0x2000) == 0) {
                func_8001C8C4((void*)D_800E2F90.y_pos.val);
                reset_level();
                AB_H(self, 4) = 1;
                func_800ED6D4(self);
                func_800ED3F4(0x9F, 0, 0x130, 0x1B);
                for (i = 0; i < 8; i++) {
                    func_800ED478(i - 0x60, 0, 0xB0, i * 16 + 0x30, i);
                }
                obj = alloc_sprite_slot();
                if (obj != 0) {
                    AB_B(obj, 0) = 1;
                    AB_H(obj, 0xA) = 0xE0;
                    AB_H(obj, 0xE) = 0xC8;
                    AB_B(obj, 1) = 0x2E;
                    AB_SB(obj, 2) = -0x10;
                }
                obj = alloc_sprite_slot();
                if (obj != 0) {
                    AB_B(obj, 0) = 1;
                    AB_B(obj, 1) = 0x2D;
                    AB_SB(obj, 2) = -0x40;
                }
                AB_B(self, 3) = 3;
                e = (u8*)&D_80097420;
                e[7] = D_8006D620;
                for (i = 0; i < e[7]; i++) {
                    D_800E2F90.y_pos.val += 0x3BC;
                }
                AB_B(self, 1)++;
                func_800EC114();
            }
        } else {
            AB_B(self, 3) = 2;
            D_800E2F90.x_pos.bytes[0] = 0;
            AB_B(self, 1) = 5;
        }
        break;
    }
}

#undef AB_B
#undef AB_H
#undef AB_SB
