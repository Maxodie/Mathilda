#ifndef __ILDA_VECTOR_FLOAT__
#define __ILDA_VECTOR_FLOAT__

#include "ILDA_core.h"
#include "ILDA_vector/ILDA_vector_double.h"

typedef struct {
	float x;
	float y;
} ILDA_vector2f;

typedef struct {
	float x;
	float y;
	float z;
} ILDA_vector3f;

typedef struct {
	float x;
	float y;
	float z;
	float w;
} ILDA_vector4f;

//copy
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector2f_copy(ILDA_vector2f* base, const ILDA_vector2f* copy);
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector3f_copy(ILDA_vector3f* base, const ILDA_vector3f* copy);
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector4f_copy(ILDA_vector4f* base, const ILDA_vector4f* copy);

//Operators
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector2f_equal(const ILDA_vector2f* base, const ILDA_vector2f* compare);
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector3f_equal(const ILDA_vector3f* base, const ILDA_vector3f* compare);
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector4f_equal(const ILDA_vector4f* base, const ILDA_vector4f* compare);

//Addition
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector2f_add(ILDA_vector2f* augend, const ILDA_vector2f* addend);
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector3f_add(ILDA_vector3f* augend, const ILDA_vector3f* addend);
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector4f_add(ILDA_vector4f* augend, const ILDA_vector4f* addend);

//Subtraction
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector2f_sub(ILDA_vector2f* minuend, const ILDA_vector2f* subtrahend);
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector3f_sub(ILDA_vector3f* minuend, const ILDA_vector3f* subtrahend);
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector4f_sub(ILDA_vector4f* minuend, const ILDA_vector4f* subtrahend);

//Multiplication
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector2f_mul(ILDA_vector2f* vector2, const float lambda);
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector3f_mul(ILDA_vector3f* vector3, const float lambda);
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector4f_mul(ILDA_vector4f* vector4, const float lambda);

//get length
ILDA_EXTERN_INLINE float ILDA_vector2f_length(const ILDA_vector2f* vector2);
ILDA_EXTERN_INLINE float ILDA_vector3f_length(const ILDA_vector3f* vector3);
ILDA_EXTERN_INLINE float ILDA_vector4f_length(const ILDA_vector4f* vector4);

//specials
ILDA_EXTERN_INLINE ILDA_vector2f ILDA_vector2f_normalize(const ILDA_vector2f* vector2);
ILDA_EXTERN_INLINE ILDA_vector3f ILDA_vector3f_normalize(const ILDA_vector3f* vector3);
ILDA_EXTERN_INLINE ILDA_vector4f ILDA_vector4f_normalize(const ILDA_vector4f* vector4);

ILDA_EXTERN_INLINE ILDA_vector3f ILDA_vector3f_cross(const ILDA_vector3f* a, const ILDA_vector3f* b);

ILDA_EXTERN_INLINE float ILDA_vector2f_dot(const ILDA_vector2f* a, const ILDA_vector2f* b);
ILDA_EXTERN_INLINE float ILDA_vector3f_dot(const ILDA_vector3f* a, const ILDA_vector3f* b);
ILDA_EXTERN_INLINE float ILDA_vector4f_dot(const ILDA_vector4f* a, const ILDA_vector4f* b);

#endif