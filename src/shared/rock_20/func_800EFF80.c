#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK reset_level();
void* alloc_sprite_slot();
struct X4_QuadObj* alloc_class6_slot(void);
M2C_UNK func_800F03B8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);

void func_800EFF80(u8* arg0) {
    s32 k;
    struct X4_QuadObj* q;
    s8* obj;

    arg0[2] = arg0[2] + 1;
    reset_level();
    func_800F03B8(0x25, 0, 0x130, 0x30);
    k = 0x10;
    q = alloc_class6_slot();
    if (q != 0) {
        q->active = 1;
        q->id = k;
        q->unk2 = k;
    }
    obj = alloc_sprite_slot();
    if (obj != 0) {
        obj[0] = 1;
        *(s16*)(obj + 0xA) = 0xE0;
        *(s16*)(obj + 0xE) = 0x58;
        obj[1] = 0x2E;
        obj[2] = -0x10;
    }
    arg0[3] = 6;
}
