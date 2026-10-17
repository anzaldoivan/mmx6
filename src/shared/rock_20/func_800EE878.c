#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 func_8001C5EC(u8);
M2C_UNK func_8002B838();
void func_800EFC74(u8** arg0);
s32 func_800EE95C(u8*, u8, s32);
extern u8 D_80097427;
extern struct X4_EngineObj D_800CCED0;
extern u8 D_800E9860[];

void func_800EE878(struct X4_MiscObj* arg0) {
    s32 i;
    u8 id;
    u8* p;
    u8* buf;

    buf = *(u8**)arg0;
    id = arg0->unk6;
    p = buf;
    for (i = 0x1FF; i >= 0; i--) {
        *p++ = 0;
    }
    __builtin_memcpy(*(u8**)arg0, D_800E9860 + 0x18, 3);
    (*(u8**)arg0)[2] = 0x13;
    if ((arg0->x_pos.bytes[0] = func_8001C5EC(id)) != 0 ||
        (func_800EFC74((u8**)arg0),
         (arg0->x_pos.bytes[0] = func_800EE95C(buf, id, 0x2000)) != 0)) {
        D_800CCED0.unk1 = 0x15;
        ((void (*)())func_8002B838)();
        D_80097427 = 0;
        D_800CCED0.unk3 = 0xD;
    }
}
