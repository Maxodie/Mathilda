#ifdef __ILDA_VECTOR_SOURCE_CHECK__
static_assert(false, "ILDA VECTOR SOURCE file is called but it was already on");
#endif

#define __ILDA_VECTOR_SOURCE_CHECK__;

//Addition
int ILDA_FUNCTION(ILDA_vector2, add)(ILDA_TYPE(ILDA_vector2)* augend, const ILDA_TYPE(ILDA_vector2)* addend)
{
	augend->x += addend->x;
	augend->y += addend->y;

	return ILDA_SUCCESS;
}

int ILDA_FUNCTION(ILDA_vector3, add)(ILDA_TYPE(ILDA_vector3)* augend, const ILDA_TYPE(ILDA_vector3)* addend)
{
	augend->x += addend->x;
	augend->y += addend->y;
	augend->z += addend->z;

	return ILDA_SUCCESS;
}

int ILDA_FUNCTION(ILDA_vector4, add)(ILDA_TYPE(ILDA_vector4)* augend, const ILDA_TYPE(ILDA_vector4)* addend)
{
	augend->x += addend->x;
	augend->y += addend->y;
	augend->z += addend->z;
	augend->w += addend->w;

	return ILDA_SUCCESS;
}

//Subtraction-
int ILDA_FUNCTION(ILDA_vector2, sub)(ILDA_TYPE(ILDA_vector2)* minuend, const ILDA_TYPE(ILDA_vector2)* subtrahend) 
{
	minuend->x -= subtrahend->x;
	minuend->y -= subtrahend->y;

	return ILDA_SUCCESS;
}

int ILDA_FUNCTION(ILDA_vector3, sub)(ILDA_TYPE(ILDA_vector3)* minuend, const ILDA_TYPE(ILDA_vector3)* subtrahend)
{
	minuend->x -= subtrahend->x;
	minuend->y -= subtrahend->y;
	minuend->z -= subtrahend->z;

	return ILDA_SUCCESS;
}

int ILDA_FUNCTION(ILDA_vector4, sub)(ILDA_TYPE(ILDA_vector4)* minuend, const ILDA_TYPE(ILDA_vector4)* subtrahend)
{
	minuend->x -= subtrahend->x;
	minuend->y -= subtrahend->y;
	minuend->z -= subtrahend->z;
	minuend->w -= subtrahend->w;

	return ILDA_SUCCESS;
}

//Multiplication
int ILDA_FUNCTION(ILDA_vector2, mul)(ILDA_TYPE(ILDA_vector2)* vector2, const ILDA_BASE_TYPE lambda)
{
	vector2->x *= lambda;
	vector2->y *= lambda;

	return ILDA_SUCCESS;
}

int ILDA_FUNCTION(ILDA_vector3, mul)(ILDA_TYPE(ILDA_vector3)* vector3, const ILDA_BASE_TYPE lambda)
{
	vector3->x *= lambda;
	vector3->y *= lambda;
	vector3->z *= lambda;

	return ILDA_SUCCESS;
}

int ILDA_FUNCTION(ILDA_vector4, mul)(ILDA_TYPE(ILDA_vector4)* vector4, const ILDA_BASE_TYPE lambda)
{
	vector4->x *= lambda;
	vector4->y *= lambda;
	vector4->z *= lambda;
	vector4->w *= lambda;

	return ILDA_SUCCESS;
}

