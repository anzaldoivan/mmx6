#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);

extern struct X4_BackgroundObj background_objects[3];
extern u16 D_800F4350[];
extern void (*D_800F4388[])(void*);
extern s16 D_800F4482;
extern s16 D_800F4484;
extern s16 D_800F4486;
extern s16 D_800F448E;

void func_800EF0FC(void* self) {
    u8* spad;
    u8 st;

    D_800F4388[M2C_FIELD(self, s8*, 5)](self);
    M2C_FIELD(SPAD, u16*, 0x96)++;
    M2C_FIELD(SPAD, u16*, 0x96) = (u8)M2C_FIELD(SPAD, u16*, 0x96);
    st = M2C_FIELD(SPAD, u8*, 0x8B);
    if (st == 3 || st == 1) {
        if (D_800F448E == 0) {
            func_80016C48(2, 2, self);
            ((void (*)(s32))func_80012D9C)(4);
            D_800F448E = 1;
        }
        spad = SPAD;
        if ((s16)((s16)M2C_FIELD(spad, u16*, 0x96) % 10) == 0) {
            u8 idx;
            M2C_FIELD(spad, u8*, 0x8A)++;
            M2C_FIELD(SPAD, u8*, 0x8A) &= 3;
            idx = M2C_FIELD(SPAD, u8*, 0x8A);
            background_objects[1].unk4C = 1;
            background_objects[1].unk40 =
                (D_800F4350[idx] - D_800F4486) + D_800F4482;
        }
        background_objects[1].y_pos.u.hi -= 2;
        if ((s16)background_objects[1].y_pos.u.hi <= D_800F4484 + 0x900) {
            func_80016C48(2, 3, self);
            M2C_FIELD(SPAD, u8*, 0x8B) = 0;
        }
    } else if (st == 4 || st == 2) {
        if (D_800F448E == 0) {
            func_80016C48(2, 2, self);
            ((void (*)(s32))func_80012D9C)(4);
            D_800F448E = 1;
        }
        spad = SPAD;
        if ((s16)((s16)M2C_FIELD(spad, u16*, 0x96) % 10) == 0) {
            u8 idx;
            M2C_FIELD(spad, u8*, 0x8A)++;
            M2C_FIELD(SPAD, u8*, 0x8A) &= 3;
            idx = M2C_FIELD(SPAD, u8*, 0x8A);
            background_objects[1].unk4C = 1;
            background_objects[1].unk40 =
                (D_800F4350[idx] - D_800F4486) + D_800F4482;
        }
        background_objects[1].y_pos.u.hi += 2;
        if ((s16)background_objects[1].y_pos.u.hi >= D_800F4484 + 0xBA0) {
            func_80016C48(2, 3, self);
            M2C_FIELD(SPAD, u8*, 0x8B) = 0;
        }
    }
}
