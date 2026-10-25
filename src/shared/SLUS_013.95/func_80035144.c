#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();               /* extern */
M2C_UNK func_8002D5D0(void*);          /* extern */
void func_8003AD18(void* arg0);        /* extern */
M2C_UNK func_8003BA04(void*, M2C_UNK); /* extern */
M2C_UNK func_8003CCBC();               /* extern */
void func_8003D394(void* arg0);        /* extern */
M2C_UNK func_8003D630(void*);          /* extern */
M2C_UNK func_8003D718(void*);          /* extern */
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CCEEC;

void func_80035144(void* arg0) {
    s8 temp_v0;

    ((void (*)())func_80017A04)();
    if (M2C_FIELD(arg0, s8*, 6) == 0) {
        if (M2C_FIELD(arg0, s8*, 0xCE) != 0) {
            if (--M2C_FIELD(arg0, s8*, 0xCE) == 0) {
                func_8003CCBC(arg0);
            }
            func_8002D5D0(arg0);
            return;
        }
        if (M2C_FIELD(arg0, u8*, 0x89) & 8) {
            func_8003BA04(arg0, 2);
            M2C_FIELD(arg0, s8*, 0x67) = 0;
            background_objects[0].unk44 = 1;
            background_objects[1].unk44 = 1;
            background_objects[2].unk44 = 1;
            M2C_FIELD(arg0, s8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
            return;
        }
        func_8002D5D0(arg0);
        func_8003D394(arg0);
        return;
    }
    if (M2C_FIELD(arg0, s8*, 0x45) != 0) {
        M2C_FIELD(arg0, s8*, 0x45) = 0;
        func_8003D718(arg0);
        func_8003D630(arg0);
    }
    if (M2C_FIELD(arg0, s8*, 0x46) == 0) {
        D_800CCEEC = 0;
        if (M2C_FIELD(arg0, s8*, 2) != 0) {
            func_8003D718(arg0);
            func_8003D630(arg0);
        }
        func_8003AD18(arg0);
    }
}
