#include "common.h"

INCLUDE_ASM("asm/rock_53/nonmatchings/FA000", D_800FA000);

#include "../shared/rock_53/func_800FA004.c"

INCLUDE_ASM("asm/rock_53/nonmatchings/FA000", func_800FA0D8);

#include "../shared/rock_53/func_800FA1AC.c"

#include "../shared/rock_53/func_800FA214.c"

#include "../shared/rock_53/func_800FA274.c"

#define func_800FA4D0 func_800FA2D4
#include "../shared/rock_48/func_800FA4D0.c"
#undef func_800FA4D0

#define func_800FA63C func_800FA318
#include "../shared/rock_47/func_800FA63C.c"
#undef func_800FA63C

INCLUDE_ASM("asm/rock_53/nonmatchings/FA000", func_800FA394);
