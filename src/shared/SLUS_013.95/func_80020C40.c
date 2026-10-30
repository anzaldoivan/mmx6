#include "common.h"

#define M2C_UNK s32

void func_80017B04(u8*, s16, s16); /* extern */
void func_8002000C(void);          /* extern */
void func_8002012C(void);          /* extern */
void func_80020258(void);          /* extern */
void func_80020378(void);          /* extern */
void func_8002048C(void);          /* extern */
void func_800205A0();              /* extern */
void func_800206C0(void);          /* extern */
void func_800207D4(void);          /* extern */
void update_layer_objects(void);   /* extern */
void func_80020A08(void);          /* extern */
void func_80020D18(void);          /* extern */
M2C_UNK func_80020D74();           /* extern */
void func_80020DC8(void);          /* extern */
void func_8002927C(void);          /* extern */
void func_8002935C(void);          /* extern */
M2C_UNK func_800293CC();           /* extern */
void func_80029D18(void);          /* extern */
void func_8002ACA8();    /* extern; was M2C_UNK (W14 regate of 2ACA8) */
M2C_UNK func_8002E84C(); /* extern */
void func_8002F288(struct X4_PlayerObj*); /* extern */
void func_80034DCC(void);                 /* extern */
M2C_UNK read_player_input();              /* extern */
extern M2C_UNK g_Player;

void func_80020C40(void) {
    func_8002E84C();
    read_player_input();
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
    func_80020D18();
    func_8002F288(&g_Player);
    func_8002927C();
    func_8002935C();
    func_800293CC();
    func_8002ACA8();
    func_80020D74();
    func_80020DC8();
    func_80017B04(&g_Player, 0x140, 0);
}
