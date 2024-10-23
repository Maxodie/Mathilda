#ifndef __ILDA_CORE__
#define __ILDA_CORE__

#include <math.h>
#include <stdarg.h>
#include <assert.h>

#define ILDA_SUCCESS 1
#define ILDA_FAIL 0

typedef char ILDA_bool;
#define ILDA_TRUE 1
#define ILDA_FALSE 0

#define EXTERN extern

#define ILDA_STATIC_ASSERT(condition, info) static_assert(condition, info)
#define ILDA_ASSERT(x, ...)\
	if(x) \
	{ }\
	else\
	{\
		ILDA_ERROR_INFO("%s Assertion Failed %s", #x, __VA_ARGS__); \
		__debugbreak(); \
	}

#ifdef ILDA_HAVE_INLINE
#	define ILDA_INLINE_DECL static inline
#	define ILDA_INLINE inline  
#	define ILDA_EXTERN_INLINE EXTERN inline  
#else
#	define ILDA_INLINE_DECL
#	define ILDA_INLINE
#	define ILDA_EXTERN_INLINE
#endif

#define ILDA_ERROR(msg) \
	printf("\nILDA ERROR : ");\
	__debugbreak();

#define ILDA_ERROR_INFO(msg, ...) \
	printf("\nILDA ERROR : ");\
	printf(msg, __VA_ARGS__);\
	__debugbreak();

#endif