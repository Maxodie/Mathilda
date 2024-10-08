#ifdef __ILDA_MATRIX_SIZE__
ILDA_STATIC_ASSERT(false, "ILDA MATRIX SIZE on is called but it was already on");
#endif

#define __ILDA_MATRIX_SIZE__
#include "ILDA_matrix/ILDA_matrix.h"

#ifdef ILDA_MATRIX4x4
#	define ILDA_MATRIX(base) CONCAT_NO_SPACE(base, 4x4)
#	define ILDA_MATRIX_COL 4
#	define ILDA_MATRIX_ROW 4
	#define ILDA_MATRIX_VECTOR_SIZE ILDA_TYPE(ILDA_vector4)
#elif defined(ILDA_MATRIX3x3)
#	define ILDA_MATRIX(base) CONCAT_NO_SPACE(base, 3x3)
#	define ILDA_MATRIX_COL 3
#	define ILDA_MATRIX_ROW 3
#define ILDA_MATRIX_VECTOR_SIZE ILDA_TYPE(ILDA_vector3)
#elif defined(ILDA_MATRIX2x2)
#	define ILDA_MATRIX(base) CONCAT_NO_SPACE(base, 2x2)
#	define ILDA_MATRIX_COL 2
#	define ILDA_MATRIX_ROW 2
	#define ILDA_MATRIX_VECTOR_SIZE ILDA_TYPE(ILDA_vector2)
#else
#	define ILDA_MATRIX(base) base
#	define ILDA_MATRIX_COL 
#	define ILDA_MATRIX_ROW
#	define ILDA_MATRIX_VECTOR_SIZE 
#endif