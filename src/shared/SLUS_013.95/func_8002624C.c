#include "common.h"

u8 func_8002624C(u8 from, u8 to, s32 den, s32 t) {
    if (from == to || den == t) {
        return from;
    }
    if (t == 0) {
        return to;
    }
    if (to < from) {
        return to + (u32)((from - to) * t) / (u32)den;
    }
    return from + (u32)((to - from) * (den - t)) / (u32)den;
}
