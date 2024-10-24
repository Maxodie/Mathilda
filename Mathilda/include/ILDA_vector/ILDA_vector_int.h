#ifndef __ILDA_VECTOR_INT__
#define __ILDA_VECTOR_INT__

#include "ILDA_vector/ILDA_vector_float.h"

typedef struct {
	int x;
	int y;
} ILDA_vector2i;

typedef struct {
	int x;
	int y;
	int z;
} ILDA_vector3i;

typedef struct {
	int x;
	int y;
	int z;
	int w;
} ILDA_vector4i;

//copy
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector2i_copy(ILDA_vector2i* base, const ILDA_vector2i* copy);
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector3i_copy(ILDA_vector3i* base, const ILDA_vector3i* copy);
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector4i_copy(ILDA_vector4i* base, const ILDA_vector4i* copy);

//Operators
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector2i_equal(const ILDA_vector2i* base, const ILDA_vector2i* compare);
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector3i_equal(const ILDA_vector3i* base, const ILDA_vector3i* compare);
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector4i_equal(const ILDA_vector4i* base, const ILDA_vector4i* compare);

//Addition
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector2i_add(ILDA_vector2i* augend, const ILDA_vector2i* addend);
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector3i_add(ILDA_vector3i* augend, const ILDA_vector3i* addend);
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector4i_add(ILDA_vector4i* augend, const ILDA_vector4i* addend);

//Subtraction
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector2i_sub(ILDA_vector2i* minuend, const ILDA_vector2i* subtrahend);
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector3i_sub(ILDA_vector3i* minuend, const ILDA_vector3i* subtrahend);
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector4i_sub(ILDA_vector4i* minuend, const ILDA_vector4i* subtrahend);

//Multiplication
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector2i_mul(ILDA_vector2i* vector2, const int lambda);
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector3i_mul(ILDA_vector3i* vector3, const int lambda);
ILDA_EXTERN_INLINE ILDA_bool ILDA_vector4i_mul(ILDA_vector4i* vector4, const int lambda);

//get length
ILDA_EXTERN_INLINE float ILDA_vector2i_length(const ILDA_vector2i* vector2);
ILDA_EXTERN_INLINE float ILDA_vector3i_length(const ILDA_vector3i* vector3);
ILDA_EXTERN_INLINE float ILDA_vector4i_length(const ILDA_vector4i* vector4);

//specials
ILDA_EXTERN_INLINE ILDA_vector2f ILDA_vector2i_normalize(const ILDA_vector2i* vector2);
ILDA_EXTERN_INLINE ILDA_vector3f ILDA_vector3i_normalize(const ILDA_vector3i* vector3);
ILDA_EXTERN_INLINE ILDA_vector4f ILDA_vector4i_normalize(const ILDA_vector4i* vector4);

ILDA_EXTERN_INLINE ILDA_vector3i ILDA_vector3i_cross(const ILDA_vector3i* a, const ILDA_vector3i* b);

ILDA_EXTERN_INLINE int ILDA_vector2i_dot(const ILDA_vector2i* a, const ILDA_vector2i* b);
ILDA_EXTERN_INLINE int ILDA_vector3i_dot(const ILDA_vector3i* a, const ILDA_vector3i* b);
ILDA_EXTERN_INLINE int ILDA_vector4i_dot(const ILDA_vector4i* a, const ILDA_vector4i* b);

#endif