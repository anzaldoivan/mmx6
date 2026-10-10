#include "common.h"
#include "mmx6/x4.h"

void func_800EFBFC(void*, u8, s16, s16);
extern struct X4_EngineObj D_800CCED0;
extern s16 D_800F0EB8[];

#define TIME(e, i) (((s32*)(e))[0x43C / 4 + (i)])
#define TIMEP(e, i) (*(s32*)((u8*)(e) + (i) * 4 + 0x43C))
#define TIMES(e) ((s32*)((u8*)(e) + 0x43C))

#define DIGIT(c, n)                                                            \
    func_800EFBFC(self, (c), self->x_pos.i.hi + D_800F0EB8[(n)],               \
                  self->y_pos.i.hi + D_800F0EB8[(n) + 1])

#define PAIR(v, n)                                                             \
    {                                                                          \
        hi_ = (v) / 10;                                                        \
        lo_ = (v) % 10;                                                        \
        DIGIT(hi_ + base, (n));                                                \
        DIGIT(lo_ + base, (n) + 2);                                            \
    }

void func_800EE368(struct X4_BaseObj* self) {
    struct X4_EngineObj* e = &D_800CCED0;
    s32* best;
    s32* times;
    s32 time;
    s32 base;
    s32 lo_;
    s32 hi_;
    s32 hours;
    s32 minutes;
    s32 seconds;

    if (TIME(e, 0) == 0 || e->character_state.bytes[1] != 0) {
        time = TIME(&D_800CCED0, D_800CCED0.character_state.bytes[0]);
        base = 0xCE;
    } else {
        times = TIMES(e);
        best = &times[e->character_state.bytes[0]];
        if (TIME(e, 0) < *best) {
            *best = TIME(e, 0);
            base = 0xC2;
        } else {
            base = 0xCE;
        }
        time = TIME(&D_800CCED0, D_800CCED0.character_state.bytes[0]);
    }
    DIGIT(base + 0xA, 4);
    DIGIT(base + 0xB, 10);
    if (time > 0x57E3F) {
        DIGIT(base + 9, 0);
        DIGIT(base + 9, 2);
        DIGIT(base + 5, 6);
        DIGIT(base + 9, 8);
        DIGIT(base + 9, 12);
        DIGIT(base + 9, 14);
    } else if (time <= 0) {
        DIGIT(base, 0);
        DIGIT(base, 2);
        DIGIT(base, 6);
        DIGIT(base, 8);
        DIGIT(base, 12);
        DIGIT(base, 14);
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
