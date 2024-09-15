#ifndef __ILDA_VECTOR_DOUBLE__
#define __ILDA_VECTOR_DOUBLE__

#include "ILDA_core.h"

typedef struct {
	double x;
	double y;
} ILDA_vector2d;

typedef struct {
	double x;
	double y;
	double z;
} ILDA_vector3d;

typedef struct {
	double x;
	double y;
	double z;
	double w;
} ILDA_vector4d;

//copy
INLINE_FUN ILDA_bool ILDA_vector2d_copy(ILDA_vector2d* base, const ILDA_vector2d* copy);
INLINE_FUN ILDA_bool ILDA_vector3d_copy(ILDA_vector3d* base, const ILDA_vector3d* copy);
INLINE_FUN ILDA_bool ILDA_vector4d_copy(ILDA_vector4d* base, const ILDA_vector4d* copy);

//Operators
INLINE_FUN ILDA_bool ILDA_vector2d_equal(const ILDA_vector2d* base, const ILDA_vector2d* compare);
INLINE_FUN ILDA_bool ILDA_vector3d_equal(const ILDA_vector3d* base, const ILDA_vector3d* compare);
INLINE_FUN ILDA_bool ILDA_vector4d_equal(const ILDA_vector4d* base, const ILDA_vector4d* compare);

//Addition
INLINE_FUN ILDA_bool ILDA_vector2d_add(ILDA_vector2d* augend, const ILDA_vector2d* addend);
INLINE_FUN ILDA_bool ILDA_vector3d_add(ILDA_vector3d* augend, const ILDA_vector3d* addend);
INLINE_FUN ILDA_bool ILDA_vector4d_add(ILDA_vector4d* augend, const ILDA_vector4d* addend);

//Subtraction
INLINE_FUN ILDA_bool ILDA_vector2d_sub(ILDA_vector2d* minuend, const ILDA_vector2d* subtrahend);
INLINE_FUN ILDA_bool ILDA_vector3d_sub(ILDA_vector3d* minuend, const ILDA_vector3d* subtrahend);
INLINE_FUN ILDA_bool ILDA_vector4d_sub(ILDA_vector4d* minuend, const ILDA_vector4d* subtrahend);

//Multiplication
INLINE_FUN ILDA_bool ILDA_vector2d_mul(ILDA_vector2d* vector2, const double lambda);
INLINE_FUN ILDA_bool ILDA_vector3d_mul(ILDA_vector3d* vector3, const double lambda);
INLINE_FUN ILDA_bool ILDA_vector4d_mul(ILDA_vector4d* vector4, const double lambda);

//get length
INLINE_FUN double ILDA_vector2d_length(const ILDA_vector2d* vector2);
INLINE_FUN double ILDA_vector3d_length(const ILDA_vector3d* vector3);
INLINE_FUN double ILDA_vector4d_length(const ILDA_vector4d* vector4);

//specials
INLINE_FUN ILDA_vector2d ILDA_vector2d_normalize(const ILDA_vector2d* vector2);
INLINE_FUN ILDA_vector3d ILDA_vector3d_normalize(const ILDA_vector3d* vector3);
INLINE_FUN ILDA_vector4d ILDA_vector4d_normalize(const ILDA_vector4d* vector4);

INLINE_FUN ILDA_vector3d ILDA_vector3d_cross(const ILDA_vector3d* a, const ILDA_vector3d* b);

INLINE_FUN double ILDA_vector2d_dot(const ILDA_vector2d* a, const ILDA_vector2d* b);
INLINE_FUN double ILDA_vector3d_dot(const ILDA_vector3d* a, const ILDA_vector3d* b);
INLINE_FUN double ILDA_vector4d_dot(const ILDA_vector4d* a, const ILDA_vector4d* b);

#endif