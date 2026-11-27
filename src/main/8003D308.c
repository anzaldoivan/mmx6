#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_PlayerObj g_Player;

M2C_UNK func_8003D308(M2C_UNK arg0, M2C_UNK arg1) {
    u8* p = (u8*)&g_Player;
    p[0xD0] = 1;
    p[0xD1] = arg0;
    p[0xD2] = arg1;
    p[0x7A] = 1;
    D_800CCEEC = 1;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

extern struct X4_PlayerObj g_Player;

M2C_UNK func_8003D330(void) {
    struct X4_PlayerObj* p = &g_Player;

    *((s8*)p + 0xD0) = 0;
    p->spike_immune = 0;
    D_800CCEEC = 0;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 get_tile_attr_origin();    /* extern */
s32 func_8003CA70(void*, s16); /* extern */

void func_8003D34C(void* arg0) {
    if (get_tile_attr_origin() == 0x24) {
        func_8003CA70(arg0, (s16)(M2C_FIELD(arg0, u16*, 0xE) & 0xFFF0));
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 get_tile_attr_bottom(); /* extern */

s32 func_8003CA70(void*, s16);
void func_8003D394(void* arg0) {
    void* temp_a2;

    if (get_tile_attr_bottom() == 0x24) {
        temp_a2 = M2C_FIELD(arg0, void**, 0x68);
        ((s32(*)())func_8003CA70)(arg0,
                                  (s16)((M2C_FIELD(temp_a2, u8*, 3) +
                                         (M2C_FIELD(arg0, u16*, 0xE) +
                                          (s8)M2C_FIELD(temp_a2, u8*, 1))) &
                                        ~0xF),
                                  temp_a2);
    }
}
