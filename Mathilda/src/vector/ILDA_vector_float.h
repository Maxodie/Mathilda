#ifndef __ILDA_VECTOR_FLOAT__
#define __ILDA_VECTOR_FLOAT__

#include "ILDA_core.h"

typedef struct {
	float x;
	float y;
} ILDA_vector2_float;

typedef struct {
	float x;
	float y;
	float z;
} ILDA_vector3_float;

typedef struct {
	float x;
	float y;
	float z;
	float w;
} ILDA_vector4_float;

//Operators
INLINE_FUN ILDA_bool ILDA_vector2_float_equal(const ILDA_vector2_float* base, const ILDA_vector2_float* compare);
INLINE_FUN ILDA_bool ILDA_vector3_float_equal(const ILDA_vector3_float* base, const ILDA_vector3_float* compare);
INLINE_FUN ILDA_bool ILDA_vector4_float_equal(const ILDA_vector4_float* base, const ILDA_vector4_float* compare);

//Addition
INLINE_FUN ILDA_bool ILDA_vector2_float_add(ILDA_vector2_float* augend, const ILDA_vector2_float* addend);
INLINE_FUN ILDA_bool ILDA_vector3_float_add(ILDA_vector3_float* augend, const ILDA_vector3_float* addend);
INLINE_FUN ILDA_bool ILDA_vector4_float_add(ILDA_vector4_float* augend, const ILDA_vector4_float* addend);

//Subtraction
INLINE_FUN ILDA_bool ILDA_vector2_float_sub(ILDA_vector2_float* minuend, const ILDA_vector2_float* subtrahend);
INLINE_FUN ILDA_bool ILDA_vector3_float_sub(ILDA_vector3_float* minuend, const ILDA_vector3_float* subtrahend);
INLINE_FUN ILDA_bool ILDA_vector4_float_sub(ILDA_vector4_float* minuend, const ILDA_vector4_float* subtrahend);

//Multiplication
INLINE_FUN ILDA_bool ILDA_vector2_float_mul(ILDA_vector2_float* vector2, const float lambda);
INLINE_FUN ILDA_bool ILDA_vector3_float_mul(ILDA_vector3_float* vector3, const float lambda);
INLINE_FUN ILDA_bool ILDA_vector4_float_mul(ILDA_vector4_float* vector4, const float lambda);

//get length
INLINE_FUN double ILDA_vector2_float_length(ILDA_vector2_float* vector2);
INLINE_FUN double ILDA_vector3_float_length(ILDA_vector3_float* vector3);
INLINE_FUN double ILDA_vector4_float_length(ILDA_vector4_float* vector4);

#endif