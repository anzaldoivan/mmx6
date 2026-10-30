#include "common.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002BFD0(void*, s32);
s32 random_byte();
extern struct X4_PlayerObj g_Player;
extern struct X4_BackgroundObj background_objects[3];
extern u8 D_800CCF38;

void func_800EC7DC(struct X4_PlayerObj* arg0) {
    s32 m;
    u8 idx;
    s16 y;
    s32 i;
    u8* tbl;
    u8* p;
    u8* q;
    struct X4_PlayerObj* obj;

    m = 0x80;
    if (D_800CCF38 >= 2) {
        m = 0x40;
    }
    idx = (u32)random_byte() % 6;
    if (arg0->x_pos.i.hi < 0x14C0) {
        if ((M2C_FIELD(arg0, u8*, 0x84) % m) == 0 && arg0->unk7 < 0x12) {
            y = idx * 0x30 + 0x1398;
            p = (u8*)arg0 + 0x86;
            {
                // !FAKE: depin: dropping it breaks the match (265/269)
                register s32 k asm("$2") = 3;
                if (p[idx] == k) {
                    idx++;
                    idx %= 6;
                    for (i = 0; i < 5; i++) {
                        y = idx * 0x30 + 0x1398;
                        q = (u8*)arg0 + 0x86;
                        if (q[idx] == 3) {
                            idx++;
                            idx %= 6;
                        } else {
                            i = 5;
                        }
                    }
                }
                tbl = (u8*)arg0 + 0x86;
            }
            obj = func_8002BFD0(arg0, 0);
            if (obj != 0) {
                obj->active = 0x41;
                obj->id = 7;
                obj->unk2 = 0xC;
                obj->unk40 = arg0->unk40;
                obj->animation_table = arg0->animation_table;
                obj->unk3C = arg0->unk3C;
                obj->unk42 = arg0->unk42;
                obj->x_pos.i.hi = y;
                obj->y_pos.i.hi = 0x4E0;
                obj->unk7 = idx;
                M2C_FIELD(obj, void**, 0x7C) = arg0;
            }
            tbl[idx]++;
            arg0->unk7++;
        }
        if (g_Player.x_pos.i.hi > 0x14A0 &&
            background_objects[0].unk24 == 0x1370) {
            background_objects[0].unk24 = 0x14D0;
            background_objects[0].unk26 = 0x14D0;
            arg0->state = 2;
        }
    } else {
        if ((M2C_FIELD(arg0, u8*, 0x84) % m) == 0 && arg0->unk7 < 0x18) {
            y = idx * 0x30 + 0x14F8;
            p = (u8*)arg0 + 0x86;
            {
                // !FAKE: depin: dropping it breaks the match (265/269)
                register s32 k asm("$2") = 4;
                if (p[idx] == k) {
                    idx++;
                    idx %= 6;
                    for (i = 0; i < 5; i++) {
                        y = idx * 0x30 + 0x14F8;
                        q = (u8*)arg0 + 0x86;
                        if (q[idx] == 4) {
                            idx++;
                            idx %= 6;
                        } else {
                            i = 5;
                        }
                    }
                }
                tbl = (u8*)arg0 + 0x86;
            }
            obj = func_8002BFD0(arg0, 0);
            if (obj != 0) {
                obj->active = 0x41;
                obj->id = 7;
                obj->unk2 = 0xC;
                obj->unk40 = arg0->unk40;
                obj->animation_table = arg0->animation_table;
                obj->unk3C = arg0->unk3C;
                obj->unk42 = arg0->unk42;
                obj->x_pos.i.hi = y;
                obj->y_pos.i.hi = 0x4E0;
                obj->unk7 = idx;
                M2C_FIELD(obj, void**, 0x7C) = arg0;
            }
            tbl[idx]++;
            arg0->unk7++;
        }
        if (g_Player.x_pos.i.hi > 0x1600 &&
            background_objects[0].unk24 == 0x14D0) {
            background_objects[0].unk24 = 0x1650;
            background_objects[0].unk26 = 0x1650;
            arg0->state = 2;
        }
    }
    M2C_FIELD(arg0, u8*, 0x84)++;
}
