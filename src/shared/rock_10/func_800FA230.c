#include "common.h"

s32 random_byte();

#define M2C_UNK s32
M2C_UNK move_object(s32);
void func_800FA230(void* arg0) {
    u8* self = arg0;
    u8* temp_s1;

    temp_s1 = *(u8**)(self + 0x7C);
    if (random_byte() & 1) {
        temp_s1[7] = 1;
        if (self[0x15] == 0) {
            self[0x15] = 0x40;
        } else {
            self[0x15] = 0;
        }
        self[6] = 3;
    } else {
        temp_s1[7] = 2;
        ((void (*)())move_object)(self);
        self[6] = 4;
    }
}
