#ifdef __ILDA_MATRIX_SOURCE_CHECK__
	ILDA_STATIC_ASSERT(false, "ILDA MATRIX SOURCE : file is called but it was already on");
#endif

#define __ILDA_MATRIX_SOURCE_CHECK__

//init
ILDA_bool ILDA_FUNCTION(ILDA_matrix, init_alloc)( size_t rowCount, size_t colCount, ILDA_matrix* matrix)
{
	matrix->data = calloc(colCount * rowCount, sizeof(double)); //also try with void* and double*

	if (NULL == matrix->data) return ILDA_FAIL;

	matrix->rowCount = rowCount;
	matrix->colCount = colCount;

	return ILDA_SUCCESS;
}

//get / set
double ILDA_FUNCTION(ILDA_matrix, get)(size_t row, size_t col, ILDA_matrix* matrix)
{
	return matrix->data[row * matrix->rowCount + col]; // same as *(matrix->data + row * matrix->rowCount + col)
}

void ILDA_FUNCTION(ILDA_matrix, set)(size_t row, size_t col, ILDA_matrix* matrix, double value)
{
	matrix->data[row * matrix->rowCount + col] = value;
}

//operators
ILDA_bool ILDA_FUNCTION(ILDA_matrix, add)(ILDA_matrix* augend, const ILDA_matrix* addend)
{
	size_t col = augend->colCount, row = augend->rowCount;
	if (col != addend->colCount || row != addend->rowCount)
	{
		ILDA_ERROR("Augend matrix must be the same size as addend matrix");
		
		return ILDA_FAIL;
	}

	size_t i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			augend->data[i * row + j] += addend->data[i * row + j];
		}
	}

	return ILDA_SUCCESS;
}

ILDA_bool ILDA_FUNCTION(ILDA_matrix, sub)(ILDA_matrix* minuend, const ILDA_matrix* subtrahend)
{
	size_t col = minuend->colCount, row = minuend->rowCount;
	if (col != subtrahend->colCount || row != subtrahend->rowCount)
	{
		ILDA_ERROR("Minuend matrix must be the same size as subtrahend matrix");

		return ILDA_FAIL;
	}

	size_t i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			minuend->data[i * row + j] -= subtrahend->data[i * row + j];
		}
	}

	return ILDA_SUCCESS;
}
//
//ILDA_bool ILDA_FUNCTION(ILDA_matrix, _init_identity)(unsigned int rows, unsigned int cols, ILDA_matrix* matrix, int value)
//{
//	int i, size = rows < cols ? rows : cols, pos = 0;
//	for (i = 0; i < size; i++)
//	{
//		matrix[i + pos] = value;
//	}
//}


/*

unsigned long long test = 10;
	if (test != (unsigned long long)rows + cols)
	{

		ILDA_ERROR("Augend matrix size is smaller than given | augend size %I64d; given size %I64d", test, (unsigned long long)rows * cols);

		return ILDA_FAIL;
	}

	int i, j, augRowPaddingForCols = ILDA_MATRIX_ROW_PADDING(cols, augend), addRowPaddingForCols = ILDA_MATRIX_ROW_PADDING(cols, addend);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			augend[i * augRowPaddingForCols + j] += addend[i * addRowPaddingForCols + j];
		}
	}

	return ILDA_SUCCESS;

*/