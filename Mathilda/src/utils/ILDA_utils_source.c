
#ifdef __ILDA_RANDOM_SOURCE_CHECK__
	ILDA_STATIC_ASSERT(false, "ILDA UTILS SOURCE : file is called but it was already on");
#endif

#define __ILDA_RANDOM_SOURCE_CHECK__

ILDA_FUN_DECL ILDA_BASE_TYPE ILDA_SIMPLE_FUNCTION(ILDA_random)(ILDA_BASE_TYPE a, ILDA_BASE_TYPE b)
{
	ILDA_ASSERT(a < b && b <= RAND_MAX, "Random required a < b && b < RAND_MAX")
#ifdef ILDA_BASE_INT
	return rand() % (b - a + 1) + a;
#elif defined(ILDA_BASE_FLOAT)
	return ((b - a) * ((float)rand() / RAND_MAX)) + a;
#endif
}

ILDA_FUN_DECL ILDA_BASE_TYPE ILDA_SIMPLE_FUNCTION(ILDA_clamp)(ILDA_BASE_TYPE value, ILDA_BASE_TYPE min, ILDA_BASE_TYPE max)
{
    const ILDA_BASE_TYPE t = value < min ? min : max;
    return t > max ? max : t;
}
