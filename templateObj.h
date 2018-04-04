/* templateObj.h */
#ifndef TEMPLATEOBJ_H
#define TEMPLATEOBJ_H

// TODO add dynamicaly handled memory items (heap memory usage)
// - must implement memory allocation and memory freeing

/* pseudoClass definition via preprocessor macros */
// private
#define PRIVATE_VARIABLES \
static float privVal1 = 0; 					\
static float privVal2 = 0; 					\
static float privVal3 = 0;
// public
#define PUBLIC_VARIABLES \
float pubVal1 = 0;
#define PUBLIC_FUNCTIONS(MORPH)			\
  MORPH( void, setprivVal1, (int x) )		\
  MORPH( int, getprivVal1, (void) )

#define FUNCTION(returnType, funcName, arguments)	\

#define FUNCTION_PTR(returnType, funcName, arguments)	\

/* Insatiations of pseudoClass */
/* give pseudoObject name and file name where to be visible */

#ifdef __TEMPLATEOBJ__
#define ALL_OBJECTS
#endif

/* Export objects into given files */
/*.
  ....*/
#define PSEUDO_OBJ_EXPORT
#ifdef __MAIN__
PSEUDO_OBJ_EXPORT
#endif

#endif /* End templateObj.h */
