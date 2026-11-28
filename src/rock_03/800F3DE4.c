#include "common.h"
#include "mmx6/rock_03.h"
#define M2C_UNK s32

M2C_UNK animate_object();
void* func_8002C458();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK apply_object_motion(void*);
s32 func_80030ECC();

#define B(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))
#define P(p, o) (*(void**)((u8*)(p) + (o)))

#define SPAWN(dx, k, dy)                                                       \
    {                                                                          \
        child = func_8002C458();                                               \
        if (child != 0) {                                                      \
            u8 id = B(arg0, 0);                                                \
            B(child, 1) = 0xF;                                                 \
            B(child, 2) = 3;                                                   \
            P(child, 0x7C) = arg0;                                             \
            B(child, 0) = id;                                                  \
            H(child, 0xA) = H(arg0, 0xA) + (dx);                               \
            H(child, 0xE) = H(arg0, 0xE) + (dy);                               \
            B(child, 7) = (k);                                                 \
        }                                                                      \
    }

#include "../shared/rock_03/func_800F3DE4.c"

#include "../shared/commander_yammark/func_800F3FB0.c"
