#include <stdio.h>
#include <stdlib.h>

#include "ILDA_vector.h"
#include "ILDA_matrix.h"

void tempMatrixPrint(const ILDA_matrix4x4* matrix);

int main(void)
{
	printf("Hello Mathilda !");/////////////////////////////

	ILDA_matrix4x4 matrix4x4;
	ILDA_vector4 vec4 = {.x = 12.0, .y = 15.0, .z = 10.0, .w = 0.0};
	ILDA_matrix4x4_init_default(&matrix4x4);

	ILDA_matrix4x4_set(0, 0, &matrix4x4, 1);
	ILDA_matrix4x4_set(1, 1, &matrix4x4, 1);
	ILDA_matrix4x4_set(2, 2, &matrix4x4, 1);
	ILDA_matrix4x4_set(3, 3, &matrix4x4, 1);

	printf("\n matrix 4x4 BEFORE : \n");
	tempMatrixPrint(&matrix4x4);
	printf("\n");

	ILDA_matrix4x4_mul_vector(&matrix4x4, &vec4);

	printf("\n matrix 4x4 AFTER : \n");
	tempMatrixPrint(&matrix4x4);
	printf("\n");
}

void tempMatrixPrint(const ILDA_matrix4x4* matrix)
{
	int index;
	int jdex;
	for (index = 0; index < matrix->rowCount; index++) {
		for (jdex = 0; jdex < matrix->colCount; jdex++) {
			printf("%f ", matrix->data[index][jdex]);
		}
		printf("\n");
	}
}
