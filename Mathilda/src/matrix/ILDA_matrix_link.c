#include "ILDA_core.h"

#define ILDA_BASE_FLOAT
#include "ILDA_type_on.h"

#define ILDA_MATRIX2x2
#include "matrix/ILDA_matrix_size_on.h"
#include "ILDA_matrix/ILDA_matrix2x2_float.h"
#include "matrix/ILDA_matrix_source.c"
#include "matrix/ILDA_matrix_size_off.h"
#undef ILDA_MATRIX2x2

#undef __ILDA_MATRIX_SOURCE_CHECK__

#define ILDA_MATRIX3x3
#include "matrix/ILDA_matrix_size_on.h"
#include "ILDA_matrix/ILDA_matrix3x3_float.h"
#include "matrix/ILDA_matrix_source.c"
#include "matrix/ILDA_matrix_size_off.h"
#undef ILDA_MATRIX3x3

#undef __ILDA_MATRIX_SOURCE_CHECK__

#define ILDA_MATRIX4x4
#include "matrix/ILDA_matrix_size_on.h"
#include "ILDA_matrix/ILDA_matrix4x4_float.h"
#include "matrix/ILDA_matrix_source.c"
#include "matrix/ILDA_matrix_size_off.h"
#undef ILDA_MATRIX4x4

#include "ILDA_type_off.h"
#undef ILDA_BASE_FLOAT

#include "matrix/ILDA_matrix_specials_source.c"
