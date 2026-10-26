#include "common.h"
#include "psyq/libetc.h"
#include "psyq/libgpu.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80012A34(void);
void func_8001ACC4(s32, s32, s32, s32);
s32 func_8001B184(s32, s32);
void func_8001B6D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5,
                   s32 arg6, s32 arg7, s32 arg8, s32 arg9);
void func_8001B784(void);
void func_8001B7A8(void);
void func_8001B90C(u32 arg0);
void func_8001B984(s32);

extern u16 D_80070CA4[];
extern u16 D_800C456C[];
extern u8 D_800C4578[];
#define DB_DISP(i) (*(X4_DISPENV*)(D_800C4578 + (i) * 0xF0))
extern s8 D_800CC869;
#define D_800CC869 (*(u8*)&D_800CC869)
extern s32 D_800CD408;
extern s8 D_800E2E65;
extern s32 D_800E2E68;
extern s32 D_800E2E70;
extern s32 D_800E2E74;
extern s32 D_800E2E78;
extern s32 D_800E2E7C;
extern X4_DISPENV D_800E2E88[];
extern M2C_UNK func_80012FE4;

s32 func_8001A6CC(s32 arg0) {
    X4_RECT rect;
    u8* p;
    u8* t;
    s32 a1;
    s32 done;
    s32 v;
    // !FAKE: depin: dropping it breaks the match (10/185)
    register s32 c asm("$6");
    u8 idx;

    idx = arg0;
    c = 0x1C000;
    v = D_800CD408;
    D_800E2E70 = v;
    v += 0x4000;
    D_800E2E74 = v;
    v += c;
    D_800E2E78 = v;
    v += c;
    D_800E2E7C = v;
    ((void (*)())func_8001ACC4)(0x140, 0xF0, c);
    func_8001B90C(0x80);
    func_8001B984(D_800CC869);
    t = (u8*)D_80070CA4;
    p = t + idx * 12;
    D_800E2E65 = 1;
    done = ((s32(*)(s32, s32, s32, s32, s32, s32, s32, s32, s32,
                    s32))func_8001B6D0)(*(s32*)p, 1, *(u16*)(p + 4), D_800E2E7C,
                                        *(u16*)(p + 6), D_800E2E74, D_800E2E78,
                                        D_800E2E70, 1, 1);
    D_800E2E68 = 0;
    if (done == 0) {
        do {
            VSync(0);
            ((s32(*)(void*))PutDispEnv)(&DB_DISP(D_800E2E68));
            a1 = 0;
            D_800E2E68 ^= 1;
            if (D_800E2E68 != 0) {
                a1 = 0xF0;
            }
            done = func_8001B184(0, a1);
            func_8001B784();
            func_80012A34();
            {
                // !FAKE: depin: dropping it breaks the match (183/185)
                register u16 m asm("$3");
                u16 g;
                g = D_800C456C[2];
                do {
                    m = *(u16*)(p + 10);
                } while (0);
                if (g & m) {
                    done = 1;
                }
            }
        } while (done == 0);
    }
    ((void (*)(s32))SetDispMask)(0);
    rect.x = 0;
    rect.y = 0;
    rect.w = 0x1E0;
    rect.h = 0x1E0;
    ClearImage(&rect, 0, 0, 0);
    DrawSync(0);
    func_8001B7A8();
    DB_DISP(0) = D_800E2E88[0];
    DB_DISP(1) = D_800E2E88[1];
    D_800E2E68 ^= 1;
    PutDispEnv(&DB_DISP(D_800E2E68));
    DrawSync(0);
    DrawSyncCallback(&func_80012FE4);
}
#undef DB_DISP
#undef D_800CC869
