/* Adapted from sozud/mmx4 @807a01b src/main/object_update.c:func_80021D20, AGPL-3.0; proven shared with X6 by exact signature 95cf5435ad21 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_AbcObj D_8008EAF0;
void func_80021760(u16, u8, u8);
void func_80021BF4(struct X4_AbcObj*);

void func_80020D18(void) {
    if (D_8008EAF0.unkC != 0) {
        func_80021BF4(&D_8008EAF0);
    } else if (D_8008EAF0.unk10 != 0) {
        func_80021760((u16)(D_8008EAF0.unk10 & ~0x8000), 0xFF, 0);
    }
}
