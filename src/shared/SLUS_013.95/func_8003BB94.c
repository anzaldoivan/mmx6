#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
extern u8 D_801EF620[];
extern u8 D_801F49F4[];

#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)
#define FLD(p, T, o) (*(T)((u8*)(p) + (o)))

M2C_UNK func_8003BB94(void* arg0, M2C_UNK arg1, s8 arg2) {
    u8* self;
    u8* q;
    // !FAKE: retail loads the table offset into the first argument register
    register s32 t asm("$4");
    s32 a2r;
    u8 v;

    self = arg0;
    if (FLD(self, s8*, 0x2) == 0) {
        if (D_801F49F4[arg1] == 0) {
            FLD(self, u8**, 0x38) = SCRATCH_14 + *(s32*)(SCRATCH_14);
            q = SCRATCH_1C;
            t = *(s32*)q;
            FLD(self, volatile u8*, 0xDC) = 5;
        } else {
            FLD(self, u8**, 0x38) = SCRATCH_14 + *(s32*)(SCRATCH_14 + 0x28);
            q = SCRATCH_1C;
            t = *(s32*)(q + 0x48);
            FLD(self, volatile u8*, 0xDC) = 0x13;
        }
        // !FAKE: both outer arms share the offset add before the 0x3C store
        goto add;
    }
    v = D_801EF620[arg1];
    if (v == 0) {
        FLD(self, u8**, 0x38) = SCRATCH_14 + *(s32*)(SCRATCH_14);
        q = SCRATCH_1C;
        q = q + *(s32*)q;
    } else if (v == 1) {
        FLD(self, u8**, 0x38) = SCRATCH_14 + *(s32*)(SCRATCH_14 + 4);
        q = SCRATCH_1C;
        q = q + *(s32*)(q + 0x14);
    } else if (v == 2) {
        FLD(self, u8**, 0x38) = SCRATCH_14 + *(s32*)(SCRATCH_14 + 8);
        q = SCRATCH_1C;
        q = q + *(s32*)(q + 0x1C);
    } else {
        // !FAKE: arms without a slot skip the shared 0x3C store
        goto end;
    }
    // !FAKE: the inner arms skip the outer arms' offset add
    goto store;
add:
    q = q + t;
store:
    FLD(self, u8**, 0x3C) = q;
end:
    ((M2C_UNK(*)())set_animation_frame)(self, arg1, a2r);
}
