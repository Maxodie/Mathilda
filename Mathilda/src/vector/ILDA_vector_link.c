#include "ILDA_core.h"


#define ILDA_BASE_DOUBLE
#include "ILDA_type_on.h"
#include "ILDA_vector/ILDA_vector_double.h"
#include "vector/ILDA_vector_source.c"
#include "ILDA_type_off.h"
#undef ILDA_BASE_DOUBLE
#undef __ILDA_VECTOR_SOURCE_CHECK__

#define ILDA_BASE_INT
#include "ILDA_type_on.h"
#include "ILDA_vector/ILDA_vector_int.h"
#include "vector/ILDA_vector_source.c"
#include "ILDA_type_off.h"
#undef ILDA_BASE_INT
#undef __ILDA_VECTOR_SOURCE_CHECK__

#define ILDA_BASE_FLOAT
#include "ILDA_type_on.h"
#include "ILDA_vector/ILDA_vector_float.h"
#include "vector/ILDA_vector_source.c"
#include "ILDA_type_off.h"
#undef ILDA_BASE_FLOAT