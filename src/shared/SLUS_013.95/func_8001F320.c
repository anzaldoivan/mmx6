#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800133A0();
M2C_UNK func_800139A0(s8);
void func_8001D218(void);
void func_8001D25C(void);
void func_8001FE74(void);
void* func_8002C530();
extern u8 D_800711AC;
extern u8 D_800711B8;
extern s32 D_80097420;

void func_8001F320(void* arg) {
    void* arg0 = arg;
    u8* p;
    u8* obj;
    u8 i;
    // !FAKE: depin: dropping it breaks the match (146/160)
    register s32 one asm("$19");
    s8* g = (s8*)&D_80097420;

    if (g[4] == 0) {
        if (*(u8*)(g + 7) == 0) {
            func_8001D25C();
            func_800133A0();
            return;
        }
        M2C_FIELD(arg0, u8*, 1) = 0;
        func_8001D218();
        g[7] = 0;
        M2C_FIELD(arg0, s16*, 4) = 0x78;
        ((void (*)(s8))func_800139A0)(8);
        if (M2C_FIELD(arg0, s8*, 0xC) == 0) {
            p = &D_800711AC;
            i = 0;
            one = 1;
            if (*p != 0) {
                obj = func_8002C530();
                if (obj != 0) {
                    obj[0] = one;
                    obj[1] = 0x20;
                    M2C_FIELD(obj, u8**, 0x50) = p;
                    p++;
                    M2C_FIELD(obj, s16*, 0xA) = D_800711AC;
                    obj[0x55] = one;
                }
            } else {
                p++;
            }
            while (*p != 0xFF) {
                obj = func_8002C530();
                if (obj != 0) {
                    obj[0] = 1;
                    obj[1] = 0x1F;
                    obj[2] = *p++;
                    obj[7] = i++;
                    M2C_FIELD(obj, s16*, 0xE) = *p++;
                    M2C_FIELD(obj, s16*, 0xA) = *p++;
                    obj[0x55] = one;
                }
            }
            func_8001FE74();
            M2C_FIELD(arg0, s16*, 8) = p[1];
            M2C_FIELD(arg0, u8*, 1) += 3;
        } else {
            p = &D_800711B8;
            i = 0;
            one = 1;
            if (*p != 0) {
                obj = func_8002C530();
                if (obj != 0) {
                    obj[0] = one;
                    obj[1] = 0x20;
                    M2C_FIELD(obj, u8**, 0x50) = p;
                    p++;
                    M2C_FIELD(obj, s16*, 0xA) = D_800711B8;
                    obj[0x55] = one;
                }
            } else {
                p++;
            }
            while (*p != 0xFF) {
                obj = func_8002C530();
                if (obj != 0) {
                    obj[0] = 1;
                    obj[1] = 0x1F;
                    obj[2] = *p++;
                    obj[7] = i++;
                    M2C_FIELD(obj, s16*, 0xE) = *p++;
                    M2C_FIELD(obj, s16*, 0xA) = *p++;
                    obj[0x55] = one;
                }
            }
            func_8001FE74();
            M2C_FIELD(arg0, s16*, 8) = p[1];
            M2C_FIELD(arg0, u8*, 1) += 1;
        }
    }
}
