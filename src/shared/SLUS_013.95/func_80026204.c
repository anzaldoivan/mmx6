#include "common.h"

void func_80026204(u16 color, u8* r, u8* g, u8* b) {
    u8 c;

    c = color & 0x1F;
    *r = (c << 3) + (c >> 2);
    c = (color >> 5) & 0x1F;
    *g = (c << 3) + (c >> 2);
    c = color >> 10;
    *b = (c << 3) + (c >> 2);
}
