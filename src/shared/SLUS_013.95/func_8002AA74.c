#include "common.h"

extern u8 D_800964A0[];

static inline void func_8002AA74_fill(u8* p, u8 c, u16 n) {
    while (n--) {
        *p++ = c;
    }
}

void func_8002AA74(void) {
    u8 c;
    u16 i;

    c = 0;
    for (i = 0; i < 32; i++) {
        func_8002AA74_fill(D_800964A0 + i * 96, c, 96);
    }
}
