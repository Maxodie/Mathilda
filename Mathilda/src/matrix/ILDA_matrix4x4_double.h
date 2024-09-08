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

INLINE_FUN ILDA_bool ILDA_matrix4x4_scale(ILDA_matrix4x4* matrix4x4, const ILDA_vector3* vector3)
{
	ILDA_matrix4x4 result = { .rowCount = 4, .colCount = 4, .data = { {vector3->x, 0, 0, 0}, {0, vector3->y, 0, 0}, {0, 0, vector3->z, 0}, {0, 0, 0, 1} } };
	ILDA_matrix4x4_mul_same(matrix4x4, &result);

	return ILDA_SUCCESS;
}

INLINE_FUN ILDA_matrix4x4 ILDA_matrix4x4_rotation(double rotation, const ILDA_vector3* vector3)
{
    double x = vector3->x, y = vector3->y, z = vector3->z;


	ILDA_matrix4x4 result = {
		.rowCount = 4,
		.colCount = 4,
		.data = {
			{ cos(rotation) + x * x * (1 - cos(rotation)), x * y * (1 - cos(rotation)) - z * sin(rotation), x * z * (1 - cos(rotation)) + y * sin(rotation), 0 },
			{ y * x * (1 - cos(rotation)) + z * sin(rotation), cos(rotation) + y * y * (1 - cos(rotation)), y * z * (1 - cos(rotation)) - x * sin(rotation), 0 },
			{ z * x * (1 - cos(rotation)) - y * sin(rotation), z * y * (1 - cos(rotation)) + x * sin(rotation), cos(rotation) + z * z * (1 - cos(rotation)), 0 },
			{ 0, 0, 0, 0 }
		}
	};

	return result;
}


//basics
#endif
