#include <stdio.h>

#include "ILDA_vector/ILDA_vector.h"
#include "ILDA_matrix/ILDA_matrix.h"
#include "ILDA_trigo/ILDA_trigo.h"
#include "ILDA_utils/ILDA_utils.h"
#include "ILDA_vector/ILDA_vector_int.h"

inline void tempMatrixPrint(const ILDA_matrix4x4* matrix);

int main(void)
{
	printf("Hello Mathilda !");/////////////////////////////

	/*ILDA_matrix4x4 matrix4x4;
	ILDA_vector4f vec4_ = { .x = 12.0, .y = 15.0, .z = 10.0, .w = 1 };
	ILDA_vector3f vec3_ = {.x = 11.0, .y = 2.0, .z = 3.0};

	ILDA_matrix4x4_set(0, 0, &matrix4x4, 1);
	ILDA_matrix4x4_set(1, 1, &matrix4x4, 1);
	ILDA_matrix4x4_set(2, 2, &matrix4x4, 1);
	ILDA_matrix4x4_set(3, 3, &matrix4x4, 1);*/

	printf("\n matrix 4x4 BEFORE : \n");
	//tempMatrixPrint(&matrix4x4);
	printf("\n");

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

	/*ILDA_matrix4x4 m1 = {.data = {{1, 2, 3,4}, {5,6,7,8}, {9,10,11,12},{13,14,15,16}}};
	ILDA_matrix4x4 m2 = { .data = { {0, 2, 3,4}, {5,6,7,8}, {9,0,11,12},{13,14,15,17}} };
	ILDA_matrix4x4 copy = ILDA_matrix4x4_mul_same_c(&m2, &m1);*/

	//ILDA_vector3i vec4_o = { .x = 5, .y = 3, .z = 8};
	//ILDA_vector3i vec3_o = { .x = 4, .y = 20, .z = 71 };
	//int cross = ILDA_vector3i_dot(&vec4_o, &vec3_o);
	//printf("\n\nx : %d", cross);

	//ILDA_matrix4x4 rotationMatrix = ILDA_matrix4x4_rotation(50, &vec3_);

	ILDA_matrix4x4 projection = ILDA_matrix_perspective_r(ILDA_radians(45.f), (float)800 / (float)600, 0.1f, 100.0f);

	ILDA_vector3f location = { .x = 4, .y = 3, .z = 3 };// Camera is at (4,3,3), in World Space
	ILDA_vector3f target = { .x = 0, .y = 0, .z = 0 };// and looks at the origin
	ILDA_vector3f worldUp = { .x = 0, .y = 1, .z = 0 };// Head is up (set to 0,-1,0 to look upside-down)
	ILDA_matrix4x4 view = ILDA_matrix_look_at_r(&location, &target, &worldUp);

	// Model matrix : an identity matrix (model will be at the origin)
	ILDA_matrix4x4 model = ILDA_matrix4x4_identity;
	// Our ModelViewProjection : multiplication of our 3 matrices
	//ILDA_matrix4x4_mul_same(&modelViewProjection, &view);
	ILDA_matrix4x4 result = { 0 }, r= {0};
	ILDA_matrix4x4_mul_same_source(&result, &projection, &view);
	//tempMatrixPrint(&result);
	ILDA_matrix4x4_mul_same_source(&r, &result, &model);
	tempMatrixPrint(&result);
	tempMatrixPrint(&view);
	tempMatrixPrint(&r);


	/*printf("\nmatrix 4x4 rotation :\n");
	tempMatrixPrint(&result);
	printf("\n");*/

	/*for (int i = 0; i < 50; i++)
	{
		int random = ILDA_randomi(5, 8);
		printf("\nvlaue int : %d", random);
	}
	for (int i = 0; i < 50; i++)
	{
		float randomf = ILDA_randomf(5.5f, 8.2f);
		printf("\nvlaue float : %f", randomf);
	}*/
}

void tempMatrixPrint(const ILDA_matrix4x4* matrix)
{
	printf("\n");
	int index;
	int jdex;
	for (index = 0; index < ILDA_matrix4x4_row; index++) {
		for (jdex = 0; jdex < ILDA_matrix4x4_col; jdex++) {
			printf("%f ", matrix->data[index][jdex]);
		}
		printf("\n");
	}
}
