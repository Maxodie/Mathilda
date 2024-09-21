#ifdef __ILDA_MATRIX_SOURCE_CHECK__
	ILDA_STATIC_ASSERT(false, "ILDA MATRIX SOURCE : file is called but it was already on");
#endif

#define __ILDA_MATRIX_SOURCE_CHECK__

#include <string.h>
//init
//ILDA_bool CONCAT2(ILDA_MATRIX(ILDA_matrix), init_alloc)( size_t rowCount, size_t colCount, ILDA_MATRIX(ILDA_matrix)* matrix)
//{
//	matrix->data = calloc(colCount * rowCount, sizeof(ILDA_BASE_TYPE)); //also try with void* and ILDA_BASE_TYPE*
//
//	if (NULL == matrix->data) return ILDA_FAIL;
//
//	ILDA_MATRIX_ROW = rowCount;
//	ILDA_MATRIX_COL = colCount;
//
//	return ILDA_SUCCESS;
//}

ILDA_bool CONCAT2(ILDA_MATRIX(ILDA_matrix), init_identity)(ILDA_MATRIX(ILDA_matrix)* matrix, float v)
{
	int i;
	for (i = 0; i < ILDA_MATRIX_ROW; i++)//assuming the matrix is squar
	{
		matrix->data[i][i] = v;
	}

	return ILDA_SUCCESS;
}

//get / set
ILDA_BASE_TYPE CONCAT2(ILDA_MATRIX(ILDA_matrix), get)(size_t row, size_t col, const ILDA_MATRIX(ILDA_matrix)* matrix)
{
	return matrix->data[row][col]; // same as *(matrix->data + row * ILDA_MATRIX_ROW + col)
}

void CONCAT2(ILDA_MATRIX(ILDA_matrix), set)(size_t row, size_t col, ILDA_MATRIX(ILDA_matrix)* matrix, ILDA_BASE_TYPE value)
{
	matrix->data[row][col] = value;
}

//operators
ILDA_bool CONCAT2(ILDA_MATRIX(ILDA_matrix), add)(ILDA_MATRIX(ILDA_matrix)* m1, const ILDA_MATRIX(ILDA_matrix)* m2)
{
	/*size_t i, j;
	for (i = 0; i < ILDA_MATRIX_ROW; i++)
	{
		for (j = 0; j < ILDA_MATRIX_COL; j++)
		{
			augend->data[i][j] += addend->data[i][j];
		}
	}*/

#ifdef ILDA_MATRIX4x4
	m1->data[0][0] += m2->data[0][0];
	m1->data[0][1] += m2->data[0][1];
	m1->data[0][2] += m2->data[0][2];
	m1->data[0][3] += m2->data[0][3];
	m1->data[1][0] += m2->data[1][0];
	m1->data[1][1] += m2->data[1][1];
	m1->data[1][2] += m2->data[1][2];
	m1->data[1][3] += m2->data[1][3];
	m1->data[2][0] += m2->data[2][0];
	m1->data[2][1] += m2->data[2][1];
	m1->data[2][2] += m2->data[2][2];
	m1->data[2][3] += m2->data[2][3];
	m1->data[3][0] += m2->data[3][0];
	m1->data[3][1] += m2->data[3][1];
	m1->data[3][2] += m2->data[3][2];
	m1->data[3][3] += m2->data[3][3];

#elif defined ILDA_MATRIX3x3
	m1->data[0][0] += m2->data[0][0];
	m1->data[0][1] += m2->data[0][1];
	m1->data[0][2] += m2->data[0][2];
	m1->data[1][0] += m2->data[1][0];
	m1->data[1][1] += m2->data[1][1];
	m1->data[1][2] += m2->data[1][2];
	m1->data[2][0] += m2->data[2][0];
	m1->data[2][1] += m2->data[2][1];
	m1->data[2][2] += m2->data[2][2];

#elif defined ILDA_MATRIX2x2
	m1->data[0][0] += m2->data[0][0];
	m1->data[0][1] += m2->data[0][1];
	m1->data[1][0] += m2->data[1][0];
	m1->data[1][1] += m2->data[1][1];

#endif

	return ILDA_SUCCESS;
}


