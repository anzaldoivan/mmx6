#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);

extern struct X4_BackgroundObj D_800971F8[3];
extern void (*D_800F3FC4[])(void*);

void func_800EC77C(void* self) {
    struct X4_BackgroundObj* bg;
    void* a;
    void* b;

    D_800F3FC4[M2C_FIELD(self, s8*, 6)](self);
    if ((u32)(M2C_FIELD(self, u8*, 2) - 8) < 2) {
        bg = D_800971F8;
        bg[2].y_pos.val += 0xFFFF0000;
        a = M2C_FIELD(self, void**, 0x84);
        b = M2C_FIELD(self, void**, 0x88);
        M2C_FIELD(a, u16*, 0x90)++;
        M2C_FIELD(b, u16*, 0x90)++;
        if (M2C_FIELD(self, s16*, 0x7E)++ >= 0x70) {
            func_80016C48(5, 3, self);
            bg[2].unk3 = 0;
            if (M2C_FIELD(self, s8*, 6) == 4 && bg[1].unk3 == 0) {
                bg[0].unk28 = 0xB00;
                bg[0].unk2A = 0x3B0;
                M2C_FIELD(self, s8*, 4) = 3;
                M2C_FIELD(a, s8*, 4) = 2;
                M2C_FIELD(b, s8*, 4) = 2;
            }
        }
    }
}
