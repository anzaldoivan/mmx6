/* Adapted from sozud/mmx4 @29b62af src/main/55C4.c:func_800153D4, AGPL-3.0; proven shared with X6 by exact signature 3313a3f0820f (see THIRD_PARTY.md). */
#include "common.h"
extern void func_8005FD54(void);
extern void func_8005FD64(void);

void func_800174D4(u8 arg0) {
    arg0 ? func_8005FD64() : func_8005FD54();
}
