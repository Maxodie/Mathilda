#ifdef __ILDA_MATRIX_SIZE__
ILDA_STATIC_ASSERT(false, "ILDA MATRIX SIZE on is called but it was already on");
#endif

#define __ILDA_MATRIX_SIZE__

#ifdef ILDA_MATRIX4x4
	#define ILDA_MATRIX(base) CONCAT2(base, 4x4)
#elif defined(ILDA_MATRIX3x3)
	#define ILDA_MATRIX(base) CONCAT2(base, 3x3)
#elif defined(ILDA_MATRIX2x2)
	#define ILDA_MATRIX(base) CONCAT2(base, 2x2)
#else
	#define ILDA_MATRIX(base) base
#endif