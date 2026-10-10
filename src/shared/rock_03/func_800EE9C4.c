#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139A0(M2C_UNK);                 /* extern */
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
void func_80029F38();                           /* extern */
M2C_UNK func_8002B36C(M2C_UNK);                 /* extern */
M2C_UNK func_8002B6B0();                        /* extern */
extern s8 D_8008EAB0;
extern struct X4_PlayerObj D_800970A0;
extern struct X4_BackgroundObj D_800971F8[3];
extern struct X4_ObjectHeader D_80097420;
extern u8 D_800C4560;
extern struct X4_EngineObj D_800CCED0;
extern s16 D_800F782C[][16];

void func_800EE9C4(void* arg0) {
    s32 temp_a1;
    s32 temp_a0;
    s8 temp_a1_2;
    s16 temp_v1;
    s16 temp_y;
    s32 idx;

    temp_a1 = M2C_FIELD(arg0, u16*, 0x80) + 1;
    temp_a0 = M2C_FIELD(arg0, u16*, 0x82) - 1;
    M2C_FIELD(arg0, u16*, 0x80) = temp_a1;
    M2C_FIELD(arg0, u16*, 0x82) = temp_a0;
    if (!(*(s32*)&D_80097420 & 1)) {
        D_800970A0.x_pos.i.hi = temp_a1;
    } else {
        D_800970A0.x_pos.i.hi = temp_a0;
    }
    if (D_80097420.state == 0) {
        temp_a1_2 = M2C_FIELD(arg0, s8*, 2);
        switch (temp_a1_2) {
        case 2:
            if (D_800970A0.unk2 == 0) {
                M2C_FIELD(arg0, s16*, 0x7E) = 0;
                D_800CCED0.checkpoint = 1;
                D_8008EAB0 = 1;
            } else {
                M2C_FIELD(arg0, s16*, 0x7E) = 1;
                D_800CCED0.checkpoint = temp_a1_2;
                D_8008EAB0 = 1;
            }
            break;
        case 3:
            D_800CCED0.checkpoint = 3;
            M2C_FIELD(arg0, s16*, 0x7E) = 2;
            break;
        case 4:
            D_800CCED0.checkpoint = 3;
            M2C_FIELD(arg0, s16*, 0x7E) = 3;
            break;
        }
        idx = M2C_FIELD(arg0, s16*, 0x7E);
        temp_v1 = D_800F782C[idx][0];
        temp_y = D_800F782C[idx][1];
        D_800970A0.x_pos.i.hi = temp_v1;
        D_800970A0.y_pos.i.hi = temp_y;
        M2C_FIELD(arg0, u16*, 0x80) = temp_v1 + 0x40;
        M2C_FIELD(arg0, u16*, 0x82) = temp_v1 - 0x40;
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
        D_800971F8[0].x_pos.i.hi = D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][2];
        D_800971F8[0].y_pos.i.hi = D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][3];
        D_800971F8[1].x_pos.i.hi = D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][4];
        D_800971F8[1].y_pos.i.hi = D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][5];
        D_800971F8[2].x_pos.i.hi = D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][6];
        D_800971F8[2].y_pos.i.hi = D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][7];
        D_800971F8[0].unk1E = D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][8];
        D_800971F8[0].unk1C = D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][9];
        D_800971F8[0].unk22 = D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][10];
        D_800971F8[0].unk20 = D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][11];
        D_800971F8[0].unk26 = D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][8];
        D_800971F8[0].unk24 = D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][9];
        D_800971F8[0].unk2A = D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][10];
        D_800971F8[0].unk28 = D_800F782C[M2C_FIELD(arg0, s16*, 0x7E)][11];
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
        D_800971F8[2].unk44 = 0;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
        func_80016C48(1, 1, arg0);
    }
}
