/* pseudo object header 
   object.h */
#ifndef object_h
#define object_h
#define OBJECT_TYPE_NAME object /* Specify object type name */ 

#define COMMA ,

/* Object typedef */
typedef struct{
  /* Private variables (flags) */
  int wFlag; /* 1 if last operation was write */
  int rFlag; /* 1 if last operation was read */
  /* Public functions - their pointers */
  void (*insertValue)(void);
  void (*displayValue)(void);  
} object_t;


#ifndef __PSEUDO_OBJECT_C__
/* Export of object instance to given files */
extern object_t MY_object;
#endif


/* Undef all helper macros! */
#undef OBJECT_TYPE_NAME
#endif /* object_h */


