#ifndef __ILDA_CORE__
#define __ILDA_CORE__


#define ILDA_SUCCESS 1
#define ILDA_FAIL 0

typedef double Double64;
typedef int Int32;
typedef float Float32;

#ifdef HAVE_INLINE
	#define INLINE_DECL static inline
	#define INLINE_FUN extern inline  
#else
	#define INLINE_DECL
	#define INLINE_FUN
#endif



#endif