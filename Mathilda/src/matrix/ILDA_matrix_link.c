#include "ILDA_core.h"

#define ILDA_BASE_DOUBLE
#include "ILDA_type_on.h"

//#define ILDA_MATRIX2x2
//#include "matrix/ILDA_matrix_size_on.h"
//#include "matrix/ILDA_matrix4x4_double.h"
//#include "matrix/ILDA_matrix_source.c"
//#include "matrix/ILDA_matrix_size_off.h"
//#undef ILDA_MATRIX2x2
//
//#define ILDA_MATRIX3x3
//#include "matrix/ILDA_matrix_size_on.h"
//#include "matrix/ILDA_matrix4x4_double.h"
//#include "matrix/ILDA_matrix_source.c"
//#include "matrix/ILDA_matrix_size_off.h"
//#undef ILDA_MATRIX3x3

#define ILDA_MATRIX4x4
#include "matrix/ILDA_matrix_size_on.h"
#include "matrix/ILDA_matrix4x4_double.h"
#include "matrix/ILDA_matrix_source.c"
#include "matrix/ILDA_matrix_size_off.h"
#undef ILDA_MATRIX4x4

#include "ILDA_type_off.h"
#undef ILDA_BASE_DOUBLE