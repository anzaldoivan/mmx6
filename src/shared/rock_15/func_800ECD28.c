#include "common.h"
#define M2C_UNK s32

M2C_UNK animate_object();
M2C_UNK clear_object_slot();
M2C_UNK func_8002CB50();
M2C_UNK move_object(s32);
#include "mmx6/state.h"
#include "mmx6/globals.h"

M2C_UNK func_800ECD28(u8* arg0) {
    u8 temp_v1;

    move_object(arg0);
    ((void (*)())animate_object)(arg0);
    if (*(s8*)(arg0 + 0x46) == 0) {
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x24) = 0;
        arg0[0x54] = 0;
        clear_object_slot(arg0);
        return;
    }
    temp_v1 = arg0[0x54];
    arg0[3] = 0;
    if (!(temp_v1 & 3) || (temp_v1 & 1)) {
        if ((D_80097420.frame_counter & 1) == *(s8*)(arg0 + 7)) {
            func_8002CB50(arg0);
        }
    } else {
        func_8002CB50(arg0);
    }
}
