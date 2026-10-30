#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

#include "mmx6/x4.h"

void func_80017A04(struct X4_AnimatedObj*);
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003D10C(void*);
M2C_UNK func_801EBF28();
extern struct X4_EngineObj g_playthrough_state;

void func_801EB61C(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x8F) != 0) {
        func_801EBF28(arg0);
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x90) != 0) {
        func_8003D10C(arg0);
        return;
    }
    if (M2C_FIELD(arg0, u8*, 0x17) == 6) {
        struct X4_EngineObj* e =
            (struct X4_EngineObj*)((s8*)&g_playthrough_state -
                                   -M2C_FIELD(arg0, s8*, 2));
        if (M2C_FIELD(arg0, s8*, 0x5C) >= (s8)(M2C_FIELD(e, s8*, 0x5B) / 3)) {
            func_8003BA04(arg0, 5);
            return;
        }
    }
    func_80017A04(arg0);
}
