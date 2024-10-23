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
EXTERN_INLINE ILDA_bool ILDA_vector2d_copy(ILDA_vector2d* base, const ILDA_vector2d* copy);
EXTERN_INLINE ILDA_bool ILDA_vector3d_copy(ILDA_vector3d* base, const ILDA_vector3d* copy);
EXTERN_INLINE ILDA_bool ILDA_vector4d_copy(ILDA_vector4d* base, const ILDA_vector4d* copy);

//Operators
EXTERN_INLINE ILDA_bool ILDA_vector2d_equal(const ILDA_vector2d* base, const ILDA_vector2d* compare);
EXTERN_INLINE ILDA_bool ILDA_vector3d_equal(const ILDA_vector3d* base, const ILDA_vector3d* compare);
EXTERN_INLINE ILDA_bool ILDA_vector4d_equal(const ILDA_vector4d* base, const ILDA_vector4d* compare);

//Addition
EXTERN_INLINE ILDA_bool ILDA_vector2d_add(ILDA_vector2d* augend, const ILDA_vector2d* addend);
EXTERN_INLINE ILDA_bool ILDA_vector3d_add(ILDA_vector3d* augend, const ILDA_vector3d* addend);
EXTERN_INLINE ILDA_bool ILDA_vector4d_add(ILDA_vector4d* augend, const ILDA_vector4d* addend);

//Subtraction
EXTERN_INLINE ILDA_bool ILDA_vector2d_sub(ILDA_vector2d* minuend, const ILDA_vector2d* subtrahend);
EXTERN_INLINE ILDA_bool ILDA_vector3d_sub(ILDA_vector3d* minuend, const ILDA_vector3d* subtrahend);
EXTERN_INLINE ILDA_bool ILDA_vector4d_sub(ILDA_vector4d* minuend, const ILDA_vector4d* subtrahend);

//Multiplication
EXTERN_INLINE ILDA_bool ILDA_vector2d_mul(ILDA_vector2d* vector2, const double lambda);
EXTERN_INLINE ILDA_bool ILDA_vector3d_mul(ILDA_vector3d* vector3, const double lambda);
EXTERN_INLINE ILDA_bool ILDA_vector4d_mul(ILDA_vector4d* vector4, const double lambda);

//get length
EXTERN_INLINE double ILDA_vector2d_length(const ILDA_vector2d* vector2);
EXTERN_INLINE double ILDA_vector3d_length(const ILDA_vector3d* vector3);
EXTERN_INLINE double ILDA_vector4d_length(const ILDA_vector4d* vector4);

//specials
EXTERN_INLINE ILDA_vector2d ILDA_vector2d_normalize(const ILDA_vector2d* vector2);
EXTERN_INLINE ILDA_vector3d ILDA_vector3d_normalize(const ILDA_vector3d* vector3);
EXTERN_INLINE ILDA_vector4d ILDA_vector4d_normalize(const ILDA_vector4d* vector4);

EXTERN_INLINE ILDA_vector3d ILDA_vector3d_cross(const ILDA_vector3d* a, const ILDA_vector3d* b);

EXTERN_INLINE double ILDA_vector2d_dot(const ILDA_vector2d* a, const ILDA_vector2d* b);
EXTERN_INLINE double ILDA_vector3d_dot(const ILDA_vector3d* a, const ILDA_vector3d* b);
EXTERN_INLINE double ILDA_vector4d_dot(const ILDA_vector4d* a, const ILDA_vector4d* b);

#endif