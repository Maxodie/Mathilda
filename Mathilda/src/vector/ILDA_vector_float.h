#ifndef __ILDA_VECTOR_FLOAT__
#define __ILDA_VECTOR_FLOAT__

#include "ILDA_core.h"

typedef struct {
	Float32 x;
	Float32 y;
} ILDA_vector2_float;

typedef struct {
	Float32 x;
	Float32 y;
	Float32 z;
} ILDA_vector3_float;

typedef struct {
	Float32 x;
	Float32 y;
	Float32 z;
	Float32 w;
} ILDA_vector4_float;

//Addition
INLINE_FUN int ILDA_vector2_float_add(ILDA_vector2_float* augend, const ILDA_vector2_float* addend);
INLINE_FUN int ILDA_vector3_float_add(ILDA_vector3_float* augend, const ILDA_vector3_float* addend);
INLINE_FUN int ILDA_vector4_float_add(ILDA_vector4_float* augend, const ILDA_vector4_float* addend);

//Subtraction
INLINE_FUN int ILDA_vector2_float_sub(ILDA_vector2_float* minuend, const ILDA_vector2_float* subtrahend);
INLINE_FUN int ILDA_vector3_float_sub(ILDA_vector3_float* minuend, const ILDA_vector3_float* subtrahend);
INLINE_FUN int ILDA_vector4_float_sub(ILDA_vector4_float* minuend, const ILDA_vector4_float* subtrahend);

//Multiplication
INLINE_FUN int ILDA_vector2_float_mul(ILDA_vector2_float* vector2, const Float32 lambda);
INLINE_FUN int ILDA_vector3_float_mul(ILDA_vector3_float* vector3, const Float32 lambda);
INLINE_FUN int ILDA_vector4_float_mul(ILDA_vector4_float* vector4, const Float32 lambda);


#endif