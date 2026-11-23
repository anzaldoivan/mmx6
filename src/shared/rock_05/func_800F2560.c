// rolefeed (3.1 T4): func_800F2560 of src/rock_05/E9860.c
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
extern struct X4_PlayerObj g_Player;

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK animate_object();
void move_object();
extern s32 D_800F4148;
extern s16 D_800F4480;

void func_800F2560(void* arg0) {
    s16* q = &D_800970AE;

    M2C_FIELD(arg0, u8*, 0x3) = 1;
    move_object(arg0);
    animate_object(arg0);
    if ((D_800F4480 + 0x440) < *q) {
        if ((D_800F4480 + 0x3D8) < M2C_FIELD(arg0, s16*, 0xE)) {
            M2C_FIELD(arg0, s16*, 0xE) = (u16)D_800F4480 + 0x3D8;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, void**, 0x68) = &D_800F4148;
            M2C_FIELD(arg0, u8*, 0x5) = 7;
            M2C_FIELD(arg0, u8*, 0x6) = 0;
        }
    } else if ((D_800F4480 + 0x438) < M2C_FIELD(arg0, s16*, 0xE)) {
        M2C_FIELD(arg0, s16*, 0xE) = (u16)D_800F4480 + 0x438;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, void**, 0x68) = &D_800F4148;
        M2C_FIELD(arg0, u8*, 0x5) = 7;
        M2C_FIELD(arg0, u8*, 0x6) = 0;
    }
}
