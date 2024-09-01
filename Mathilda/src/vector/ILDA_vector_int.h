#ifndef __ILDA_VECTOR_INT__
#define __ILDA_VECTOR_INT__

#include "ILDA_core.h"

typedef struct {
	int x;
	int y;
} ILDA_vector2_int;

typedef struct {
	int x;
	int y;
	int z;
} ILDA_vector3_int;

typedef struct {
	int x;
	int y;
	int z;
	int w;
} ILDA_vector4_int;

//Operators
INLINE_FUN ILDA_bool ILDA_vector2_int_equal(const ILDA_vector2_int* base, const ILDA_vector2_int* compare);
INLINE_FUN ILDA_bool ILDA_vector3_int_equal(const ILDA_vector3_int* base, const ILDA_vector3_int* compare);
INLINE_FUN ILDA_bool ILDA_vector4_int_equal(const ILDA_vector4_int* base, const ILDA_vector4_int* compare);

//Addition
INLINE_FUN ILDA_bool ILDA_vector2_int_add(ILDA_vector2_int* augend, const ILDA_vector2_int* addend);
INLINE_FUN ILDA_bool ILDA_vector3_int_add(ILDA_vector3_int* augend, const ILDA_vector3_int* addend);
INLINE_FUN ILDA_bool ILDA_vector4_int_add(ILDA_vector4_int* augend, const ILDA_vector4_int* addend);

//Subtraction
INLINE_FUN ILDA_bool ILDA_vector2_int_sub(ILDA_vector2_int* minuend, const ILDA_vector2_int* subtrahend);
INLINE_FUN ILDA_bool ILDA_vector3_int_sub(ILDA_vector3_int* minuend, const ILDA_vector3_int* subtrahend);
INLINE_FUN ILDA_bool ILDA_vector4_int_sub(ILDA_vector4_int* minuend, const ILDA_vector4_int* subtrahend);

//Multiplication
INLINE_FUN ILDA_bool ILDA_vector2_int_mul(ILDA_vector2_int* vector2, const int lambda);
INLINE_FUN ILDA_bool ILDA_vector3_int_mul(ILDA_vector3_int* vector3, const int lambda);
INLINE_FUN ILDA_bool ILDA_vector4_int_mul(ILDA_vector4_int* vector4, const int lambda);

INLINE_FUN double ILDA_vector2_int_length(ILDA_vector2_int* vector2);
INLINE_FUN double ILDA_vector3_int_length(ILDA_vector3_int* vector3);
INLINE_FUN double ILDA_vector4_int_length(ILDA_vector4_int* vector4);

#endif