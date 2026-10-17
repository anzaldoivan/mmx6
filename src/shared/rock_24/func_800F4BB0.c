#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80017A04(void*);
void func_80027BA0(s32, s32, s32, void*);
void* func_8002C458();
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern u8 D_8008EAFC;
extern u8 D_800F7588;

void func_800F4BB0(u8* arg0) {
    s32 i;
    u8* obj;

    if (D_8008EAFC == 0) {
        func_80027BA0(0, 0xC80, 0x470, &D_800F7588);
        i = 0;
        do {
            obj = func_8002C458();
            if (obj != 0) {
                s32 b = arg0[0];

                obj[1] = 0x1A;
                obj[2] = i + 0xF;
                *(u8**)(obj + 0x7C) = arg0;
                obj[0] = b;
            }
            i++;
        } while (i < 6);
        *(s16*)(arg0 + 0x7C) = 2;
        arg0[6]++;
    }
    func_80017A04(arg0);
    func_8002D230(arg0);
    func_8002CCB0(arg0, 0x30, 0x40);
}
