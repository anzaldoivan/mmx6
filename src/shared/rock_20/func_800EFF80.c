#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002B838();
void* func_8002C530();
struct X4_QuadObj* func_8002C7F0(void);
M2C_UNK func_800F03B8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);

void func_800EFF80(u8* arg0) {
    s32 k;
    struct X4_QuadObj* q;
    s8* obj;

    arg0[2] = arg0[2] + 1;
    func_8002B838();
    func_800F03B8(0x25, 0, 0x130, 0x30);
    k = 0x10;
    q = func_8002C7F0();
    if (q != 0) {
        q->active = 1;
        q->id = k;
        q->unk2 = k;
    }
    obj = func_8002C530();
    if (obj != 0) {
        obj[0] = 1;
        *(s16*)(obj + 0xA) = 0xE0;
        *(s16*)(obj + 0xE) = 0x58;
        obj[1] = 0x2E;
        obj[2] = -0x10;
    }
    arg0[3] = 6;
}
