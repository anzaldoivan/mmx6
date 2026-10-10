#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_80017A04(struct X4_AnimatedObj*);
void* func_8002C32C();
struct X4_VisualObj* func_8002C398(void);
void func_801EC6D0(void*, s32);
extern s32 D_80090C90[];
extern s8 D_80090D56;
extern s16 D_80090D5C;
extern M2C_UNK D_800970A0;
#define D_800970A0 (*(struct X4_PlayerObj*)&D_800970A0)
extern s8 D_8009742C;
extern s16 D_80097430;
extern u8 D_800C4560;
extern s8 D_800CF850;
extern s16 D_800CF854;
extern u8 D_801F4DD9;
extern s32 D_801F4DE8[];

void func_801EA724(u8* arg0) {
    s32 i;
    s32 j;
    s32 kind;
    u16 t;
    u8* obj;
    struct X4_PlayerObj* player;

    if (D_801F4DD9 != 0) {
        if (--D_801F4DD9 != 0) {
            return;
        }
        for (i = 0; i < 16; i++) {
            D_80090C90[i + 16] = D_801F4DE8[i];
        }
        player = &D_800970A0;
        {
            s8* p0 = &D_80090D56;
            s8* p1 = &D_8009742C;
            s8* p2 = &D_800CF850;
            p0[1] = 1;
            p1[1] = 1;
            p2[1] = 1;
        }
        kind = 1;
        if (player->unk15 != 0) {
            kind = 2;
        }
        for (j = 0; j < 5; j++) {
            obj = (u8*)func_8002C398();
            if (obj != 0) {
                obj[0] = 1;
                obj[1] = 0x11;
                obj[2] = kind;
                obj[0x47] = 0x55;
                M2C_FIELD(obj, s16*, 0xA) = j << 6;
                M2C_FIELD(obj, s16*, 0xE) = 0x80;
                obj[5] = player->unk5;
            }
        }
        obj = (u8*)func_8002C398();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x11;
            obj[2] = kind;
            obj[0x47] = 0x55;
            if (kind == 1) {
                M2C_FIELD(obj, s16*, 0xA) = 0x140;
            } else {
                M2C_FIELD(obj, s16*, 0xA) = -0x40;
            }
            M2C_FIELD(obj, s16*, 0xE) = 0x80;
            obj[5] = player->unk5;
        }
        arg0[0xE1] = 0;
        obj = func_8002C32C();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x2F;
            obj[2] = 0;
            obj[0x14] = arg0[0x14];
            M2C_FIELD(obj, s32*, 0x84) = arg0[0x17];
        }
        obj = func_8002C32C();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x2F;
            obj[2] = 1;
            obj[0x14] = arg0[0x14];
            M2C_FIELD(obj, s32*, 0x84) = arg0[0x17];
        }
        if (D_801F4DD9 != 0) {
            return;
        }
    }
    func_80017A04((struct X4_AnimatedObj*)arg0);
    if (((s8*)arg0)[7] == 0) {
        func_801EC6D0(arg0, 0x32);
    } else {
        func_801EC6D0(arg0, 0x33);
    }
    if (++arg0[0xE1] >= 0x95) {
        arg0[6]++;
    }
    if (arg0[0xE1] >= 0x8F) {
        u16* q0 = (u16*)&D_800CF854;
        t = q0[1];
        if (t != 0) {
            u16* q1;
            u16* q2;
            q0[1] = t - 8;
            q1 = (u16*)&D_80097430;
            q2 = (u16*)&D_80090D5C;
            q1[1] -= 0x100;
            q2[1] -= 0x2000;
            if ((u16)(t - 8) < 8) {
                q2[1] = 0;
                q1[1] = 0;
                q0[1] = 0;
                arg0[0xE4] &= 0xFE;
                D_800C4560 |= 1;
            }
        }
    }
}
#undef D_800970A0
