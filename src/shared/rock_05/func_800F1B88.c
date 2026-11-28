// rolefeed (3.1 T4): func_800F1B88 of src/rock_05/E9860.c
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK clear_object_slot();
extern struct X4_PlayerObj g_Player;

#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK animate_object();
void* func_8002C458();
void func_800F2B4C();

void func_800F1B88(void* arg0) {
    s8 temp_s1;
    void* temp_v0;

    func_800F2B4C();
    animate_object(arg0);
    temp_s1 = M2C_FIELD(arg0, s8*, 0x45);
    if (temp_s1 == 1) {
        temp_v0 = func_8002C458();
        if (temp_v0 != 0) {
            M2C_FIELD(temp_v0, u8*, 0) = 0x41;
            M2C_FIELD(temp_v0, u8*, 1) = 0x12;
            M2C_FIELD(temp_v0, u8*, 2) = temp_s1;
            M2C_FIELD(temp_v0, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
            M2C_FIELD(temp_v0, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(temp_v0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(temp_v0, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
            M2C_FIELD(temp_v0, void**, 0x7C) = arg0;
            ((s32(*)(s32, s32, void*, void*))play_sound)(2, 0xC, arg0, temp_v0);
            play_sound(2, 0x23, arg0);
        }
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
