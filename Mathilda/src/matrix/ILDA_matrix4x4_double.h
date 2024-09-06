#ifndef __ILDA_MATRIX4x4_DOUBLE__
#define __ILDA_MATRIX4x4_DOUBLE__

#include "ILDA_core.h"
#include "vector/ILDA_vector_double.h"

typedef struct ILDA_matrix4x4 {
	double data[4][4];
	size_t rowCount, colCount;
} ILDA_matrix4x4;

//default 
static const ILDA_matrix4x4 ILDA_mat4x4_identity = { .colCount = 4, .rowCount = 4, .data = {{1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,1}} };

//init
//ILDA_bool ILDA_matrix4x4_init_alloc(ILDA_matrix4x4 matrix);
//ILDA_bool ILDA_matrix4x4_init_identity(ILDA_matrix4x4* matrix, double value);
INLINE_FUN ILDA_bool ILDA_matrix4x4_init_default(ILDA_matrix4x4* matrix);

//get / setB
INLINE_FUN double ILDA_matrix4x4_get(size_t row, size_t col, const ILDA_matrix4x4* matrix);
INLINE_FUN void ILDA_matrix4x4_set(size_t row, size_t col, ILDA_matrix4x4* matrix, double value);

//basic operators
ILDA_bool ILDA_matrix4x4_add(ILDA_matrix4x4* augend, const ILDA_matrix4x4* addend);
ILDA_bool ILDA_matrix4x4_sub(ILDA_matrix4x4* minuend, const ILDA_matrix4x4* subtrahend);
ILDA_bool ILDA_matrix4x4_mul_same(ILDA_matrix4x4* multiplicand, const ILDA_matrix4x4* multiplier);
ILDA_bool ILDA_matrix4x4_mul_vector(ILDA_matrix4x4* multiplicand, const ILDA_vector4* multiplier);


//basics
#endif