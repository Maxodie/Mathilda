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
ILDA_vector4 ILDA_matrix4x4_mul_vector(const ILDA_matrix4x4* multiplicand, const ILDA_vector4* multiplier);

//matrix4x4 only
INLINE_FUN ILDA_matrix4x4 ILDA_matrix4x4_translate(const ILDA_matrix4x4* identity, const ILDA_vector3* multiplier)
{
	ILDA_matrix4x4 mat4x4 = { .rowCount = 4, .colCount = 4, .data = { {0, 0, 0, multiplier->x}, {0, 0, 0, multiplier->y}, {0, 0, 0, multiplier->z}, {0, 0, 0, 0} } };
	ILDA_matrix4x4_add(&mat4x4, identity);

	return mat4x4;
}

INLINE_FUN ILDA_matrix4x4 ILDA_matrix4x4_scale(double x, double y, double z)
{
	ILDA_matrix4x4 matrix = { .rowCount = 4, .colCount = 4, .data = { {x, 0, 0, 0}, {0, y, 0, 0}, {0, 0, z, 0}, {0, 0, 0, 1} } };
	return matrix;
}


//basics
#endif
