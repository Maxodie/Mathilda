#ifndef __ILDA_VECTOR_DOUBLE__
#define __ILDA_VECTOR_DOUBLE__

#include "ILDA_core.h"

typedef struct {
	double x;
	double y;
} ILDA_vector2;

typedef struct {
	double x;
	double y;
	double z;
} ILDA_vector3;

typedef struct {
	double x;
	double y;
	double z;
	double w;
} ILDA_vector4;

//Operators
INLINE_FUN ILDA_bool ILDA_vector2_equal(const ILDA_vector2* base, const ILDA_vector2* compare);
INLINE_FUN ILDA_bool ILDA_vector3_equal(const ILDA_vector3* base, const ILDA_vector3* compare);
INLINE_FUN ILDA_bool ILDA_vector4_equal(const ILDA_vector4* base, const ILDA_vector4* compare);

//Addition
INLINE_FUN ILDA_bool ILDA_vector2_add(ILDA_vector2* augend, const ILDA_vector2* addend);
INLINE_FUN ILDA_bool ILDA_vector3_add(ILDA_vector3* augend, const ILDA_vector3* addend);
INLINE_FUN ILDA_bool ILDA_vector4_add(ILDA_vector4* augend, const ILDA_vector4* addend);

//Subtraction
INLINE_FUN ILDA_bool ILDA_vector2_sub(ILDA_vector2* minuend, const ILDA_vector2* subtrahend);
INLINE_FUN ILDA_bool ILDA_vector3_sub(ILDA_vector3* minuend, const ILDA_vector3* subtrahend);
INLINE_FUN ILDA_bool ILDA_vector4_sub(ILDA_vector4* minuend, const ILDA_vector4* subtrahend);

//Multiplication
INLINE_FUN ILDA_bool ILDA_vector2_mul(ILDA_vector2* vector2, const double lambda);
INLINE_FUN ILDA_bool ILDA_vector3_mul(ILDA_vector3* vector3, const double lambda);
INLINE_FUN ILDA_bool ILDA_vector4_mul(ILDA_vector4* vector4, const double lambda);

INLINE_FUN double ILDA_vector2_length(ILDA_vector2* vector2);
INLINE_FUN double ILDA_vector3_length(ILDA_vector3* vector3);
INLINE_FUN double ILDA_vector4_length(ILDA_vector4* vector4);


#endif