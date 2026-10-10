#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139A0(M2C_UNK);                 /* extern */
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
void func_80029F38();                           /* extern */
M2C_UNK func_8002B36C(M2C_UNK);                 /* extern */
M2C_UNK func_8002B6B0();                        /* extern */
extern struct X4_PlayerObj D_800970A0;
extern struct X4_BackgroundObj D_800971F8[3];
extern s32 D_80097420;
#define D_80097420_h (*(struct X4_ObjectHeader*)&D_80097420)
extern u8 D_800C4560;
extern struct X4_EngineObj D_800CCED0;
extern u8 D_800F5644[];
extern s16 D_800F5754[][16];

#define IDX D_800F5644[M2C_FIELD(arg0, s8*, 2) + base]
#define IDX2 D_800F5644[M2C_FIELD(arg0, s8*, 2) + base2]

void func_800EBEA0(void* arg0) {
    s32 temp_a1;
    s32 temp_a0;
    s16 temp_v1;
    s16 temp_y;
    s32 base;
    s32 base2;

    temp_a1 = M2C_FIELD(arg0, u16*, 0x82) + 1;
    temp_a0 = M2C_FIELD(arg0, u16*, 0x84) - 1;
    M2C_FIELD(arg0, u16*, 0x82) = temp_a1;
    M2C_FIELD(arg0, u16*, 0x84) = temp_a0;
    if (!(D_80097420 & 1)) {
        D_800970A0.x_pos.i.hi = temp_a1;
    } else {
        D_800970A0.x_pos.i.hi = temp_a0;
    }
    if (D_80097420_h.state == 0) {
        temp_v1 = D_800F5754
            [D_800F5644[M2C_FIELD(arg0, s8*, 2) +
                        (base = D_800CCED0.character_state.bytes[10] * 4 - 1)]]
            [0];
        temp_y = D_800F5754[IDX][1];
        D_800970A0.x_pos.i.hi = temp_v1;
        D_800970A0.y_pos.i.hi = temp_y;
        M2C_FIELD(arg0, u16*, 0x82) = temp_v1 + 0x40;
        M2C_FIELD(arg0, u16*, 0x84) = temp_v1 - 0x40;
        if (D_800970A0.unk2 != 0) {
            D_800970A0.y_pos.i.hi--;
        }
        D_800970A0.spike_immune = 0;
        D_800CCED0.unk1C = 0;
        D_800970A0.nova_strike_active = 0;
        D_800970A0.unk18.val = D_800970A0.x_pos.val;
        D_800970A0.unk1C.val = D_800970A0.y_pos.val;
        func_8002B36C(0);
        D_800C4560 = 1;
        (&D_800970A0)[1].active = 0;
        D_800971F8[0].unk44 = 1;
        D_800971F8[1].unk44 = 1;
        D_800971F8[2].unk44 = 1;
        base2 = D_800CCED0.character_state.bytes[10] * 4 - 1;
        D_800971F8[0].x_pos.i.hi = D_800F5754[IDX2][2];
        D_800971F8[0].y_pos.i.hi = D_800F5754[IDX2][3];
        D_800971F8[1].x_pos.i.hi = D_800F5754[IDX2][4];
        D_800971F8[1].y_pos.i.hi = D_800F5754[IDX2][5];
        D_800971F8[2].x_pos.i.hi = D_800F5754[IDX2][6];
        D_800971F8[2].y_pos.i.hi = D_800F5754[IDX2][7];
        D_800971F8[0].unk1E = D_800F5754[IDX2][8];
        D_800971F8[0].unk1C = D_800F5754[IDX2][9];
        D_800971F8[0].unk22 = D_800F5754[IDX2][10];
        D_800971F8[0].unk20 = D_800F5754[IDX2][11];
        D_800971F8[0].unk26 = D_800F5754[IDX2][8];
        D_800971F8[0].unk24 = D_800F5754[IDX2][9];
        D_800971F8[0].unk2A = D_800F5754[IDX2][10];
        D_800971F8[0].unk28 = D_800F5754[IDX2][11];
        D_800971F8[0].unk4C = 1;
        D_800971F8[1].unk4C = 1;
        D_800971F8[2].unk4C = 1;
        D_800970A0.air_state = 0;
        func_8002B6B0();
        (&D_800970A0)[1].active = 0;
        D_800970A0.hurt_phase = 0;
        D_800970A0.invincibility_timer = 0;
        func_80029F38(D_800971F8[0].x_pos.i.hi - 0x30,
                      D_800971F8[0].x_pos.i.hi + 0x170,
                      D_800971F8[0].y_pos.i.hi - 0x30,
                      D_800971F8[0].y_pos.i.hi + 0x120, 0);
        func_800139A0(8);
        D_800971F8[0].unk44 = 0;
        D_800971F8[1].unk44 = 0;
        func_80016C48(1, 1, arg0);
        M2C_FIELD(arg0, u8*, 7) = M2C_FIELD(arg0, u8*, 7) + 1;
    }
}
