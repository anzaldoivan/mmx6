#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define FX(p, type, off) (*(type*)((u8*)(p) + (off)))

M2C_UNK clear_object_slot();
void func_8002CCB0(struct X4_BaseObj*, s32, s32);
M2C_UNK func_8002F288(M2C_UNK*);
s32 check_enemy_hits(void*);
M2C_UNK func_80031DA8();
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
M2C_UNK func_80049EBC(void*, M2C_UNK, M2C_UNK, M2C_UNK);
extern M2C_UNK D_800F55DC;

void func_800EC614(void* arg0) {
    void* parent;
    s32 i;

    parent = FX(arg0, void*, 0x7C);
    FX(arg0, u16, 0x42) &= 0x7FFF;
    func_80031DA8();
    check_enemy_hits(arg0);
    func_8002F288(arg0);
    func_8002CCB0(arg0, 0x40, 0x20);
    if (FX(parent, s8, 0x4) == 3) {
        for (i = 4; i >= 0; i--) {
            func_80049EBC(arg0, 1, 0x10, 0x10);
        }
        func_800477E4(4, &D_800F55DC, arg0);
        FX(arg0, u8, 0x3) = 0;
        clear_object_slot(arg0);
    }
}
