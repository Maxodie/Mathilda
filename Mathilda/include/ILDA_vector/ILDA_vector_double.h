#ifndef __ILDA_VECTOR_DOUBLE__
#define __ILDA_VECTOR_DOUBLE__

#include "ILDA_core.h"

typedef struct ILDA_vector2d {
	double x;
	double y;
} ILDA_vector2d;

static const ILDA_vector2d ILDA_vector2d_one = {.x = 1, .y = 1};

typedef struct ILDA_vector3d {
	double x;
	double y;
	double z;
} ILDA_vector3d;

static const ILDA_vector3d ILDA_vector3d_one = {.x = 1, .y = 1, .z = 1};

typedef struct ILDA_vector4d {
	double x;
	double y;
	double z;
	double w;
} ILDA_vector4d;

static const ILDA_vector4d ILDA_vector4d_one = {.x = 1, .y = 1, .z = 1, .w = 1};

//copy
ILDA_FUN_DECL ILDA_bool ILDA_vector2d_copy(ILDA_vector2d* base, const ILDA_vector2d* copy);
ILDA_FUN_DECL ILDA_bool ILDA_vector3d_copy(ILDA_vector3d* base, const ILDA_vector3d* copy);
ILDA_FUN_DECL ILDA_bool ILDA_vector4d_copy(ILDA_vector4d* base, const ILDA_vector4d* copy);

//Operators
ILDA_FUN_DECL ILDA_bool ILDA_vector2d_equal(const ILDA_vector2d* base, const ILDA_vector2d* compare);
ILDA_FUN_DECL ILDA_bool ILDA_vector3d_equal(const ILDA_vector3d* base, const ILDA_vector3d* compare);
ILDA_FUN_DECL ILDA_bool ILDA_vector4d_equal(const ILDA_vector4d* base, const ILDA_vector4d* compare);

//Addition
ILDA_FUN_DECL ILDA_bool ILDA_vector2d_add(ILDA_vector2d* augend, const ILDA_vector2d* addend);
ILDA_FUN_DECL ILDA_bool ILDA_vector3d_add(ILDA_vector3d* augend, const ILDA_vector3d* addend);
ILDA_FUN_DECL ILDA_bool ILDA_vector4d_add(ILDA_vector4d* augend, const ILDA_vector4d* addend);

//Subtraction
ILDA_FUN_DECL ILDA_bool ILDA_vector2d_sub(ILDA_vector2d* minuend, const ILDA_vector2d* subtrahend);
ILDA_FUN_DECL ILDA_bool ILDA_vector3d_sub(ILDA_vector3d* minuend, const ILDA_vector3d* subtrahend);
ILDA_FUN_DECL ILDA_bool ILDA_vector4d_sub(ILDA_vector4d* minuend, const ILDA_vector4d* subtrahend);

//Multiplication
ILDA_FUN_DECL ILDA_bool ILDA_vector2d_mul(ILDA_vector2d* vector2, const double lambda);
ILDA_FUN_DECL ILDA_bool ILDA_vector3d_mul(ILDA_vector3d* vector3, const double lambda);
ILDA_FUN_DECL ILDA_bool ILDA_vector4d_mul(ILDA_vector4d* vector4, const double lambda);

//get length
ILDA_FUN_DECL double ILDA_vector2d_length(const ILDA_vector2d* vector2);
ILDA_FUN_DECL double ILDA_vector3d_length(const ILDA_vector3d* vector3);
ILDA_FUN_DECL double ILDA_vector4d_length(const ILDA_vector4d* vector4);

//specials
ILDA_FUN_DECL ILDA_vector2d ILDA_vector2d_normalize(const ILDA_vector2d* vector2);
ILDA_FUN_DECL ILDA_vector3d ILDA_vector3d_normalize(const ILDA_vector3d* vector3);
ILDA_FUN_DECL ILDA_vector4d ILDA_vector4d_normalize(const ILDA_vector4d* vector4);

ILDA_FUN_DECL ILDA_vector3d ILDA_vector3d_cross(const ILDA_vector3d* a, const ILDA_vector3d* b);

ILDA_FUN_DECL double ILDA_vector2d_dot(const ILDA_vector2d* a, const ILDA_vector2d* b);
ILDA_FUN_DECL double ILDA_vector3d_dot(const ILDA_vector3d* a, const ILDA_vector3d* b);
ILDA_FUN_DECL double ILDA_vector4d_dot(const ILDA_vector4d* a, const ILDA_vector4d* b);

#endif
