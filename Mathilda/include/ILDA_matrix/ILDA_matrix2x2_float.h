#ifndef __ILDA_MATRIX2x2_DOUBLE__
#define __ILDA_MATRIX2x2_DOUBLE__

#include "ILDA_vector/ILDA_vector_float.h"

typedef struct ILDA_matrix2x2 {
	float data[2][2];
} ILDA_matrix2x2;

//default
static const ILDA_matrix2x2 ILDA_mat2x2_identity = { .data = {{1,0}, {0,1}} };
static const size_t ILDA_matrix2x2_row = 2;
static const size_t ILDA_matrix2x2_col = 2;

//init
//ILDA_bool ILDA_matrix2x2_init_alloc(ILDA_matrix2x2 matrix);
ILDA_FUN_DECL ILDA_bool ILDA_matrix2x2_init_identity(ILDA_matrix2x2* matrix, float v);

//get / setB
ILDA_FUN_DECL float ILDA_matrix2x2_get(size_t row, size_t col, const ILDA_matrix2x2* matrix);
ILDA_FUN_DECL void ILDA_matrix2x2_set(size_t row, size_t col, ILDA_matrix2x2* matrix, float value);

//basic operators
ILDA_FUN_DECL ILDA_bool ILDA_matrix2x2_add(ILDA_matrix2x2* m1, const ILDA_matrix2x2* m2);
ILDA_FUN_DECL ILDA_matrix2x2 ILDA_matrix2x2_add_c(const ILDA_matrix2x2* augend, const ILDA_matrix2x2* addend);


ILDA_FUN_DECL ILDA_bool ILDA_matrix2x2_sub(ILDA_matrix2x2* m1, const ILDA_matrix2x2* m2);
ILDA_FUN_DECL ILDA_matrix2x2 ILDA_matrix2x2_sub_c(const ILDA_matrix2x2* minuend, const ILDA_matrix2x2* subtrahend);

//do not put the same matrix in container and in m1 or m2
ILDA_FUN_DECL ILDA_bool ILDA_matrix2x2_mul_same_source(ILDA_matrix2x2* container, const ILDA_matrix2x2* m1, const ILDA_matrix2x2* m2);
ILDA_FUN_DECL ILDA_bool ILDA_matrix2x2_mul_same(ILDA_matrix2x2* m1, const ILDA_matrix2x2* m2);
ILDA_FUN_DECL ILDA_matrix2x2 ILDA_matrix2x2_mul_same_c(const ILDA_matrix2x2* multiplicand, const ILDA_matrix2x2* multiplier);


ILDA_FUN_DECL ILDA_vector2f ILDA_matrix2x2_mul_vector(const ILDA_matrix2x2* multiplicand, const ILDA_vector2f* multiplier);

//basics
#endif
