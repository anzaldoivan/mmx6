#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern M2C_UNK g_Player;
extern s32 D_800C1220[];
extern struct X4_EngineObj D_800CCED0;
M2C_UNK func_8002CD6C(void*);

#define SP_OBJ_CUR (*(u8**)SP(0x060))
#define SP_OBJ_FUNCS (*(void (***)())SP(0x094))

void func_800205A0(void) {
    u8* obj;
    u8 flags;

    s8* pl0 = (s8*)&g_Player;
    if (pl0[0xCC] == 0) {
        SP_OBJ_CUR = (u8*)D_800C1220;
        if ((u8*)D_800C1220 < (u8*)D_800C1220 + 0x3340) {
            do {
                obj = SP_OBJ_CUR;
                flags = obj[0];
                if (((s8*)obj)[0] != 0) {
                    s8* pl = (s8*)&g_Player;
                    if (pl[0xCC] != 0 ||
                        (D_800CCED0.unk16 != 0 && !(flags & 8))) {
                        if (((s8*)obj)[3] != 0) {
                            ((void (*)())func_8002CD6C)(obj, flags);
                        }
                    } else {
                        SP_OBJ_FUNCS[((s8*)obj)[1]](obj);
                    }
                }
                SP_OBJ_CUR += 0xA4;
            } while (SP_OBJ_CUR < (u8*)D_800C1220 + 0x3340);
        }
    }
}

#undef SP_OBJ_CUR
#undef SP_OBJ_FUNCS