ILDA_MATRIX(ILDA_matrix) CONCAT2(ILDA_MATRIX(ILDA_matrix), add_c)(const ILDA_MATRIX(ILDA_matrix)* augend, const ILDA_MATRIX(ILDA_matrix)* addend)
{
	ILDA_MATRIX(ILDA_matrix) matrix = {0};
	memcpy(matrix.data, augend->data, sizeof(augend->data));
	CONCAT2(ILDA_MATRIX(ILDA_matrix), add)(&matrix, addend);
	return matrix;
}

ILDA_bool CONCAT2(ILDA_MATRIX(ILDA_matrix), sub)(ILDA_MATRIX(ILDA_matrix)* m1, const ILDA_MATRIX(ILDA_matrix)* m2)
{
	/*size_t i, j;
	for (i = 0; i < ILDA_MATRIX_ROW; i++)
	{
		for (j = 0; j < ILDA_MATRIX_COL; j++)
		{
			minuend->data[i][j] -= subtrahend->data[i][j];
		}
	}*/

#ifdef ILDA_MATRIX4x4
	m1->data[0][0] -= m2->data[0][0];
	m1->data[0][1] -= m2->data[0][1];
	m1->data[0][2] -= m2->data[0][2];
	m1->data[0][3] -= m2->data[0][3];
	m1->data[1][0] -= m2->data[1][0];
	m1->data[1][1] -= m2->data[1][1];
	m1->data[1][2] -= m2->data[1][2];
	m1->data[1][3] -= m2->data[1][3];
	m1->data[2][0] -= m2->data[2][0];
	m1->data[2][1] -= m2->data[2][1];
	m1->data[2][2] -= m2->data[2][2];
	m1->data[2][3] -= m2->data[2][3];
	m1->data[3][0] -= m2->data[3][0];
	m1->data[3][1] -= m2->data[3][1];
	m1->data[3][2] -= m2->data[3][2];
	m1->data[3][3] -= m2->data[3][3];

#elif defined ILDA_MATRIX3x3
	m1->data[0][0] -= m2->data[0][0];
	m1->data[0][1] -= m2->data[0][1];
	m1->data[0][2] -= m2->data[0][2];
	m1->data[1][0] -= m2->data[1][0];
	m1->data[1][1] -= m2->data[1][1];
	m1->data[1][2] -= m2->data[1][2];
	m1->data[2][0] -= m2->data[2][0];
	m1->data[2][1] -= m2->data[2][1];
	m1->data[2][2] -= m2->data[2][2];

#elif defined ILDA_MATRIX2x2
	m1->data[0][0] -= m2->data[0][0];
	m1->data[0][1] -= m2->data[0][1];
	m1->data[1][0] -= m2->data[1][0];
	m1->data[1][1] -= m2->data[1][1];

#endif

	return ILDA_SUCCESS;
}


ILDA_MATRIX(ILDA_matrix) CONCAT2(ILDA_MATRIX(ILDA_matrix), sub_c)(const ILDA_MATRIX(ILDA_matrix)* minuend, const ILDA_MATRIX(ILDA_matrix)* subtrahend)
{
	ILDA_MATRIX(ILDA_matrix) matrix = { 0 };
	memcpy(matrix.data, minuend->data, sizeof(minuend->data));
	CONCAT2(ILDA_MATRIX(ILDA_matrix), sub)(&matrix, subtrahend);
	return matrix;
}

/// MULTIPLICATIONS

