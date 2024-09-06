#ifdef __ILDA_MATRIX_SOURCE_CHECK__
	ILDA_STATIC_ASSERT(false, "ILDA MATRIX SOURCE : file is called but it was already on");
#endif

#define __ILDA_MATRIX_SOURCE_CHECK__

#include <string.h>
//init
//ILDA_bool ILDA_FUNCTION(ILDA_matrix4x4, init_alloc)( size_t rowCount, size_t colCount, ILDA_matrix4x4* matrix)
//{
//	matrix->data = calloc(colCount * rowCount, sizeof(double)); //also try with void* and double*
//
//	if (NULL == matrix->data) return ILDA_FAIL;
//
//	matrix->rowCount = rowCount;
//	matrix->colCount = colCount;
//
//	return ILDA_SUCCESS;
//}

ILDA_bool ILDA_FUNCTION(ILDA_matrix4x4, init_default)(ILDA_matrix4x4* matrix)
{
		matrix->colCount = 4;
		matrix->rowCount = 4;

	return ILDA_SUCCESS;
}

//get / set
double ILDA_FUNCTION(ILDA_matrix4x4, get)(size_t row, size_t col, const ILDA_matrix4x4* matrix)
{
	return matrix->data[row][col]; // same as *(matrix->data + row * matrix->rowCount + col)
}

void ILDA_FUNCTION(ILDA_matrix4x4, set)(size_t row, size_t col, ILDA_matrix4x4* matrix, double value)
{
	matrix->data[row][col] = value;
}

//operators
ILDA_bool ILDA_FUNCTION(ILDA_matrix4x4, add)(ILDA_matrix4x4* augend, const ILDA_matrix4x4* addend)
{
	size_t i, j;
	for (i = 0; i < augend->rowCount; i++)
	{
		for (j = 0; j < augend->colCount; j++)
		{
			augend->data[i][j] += addend->data[i][j];
		}
	}

	return ILDA_SUCCESS;
}

ILDA_bool ILDA_FUNCTION(ILDA_matrix4x4, sub)(ILDA_matrix4x4* minuend, const ILDA_matrix4x4* subtrahend)
{
	size_t i, j;
	for (i = 0; i < minuend->rowCount; i++)
	{
		for (j = 0; j < minuend->colCount; j++)
		{
			minuend->data[i][j] -= subtrahend->data[i][j];
		}
	}

	return ILDA_SUCCESS;
}

ILDA_bool ILDA_FUNCTION(ILDA_matrix4x4, mul_same)(ILDA_matrix4x4* multiplicand, const ILDA_matrix4x4* multiplier)
{
	size_t i, j, k;
	double saveMul[4][4];
	memcpy(saveMul, multiplicand->data, sizeof(saveMul));
	for (i = 0; i < multiplicand->rowCount; i++)
	{
		for (j = 0; j < multiplicand->colCount; j++)
		{
			multiplicand->data[i][j] = 0;
			for (k = 0; k < multiplicand->colCount; k++)
			{
				multiplicand->data[i][j] += multiplier->data[i][k] * saveMul[k][j];
			}

		}
	}

	return ILDA_SUCCESS;
}

ILDA_vector4 ILDA_FUNCTION(ILDA_matrix4x4, mul_vector)(const ILDA_matrix4x4* multiplicand, const ILDA_vector4* multiplier)
{
	double vector4Saved[4] = { multiplier->x, multiplier->y, multiplier->z, multiplier->w };
	double vector4[4] = {0};
	size_t i, j, k;
	for (i = 0; i < multiplicand->rowCount; i++)
	{
		for (k = 0; k < multiplicand->colCount; k++)
		{
			vector4[i] += multiplicand->data[i][k] * vector4Saved[k];
		}
	}
	ILDA_vector4 result = { .x = vector4[0], .y = vector4[1], .z = vector4[2], .w = vector4[3] };
	return result;
}