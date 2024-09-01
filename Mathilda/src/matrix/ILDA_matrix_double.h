#ifndef __ILDA_MATRIX_INT__
#define __ILDA_MATRIX_INT__

#include "ILDA_core.h"

typedef struct ILDA_matrix {
	double* data;
	size_t rowCount, colCount;
} ILDA_matrix;

//init
ILDA_bool ILDA_matrix_init_alloc(size_t rowCount, size_t colCount, ILDA_matrix* matrix);

//get / set
INLINE_FUN double ILDA_matrix_get(size_t row, size_t col, ILDA_matrix* matrix);
INLINE_FUN void ILDA_matrix_set(size_t row, size_t col, ILDA_matrix* matrix, double value);

//operators
ILDA_bool ILDA_matrix_add(ILDA_matrix *augend, const ILDA_matrix *addend);

ILDA_bool ILDA_matrix_sub(ILDA_matrix* minuend, const ILDA_matrix* subtrahend);

//ILDA_bool ILDA_matrix_mul(ILDA_matrix* augend, const ILDA_matrix* addend);


//basics
//INLINE_FUN ILDA_bool ILDA_matrix_init_identity(unsigned int rows, unsigned int cols, ILDA_matrix* matrix, int value);
#endif