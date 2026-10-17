#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_80013008(void);
void func_8001750C(u8, u8);
void func_800186A8();
void func_8001E32C(void* arg0);
void func_80020C40(void);
void func_80025FB0();
void func_8002B29C(void);

extern s32 D_8008EC0C;
extern u8 D_80097184;
extern s8 D_80097424;
extern u8 D_800C4560;
extern struct X4_EngineObj D_800CCED0;

void func_8001EB48(void* arg0) {
    struct X4_EngineObj* e;

    if (D_80097424 != 0) {
        func_80020C40();
        if (D_80097184 != 0) {
            func_8002B29C();
        }
        func_80025FB0();
        return;
    }
    func_8001E32C(arg0);
    D_800C4560 = 1;
    func_8001750C(0xFF, 0);
    if (((u8*)arg0)[0x1B] == 0) {
        func_800186A8();
    }
    func_80013008();
    D_8008EC0C = 0;
    e = &D_800CCED0;
    e->unk10 = 0;
    e->unk11 = 0;
    e->unk14 = 0;
    e->unk16 = 0;
    e->unk17 = 0;
}
