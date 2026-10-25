#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80017B04(u8*, s16, s16);        /* extern */
void func_8002000C(void);                 /* extern */
void func_8002012C(void);                 /* extern */
void func_80020258(void);                 /* extern */
void func_80020378(void);                 /* extern */
void func_8002048C(void);                 /* extern */
void func_800205A0();                     /* extern */
void func_800206C0(void);                 /* extern */
void func_800207D4(void);                 /* extern */
void update_layer_objects(void);          /* extern */
void func_80020A08(void);                 /* extern */
M2C_UNK func_80020D74();                  /* extern */
void func_80020DC8(void);                 /* extern */
void func_8002927C(void);                 /* extern */
void func_8002935C(void);                 /* extern */
M2C_UNK func_800293CC();                  /* extern */
void func_80029D18(void);                 /* extern */
void func_8002ACA8();                     /* extern */
M2C_UNK func_8002E84C();                  /* extern */
void func_8002F288(struct X4_PlayerObj*); /* extern */
void func_80034DCC(void);                 /* extern */
extern M2C_UNK g_Player;
extern s32 D_801F6000;
#define D_801F6000 (*(s32*)0x801F6000)
#define D_801F68DC ((u16*)0x801F68DC)

#define P (*(struct X4_PlayerObj*)&g_Player)

void func_80021500(void) {
    struct X4_PlayerObj* p = &P;

    p->input.buttons.previous = p->input.buttons.held;
    if (D_801F6000 != 0x9C4) {
        p->input.buttons.held = D_801F68DC[D_801F6000];
        D_801F6000++;
    } else {
        p->input.buttons.held = 0;
    }
    p->pressed_input = p->input.buttons.held &
                       (p->input.buttons.held ^ p->input.buttons.previous);
    func_8002E84C();
    func_80020A08();
    func_80034DCC();
    func_8002012C();
    update_layer_objects();
    func_8002000C();
    func_80020258();
    func_80020378();
    func_800205A0();
    func_800206C0();
    func_800207D4();
    func_80029D18();
    func_8002048C();
    func_8002F288((struct X4_PlayerObj*)&g_Player);
    func_8002927C();
    func_8002935C();
    func_800293CC();
    func_8002ACA8();
    func_80020D74();
    func_80020DC8();
    func_80017B04(&g_Player, 0x140, 0);
}
#undef P
#undef D_801F68DC
#undef D_801F6000
