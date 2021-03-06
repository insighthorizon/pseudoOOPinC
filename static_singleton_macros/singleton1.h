#ifndef _SINGLETON1_H_
#define _SINGLETON1_H_

// nasty redefinition
#undef SINGLETON_NAME
#undef PUBLIC_FUNCTIONS_DEF
#undef PRIVATE_FUNCTIONS_DEF
#undef COMMA
#undef PASTE
#undef TYPE_PASTE
#undef PUB_HEADER
#undef PRIV_HEADER
#undef FUN_POINTER
#undef SEMICOLON
#undef FUN_BODY



#define SINGLETON_NAME singleton1
#define PUBLIC_FUNCTIONS_DEF(HEADER, BODY)	\
  HEADER( void, pubFun1, void)			\
  BODY(  printf("%d\n", getPriv1() );		\
	 singleton1.pubVar1 += 1;		\
	 return; )				\
  HEADER( void, pubFun2, void)			\
  BODY(   printf("%d\n", getPriv2() );		\
	  singleton1.pubVar2 += 1;		\
	  return; )				\
  HEADER( void, pubFun3, int x COMMA int y)	\
  BODY(   priv1 = x;				\
	  priv2 = y;				\
	  singleton1.pubVar1 += 1;		\
	  singleton1.pubVar2 += 1;		\
	  return; )
#define PRIVATE_FUNCTIONS_DEF(HEADER, BODY)	\
  HEADER( int, getPriv1, void)			\
  BODY( return priv1; )				\
  HEADER( int, getPriv2, void)			\
  BODY( return priv2; )

#define COMMA ,
#define PASTE(X,Y) X ## Y
#define TYPE_PASTE PASTE(SINGLETON_NAME, _t)
#define PUB_HEADER(X, Y, Z) X Y(Z)
#define PRIV_HEADER(X, Y, Z) static X Y(Z)
#define FUN_POINTER(X, Y, Z) X (*Y)(Z)
#define SEMICOLON(X) ;
#define FUN_BODY(X) {X}


typedef struct{ // never use this define to create another instance of this class
  int pubVar1;
  int pubVar2;
  PUBLIC_FUNCTIONS_DEF(FUN_POINTER, SEMICOLON)
}TYPE_PASTE;

#ifdef _SINGLETON1_C_
PUBLIC_FUNCTIONS_DEF(PUB_HEADER, SEMICOLON)
PRIVATE_FUNCTIONS_DEF(PRIV_HEADER, SEMICOLON)
#else
extern TYPE_PASTE SINGLETON_NAME;
#endif

#endif
