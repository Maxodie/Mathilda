#ifndef __ILDA_MATRIX4x4_DOUBLE__
#define __ILDA_MATRIX4x4_DOUBLE__

#include "ILDA_core.h"
#include "vector/ILDA_vector_float.h"

typedef struct ILDA_matrix4x4 {
	float data[4][4];
	size_t rowCount, colCount;
} ILDA_matrix4x4;

//default
static const ILDA_matrix4x4 ILDA_mat4x4_identity = { .colCount = 4, .rowCount = 4, .data = {{1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,1}} };

//init
//ILDA_bool ILDA_matrix4x4_init_alloc(ILDA_matrix4x4 matrix);
INLINE_FUN ILDA_bool ILDA_matrix4x4_init_identity(ILDA_matrix4x4* matrix, float v);
INLINE_FUN ILDA_bool ILDA_matrix4x4_init_default(ILDA_matrix4x4* matrix);

//get / setB
INLINE_FUN float ILDA_matrix4x4_get(size_t row, size_t col, const ILDA_matrix4x4* matrix);
INLINE_FUN void ILDA_matrix4x4_set(size_t row, size_t col, ILDA_matrix4x4* matrix, float value);

//basic operators
EXTERN ILDA_bool ILDA_matrix4x4_add(ILDA_matrix4x4* augend, const ILDA_matrix4x4* addend);
EXTERN ILDA_bool ILDA_matrix4x4_sub(ILDA_matrix4x4* minuend, const ILDA_matrix4x4* subtrahend);
EXTERN ILDA_bool ILDA_matrix4x4_mul_same(ILDA_matrix4x4* multiplicand, const ILDA_matrix4x4* multiplier);
EXTERN ILDA_vector4f ILDA_matrix4x4_mul_vector(const ILDA_matrix4x4* multiplicand, const ILDA_vector4f* multiplier);

//matrix4x4 only
INLINE_FUN ILDA_matrix4x4 ILDA_translate(const ILDA_matrix4x4* identity, const ILDA_vector3f* translation);

INLINE_FUN ILDA_bool ILDA_scale(ILDA_matrix4x4* matrix4x4, const ILDA_vector3f* scale);

INLINE_FUN ILDA_matrix4x4 ILDA_rotation(float rotation, const ILDA_vector3f* vector3);

INLINE_FUN ILDA_matrix4x4 ILDA_matrix_look_at_r(const ILDA_vector3f* position, const ILDA_vector3f* target, const ILDA_vector3f* worldUp);

//basics
#endif
