#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* alloc_class4_slot();
M2C_UNK clear_object_slot();
M2C_UNK func_8002CA54();

void func_800EC25C(void* arg0) {
    void* e;

    e = alloc_class4_slot();
    if (e != 0) {
        u8 t = M2C_FIELD(arg0, u8*, 0);
        M2C_FIELD(e, u8*, 1) = 1;
        M2C_FIELD(e, u8*, 0) = t;
        M2C_FIELD(e, u8*, 2) = M2C_FIELD(arg0, u8*, 2);
        M2C_FIELD(e, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(e, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
        M2C_FIELD(e, s32*, 0x10) = M2C_FIELD(arg0, s32*, 0x10);
        M2C_FIELD(e, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
        M2C_FIELD(e, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42);
        M2C_FIELD(e, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
        clear_object_slot(arg0, e);
        return;
    }
    func_8002CA54(arg0);
}
