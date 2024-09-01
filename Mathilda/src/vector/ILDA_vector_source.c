#ifdef __ILDA_VECTOR_SOURCE_CHECK__
	ILDA_STATIC_ASSERT(false, "ILDA VECTOR SOURCE : file is called but it was already on");
#endif

#define __ILDA_VECTOR_SOURCE_CHECK__

//Operators
ILDA_bool ILDA_FUNCTION(ILDA_vector2, equal)(const ILDA_TYPE(ILDA_vector2)* base, const ILDA_TYPE(ILDA_vector2)* compare)
{
	return base->x == compare->x && base->y == base->y;
}

ILDA_bool ILDA_FUNCTION(ILDA_vector3, equal)(const ILDA_TYPE(ILDA_vector3)* base, const ILDA_TYPE(ILDA_vector3)* compare)
{
	return base->x == compare->x && base->y == base->y && base->z == compare->z;
}

ILDA_bool ILDA_FUNCTION(ILDA_vector4, equal)(const ILDA_TYPE(ILDA_vector4)* base, const ILDA_TYPE(ILDA_vector4)* compare)
{
	return base->x == compare->x && base->y == base->y && base->z == compare->z && base->w == compare->w;
}

//Addition
ILDA_bool ILDA_FUNCTION(ILDA_vector2, add)(ILDA_TYPE(ILDA_vector2)* au, const ILDA_TYPE(ILDA_vector2)* ad)
{
	au->x += ad->x;
	au->y += ad->y;

	return ILDA_SUCCESS;
}

ILDA_bool ILDA_FUNCTION(ILDA_vector3, add)(ILDA_TYPE(ILDA_vector3)* au, const ILDA_TYPE(ILDA_vector3)* ad)
{
	au->x += ad->x;
	au->y += ad->y;
	au->z += ad->z;

	return ILDA_SUCCESS;
}

ILDA_bool ILDA_FUNCTION(ILDA_vector4, add)(ILDA_TYPE(ILDA_vector4)* au, const ILDA_TYPE(ILDA_vector4)* ad)
{
	au->x += ad->x;
	au->y += ad->y;
	au->z += ad->z;
	au->w += ad->w;

	return ILDA_SUCCESS;
}

//Subtraction-
ILDA_bool ILDA_FUNCTION(ILDA_vector2, sub)(ILDA_TYPE(ILDA_vector2)* m, const ILDA_TYPE(ILDA_vector2)* s)
{
	m->x -= s->x;
	m->y -= s->y;

	return ILDA_SUCCESS;
}

ILDA_bool ILDA_FUNCTION(ILDA_vector3, sub)(ILDA_TYPE(ILDA_vector3)* m, const ILDA_TYPE(ILDA_vector3)* s)
{
	m->x -= s->x;
	m->y -= s->y;
	m->z -= s->z;

	return ILDA_SUCCESS;
}

ILDA_bool ILDA_FUNCTION(ILDA_vector4, sub)(ILDA_TYPE(ILDA_vector4)* m, const ILDA_TYPE(ILDA_vector4)* s)
{
	m->x -= s->x;
	m->y -= s->y;
	m->z -= s->z;
	m->w -= s->w;

	return ILDA_SUCCESS;
}

//Multiplication
ILDA_bool ILDA_FUNCTION(ILDA_vector2, mul)(ILDA_TYPE(ILDA_vector2)* v, const ILDA_BASE_TYPE lambda)
{
	v->x *= lambda;
	v->y *= lambda;

	return ILDA_SUCCESS;
}

ILDA_bool ILDA_FUNCTION(ILDA_vector3, mul)(ILDA_TYPE(ILDA_vector3)* v, const ILDA_BASE_TYPE lambda)
{
	v->x *= lambda;
	v->y *= lambda;
	v->z *= lambda;

	return ILDA_SUCCESS;
}

ILDA_bool ILDA_FUNCTION(ILDA_vector4, mul)(ILDA_TYPE(ILDA_vector4)* v, const ILDA_BASE_TYPE lambda)
{
	v->x *= lambda;
	v->y *= lambda;
	v->z *= lambda;
	v->w *= lambda;

	return ILDA_SUCCESS;
}


//get Length
double ILDA_FUNCTION(ILDA_vector2, length)(ILDA_TYPE(ILDA_vector2)* v)
{
	return sqrt( v->x * v->x + v->y * v->y );
}

double ILDA_FUNCTION(ILDA_vector3, length)(ILDA_TYPE(ILDA_vector3)* v)
{
	return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}

double ILDA_FUNCTION(ILDA_vector4, length)(ILDA_TYPE(ILDA_vector4)* v)
{
	return sqrt(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
}