EXTERN ILDA_bool CONCAT2(ILDA_MATRIX(ILDA_matrix), mul_same_source)(ILDA_MATRIX(ILDA_matrix)* container, const  ILDA_MATRIX(ILDA_matrix)* m1, const  ILDA_MATRIX(ILDA_matrix)* m2)
{

#ifdef ILDA_MATRIX4x4
	container->data[0][0] = m1->data[0][0] * m2->data[0][0] + m1->data[0][1] * m2->data[1][0] + m1->data[0][2] * m2->data[2][0] + m1->data[0][3] * m2->data[3][0];
	container->data[0][1] = m1->data[0][0] * m2->data[0][1] + m1->data[0][1] * m2->data[1][1] + m1->data[0][2] * m2->data[2][1] + m1->data[0][3] * m2->data[3][1];
	container->data[0][2] = m1->data[0][0] * m2->data[0][2] + m1->data[0][1] * m2->data[1][2] + m1->data[0][2] * m2->data[2][2] + m1->data[0][3] * m2->data[3][2];
	container->data[0][3] = m1->data[0][0] * m2->data[0][3] + m1->data[0][1] * m2->data[1][3] + m1->data[0][2] * m2->data[2][3] + m1->data[0][3] * m2->data[3][3];

	container->data[1][0] = m1->data[1][0] * m2->data[0][0] + m1->data[1][1] * m2->data[1][0] + m1->data[1][2] * m2->data[2][0] + m1->data[1][3] * m2->data[3][0];
	container->data[1][1] = m1->data[1][0] * m2->data[0][1] + m1->data[1][1] * m2->data[1][1] + m1->data[1][2] * m2->data[2][1] + m1->data[1][3] * m2->data[3][1];
	container->data[1][2] = m1->data[1][0] * m2->data[0][2] + m1->data[1][1] * m2->data[1][2] + m1->data[1][2] * m2->data[2][2] + m1->data[1][3] * m2->data[3][2];
	container->data[1][3] = m1->data[1][0] * m2->data[0][3] + m1->data[1][1] * m2->data[1][3] + m1->data[1][2] * m2->data[2][3] + m1->data[1][3] * m2->data[3][3];

	container->data[2][0] = m1->data[2][0] * m2->data[0][0] + m1->data[2][1] * m2->data[1][0] + m1->data[2][2] * m2->data[2][0] + m1->data[2][3] * m2->data[3][0];
	container->data[2][1] = m1->data[2][0] * m2->data[0][1] + m1->data[2][1] * m2->data[1][1] + m1->data[2][2] * m2->data[2][1] + m1->data[2][3] * m2->data[3][1];
	container->data[2][2] = m1->data[2][0] * m2->data[0][2] + m1->data[2][1] * m2->data[1][2] + m1->data[2][2] * m2->data[2][2] + m1->data[2][3] * m2->data[3][2];
	container->data[2][3] = m1->data[2][0] * m2->data[0][3] + m1->data[2][1] * m2->data[1][3] + m1->data[2][2] * m2->data[2][3] + m1->data[2][3] * m2->data[3][3];

	container->data[3][0] = m1->data[3][0] * m2->data[0][0] + m1->data[3][1] * m2->data[1][0] + m1->data[3][2] * m2->data[2][0] + m1->data[3][3] * m2->data[3][0];
	container->data[3][1] = m1->data[3][0] * m2->data[0][1] + m1->data[3][1] * m2->data[1][1] + m1->data[3][2] * m2->data[2][1] + m1->data[3][3] * m2->data[3][1];
	container->data[3][2] = m1->data[3][0] * m2->data[0][2] + m1->data[3][1] * m2->data[1][2] + m1->data[3][2] * m2->data[2][2] + m1->data[3][3] * m2->data[3][2];
	container->data[3][3] = m1->data[3][0] * m2->data[0][3] + m1->data[3][1] * m2->data[1][3] + m1->data[3][2] * m2->data[2][3] + m1->data[3][3] * m2->data[3][3];

#elif defined ILDA_MATRIX3x3
	container->data[0][0] = m1->data[0][0] * m2->data[0][0] + m1->data[0][1] * m2->data[1][0] + m1->data[0][2] * m2->data[2][0];
	container->data[0][1] = m1->data[0][0] * m2->data[0][1] + m1->data[0][1] * m2->data[1][1] + m1->data[0][2] * m2->data[2][1];
	container->data[0][2] = m1->data[0][0] * m2->data[0][2] + m1->data[0][1] * m2->data[1][2] + m1->data[0][2] * m2->data[2][2];

	container->data[1][0] = m1->data[1][0] * m2->data[0][0] + m1->data[1][1] * m2->data[1][0] + m1->data[1][2] * m2->data[2][0];
	container->data[1][1] = m1->data[1][0] * m2->data[0][1] + m1->data[1][1] * m2->data[1][1] + m1->data[1][2] * m2->data[2][1];
	container->data[1][2] = m1->data[1][0] * m2->data[0][2] + m1->data[1][1] * m2->data[1][2] + m1->data[1][2] * m2->data[2][2];

	container->data[2][0] = m1->data[2][0] * m2->data[0][0] + m1->data[2][1] * m2->data[1][0] + m1->data[2][2] * m2->data[2][0];
	container->data[2][1] = m1->data[2][0] * m2->data[0][1] + m1->data[2][1] * m2->data[1][1] + m1->data[2][2] * m2->data[2][1];
	container->data[2][2] = m1->data[2][0] * m2->data[0][2] + m1->data[2][1] * m2->data[1][2] + m1->data[2][2] * m2->data[2][2];

#elif defined ILDA_MATRIX2x2
	container->data[0][0] = m1->data[0][0] * m2->data[0][0] + m1->data[0][1] * m2->data[1][0];
	container->data[0][1] = m1->data[0][0] * m2->data[0][1] + m1->data[0][1] * m2->data[1][1];

	container->data[1][0] = m1->data[1][0] * m2->data[0][0] + m1->data[1][1] * m2->data[1][0];
	container->data[1][1] = m1->data[1][0] * m2->data[0][1] + m1->data[1][1] * m2->data[1][1];
#endif

	return ILDA_SUCCESS;
}

