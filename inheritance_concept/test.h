
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

#define INHERIT(X) BUILDER_MACROS__(X) /* you have to tell what builders to inherit */

/* YOU have to give unique builder name (after the class) */
#define BUILDER_TEST__(MORPH) \
  INHERIT(MORPH)  /* commen can be there, not after the blackslash */ \
  MORPH( e, f ) \
  MORPH( g, h )


#define BUILDER(X) BUILDER_TEST__(X) /* put builder name also there */
#define MORPHER1(X, Y) Y X

BUILDER(MORPHER1)

  



  /* Notes to polymorphism concept */
  /* Object arguments can be passed by special callback function (implemented with function pointer)
     that acts like argument wraper,
     this callback would passed information about data type and data itself,
     this way object can have different behaviour for different type of arguments */
