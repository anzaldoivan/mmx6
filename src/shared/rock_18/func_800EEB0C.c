#include "common.h"
#include "mmx6/x4.h"

void func_800EFBFC(void*, u8, s16, s16);
extern s16 D_800F0EB8[];

#define PART(c, n, dx, dy)                                                     \
    func_800EFBFC(self, (c), self->x_pos.i.hi + D_800F0EB8[(n)] + (dx),        \
                  self->y_pos.i.hi + D_800F0EB8[(n) + 1] + (dy))

void func_800EEB0C(struct X4_BaseObj* self) {
    PART(0xD8, 4, 0, 0);
    PART(0xD9, 10, 0, 0);
    PART(0xDA, 0, 0x74, 4);
    PART(0xDA, 2, 0x74, 4);
    PART(0xDA, 6, 0x74, 4);
    PART(0xDA, 8, 0x74, 4);
    PART(0xDA, 12, 0x74, 4);
    PART(0xDA, 14, 0x74, 4);
    self->state = 2;
}
