#ifdef __ILDA_VECTOR_SOURCE_CHECK__
	ILDA_STATIC_ASSERT(false, "ILDA VECTOR SOURCE : file is called but it was already on");
#endif

#define __ILDA_VECTOR_SOURCE_CHECK__

//#if defined(_M_IX86) || defined(_M_X64)
//#include <immintrin.h>
//#endif

//Copy
ILDA_FUN_DECL ILDA_bool ILDA_FUNCTION(ILDA_vector2, copy)(ILDA_TYPE(ILDA_vector2)* base, const ILDA_TYPE(ILDA_vector2)* copy)
{
    base->x = copy->x;
	base->y = copy->y;
    return ILDA_SUCCESS;
}

ILDA_FUN_DECL ILDA_bool ILDA_FUNCTION(ILDA_vector3, copy)(ILDA_TYPE(ILDA_vector3)* base, const ILDA_TYPE(ILDA_vector3)* copy)
{
	base->x = copy->x;
	base->y = copy->y;
	base->z = copy->z;
	return ILDA_SUCCESS;
}

ILDA_FUN_DECL ILDA_bool ILDA_FUNCTION(ILDA_vector4, copy)(ILDA_TYPE(ILDA_vector4)* base, const ILDA_TYPE(ILDA_vector4)* copy)
{
	base->x = copy->x;
	base->y = copy->y;
	base->z = copy->z;
	base->w = copy->w;
	return ILDA_SUCCESS;
}

	//Operators
ILDA_FUN_DECL ILDA_bool ILDA_FUNCTION(ILDA_vector2, equal)(const ILDA_TYPE(ILDA_vector2)* base, const ILDA_TYPE(ILDA_vector2)* compare)
{
	return base->x == compare->x && base->y == base->y;
}

ILDA_FUN_DECL ILDA_bool ILDA_FUNCTION(ILDA_vector3, equal)(const ILDA_TYPE(ILDA_vector3)* base, const ILDA_TYPE(ILDA_vector3)* compare)
{
	return base->x == compare->x && base->y == base->y && base->z == compare->z;
}

ILDA_FUN_DECL ILDA_bool ILDA_FUNCTION(ILDA_vector4, equal)(const ILDA_TYPE(ILDA_vector4)* base, const ILDA_TYPE(ILDA_vector4)* compare)
{
	return base->x == compare->x && base->y == base->y && base->z == compare->z && base->w == compare->w;
}

	//Addition
ILDA_FUN_DECL ILDA_bool ILDA_FUNCTION(ILDA_vector2, add)(ILDA_TYPE(ILDA_vector2)* au, const ILDA_TYPE(ILDA_vector2)* ad)
{
	au->x += ad->x;
	au->y += ad->y;
	return ILDA_SUCCESS;
}

ILDA_FUN_DECL ILDA_bool ILDA_FUNCTION(ILDA_vector3, add)(ILDA_TYPE(ILDA_vector3)* au, const ILDA_TYPE(ILDA_vector3)* ad)
	{
		au->x += ad->x;
		au->y += ad->y;
		au->z += ad->z;

		return ILDA_SUCCESS;
	}

ILDA_FUN_DECL ILDA_bool ILDA_FUNCTION(ILDA_vector4, add)(ILDA_TYPE(ILDA_vector4)* au, const ILDA_TYPE(ILDA_vector4)* ad)
	{
		au->x += ad->x;
		au->y += ad->y;
		au->z += ad->z;
		au->w += ad->w;

		return ILDA_SUCCESS;
	}

	//Subtraction-
ILDA_FUN_DECL ILDA_bool ILDA_FUNCTION(ILDA_vector2, sub)(ILDA_TYPE(ILDA_vector2)* m, const ILDA_TYPE(ILDA_vector2)* s)
	{
		m->x -= s->x;
		m->y -= s->y;

		return ILDA_SUCCESS;
	}

ILDA_FUN_DECL ILDA_bool ILDA_FUNCTION(ILDA_vector3, sub)(ILDA_TYPE(ILDA_vector3)* m, const ILDA_TYPE(ILDA_vector3)* s)
	{
		m->x -= s->x;
		m->y -= s->y;
		m->z -= s->z;

		return ILDA_SUCCESS;
	}

ILDA_FUN_DECL ILDA_bool ILDA_FUNCTION(ILDA_vector4, sub)(ILDA_TYPE(ILDA_vector4)* m, const ILDA_TYPE(ILDA_vector4)* s)
	{
		m->x -= s->x;
		m->y -= s->y;
		m->z -= s->z;
		m->w -= s->w;

		return ILDA_SUCCESS;
	}

	//Multiplication
ILDA_FUN_DECL ILDA_bool ILDA_FUNCTION(ILDA_vector2, mul)(ILDA_TYPE(ILDA_vector2)* v, const ILDA_BASE_TYPE lambda)
	{
		v->x *= lambda;
		v->y *= lambda;

		return ILDA_SUCCESS;
	}

