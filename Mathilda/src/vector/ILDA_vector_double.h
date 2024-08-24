#ifndef __ILDA_VECTOR_DOUBLE__
#define __ILDA_VECTOR_DOUBLE__

#include "ILDA_core.h"

typedef struct {
	Double64 x;
	Double64 y;
} ILDA_vector2;

typedef struct {
	Double64 x;
	Double64 y;
	Double64 z;
} ILDA_vector3;

typedef struct {
	Double64 x;
	Double64 y;
	Double64 z;
	Double64 w;
} ILDA_vector4;

//Addition
INLINE_FUN int ILDA_vector2_add(ILDA_vector2* augend, const ILDA_vector2* addend);
INLINE_FUN int ILDA_vector3_add(ILDA_vector3* augend, const ILDA_vector3* addend);
INLINE_FUN int ILDA_vector4_add(ILDA_vector4* augend, const ILDA_vector4* addend);

//Subtraction
INLINE_FUN int ILDA_vector2_sub(ILDA_vector2* minuend, const ILDA_vector2* subtrahend);
INLINE_FUN int ILDA_vector3_sub(ILDA_vector3* minuend, const ILDA_vector3* subtrahend);
INLINE_FUN int ILDA_vector4_sub(ILDA_vector4* minuend, const ILDA_vector4* subtrahend);

//Multiplication
INLINE_FUN int ILDA_vector2_mul(ILDA_vector2* vector2, const Double64 lambda);
INLINE_FUN int ILDA_vector3_mul(ILDA_vector3* vector3, const Double64 lambda);
INLINE_FUN int ILDA_vector4_mul(ILDA_vector4* vector4, const Double64 lambda);

#endif