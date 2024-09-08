#ifndef __ILDA_MATRIX2x2_DOUBLE__
#define __ILDA_MATRIX2x2_DOUBLE__

#include "ILDA_core.h"
#include "vector/ILDA_vector_double.h"

typedef struct ILDA_matrix2x2 {
	double data[2][2];
	size_t rowCount, colCount;
} ILDA_matrix2x2;

//default
static const ILDA_matrix2x2 ILDA_mat2x2_identity = { .colCount = 2, .rowCount = 2, .data = {{1,0}, {0,1}} };

//init
//ILDA_bool ILDA_matrix2x2_init_alloc(ILDA_matrix2x2 matrix);
//ILDA_bool ILDA_matrix2x2_init_identity(ILDA_matrix2x2* matrix, double value);
INLINE_FUN ILDA_bool ILDA_matrix2x2_init_default(ILDA_matrix2x2* matrix);

//get / setB
INLINE_FUN double ILDA_matrix2x2_get(size_t row, size_t col, const ILDA_matrix2x2* matrix);
INLINE_FUN void ILDA_matrix2x2_set(size_t row, size_t col, ILDA_matrix2x2* matrix, double value);

//basic operators
ILDA_bool ILDA_matrix2x2_add(ILDA_matrix2x2* augend, const ILDA_matrix2x2* addend);
ILDA_bool ILDA_matrix2x2_sub(ILDA_matrix2x2* minuend, const ILDA_matrix2x2* subtrahend);
ILDA_bool ILDA_matrix2x2_mul_same(ILDA_matrix2x2* multiplicand, const ILDA_matrix2x2* multiplier);
ILDA_vector2 ILDA_matrix2x2_mul_vector(const ILDA_matrix2x2* multiplicand, const ILDA_vector2* multiplier);

//basics
#endif
