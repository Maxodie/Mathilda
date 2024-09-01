#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef __ILDA_TYPE__
	ILDA_STATIC_ASSERT(false, "ILDA TYPE on is called but it was already on");
#endif

#define __ILDA_TYPE__

#define INT_NAME int
#define FLOAT_NAME float


#define CONCAT2x(a, b) a ## _ ## b
#define CONCAT2(a, b) CONCAT2x(a,b)
#define CONCAT3x(a, b, c) a ## _ ## b ## _ ## c
#define CONCAT3(a, b, c) CONCAT3x(a,b,c)

#ifdef ILDA_BASE_INT
	#define ILDA_TYPE(dir) CONCAT2(dir,INT_NAME)
	#define ILDA_FUNCTION(dir, name) CONCAT3(dir,INT_NAME,name)
	#define ILDA_BASE_TYPE int

#elif  defined(ILDA_BASE_FLOAT)
	#define ILDA_TYPE(dir) CONCAT2(dir,FLOAT_NAME)
	#define ILDA_FUNCTION(dir, name) CONCAT3(dir,FLOAT_NAME,name)
	#define ILDA_BASE_TYPE float

#else
	#define ILDA_TYPE(dir) dir
	#define ILDA_FUNCTION(dir, name) CONCAT2(dir,name)
	#define ILDA_BASE_TYPE double
#endif // ILDA_BASE_INT

