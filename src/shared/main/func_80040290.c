/* func_80040290 in X5 func_80044BD8's form: the 7-entry handler table is an extern object (D_80011574), copied to the stack */
#include "common.h"

/* needs `typedef struct { void* fn[7]; } FnTbl7;` in include/mmx6/types.h (recipe.diff): typecheck refuses it here (outside) */
extern FnTbl7 D_80011574;

void func_80040290(u8* a0) {
    FnTbl7 tbl = D_80011574;

    ((void (*)(u8*))tbl.fn[((s8*)a0)[0x63]])(a0);
}
