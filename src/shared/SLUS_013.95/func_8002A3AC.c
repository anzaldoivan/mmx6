#include "common.h"
#include "mmx6/x4.h"

extern struct X4_AnimatedObj* (*D_8007347C[])();

struct X4_AnimatedObj* func_8002A3AC(u8 arg0) {
    return D_8007347C[arg0 & 0xF]();
}
