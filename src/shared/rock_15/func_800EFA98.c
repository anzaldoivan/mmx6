#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);

extern void (*D_800F67AC[])(void*);
extern void* D_800F70E4;

#define U8(o) M2C_FIELD(self, u8*, o)
#define S8(o) M2C_FIELD(self, s8*, o)

void func_800EFA98(void* self) {
    if (M2C_FIELD(D_800F70E4, s8*, 4) != 1) {
        U8(3) = 0;
        U8(4)++;
        return;
    }
    func_80017A04(self);
    func_8002CCB0(self, 0x20, 0x20);
    (*(void (**)(void*))((S8(5) << 2) + (s32)D_800F67AC))(self);
}
