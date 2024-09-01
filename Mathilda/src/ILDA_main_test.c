#include <stdio.h>
#include <stdlib.h>

#include "ILDA_vector.h"
#include "ILDA_matrix.h"

void tempMatrixPrint(const ILDA_matrix* matrix);

int main(void)
{
	printf("Hello Mathilda !");/////////////////////////////

	ILDA_matrix matrix3x2;
	ILDA_matrix matrix3x2_;
	ILDA_matrix_init_alloc(3, 2, &matrix3x2);
	ILDA_matrix_init_alloc(3, 2, &matrix3x2_);

	ILDA_matrix_set(2, 1, &matrix3x2, 1);
	ILDA_matrix_set(2, 1, &matrix3x2_, 3);

	printf("\n matrix 2x2 BEFORE : \n");
	tempMatrixPrint(&matrix3x2);
	printf("\n");

	ILDA_matrix_sub(&matrix3x2, &matrix3x2_);

	printf("\n matrix 2x2 AFTER : \n");
	tempMatrixPrint(&matrix3x2);
	printf("\n");
}

void tempMatrixPrint(const ILDA_matrix* matrix)
{
	int index;
	int jdex;
	for (index = 0; index < matrix->rowCount; index++) {
		for (jdex = 0; jdex < matrix->colCount; jdex++) {
			printf("%f ", ILDA_matrix_get(index, jdex, matrix));
		}
		printf("\n");
	}
}