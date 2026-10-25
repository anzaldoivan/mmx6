/* Adapted from sozud/mmx4 @6a6b455 src/main/weapons/weapon_00_lemon.c:lemon_main, AGPL-3.0; proven shared with X6 by exact signature e25d4c5c1482 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
void func_801EE4DC(struct X4_AnimatedObj*);
void func_801EE538(struct X4_WeaponObj*);
void func_801EE638(void* arg0);
#define M2C_UNK s32
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
void func_80017A04(struct X4_AnimatedObj*);
s32 func_8002CBFC(struct X4_BaseObj*, s32, s32);

void func_801EE458(struct X4_WeaponObj* arg0) {
    if (func_8002CBFC(BASE_OBJECT(arg0), 0xC, 8) == 0) {
        func_80017A04(ANIMATED_OBJECT(arg0));
        if (arg0->unk98 == 0) {
            func_801EE4DC(ANIMATED_OBJECT(arg0));
            func_8002CCB0(BASE_OBJECT(arg0), 0xC, 8);
            return;
        }
        func_801EE538(arg0);
        return;
    }
    func_801EE638(arg0);
}
