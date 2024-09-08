#ifdef __ILDA_MATRIX_SOURCE_CHECK__
	ILDA_STATIC_ASSERT(false, "ILDA MATRIX SOURCE : file is called but it was already on");
#endif

#define __ILDA_MATRIX_SOURCE_CHECK__

#include <string.h>
//init
//ILDA_bool ILDA_FUNCTION(ILDA_MATRIX(ILDA_matrix), init_alloc)( size_t rowCount, size_t colCount, ILDA_MATRIX(ILDA_matrix)* matrix)
//{
//	matrix->data = calloc(colCount * rowCount, sizeof(ILDA_BASE_TYPE)); //also try with void* and ILDA_BASE_TYPE*
//
//	if (NULL == matrix->data) return ILDA_FAIL;
//
//	matrix->rowCount = rowCount;
//	matrix->colCount = colCount;
//
//	return ILDA_SUCCESS;
//}

	ILDA_bool ILDA_FUNCTION(ILDA_MATRIX(ILDA_matrix), init_default)(ILDA_MATRIX(ILDA_matrix)* matrix)
	{
		matrix->colCount = ILDA_MATRIX_COL;
		matrix->rowCount = ILDA_MATRIX_COL;

		return ILDA_SUCCESS;
	}

	//get / set
	ILDA_BASE_TYPE ILDA_FUNCTION(ILDA_MATRIX(ILDA_matrix), get)(size_t row, size_t col, const ILDA_MATRIX(ILDA_matrix)* matrix)
	{
		return matrix->data[row][col]; // same as *(matrix->data + row * matrix->rowCount + col)
	}

	void ILDA_FUNCTION(ILDA_MATRIX(ILDA_matrix), set)(size_t row, size_t col, ILDA_MATRIX(ILDA_matrix)* matrix, ILDA_BASE_TYPE value)
	{
		matrix->data[row][col] = value;
	}

	//operators
	ILDA_bool ILDA_FUNCTION(ILDA_MATRIX(ILDA_matrix), add)(ILDA_MATRIX(ILDA_matrix)* augend, const ILDA_MATRIX(ILDA_matrix)* addend)
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

	ILDA_bool ILDA_FUNCTION(ILDA_MATRIX(ILDA_matrix), sub)(ILDA_MATRIX(ILDA_matrix)* minuend, const ILDA_MATRIX(ILDA_matrix)* subtrahend)
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

	ILDA_bool ILDA_FUNCTION(ILDA_MATRIX(ILDA_matrix), mul_same)(ILDA_MATRIX(ILDA_matrix)* multiplicand, const ILDA_MATRIX(ILDA_matrix)* multiplier)
	{
		size_t i, j, k;
		ILDA_BASE_TYPE saveMul[ILDA_MATRIX_COL][ILDA_MATRIX_COL];
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

	ILDA_MATRIX_VECTOR_SIZE ILDA_FUNCTION(ILDA_MATRIX(ILDA_matrix), mul_vector)(const ILDA_MATRIX(ILDA_matrix)* multiplicand, const ILDA_MATRIX_VECTOR_SIZE* multiplier)
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
		for (i = 0; i < multiplicand->rowCount; i++)
		{
			for (k = 0; k < multiplicand->colCount; k++)
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