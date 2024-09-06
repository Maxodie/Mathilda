#ifndef __ILDA_CORE__
#define __ILDA_CORE__

#include <math.h>
#include <stdarg.h>

#define ILDA_SUCCESS 1
#define ILDA_FAIL 0

typedef char ILDA_bool;
#define ILDA_TRUE 1
#define ILDA_FALSE 0

#define EXTERN extern

#define ILDA_STATIC_ASSERT(condition, info) static_assert(condition, info)

#ifdef ILDA_HAVE_INLINE
	#define INLINE_DECL static inline
	#define INLINE_FUN EXTERN inline  
#else
	#define INLINE_DECL
	#define INLINE_FUN
#endif

#define ILDA_ERROR(msg) \
	printf("\nILDA ERROR : ");\
	__debugbreak();

#define ILDA_ERROR_INFO(msg, ...) \
	printf("\nILDA ERROR : ");\
	printf(msg, __VA_ARGS__);\
	__debugbreak();

#endif