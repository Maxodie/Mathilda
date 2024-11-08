#ifndef __ILDA_UTILS__
#define __ILDA_UTILS__

#include "ILDA_core.h"

#include "ILDA_utils/ILDA_utils_float.h"
#include "ILDA_utils/ILDA_utils_int.h"

#define ILDA_clamp(Value, Min, Max) (((Value) < (Min)) ? (Min) : ((Value) > (Max)) ? (Max) : (Value))

#endif
