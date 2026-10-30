#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
extern struct X4_PlayerObj g_Player;
M2C_UNK func_80017A04();
M2C_UNK clear_object_slot();
M2C_UNK func_801ED3DC();
void func_801ED6F0(u8* self, u8* parent);

void func_801ED2A8(void* arg0) {
    struct X4_PlayerObj* p = &g_Player;
    s32 var_a1;
    u8 id;

    var_a1 = p->hp == 0;
    if (M2C_FIELD(p, s8*, 0xD3) != 0) {
        var_a1 = 1;
    }
    if (M2C_FIELD(p, s8*, 0xCF) != 0) {
        var_a1 = 1;
    }
    if (M2C_FIELD(arg0, s32*, 0x84) != p->unk17) {
        var_a1 = 1;
    }
    id = M2C_FIELD(arg0, u8*, 0x1);
    if (M2C_FIELD(arg0, u8*, 0x15) != p->unk15 && (u32)(id - 0x18) < 3) {
        var_a1 = 1;
    }
    if ((s8)id == 0x2A &&
        M2C_FIELD(arg0, s8*, 0x2) != M2C_FIELD(p, s8*, 0xCB)) {
        var_a1 = 1;
    }
    if (var_a1 != 0) {
        // !FAKE: block order, release call placed before the init path
        goto release;
    }
    if (M2C_FIELD(arg0, s8*, 0x4) == 0) {
        // !FAKE: block order, init path placed after the release call
        goto init;
    }
    ((void (*)())func_80017A04)(arg0);
    if ((M2C_FIELD(arg0, s32*, 0x0) & 0xFFFF00) == 0x2400 ||
        M2C_FIELD(arg0, s8*, 0x46) != 0) {
        // !FAKE: block order, shares the update call tail
        goto update;
    }
release:
    clear_object_slot(arg0);
    return;
init:
    func_801ED3DC(arg0, p);
update:
    func_801ED6F0(arg0, p);
}