ILDA_FUN_DECL ILDA_bool ILDA_FUNCTION(ILDA_vector3, mul)(ILDA_TYPE(ILDA_vector3)* v, const ILDA_BASE_TYPE lambda)
	{
		v->x *= lambda;
		v->y *= lambda;
		v->z *= lambda;

		return ILDA_SUCCESS;
	}

ILDA_FUN_DECL ILDA_bool ILDA_FUNCTION(ILDA_vector4, mul)(ILDA_TYPE(ILDA_vector4)* v, const ILDA_BASE_TYPE lambda)
{
	v->x *= lambda;
	v->y *= lambda;
	v->z *= lambda;
	v->w *= lambda;

	return ILDA_SUCCESS;
}


//get Length
ILDA_FUN_DECL ILDA_DEC_BASE_TYPE ILDA_FUNCTION(ILDA_vector2, length)(const ILDA_TYPE(ILDA_vector2)* v)
{
#ifdef ILDA_BASE_DOUBLE
	return sqrt(v->x * v->x + v->y * v->y);
#else // ILDA_BASE_DOUBLE
	return sqrtf((ILDA_DEC_BASE_TYPE)v->x * v->x + v->y * v->y);
#endif
}

ILDA_FUN_DECL ILDA_DEC_BASE_TYPE ILDA_FUNCTION(ILDA_vector3, length)(const ILDA_TYPE(ILDA_vector3)* v)
{
#ifdef ILDA_BASE_DOUBLE
	return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
#else // ILDA_BASE_DOUBLE
	return sqrtf((ILDA_DEC_BASE_TYPE)v->x * v->x + v->y * v->y + v->z * v->z);
#endif
}

ILDA_FUN_DECL ILDA_DEC_BASE_TYPE ILDA_FUNCTION(ILDA_vector4, length)(const ILDA_TYPE(ILDA_vector4)* v)
{
#ifdef ILDA_BASE_DOUBLE
	return sqrt(v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
#else // ILDA_BASE_DOUBLE
	return sqrtf((ILDA_DEC_BASE_TYPE)v->x * v->x + v->y * v->y + v->z * v->z + v->w * v->w);
#endif
}

//specials
ILDA_FUN_DECL ILDA_DEC_TYPE(ILDA_vector2) ILDA_FUNCTION(ILDA_vector2, normalize)(const ILDA_TYPE(ILDA_vector2)* vector2)
{
	ILDA_DEC_BASE_TYPE length = ILDA_FUNCTION(ILDA_vector2, length)(vector2);
	return (ILDA_DEC_TYPE(ILDA_vector2)) { .x = vector2->x / length, .y = vector2->y / length };
}

ILDA_FUN_DECL ILDA_DEC_TYPE(ILDA_vector3) ILDA_FUNCTION(ILDA_vector3, normalize)(const ILDA_TYPE(ILDA_vector3)* vector3)
{
	ILDA_DEC_BASE_TYPE length = ILDA_FUNCTION(ILDA_vector3, length)(vector3);
	return (ILDA_DEC_TYPE(ILDA_vector3)) { .x = vector3->x / length, .y = vector3->y / length, .z = vector3->z / length };
}

ILDA_FUN_DECL ILDA_DEC_TYPE(ILDA_vector4) ILDA_FUNCTION(ILDA_vector4, normalize)(const ILDA_TYPE(ILDA_vector4)* vector4)
{
	ILDA_DEC_BASE_TYPE length = ILDA_FUNCTION(ILDA_vector4, length)(vector4);
	return (ILDA_DEC_TYPE(ILDA_vector4)) { .x = vector4->x / length, .y = vector4->y / length, .z = vector4->z / length, .w = vector4->w / length };
}

ILDA_FUN_DECL ILDA_TYPE(ILDA_vector3) ILDA_FUNCTION(ILDA_vector3, cross)(const ILDA_TYPE(ILDA_vector3)* a, const ILDA_TYPE(ILDA_vector3)* b)
{
	return (ILDA_TYPE(ILDA_vector3)) { .x = (a->y * b->z) - (a->z * b->y), .y = (a->z * b->x) - (a->x * b->z), .z = (a->x * b->y) - (a->y * b->x) };
}

ILDA_FUN_DECL ILDA_BASE_TYPE ILDA_FUNCTION(ILDA_vector2, dot)(const ILDA_TYPE(ILDA_vector2)* a, const ILDA_TYPE(ILDA_vector2)* b)
{
    return a->x * b->x + a->y * b->y;
}

ILDA_FUN_DECL ILDA_BASE_TYPE ILDA_FUNCTION(ILDA_vector3, dot)(const ILDA_TYPE(ILDA_vector3)* a, const ILDA_TYPE(ILDA_vector3)* b)
{
	return a->x * b->x + a->y * b->y + a->z * b->z;
}

ILDA_FUN_DECL ILDA_BASE_TYPE ILDA_FUNCTION(ILDA_vector4, dot)(const ILDA_TYPE(ILDA_vector4)* a, const ILDA_TYPE(ILDA_vector4)* b)
{
	return a->x * b->x + a->y * b->y + a->z * b->z + a->w * b->w;
}
