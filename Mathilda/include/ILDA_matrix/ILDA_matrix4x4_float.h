#ifndef __ILDA_MATRIX4x4_DOUBLE__
#define __ILDA_MATRIX4x4_DOUBLE__

#include "ILDA_vector/ILDA_vector_float.h"

typedef struct ILDA_matrix4x4 {
	float data[4][4];
} ILDA_matrix4x4;

//default
static const ILDA_matrix4x4 ILDA_matrix4x4_identity = { .data = {{1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,1}} };
static const size_t ILDA_matrix4x4_row = 4;
static const size_t ILDA_matrix4x4_col = 4;

//init
//ILDA_bool ILDA_matrix4x4_init_alloc(ILDA_matrix4x4 matrix);
EXTERN_INLINE ILDA_bool ILDA_matrix4x4_init_identity(ILDA_matrix4x4* matrix, float v);

//get / setB
EXTERN_INLINE float ILDA_matrix4x4_get(size_t row, size_t col, const ILDA_matrix4x4* matrix);
EXTERN_INLINE void ILDA_matrix4x4_set(size_t row, size_t col, ILDA_matrix4x4* matrix, float value);

//basic operators
EXTERN_INLINE ILDA_bool ILDA_matrix4x4_add(ILDA_matrix4x4* m1, const ILDA_matrix4x4* m2);
EXTERN_INLINE ILDA_matrix4x4 ILDA_matrix4x4_add_c(const ILDA_matrix4x4* augend, const ILDA_matrix4x4* addend);


EXTERN_INLINE ILDA_bool ILDA_matrix4x4_sub(ILDA_matrix4x4* m1, const ILDA_matrix4x4* m2);
EXTERN_INLINE ILDA_matrix4x4 ILDA_matrix4x4_sub_c(const ILDA_matrix4x4* minuend, const ILDA_matrix4x4* subtrahend);

//do not put the same matrix in container and in m1 or m2
EXTERN_INLINE ILDA_bool ILDA_matrix4x4_mul_same_source(ILDA_matrix4x4* container, const ILDA_matrix4x4* m1, const ILDA_matrix4x4* m2);
EXTERN_INLINE ILDA_bool ILDA_matrix4x4_mul_same(ILDA_matrix4x4* m1, const ILDA_matrix4x4* m2);
EXTERN_INLINE ILDA_matrix4x4 ILDA_matrix4x4_mul_same_c(const ILDA_matrix4x4* multiplicand, const ILDA_matrix4x4* multiplier);


EXTERN_INLINE ILDA_vector4f ILDA_matrix4x4_mul_vector(const ILDA_matrix4x4* multiplicand, const ILDA_vector4f* multiplier);

//matrix4x4 only
//TODO : translate fun
EXTERN_INLINE ILDA_bool ILDA_scale(ILDA_matrix4x4* matrix4x4, const ILDA_vector3f* scale);
//TODO : rotate fun
EXTERN_INLINE ILDA_matrix4x4 ILDA_translation(const ILDA_matrix4x4* identity, const ILDA_vector3f* translation);
EXTERN_INLINE ILDA_matrix4x4 ILDA_rotation(float rotation, const ILDA_vector3f* vector3);
//Look at target right handed for opengl TODO : left handed version for directX, Metal, Vulkan
EXTERN_INLINE ILDA_matrix4x4 ILDA_matrix_look_at_r(const ILDA_vector3f* position, const ILDA_vector3f* target, const ILDA_vector3f* worldUp);
//Look at target right handed for opengl TODO : left handed version for directX, Metal, Vulkan
EXTERN_INLINE ILDA_matrix4x4 ILDA_matrix_perspective_r(float fovy, float aspect, float zNear, float zFar);
//basics
#endif
