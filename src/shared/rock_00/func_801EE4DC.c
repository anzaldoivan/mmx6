#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void move_object(struct X4_MovingObj*);
M2C_UNK func_8002EE10(void*);
void func_800383F8(void*);
void func_801EE638(void* arg0);

void func_801EE4DC(struct X4_AnimatedObj* arg0) {
    move_object(MOVING_OBJECT(arg0));
    if (*((u8*)arg0 + 0x70) == 0) {
        func_8002EE10(arg0);
        if (*((u8*)arg0 + 0x70) == 0) {
            return;
        }
    }
    func_800383F8(arg0);
    func_801EE638(arg0);
}
