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

//#define ILDA_FORCE_LEFT_HANDED, by default mathilda is right handled

#ifdef ILDA_ENABLE_ASSERTS
#   define ILDA_ASSERT(x, ...)\
	if(x) \
	{ }\
	else\
	{\
		ILDA_ERROR_INFO("%s Assertion Failed %s", #x, __VA_ARGS__); \
		__debugbreak(); \
	}

#   define ILDA_STATIC_ASSERT(condition, info) static_assert(condition, info)

#else
#   define ILDA_ASSERT(...)
#   define ILDA_STATILDA_STATIC_ASSERT(...)
#endif

#ifdef HAVE_ILDA_INLINE
#	define ILDA_INLINE_STATIC static inline __cdecl
#	define ILDA_INLINE inline __cdecl
#	define ILDA_EXTERN EXTERN __cdecl
#	define ILDA_EXTERN_INLINE EXTERN inline __cdecl
#   define ILDA_FUN_DECL __cdecl
#else
#	define ILDA_INLINE_STATIC static
#	define ILDA_INLINE
#	define ILDA_EXTERN EXTERN
#   define ILDA_FUN_DECL
#   define ILDA_EXTERN_INLINE
#endif
#if defined(ILDA_DEBUG) || defined(ILDA_RELEASE)
#define ILDA_ERROR(msg) \
	printf("\nILDA ERROR : ");\
	__debugbreak();

#define ILDA_ERROR_INFO(msg, ...) \
	printf("\nILDA ERROR : ");\
	printf(msg, __VA_ARGS__);\
	__debugbreak();
#else
#   define ILDA_ERROR(...)
#   define ILDA_ERROR_INFO(...)
#endif

#endif
