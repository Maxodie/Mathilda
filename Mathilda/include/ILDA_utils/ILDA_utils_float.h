#ifndef __ILDA_UTILS_FLOAT__
#define __ILDA_UTILS_FLOAT__

#include "ILDA_core.h"

//random number between a and b (include)
ILDA_FUN_DECL float ILDA_randomf(float a, float b);

//clamp number between a and b (include)
ILDA_FUN_DECL float ILDA_clampf(float value, float min, float max);

#endif
