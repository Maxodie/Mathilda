#ifndef __ILDA_MATRIX3x3_DOUBLE__
#define __ILDA_MATRIX3x3_DOUBLE__

#include "ILDA_core.h"
#include "vector/ILDA_vector_double.h"

typedef struct ILDA_matrix3x3 {
	double data[3][3];
	size_t rowCount, colCount;
} ILDA_matrix3x3;

//default
static const ILDA_matrix3x3 ILDA_mat3x3_identity = { .colCount = 3, .rowCount = 3, .data = {{1,0,0}, {0,1,0}, {0,0,1}} };

//init
//ILDA_bool ILDA_matrix3x3_init_alloc(ILDA_matrix3x3 matrix);
//ILDA_bool ILDA_matrix3x3_init_identity(ILDA_matrix3x3* matrix, double value);
INLINE_FUN ILDA_bool ILDA_matrix3x3_init_default(ILDA_matrix3x3* matrix);

//get / setB
INLINE_FUN double ILDA_matrix3x3_get(size_t row, size_t col, const ILDA_matrix3x3* matrix);
INLINE_FUN void ILDA_matrix3x3_set(size_t row, size_t col, ILDA_matrix3x3* matrix, double value);

//basic operators
ILDA_bool ILDA_matrix3x3_add(ILDA_matrix3x3* augend, const ILDA_matrix3x3* addend);
ILDA_bool ILDA_matrix3x3_sub(ILDA_matrix3x3* minuend, const ILDA_matrix3x3* subtrahend);
ILDA_bool ILDA_matrix3x3_mul_same(ILDA_matrix3x3* multiplicand, const ILDA_matrix3x3* multiplier);
ILDA_vector3 ILDA_matrix3x3_mul_vector(const ILDA_matrix3x3* multiplicand, const ILDA_vector3* multiplier);

//basics
#endif
