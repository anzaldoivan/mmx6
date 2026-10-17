#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();      /* extern */
s32 func_80039984(void*);     /* extern */
s32 func_8003A3DC(void*);     /* extern */
M2C_UNK func_8003AFF4(s32);   /* extern */
M2C_UNK func_8003B054(void*); /* extern */
void func_8003B360(void*);    /* extern */
s32 func_8003E174(void*);     /* extern */
extern void (*D_80073C10[])(void*);

void func_80037130(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x89) & 8) {
        ((void (*)())func_8003B054)();
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0xD3) != 0) {
        func_8003AFF4((s32)arg0);
        return;
    }
    if (func_80039984(arg0) != 0) {
        return;
    }
    if (func_8003A3DC(arg0) != 0) {
        return;
    }
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        if (func_8003E174(arg0) != 0) {
            return;
        }
        if (M2C_FIELD(arg0, s8*, 0x8E) != 0) {
            func_8003B360(arg0);
            return;
        }
    }
    func_80017A04(arg0);
    (*(void (**)(void*))((M2C_FIELD(arg0, s8*, 6) << 2) + (s32)D_80073C10))(
        arg0);
}
