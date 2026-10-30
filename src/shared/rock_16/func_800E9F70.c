#include "common.h"

void* alloc_sprite_slot();
extern s32 D_800F0E74[];
extern u8 D_800F0EEC[];
extern u8 D_800F0EF4[];

void func_800E9F70(u8* arg0) {
    u8* obj;
    s32 i;

    if (arg0[0x5F] & 0x10) {
        for (i = 0; i < 2; i++) {
            obj = alloc_sprite_slot();
            if (obj != 0) {
                obj[0] = 1;
                obj[1] = 0x18;
                obj[2] = i;
            }
        }
    }
    for (i = 0; i < 0x18; i++) {
        if (*(s32*)(arg0 + 0x70) & D_800F0E74[i]) {
            obj = alloc_sprite_slot();
            if (obj != 0) {
                obj[0] = 1;
                obj[1] = 0x28;
                obj[2] = i;
            }
        }
    }
    for (i = 0; i < 8; i++) {
        if (arg0[0x69] & D_800F0EEC[i]) {
            obj = alloc_sprite_slot();
            if (obj != 0) {
                obj[0] = 1;
                obj[1] = 0x28;
                obj[2] = i + 0x18;
            }
        }
    }
    for (i = 0; i < 6; i++) {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x28;
            obj[2] = i + 0x20;
        }
    }
    for (i = 0; i < 2; i++) {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x28;
            obj[2] = i + 0x26;
        }
    }
    for (i = 0; i < 5; i++) {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x28;
            obj[2] = i + 0x28;
        }
    }
    for (i = 0; i < 5; i++) {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x28;
            obj[2] = i + 0x2D;
        }
    }
    for (i = 0; i < 5; i++) {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x28;
            obj[2] = i + 0x32;
        }
    }
    for (i = 0; i < 2; i++) {
        obj = alloc_sprite_slot();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x28;
            obj[2] = i + 0x37;
        }
    }
    for (i = 0; i < 4; i++) {
        if (arg0[0x5F] & D_800F0EF4[i]) {
            obj = alloc_sprite_slot();
            if (obj != 0) {
                obj[0] = 1;
                obj[1] = 0x28;
                obj[2] = i + 0x39;
            }
        }
    }
}
