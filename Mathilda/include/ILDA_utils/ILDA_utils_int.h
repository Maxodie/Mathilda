
#ifndef __ILDA_UTILS_INT__
#define __ILDA_UTILS_INT__

#include "ILDA_core.h"

//random number between a and b (include)
ILDA_FUN_DECL int ILDA_randomi(int a, int b);

//clamp number between a and b (include)
ILDA_FUN_DECL int ILDA_clampi(int value, int min, int max);

#endif
