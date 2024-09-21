#include <stdio.h>
#include <stdlib.h>

#include "ILDA_vector/ILDA_vector.h"
#include "ILDA_matrix/ILDA_matrix.h"

inline void tempMatrixPrint(const ILDA_matrix2x2* matrix);

int main(void)
{
	printf("Hello Mathilda !");/////////////////////////////

	//ILDA_matrix4x4 matrix4x4;
	//ILDA_vector4f vec4_ = { .x = 12.0, .y = 15.0, .z = 10.0, .w = 1 };
	//ILDA_vector3f vec3_ = {.x = 11.0, .y = 2.0, .z = 3.0};

	//ILDA_matrix4x4_set(0, 0, &matrix4x4, 1);
	//ILDA_matrix4x4_set(1, 1, &matrix4x4, 1);
	//ILDA_matrix4x4_set(2, 2, &matrix4x4, 1);
	//ILDA_matrix4x4_set(3, 3, &matrix4x4, 1);

	//printf("\n matrix 4x4 BEFORE : \n");
	////tempMatrixPrint(&matrix4x4);
	//printf("\n");

	//ILDA_matrix4x4_translate(&matrix4x4, &vec3);
	//ILDA_matrix4x4 translateMatrix = ILDA_matrix4x4_translate(&ILDA_mat4x4_identity, &vec3_);
	//tempMatrixPrint(&translateMatrix);
	//ILDA_vector4_float vec4 = ILDA_matrix4x4_mul_vector(&translateMatrix,&vec4_);

	//printf("\n %f; %f; %f; %f", vec4.x, vec4.y, vec4.z, vec4.w);

	//ILDA_scale(&matrix4x4, &vec3_);
	/*ILDA_vector3f a = { .x = 5.0f, .y = 3.f, .z = 8.0f };
	ILDA_vector3f b = { .x = 4.0f, .y = 20.5f, .z = 7.0f };
	ILDA_vector3f c = { .x = 0.f, .y = 1.f, .z = 0.0f };
	ILDA_matrix4x4 lookAt = ILDA_matrix_look_at_r(&a, &b, &c);*/

	//float fovy = 1.5f, aspect = 159.f, zNear = 18.f, zFar = 845.f;
	//ILDA_matrix4x4 perspective = ILDA_matrix_perspective_r(fovy, aspect, zNear, zFar);
	
	/*ILDA_matrix2x2 m1 = { .data = { {1, 2}, {3,4}} };
	ILDA_matrix2x2 m2 = { .data = { {1, 2}, {3,4}} };
	ILDA_matrix2x2 copy = ILDA_matrix2x2_mul_same_c(&m1, &m2);*/

	//ILDA_vector3i vec4_o = { .x = 5, .y = 3, .z = 8};
	//ILDA_vector3i vec3_o = { .x = 4, .y = 20, .z = 71 };
	//int cross = ILDA_vector3i_dot(&vec4_o, &vec3_o);
	//printf("\n\nx : %d", cross);

	//ILDA_matrix4x4 rotationMatrix = ILDA_matrix4x4_rotation(50, &vec3_);

	/*printf("\nmatrix 4x4 rotation :\n");
	tempMatrixPrint(&copy);
	printf("\n");*/
}

void tempMatrixPrint(const ILDA_matrix2x2* matrix)
{
	int index;
	int jdex;
	for (index = 0; index < ILDA_matrix2x2_row; index++) {
		for (jdex = 0; jdex < ILDA_matrix2x2_col; jdex++) {
			printf("%f ", matrix->data[index][jdex]);
		}
		printf("\n");
	}
}