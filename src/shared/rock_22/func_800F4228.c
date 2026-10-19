#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
extern s32 D_8007429C;
extern M2C_UNK D_800FC734;
extern M2C_UNK D_800FC738;

void func_800F4228(struct X4_PlayerObj* arg0) {
    // volatile local view keeps retail store order (sched1 otherwise sinks byte stores)
    volatile struct X4_PlayerObj* v = arg0;
    s32 x;
    // !FAKE: numeric pin holds retail register for the store-run schedule
    register s32 t asm("$5");
    // !FAKE: numeric pin holds retail register for the store-run schedule
    register void* p asm("$3");
    // !FAKE: numeric pin holds retail register for the store-run schedule
    register s32 x3 asm("$3");
    s32 y3;
    // !FAKE: numeric pin holds retail register for the store-run schedule
    register void* q asm("$2");

    t = 1;
    q = &D_800FC738;
    p = &D_800FC734;
    x = v->x_vel.val;
    v->unk68 = q;
    v->state = t;
    v->on_screen = t;
    v->hp = t;
    t = v->y_vel.val;
    v->unk58 = &D_8007429C;
    v->unk16 = 0;
    v->unk54 = p;
    v->unk50 = p;
    v->unk60 = 3;
    x3 = x * 3;
    y3 = t * 3;
    v->x_vel.val = x3;
    arg0->y_vel.val = y3;
    func_800179A4(arg0, 0x11);
}
