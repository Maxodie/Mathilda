#include <stdio.h>
#include <stdlib.h>

#include "ILDA_vector.h"
#include "ILDA_matrix.h"

void tempMatrixPrint(const ILDA_matrix* matrix);

int main(void)
{
	printf("Hello Mathilda !");/////////////////////////////

	ILDA_matrix matrix3x2;
	ILDA_bool result = ILDA_matrix_init_alloc(3, 2, &matrix3x2);
	printf("\n--- result init alloc %d ---\n", result);

	printf("\n matrix 2x2 BEFORE : \n");
	tempMatrixPrint(&matrix3x2);
	printf("\n");

	//ILDA_matrix_add(3, 2, &matrix3x2, &matrix3x2);

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
			printf("%f ", matrix->data[0][0]);
		}
		printf("\n");
	}
}