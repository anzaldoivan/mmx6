#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*);
extern s32 D_800FC9A0;
extern void (*D_800FCB88[])(void*);
extern s8 D_800FD51C;

// str 0x800FC9A0 sha1=44c6d6c2ecd801e25abad8013bf897c534962379 = "printable byte run: a table, not text"
void func_800F39A8(void* arg0) {
    if (D_800FD51C == 0) {
        if (M2C_FIELD(arg0, s8*, 6) != 3) {
            ((void (*)(s32, void*, void*))func_800477E4)(4, &D_800FC9A0, arg0);
        }
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 4) = 3;
        M2C_FIELD(arg0, s8*, 6) = 0;
        return;
    }
    D_800FCB88[M2C_FIELD(arg0, s8*, 6)](arg0);
}
