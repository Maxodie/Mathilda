#ifndef __ILDA_MATRIX3x3_DOUBLE__
#define __ILDA_MATRIX3x3_DOUBLE__

#include "ILDA_core.h"
#include "vector/ILDA_vector_float.h"

typedef struct ILDA_matrix3x3 {
	float data[3][3];
	size_t rowCount, colCount;
} ILDA_matrix3x3;

//default
static const ILDA_matrix3x3 ILDA_mat3x3_identity = { .colCount = 3, .rowCount = 3, .data = {{1,0,0}, {0,1,0}, {0,0,1}} };

//init
//ILDA_bool ILDA_matrix3x3_init_alloc(ILDA_matrix3x3 matrix);
INLINE_FUN ILDA_bool ILDA_matrix3x3_init_identity(ILDA_matrix3x3* matrix, float v);
INLINE_FUN ILDA_bool ILDA_matrix3x3_init_default(ILDA_matrix3x3* matrix);

//get / setB
INLINE_FUN float ILDA_matrix3x3_get(size_t row, size_t col, const ILDA_matrix3x3* matrix);
INLINE_FUN void ILDA_matrix3x3_set(size_t row, size_t col, ILDA_matrix3x3* matrix, float value);

//basic operators
EXTERN ILDA_bool ILDA_matrix3x3_add(ILDA_matrix3x3* augend, const ILDA_matrix3x3* addend);
EXTERN ILDA_bool ILDA_matrix3x3_sub(ILDA_matrix3x3* minuend, const ILDA_matrix3x3* subtrahend);
EXTERN ILDA_bool ILDA_matrix3x3_mul_same(ILDA_matrix3x3* multiplicand, const ILDA_matrix3x3* multiplier);
EXTERN ILDA_vector3f ILDA_matrix3x3_mul_vector(const ILDA_matrix3x3* multiplicand, const ILDA_vector3f* multiplier);

//basics
#endif
