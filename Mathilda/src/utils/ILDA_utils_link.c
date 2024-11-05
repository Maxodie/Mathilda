#include "ILDA_core.h"

//Random
#define ILDA_BASE_FLOAT
#include "ILDA_type_on.h"
#include "ILDA_utils/ILDA_utils_int.h"
#include "ILDA_type_off.h"
#undef ILDA_BASE_FLOAT
#undef __ILDA_RANDOM_SOURCE_CHECK__

#define ILDA_BASE_INT
#include "ILDA_type_on.h"
#include "ILDA_utils/ILDA_utils_int.h"
#include "ILDA_type_off.h"
#undef ILDA_BASE_INT
#undef __ILDA_RANDOM_SOURCE_CHECK__
