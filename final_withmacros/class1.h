#ifndef _CLASS1_H_
#define _CLASS1_H_

#if defined(_CLASS1_H_) || defined(_CLASS1_C_)
#define COMMA , // use for separating multiple arguments of functions
#define NONE
#define PASTE(X,Y) X ## Y
#define INDIR_PASTE(X,Y) PASTE(X,Y)




#define CLASS_NAME /* Enter class name here: */class1
/* Data must be primitive types, structs, arrays or pointers, if you have for example linked list, you put only pointer there (head) */
#define PUBLIC_DATA_DEF						\
  /* Public data definition: */					\
  int pubVar1;							\
  int pubVar2;
#define PRIVATE_DATA_DEF			\
  /* Private data definition: */		\
  int privVar1;					\
  int privVar2;
#define PUBLIC_FUNCTIONS_DEF(HEADER, BODY, SEPARATE)				\
  HEADER( void, print_privVar1, void )					\
  BODY( printf("This is privVar1: %d\n", get_privVar1());		\
	return; )							\
  SEPARATE								\
  HEADER( void, print_privVar2, void )					\
  BODY( printf("This is privVar2: %d\n", get_privVar2());		\
	return; )							\
  SEPARATE								\
  HEADER( void, set_privVars, int priv1 COMMA int priv2)		\
  BODY( instPtrTmp->PRIVATES.privVar1 = priv1;			\
	instPtrTmp->PRIVATES.privVar2 = priv2;			\
	return; )
#define PRIVATE_FUNCTIONS_DEF(HEADER, BODY)				\
 HEADER(/*Return type*/int,/*Name*/get_privVar1,/*Arguments*/void)	\
 BODY( return instPtrTmp->PRIVATES.privVar1; )			\
 HEADER(int, get_privVar2, void)					\
 BODY( return instPtrTmp->PRIVATES.privVar2; )



#define PRIVATES dontuseoutside
#define CLASS_T INDIR_PASTE(CLASS_NAME, _t)
#define CLASS_PRIV_T INDIR_PASTE(CLASS_NAME, Priv_t) 
#define BUILD_PUBLIC_DATA				\
  typedef struct{					\
    PUBLIC_DATA_DEF					\
      CLASS_PRIV_T PRIVATES;			\
  }CLASS_T;
#define BUILD_PRIVATE_DATA					\
  typedef struct{						\
    PRIVATE_DATA_DEF						\
      }CLASS_PRIV_T;

#define PRIV_HEADER(X, Y, Z) static X Y(Z)
#define PUB_HEADER(X, Y, Z) X Y(Z)
#define TAKE_NAME(X, Y, Z) Y
#define MAKE_POINTER(X, Y, Z) X (*Y)(Z)
#define FUN_BODY(X) {X}
#define SEMICOLON(X) ;
#define JUST_NAME(X)

#define CLASS_METHODS_T INDIR_PASTE(CLASS_NAME, Methods_t)
#define CLASS_M INDIR_PASTE(CLASS_NAME, _m)

#endif

BUILD_PRIVATE_DATA
BUILD_PUBLIC_DATA

/* Method interface - better to not have methods global,
avoiding naming collisions, etc. having only interface
 method for the class global, shared by instancess of class*/
typedef struct{
  PUBLIC_FUNCTIONS_DEF(MAKE_POINTER, SEMICOLON, NONE)
}CLASS_METHODS_T;

#ifdef _CLASS1_C_
/* Public and private functions prototypes - only visible inside file */
PUBLIC_FUNCTIONS_DEF(PUB_HEADER, SEMICOLON, NONE)
PRIVATE_FUNCTIONS_DEF(PRIV_HEADER, SEMICOLON)
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
