#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK move_object();
void func_800EAB04(void*);
extern s16 D_800970AA;
extern u16 D_80097202;
#define D_80097202 (*(s16*)&D_80097202)
extern u8 D_800FB26C[];

void func_800EA220(void* self) {
    ((void (**)(void*))(D_800FB26C + 0xB94))[M2C_FIELD(self, s8*, 0x6)](self);
    move_object(self);
    {
        // !FAKE: depin: dropping it breaks the match (72/76)
        register u8* p asm("$2") = SPAD;
        if (p[0x88] == 0) {
            if ((M2C_FIELD(self, u8*, 0x15) == 0 &&
                 M2C_FIELD(self, s16*, 0xA) < D_80097202 + 0xA0) ||
                (M2C_FIELD(self, u8*, 0x15) == 0x40 &&
                 D_80097202 + 0xA0 < M2C_FIELD(self, s16*, 0xA))) {
                SPAD[0x88] = 1;
                func_800EAB04(self);
                M2C_FIELD(self, u8*, 0x5) = 2;
                M2C_FIELD(self, u8*, 0x6) = 0;
            }
        }
    }
    if ((M2C_FIELD(self, u8*, 0x15) == 0 &&
         D_800970AA > M2C_FIELD(self, s16*, 0xA)) ||
        (M2C_FIELD(self, u8*, 0x15) == 0x40 &&
         D_800970AA < M2C_FIELD(self, s16*, 0xA))) {
        M2C_FIELD(self, u8*, 0x5) = 2;
        M2C_FIELD(self, u8*, 0x6) = 0;
    }
}
#undef D_80097202
