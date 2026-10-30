#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK clear_object_slot();
M2C_UNK func_8002CB50();
s32 func_8002CBFC(s32, M2C_UNK, M2C_UNK);
M2C_UNK func_80030ECC(void*);
s32 check_enemy_hits(void*);
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049E50(void*);
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_800F7694;
extern void (*D_800F7738[])(void*);

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))
#define FU8(p, o) (*(u8*)((u8*)(p) + (o)))
#define F16(p, o) (*(s16*)((u8*)(p) + (o)))
#define F32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_800ED584(void* arg0) {
    void* sub;
    s32 dir;

    sub = *(void**)((u8*)arg0 + 0x7C);
    if (check_enemy_hits(arg0) < 0 || F8(sub, 4) == 2 || F8(sub, 5) == 5) {
        if (F8(arg0, 2) == 2) {
            func_800477E4(2, &D_800F7694, arg0);
            func_80049E50(arg0);
        }
        F8(arg0, 4) = 2;
        return;
    }
    func_80030ECC(arg0);
    D_800F7738[F8(arg0, 5)](arg0);
    if (func_8002CBFC(arg0, 0x40, 0x40) == 0) {
        func_8002CB50(arg0);
    } else {
        if (F8(arg0, 2) != 2) {
            return;
        }
        if (F16(arg0, 0xE) - background_objects[F8(arg0, 0x14)].y_pos.i.hi >=
            0x12D) {
            clear_object_slot(arg0);
        }
    }
    if (F8(arg0, 2) == 2) {
        if (FU8(arg0, 0x70) & 8) {
            F8(arg0, 0x67) = 0;
            return;
        }
        dir = F32(arg0, 0x24);
        if (dir >= 0) {
            dir = 1;
        } else {
            dir = -1;
        }
        F8(arg0, 0x67) = dir;
    }
}
