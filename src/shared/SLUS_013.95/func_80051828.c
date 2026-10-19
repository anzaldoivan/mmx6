#include "common.h"
#include "mmx6/x4.h"

struct X4_VisualObj* func_8002C398(void);

void func_80051828(struct X4_PlayerObj* arg0, s8 arg1, s8 arg2) {
    struct X4_VisualObj* obj;

    obj = func_8002C398();
    if (obj != 0) {
        obj->active = 0x49;
        obj->id = arg1;
        obj->unk2 = arg2;
        obj->bg_offset = arg0->bg_offset;
        obj->unk50 = arg0;
    }
}
