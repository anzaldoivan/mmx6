#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define H(p, o) M2C_FIELD(p, u16*, o)

void* alloc_class4_slot();
M2C_UNK clear_object_slot();
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800F5990[];

void func_800ED950(s32 arg0) {
    void* temp_v0;

    temp_v0 = alloc_class4_slot();
    if (temp_v0 != 0) {
        u8* t = D_800F5990;
        struct X4_EngineObj* e = &g_playthrough_state;
        B(temp_v0, 0) = 0x41;
        B(temp_v0, 1) = 3;
        B(temp_v0, 2) = 0;
        H(temp_v0, 0xA) = *(u16*)((M2C_FIELD(e, s8*, 0x2F) * 4) + t);
        H(temp_v0, 0xE) =
            *(u16*)(D_800F5990 + (M2C_FIELD(e, s8*, 0x2F) * 4) + 2);
    }
    clear_object_slot(arg0);
}