ILDA_bool CONCAT2(ILDA_MATRIX(ILDA_matrix), mul_same)(ILDA_MATRIX(ILDA_matrix)* m1, const ILDA_MATRIX(ILDA_matrix)* m2)
{
	ILDA_MATRIX(ILDA_matrix) matrix = { 0 };
	memcpy(matrix.data, m1->data, sizeof(m1->data));
	CONCAT2(ILDA_MATRIX(ILDA_matrix), mul_same_source)(m1, &matrix, m2);
}


ILDA_MATRIX(ILDA_matrix) CONCAT2(ILDA_MATRIX(ILDA_matrix), mul_same_c)(const ILDA_MATRIX(ILDA_matrix)* multiplicand, const ILDA_MATRIX(ILDA_matrix)* multiplier)
{
	ILDA_MATRIX(ILDA_matrix) matrix = { 0 };
	CONCAT2(ILDA_MATRIX(ILDA_matrix), mul_same_source)(&matrix, multiplicand, multiplier);
	return matrix;
}


ILDA_MATRIX_VECTOR_SIZE CONCAT2(ILDA_MATRIX(ILDA_matrix), mul_vector)(const ILDA_MATRIX(ILDA_matrix)* multiplicand, const ILDA_MATRIX_VECTOR_SIZE* multiplier)
{
#ifdef ILDA_MATRIX4x4

	ILDA_BASE_TYPE vectorSaved[ILDA_MATRIX_COL] = { multiplier->x, multiplier->y, multiplier->z, multiplier->w };

#elif defined(ILDA_MATRIX3x3)

	ILDA_BASE_TYPE vectorSaved[ILDA_MATRIX_COL] = { multiplier->x, multiplier->y, multiplier->z };

#elif defined(ILDA_MATRIX2x2)

	ILDA_BASE_TYPE vectorSaved[ILDA_MATRIX_COL] = { multiplier->x, multiplier->y };

#endif // ILDA_MATRIX4x4

	ILDA_BASE_TYPE vector[ILDA_MATRIX_COL] = { 0 };
	size_t i, k;
	for (i = 0; i < ILDA_MATRIX_ROW; i++)
	{
		for (k = 0; k < ILDA_MATRIX_COL; k++)
		{
			vector[i] += multiplicand->data[i][k] * vectorSaved[k];
		}
	}

#ifdef ILDA_MATRIX4x4

	ILDA_MATRIX_VECTOR_SIZE result = { .x = vector[0], .y = vector[1], .z = vector[2], .w = vector[3] };

#elif defined(ILDA_MATRIX3x3)

	ILDA_MATRIX_VECTOR_SIZE result = { .x = vector[0], .y = vector[1], .z = vector[2] };

#elif defined(ILDA_MATRIX2x2)

	ILDA_MATRIX_VECTOR_SIZE result = { .x = vector[0], .y = vector[1] };

#endif
		
	return result;
}