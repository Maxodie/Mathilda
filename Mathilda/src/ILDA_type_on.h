#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef __ILDA_TYPE__
	ILDA_STATIC_ASSERT(false, "ILDA TYPE on is called but it was already on");
#endif

#define __ILDA_TYPE__

#define INT_SUFFIX i
#define FLOAT_SUFFIX f
#define DOUBLE_SUFFIX d

#define CONCAT2x(a, b) a ## _ ## b
#define CONCAT2(a, b) CONCAT2x(a,b)
#define CONCAT3x(a, b, c) a ## _ ## b ## _ ## c
#define CONCAT3(a, b, c) CONCAT3x(a,b,c)

#define CONCAT_NO_SPACEx(a, b) a ## b
#define CONCAT_NO_SPACE(a, b) CONCAT_NO_SPACEx(a,b)

#ifdef ILDA_BASE_INT
		#define ILDA_TYPE(dir) CONCAT_NO_SPACE(dir,INT_SUFFIX)
		#define ILDA_BASE_TYPE int
		#define ILDA_DEC_BASE_TYPE float 
		#define ILDA_DEC_TYPE(dir) CONCAT_NO_SPACE(dir,FLOAT_SUFFIX)

#elif defined(ILDA_BASE_FLOAT)
	#define ILDA_TYPE(dir) CONCAT_NO_SPACE(dir,FLOAT_SUFFIX)
	#define ILDA_BASE_TYPE float
	#define ILDA_DEC_BASE_TYPE float 
	#define ILDA_DEC_TYPE(dir) CONCAT_NO_SPACE(dir,FLOAT_SUFFIX)

#else
	#define ILDA_TYPE(dir) CONCAT_NO_SPACE(dir,DOUBLE_SUFFIX)
	#define ILDA_BASE_TYPE double
	#define ILDA_DEC_BASE_TYPE double 
	#define ILDA_DEC_TYPE(dir) CONCAT_NO_SPACE(dir,DOUBLE_SUFFIX)
#endif // ILDA_BASE_INT


#define ILDA_FUNCTION(dir, name) CONCAT2(ILDA_TYPE(dir),name)