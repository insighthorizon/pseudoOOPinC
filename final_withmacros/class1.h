#ifndef _CLASS1_H_
#define _CLASS1_H_

#if defined(_CLASS1_H_) || defined(_CLASS1_C_)
#define COMMA , // use for separating multiple arguments of functions
#define NONE
#define PASTE(X,Y) X ## Y
#define INDIR_PASTE(X,Y) PASTE(X,Y)



#define CLASS_NAME /* Enter class name here: */class1
#define OBJECT_DATA_DEF						\
  int var1;							\
  int var2;
#define USER_FUNCTIONS_DEF(HEADER, BODY, SEPARATE)			\
  HEADER( void, printVar1, void )					\
  BODY( printf("This is Var1: %d\n", getVar1());			\
	return; )							\
  SEPARATE								\
  HEADER( void, printVar2, void )					\
  BODY( printf("This is Var2: %d\n", getVar2());			\
	return; )							\
  SEPARATE								\
  HEADER( void, setVars, int v1 COMMA int v2)		\
  BODY( instPtrTmp->var1 = v1;				\
	instPtrTmp->var2 = v2;				\
	return; )
#define HIDDEN_FUNCTIONS_DEF(HEADER, BODY)				\
  HEADER(/*Return type*/int,/*Name*/getVar1,/*Arguments*/void)		\
  BODY( return instPtrTmp->var1; )					\
  HEADER(int, getVar2, void)						\
  BODY( return instPtrTmp->var2; )



#define CLASS_T INDIR_PASTE(CLASS_NAME, _t)
#define BUILD_OBJECT_TYPE				\
  typedef struct{					\
    OBJECT_DATA_DEF					\
  }CLASS_T;

#define HIDD_HEADER(X, Y, Z) static X Y(Z)
#define USER_HEADER(X, Y, Z) X Y(Z)
#define TAKE_NAME(X, Y, Z) Y
#define MAKE_POINTER(X, Y, Z) X (*Y)(Z)
#define FUN_BODY(X) {X}
#define SEMICOLON(X) ;
#define JUST_NAME(X)

#define CLASS_METHODS_T INDIR_PASTE(CLASS_NAME, Methods_t)
#define CLASS_M INDIR_PASTE(CLASS_NAME, _m)

#endif

BUILD_OBJECT_TYPE

/* Method interface - better to not have methods global,
avoiding naming collisions, etc. having only interface
 method for the class global, shared by instancess of class*/
typedef struct{
  USER_FUNCTIONS_DEF(MAKE_POINTER, SEMICOLON, NONE)
}CLASS_METHODS_T;

#ifdef _CLASS1_C_
/* Public and private functions prototypes - only visible inside file */
USER_FUNCTIONS_DEF(USER_HEADER, SEMICOLON, NONE)
HIDDEN_FUNCTIONS_DEF(HIDD_HEADER, SEMICOLON)
#else
/* Interface of the object visible everywhere the class file is included */
extern CLASS_METHODS_T CLASS_M(CLASS_T *inst);
// Global objects have to be externed here:

/* If you need real private data, than ooption is to create private object
in a file wich will be static and not exported and second obbject in the same file
which will have acces to this private object, but will be exported...
... disadvantage: its static, so the lifetime is whole program
 */
#endif
#endif
