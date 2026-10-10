#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK); /* extern */
M2C_UNK func_80017A04(void*);
void func_80027BA0(s32, s32, s32, void*);
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D230(void*);                   /* extern */
M2C_UNK func_80030ECC(void*, s16);              /* extern */
#define func_80030ECC (*(M2C_UNK(*)(void*)) & func_80030ECC)
s32 func_80031474(void*);                        /* extern */
M2C_UNK func_800477E4(M2C_UNK, M2C_UNK*, void*); /* extern */
M2C_UNK func_80049E50(void*);                    /* extern */
extern s16 D_800970AA;
extern struct X4_BackgroundObj D_800971F8[3];
extern s16 D_8009721C;
extern s16 D_80097222;
extern struct X4_EngineObj D_800CCED0;
extern M2C_UNK D_800F6C84;
extern s16 D_800F6D6C[];
extern s16 D_800F6D7C[][2];
extern u8 D_800F6D98[];
extern void (*D_800F6DA8[])(struct X4_MainObj*);
extern u8 D_800F7794;

void func_800ED504(struct X4_MainObj* arg0) {
    s32 r;

    r = func_80031474(arg0);
    if (D_800970AA >= D_800F6D7C[D_800F7794][0] &&
        D_800970AA <= D_800F6D7C[D_800F7794][1]) {
        D_800CCED0.character_state.bytes[0] = 1;
    } else {
        D_800CCED0.character_state.bytes[0] = 0;
    }
    if (r < 0) {
        if (D_800F7794 == 5) {
            D_800971F8[0].unk26 = D_800971F8[0].unk24;
        }
        if (D_800F6D6C[D_800F7794] != 0) {
            D_8009721C = D_800F6D6C[D_800F7794];
        }
        if (D_800F7794 == 1) {
            D_80097222 = 0xE0;
            func_80027BA0(0, 0xA20, 0x60, D_800F6D98);
            func_80027BA0(0, 0xB10, 0, D_800F6D98 + 8);
        }
        D_800CCED0.character_state.bytes[0] = 0;
        func_80049E50(arg0);
        func_800477E4(4, &D_800F6C84, arg0);
        func_800179A4(arg0, 0xD);
        arg0->state = 2;
        arg0->unk42 &= 0x7FFF;
        func_8002CCB0(arg0, 0x28, 0x40);
        return;
    }
    func_80030ECC(arg0);
    if (func_8002CBFC(arg0, 0x28, 0x40) == 0) {
        func_8002CCB0(arg0, 0x28, 0x40);
    }
    D_800F6DA8[arg0->unk5](arg0);
    func_8002D230(arg0);
    func_80017A04(arg0);
}
#undef func_80030ECC
