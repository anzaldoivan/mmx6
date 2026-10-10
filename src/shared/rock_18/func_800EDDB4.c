#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EFBFC(void*, u8, s16, s16);
extern struct X4_EngineObj D_800CCED0;
extern s16 D_800F0E98[];

#define DIGIT(c, n)                                                            \
    func_800EFBFC(self, (c), self->x_pos.i.hi + D_800F0E98[(n)],               \
                  self->y_pos.i.hi + D_800F0E98[(n) + 1])

#define PAIR(v, n)                                                             \
    {                                                                          \
        hi_ = (v) / 10;                                                        \
        lo_ = (v) % 10;                                                        \
        DIGIT(hi_ + 0x3F, (n));                                                \
        DIGIT(lo_ + 0x3F, (n) + 2);                                            \
    }

void func_800EDDB4(struct X4_BaseObj* self) {
    s32 time;
    s32 lo_;
    s32 hi_;
    s32 hours;
    s32 minutes;
    s32 seconds;

    if ((u32)((u8)D_800CCED0.character_state.bytes[0] - 1) < 8U) {
        time = ((s32*)&D_800CCED0)[0x43C / 4];
    } else {
        time = ((s32*)&D_800CCED0)[0x90 / 4];
    }
    DIGIT(0x49, 4);
    DIGIT(0x4A, 10);
    if (time > 0x57E3F) {
        DIGIT(0x48, 0);
        DIGIT(0x48, 2);
        DIGIT(0x44, 6);
        DIGIT(0x48, 8);
        DIGIT(0x48, 12);
        DIGIT(0x48, 14);
    } else if (time <= 0) {
        DIGIT(0x3F, 0);
        DIGIT(0x3F, 2);
        DIGIT(0x3F, 6);
        DIGIT(0x3F, 8);
        DIGIT(0x3F, 12);
        DIGIT(0x3F, 14);
    } else {
        hours = time / 3600;
        minutes = time / 60;
        minutes -= hours * 60;
        seconds = time % 60;
        if (hours >= 100) {
            hours = 99;
        }
        PAIR(hours, 0);
        PAIR(minutes, 6);
        seconds = seconds * 100 / 60;
        PAIR(seconds, 12);
    }
    self->state = 2;
}
