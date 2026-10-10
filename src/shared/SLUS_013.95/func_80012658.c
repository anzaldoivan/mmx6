#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80012FA0(void* arg0);
void func_80013008(void);
void func_80013128(void);
M2C_UNK func_80013300(M2C_UNK, M2C_UNK*);
void func_800147D0(void);
void func_800163A4(void);
void func_80016780(void);
void func_80016950(void);
void func_8001C024(void);
void func_80060B74(void);
void func_80060C68(void);
void func_80065ABC(void);
void func_80065B44(s32, s32);
void func_80065B64(s32);
void func_80065DD4(s32);
M2C_UNK func_80066150(M2C_UNK);
void func_800662D4(X4_RECT*, s32, s32, s32);
void func_80066EDC(void*, s16*);
void func_80066F5C(void*, s16*);
void func_80068CD4(void*, s32, s32, s32, s32);
void func_80068D94(void*, s32, s32, s32, s32);
void func_800698C4(void);
void func_80069954(s32);
void func_800699E4(void);
void func_80069F54(s32);
void func_8006AB54(void);
void func_8006AC64(void*, void*);
void func_8001CB3C(void);

extern X4_RECT D_8006D87C;
extern s32 D_8008EC0C;
extern u16 D_80090D6A;
extern u16 D_80090E70;
extern s16 D_8009741A;
extern u16 D_8009B79C;
extern struct X4_DrawInfo* D_8009B7A0;
extern u8 D_800C458C[];
extern u8 D_800CF870[];
extern u8 D_800CF908[];
extern u8 D_800CF920[];
extern u8 D_800CF948[];

#define SCRATCH0 (*(s32*)0x1F800000)

void func_80012658(void) {
    s16 r[4];
    s16 t[4];
    u8* p;
    void* a;
    void* b;

    D_80090D6A = 0;
    D_8009B79C = 0x140;
    func_80060B74();
    func_80060C68();
    func_80065DD4(0);
    func_80065ABC();
    func_80065B44(D_8009B79C >> 1, 0x78);
    func_80065B64(0x200);
    func_80069954(0);
    func_800699E4();
    p = D_800C458C;
    a = p - 0x14;
    func_800698C4();
    func_8001C024();
    func_8006AC64(D_800CF920, D_800CF870);
    func_8006AB54();
    func_80016950();
    func_800163A4();
    func_80069F54(0);
    func_800662D4(&D_8006D87C, 0, 0, 0);
    func_80066150(0);
    func_80068CD4(p, 0, 0, D_8009B79C, 0xF0);
    func_80068D94(a, 0, 0xF0, D_8009B79C, 0xF0);
    func_80068CD4(p + 0xF0, 0, 0xF0, D_8009B79C, 0xF0);
    b = p + 0xDC;
    func_80068D94(b, 0, 0, D_8009B79C, 0xF0);
    r[0] = 0;
    r[1] = 0;
    r[3] = 0xF0;
    r[2] = D_8009B79C;
    func_80066EDC(D_800CF948, r);
    r[0] = 0;
    r[1] = 0xF0;
    r[3] = 0xF0;
    r[2] = D_8009B79C;
    func_80066EDC(D_800CF948 + 0xC, r);
    t[0] = 0;
    t[1] = 0;
    t[2] = 0;
    t[3] = 0xF0;
    func_80066F5C(D_800CF908, &t[0]);
    func_80066F5C(D_800CF908 + 0xC, &t[2]);
    func_80012FA0(a);
    func_80012FA0(b);
    func_80013128();
    D_8009B7A0 = a;
    SCRATCH0 = 0;
    D_80090E70 = 0xD37;
    func_800147D0();
    func_80016780();
    func_80013008();
    D_8008EC0C = 0;
    D_8009741A = 0x3C;
    func_80013300(0, (M2C_UNK*)func_8001CB3C);
}
