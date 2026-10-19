#include "common.h"

#define SCR_WORD (*(s32*)0x1F800000)

void func_80017630(s32, s32, s32, s32, void*);
extern s8 D_800970A2;
extern u8 D_800AF168[];

void func_80017E98(void) {
    s32 var_s0;
    u8* temp_s1;

    temp_s1 = D_800AF168 + SCR_WORD * 0xA000;
    var_s0 = 8;
    if (D_800970A2 == 1) {
        var_s0 = 0x11;
    }
    func_80017630(0, 0x80, 0x78, var_s0, temp_s1);
    func_80017630(0, 0x120, 0x78, var_s0, temp_s1);
}
