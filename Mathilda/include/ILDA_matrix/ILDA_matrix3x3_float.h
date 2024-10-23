#ifndef __ILDA_MATRIX3x3_DOUBLE__
#define __ILDA_MATRIX3x3_DOUBLE__

#include "ILDA_vector/ILDA_vector_float.h"

typedef struct ILDA_matrix3x3 {
	float data[3][3];
} ILDA_matrix3x3;

//default
static const ILDA_matrix3x3 ILDA_mat3x3_identity = { .data = {{1,0,0}, {0,1,0}, {0,0,1}} };
static const size_t ILDA_matrix3x3_row = 3;
static const size_t ILDA_matrix3x3_col = 3;

//init
//ILDA_bool ILDA_matrix3x3_init_alloc(ILDA_matrix3x3 matrix);
EXTERN_INLINE ILDA_bool ILDA_matrix3x3_init_identity(ILDA_matrix3x3* matrix, float v);

//get / setB
EXTERN_INLINE float ILDA_matrix3x3_get(size_t row, size_t col, const ILDA_matrix3x3* matrix);
EXTERN_INLINE void ILDA_matrix3x3_set(size_t row, size_t col, ILDA_matrix3x3* matrix, float value);

//basic operators
EXTERN_INLINE ILDA_bool ILDA_matrix3x3_add(ILDA_matrix3x3* m1, const ILDA_matrix3x3* m2);
EXTERN_INLINE ILDA_matrix3x3 ILDA_matrix3x3_add_c(const ILDA_matrix3x3* augend, const ILDA_matrix3x3* addend);


EXTERN_INLINE ILDA_bool ILDA_matrix3x3_sub(ILDA_matrix3x3* m1, const ILDA_matrix3x3* m2);
EXTERN_INLINE ILDA_matrix3x3 ILDA_matrix3x3_sub_c(const ILDA_matrix3x3* minuend, const ILDA_matrix3x3* subtrahend);

//do not put the same matrix in container and in m1 or m2
EXTERN_INLINE ILDA_bool ILDA_matrix3x3_mul_same_source(ILDA_matrix3x3* container, const ILDA_matrix3x3* m1, const ILDA_matrix3x3* m2);
EXTERN_INLINE ILDA_bool ILDA_matrix3x3_mul_same(ILDA_matrix3x3* m1, const ILDA_matrix3x3* m2);
EXTERN_INLINE ILDA_matrix3x3 ILDA_matrix3x3_mul_same_c(const ILDA_matrix3x3* multiplicand, const ILDA_matrix3x3* multiplier);


EXTERN_INLINE ILDA_vector3f ILDA_matrix3x3_mul_vector(const ILDA_matrix3x3* multiplicand, const ILDA_vector3f* multiplier);

//basics
#endif
