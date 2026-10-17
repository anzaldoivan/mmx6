#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
M2C_UNK func_8002CB50();
extern struct X4_EngineObj D_800CCED0;
extern u16 D_800F12A8[][2];

void func_800EEE80(void* arg0) {
    ((void (*)())func_80017A04)();
    if (*(s8*)((u8*)arg0 + 2) == 0x26) {
        *(u16*)((u8*)arg0 + 0xA) =
            D_800F12A8[D_800CCED0.character_state.bytes[4]][0];
    } else {
        *(u16*)((u8*)arg0 + 0xA) =
            D_800F12A8[D_800CCED0.character_state.bytes[4]][0] + 0x600;
    }
    *(u16*)((u8*)arg0 + 0xE) =
        D_800F12A8[D_800CCED0.character_state.bytes[4]][1];
    if (D_800CCED0.unk5F & 0x10) {
        if (D_800CCED0.unk1 == 5) {
            *(u8*)((u8*)arg0 + 3) = 0;
        }
        if (D_800CCED0.unk1 == 6) {
            ((void (*)())func_8002CB50)(arg0);
        }
    } else {
        ((void (*)())func_8002CB50)(arg0);
    }
}
