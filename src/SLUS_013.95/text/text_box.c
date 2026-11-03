/* Adapted from sozud/mmx4 @807a01b src/main/object_update.c:func_80021D20, AGPL-3.0; proven shared with X6 by exact signature 95cf5435ad21 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/globals.h"
void open_text_box(u16, u8, u8);
void update_text_box(struct X4_AbcObj*);

// 0x80020D18 run_text_box: per-frame text box step: updates the active text box, else opens the pending text id.
// basis: xref update_text_box (docs/leads/derived.tsv:11)
// callers: func_80020C40, rock_16 func_800EC858, rock_18 func_800EA5C8, rock_18 func_800ED760, rock_20 func_800EE97C, one function in each of rock_46..rock_58
void run_text_box(void) {
    if (D_8008EAF0.unkC != 0) {
        update_text_box(&D_8008EAF0);
    } else if (D_8008EAF0.unk10 != 0) {
        open_text_box((u16)(D_8008EAF0.unk10 & ~0x8000), 0xFF, 0);
    }
}
