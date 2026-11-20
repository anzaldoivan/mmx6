#include "common.h"

void func_80013BD0(s32* start, s32* end) {
    do {
        *(volatile s32*)start = 0;
    } while (end != start && (start++, 1));
}
