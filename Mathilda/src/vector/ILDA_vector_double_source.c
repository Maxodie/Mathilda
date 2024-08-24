#include "vector/ILDA_vector_double.h"

//Addition
int ILDA_vector2_add(ILDA_vector2* augend, const ILDA_vector2* addend)
{
	augend->x += addend->x;
	augend->y += addend->y;

	return ILDA_SUCCESS;
}

int ILDA_vector3_add(ILDA_vector3* augend, const ILDA_vector3* addend)
{
	augend->x += addend->x;
	augend->y += addend->y;
	augend->z += addend->z;

	return ILDA_SUCCESS;
}

int ILDA_vector4_add(ILDA_vector4* augend, const ILDA_vector4* addend)
{
	augend->x += addend->x;
	augend->y += addend->y;
	augend->z += addend->z;
	augend->w += addend->w;

	return ILDA_SUCCESS;
}

int ILDA_vector2_sub(ILDA_vector2* minuend, const ILDA_vector2* subtrahend)
{
	minuend->x -= subtrahend->x;
	minuend->y -= subtrahend->y;

	return ILDA_SUCCESS;
}

//Subtraction
int ILDA_vector3_sub(ILDA_vector3* minuend, const ILDA_vector3* subtrahend)
{
	minuend->x -= subtrahend->x;
	minuend->y -= subtrahend->y;
	minuend->z -= subtrahend->z;

	return ILDA_SUCCESS;
}

int ILDA_vector4_sub(ILDA_vector4* minuend, const ILDA_vector4* subtrahend)
{
	minuend->x -= subtrahend->x;
	minuend->y -= subtrahend->y;
	minuend->z -= subtrahend->z;
	minuend->w -= subtrahend->w;

	return ILDA_SUCCESS;
}

//Multiplication
int ILDA_vector2_mul(ILDA_vector2* vector2, const Double64 lambda)
{
	vector2->x *= lambda;
	vector2->y *= lambda;

	return ILDA_SUCCESS;
}

int ILDA_vector3_mul(ILDA_vector3* vector3, const Double64 lambda)
{
	vector3->x *= lambda;
	vector3->y *= lambda;
	vector3->z *= lambda;

	return ILDA_SUCCESS;
}

int ILDA_vector4_mul(ILDA_vector4* vector4, const Double64 lambda)
{
	vector4->x *= lambda;
	vector4->y *= lambda;
	vector4->z *= lambda;
	vector4->w *= lambda;

	return ILDA_SUCCESS;
}