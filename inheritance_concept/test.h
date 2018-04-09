
/* TODO Function wrappers for public functions,
   somethign like:
   int MY_object_some_public_fun(void)
   {
     int actual_fun(&privateStructContainer)
   }
   ... for all public funs for every class instance
   MY_object.some_public_fun = MY_object_some_public_fun;

   int actual_fun(&privStruct)
   {
     privStruct->a = 0xFF;
   }
*/



/* INHERITANCE CONCEPT */
#undef COMMA
#define COMMA ,

/* test.h object inherits from parrents macros.h and writers.h */
/* you have to tell what builders to inherit */
#define INHERIT_TEST__(X) \
  BUILDER_WRITERS__(X)\
  BUILDER_MACROS__(X)

/* YOU have to give unique builder and inherit  name (after the class) */
#define BUILDER_TEST__(MORPH) \
  INHERIT_TEST__(MORPH)  /* commen can be there, not after the blackslash */ \
  MORPH( e, f ) \
  MORPH( g, h )


#define BUILDER(X) BUILDER_TEST__(X) /* put builder name also there */
#define MORPHER1(X, Y) Y X

BUILDER(MORPHER1)
