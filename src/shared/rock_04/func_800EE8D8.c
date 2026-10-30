#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void* enemy_slot_alloc();
s32 random_byte();
extern s16 D_800970AA;
extern s8 D_800CCEED;

#define SB(p, o) (*(s8*)((u8*)(p) + (o)))
#define UB(p, o) (*(u8*)((u8*)(p) + (o)))
#define H(p, o) (*(s16*)((u8*)(p) + (o)))
#define UH(p, o) (*(u16*)((u8*)(p) + (o)))
#define W(p, o) (*(s32*)((u8*)(p) + (o)))
#define ABS(v) ((v) < 0 ? -(v) : (v))

#define SPAWN_HEAD(obj, kind)                                                  \
    UB(obj, 0) = 0x41;                                                         \
    UB(obj, 1) = 0x11;                                                         \
    UB(obj, 2) = (kind);                                                       \
    UH(obj, 0x42) = UH(arg0, 0x42) & 0x7FFF;                                   \
    W(obj, 0x30) = W(arg0, 0x30);                                              \
    W(obj, 0x3C) = W(arg0, 0x3C);                                              \
    UH(obj, 0x40) = UH(arg0, 0x40);

void func_800EE8D8(void* arg0) {
    void* obj;
    s32 d;

    if (H(arg0, 0x7C) != 0) {
        H(arg0, 0x7C)--;
        return;
    }
    switch (SB(arg0, 2)) {
    case 0:
        if (D_800CCEED <= 0 && H(arg0, 0x7E) != 0) {
            obj = enemy_slot_alloc();
            if (obj != NULL && (s16)(H(arg0, 0x7E) % 7) == 0) {
                SPAWN_HEAD(obj, 4)
                UH(obj, 0xA) = UH(arg0, 0xA);
                UH(obj, 0xE) =
                    UH(arg0, 0xE) + ((random_byte() & 0x1F) - 0x10);
            }
            H(arg0, 0x7E)--;
        } else {
            SB(arg0, 4) = 2;
        }
        break;
    case 1:
        if (H(arg0, 0x7E) != 0) {
            obj = enemy_slot_alloc();
            if (obj != NULL && (s16)(H(arg0, 0x7E) % 7) == 0) {
                SPAWN_HEAD(obj, 5)
                UH(obj, 0xA) = UH(arg0, 0xA);
                UH(obj, 0xE) =
                    UH(arg0, 0xE) + ((random_byte() & 0x1F) - 0x10);
            }
            H(arg0, 0x7E)--;
        } else {
            SB(arg0, 4) = 2;
        }
        break;
    case 2:
        if (H(arg0, 0x7E) != 0) {
            obj = enemy_slot_alloc();
            if (obj != NULL && (s16)(H(arg0, 0x7E) % 10) == 0) {
                SPAWN_HEAD(obj, 6)
                UH(obj, 0xA) = UH(arg0, 0xA) + ((random_byte() & 0xF) - 8);
                UH(obj, 0xE) = UH(arg0, 0xE);
            }
            H(arg0, 0x7E)--;
        } else {
            H(arg0, 0x7C) = 0x78;
            H(arg0, 0x7E) = 0xB4;
        }
        break;
    case 3:
        d = D_800970AA - H(arg0, 0xA);
        if (d >= 0) {
            if (d >= 0x30) {
                goto far;
            }
            return;
        }
        if (H(arg0, 0xA) - D_800970AA < 0x30) {
            return;
        }
    far:
        if (H(arg0, 0x7E) != 0) {
            H(arg0, 0x7E)--;
            break;
        }
        obj = enemy_slot_alloc();
        if (obj != NULL && (s16)(H(arg0, 0x7E) % 31) == 0) {
            SPAWN_HEAD(obj, 7)
            UH(obj, 0xA) = UH(arg0, 0xA) + ((random_byte() & 0xF) - 8);
            UH(obj, 0xE) = UH(arg0, 0xE);
        }
        if (UB(arg0, 0x81)++ >= 3) {
            UB(arg0, 0x81) = 0;
            H(arg0, 0x7C) = 0x8C;
        }
        H(arg0, 0x7E) = 100;
        break;
    }
}
