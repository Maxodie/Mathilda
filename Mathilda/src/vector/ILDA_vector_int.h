#ifndef __ILDA_VECTOR_INT__
#define __ILDA_VECTOR_INT__

#include "ILDA_core.h"

typedef struct {
	Int32 x;
	Int32 y;
} ILDA_vector2_int;

typedef struct {
	Int32 x;
	Int32 y;
	Int32 z;
} ILDA_vector3_int;

typedef struct {
	Int32 x;
	Int32 y;
	Int32 z;
	Int32 w;
} ILDA_vector4_int;

//Addition
INLINE_FUN int ILDA_vector2_int_add(ILDA_vector2_int* augend, const ILDA_vector2_int* addend);
INLINE_FUN int ILDA_vector3_int_add(ILDA_vector3_int* augend, const ILDA_vector3_int* addend);
INLINE_FUN int ILDA_vector4_int_add(ILDA_vector4_int* augend, const ILDA_vector4_int* addend);

//Subtraction
INLINE_FUN int ILDA_vector2_int_sub(ILDA_vector2_int* minuend, const ILDA_vector2_int* subtrahend);
INLINE_FUN int ILDA_vector3_int_sub(ILDA_vector3_int* minuend, const ILDA_vector3_int* subtrahend);
INLINE_FUN int ILDA_vector4_int_sub(ILDA_vector4_int* minuend, const ILDA_vector4_int* subtrahend);

//Multiplication
INLINE_FUN int ILDA_vector2_int_mul(ILDA_vector2_int* vector2, const Int32 lambda);
INLINE_FUN int ILDA_vector3_int_mul(ILDA_vector3_int* vector3, const Int32 lambda);
INLINE_FUN int ILDA_vector4_int_mul(ILDA_vector4_int* vector4, const Int32 lambda);

#endif