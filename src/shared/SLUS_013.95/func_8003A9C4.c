#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002D2D4();
M2C_UNK func_8003CFE0(void*, M2C_UNK);
void func_8003D18C(void* arg0);
void player_set_animation_shooting(struct X4_PlayerObj* self, s32 animation);
extern u8 D_80073CE4[];

void func_8003A9C4(struct X4_PlayerObj* self) {
    s8 state;

    M2C_FIELD(self, s8*, 0x84) = 1;
    M2C_FIELD(self, s8*, 0x86) = 1;
    if (M2C_FIELD(self, u16*, 0x80) & 0x80) {
        s32 temp = M2C_FIELD(self, s32*, 0xF8);
        M2C_FIELD(self, s8*, 0x67) = 1;
        {
            // !FAKE: depin: dropping it breaks the match (63/67)
            register s32 one asm("$3") = 1;
            M2C_FIELD(self, s8*, 0x8C) = one;
        }
        M2C_FIELD(self, s8*, 0x86) = 2;
        M2C_FIELD(self, s32*, 0x20) = 0;
        M2C_FIELD(self, s32*, 0x28) = 0;
        M2C_FIELD(self, s8*, 0x8B) = 0xA;
        M2C_FIELD(self, s32*, 0x24) = temp;
        M2C_FIELD(self, s32*, 0x2C) = M2C_FIELD(self, s32*, 0x134);
        ((void (*)())player_set_animation_shooting)(self, 0xA, temp);
        if (func_8002D2D4() & 4) {
            func_8003CFE0(self, D_80073CE4[(func_8002D2D4() & 3) +
                                           M2C_FIELD(self, s8*, 2) * 4]);
        }
        func_8003D18C(self);
        state = 6;
    } else {
        player_set_animation_shooting(self, 0x10);
        M2C_FIELD(self, s32*, 0x24) = 0;
        M2C_FIELD(self, s32*, 0x2C) = 0;
        M2C_FIELD(self, s32*, 0x28) = M2C_FIELD(self, s32*, 0x10C);
        if (M2C_FIELD(self, s32*, 0xEC) & 0x10) {
            M2C_FIELD(self, s8*, 0x85) = 0xF;
        } else {
            M2C_FIELD(self, s8*, 0x85) = 0x1E;
        }
        state = 0xC;
    }
    M2C_FIELD(self, s8*, 5) = state;
    do {
    } while (0);
    M2C_FIELD(self, s8*, 6) = 0;
}
