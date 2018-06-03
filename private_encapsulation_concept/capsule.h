/* CLASS NAME = obj1 */
#ifndef __OBJ1_H__
#define __OBJ1_H__
/* OBJECT structure TYPEdef */
/* Must be inside c file and also outside to have access to object */
typedef struct{
  /* Public variables defined by user */
  int pubVar1;
  /* Pointers to public functions */
  void (*setVal1)(int val);
  void (*setVal2)(int val);
  void (*setVal3)(int val);
  int (*getVal1)(void);
  int (*getVal2)(void);
  int (*getVal3)(void);
  void (*usePubVars1)(int x);
  int (*usePubVars2)(void);
  void (*usePrivFun)(void);
}obj1_publics_T;

#ifdef __OBJ1_C__ /* macro defined inside class c file */
/* Privates container (struct) - for all instances of object */
typedef struct{
  int value1;
  int value2;
  int value3;
  /* Pointers to private functions */
  void (*giveInfo)(void);
} obj1_privates_T;

/* Function declarations */
/*  priv variables accessors */
obj1_privates_T *obj1_inst1_privatesACCESS(void);
obj1_privates_T *obj1_inst2_privatesACCESS(void);
/*  priv functions implementation */
static void obj1_giveInfo_privFun(obj1_publics_T *publics, obj1_privates_T *privates);
/*  priv function wrappers */
static void privWrapperObj1_inst1_giveInfo(void);
static void privWrapperObj1_inst2_giveInfo(void);
/*  pub functions implementation */
void obj1_setVal1(obj1_publics_T *publics, obj1_privates_T *privates,/*Here start user input variables*/ int val);
void obj1_setVal2(obj1_publics_T *publics, obj1_privates_T *privates,/*Here start user input variables*/ int val);
void obj1_setVal3(obj1_publics_T *publics, obj1_privates_T *privates,/*Here start user input variables*/ int val);
int obj1_getVal1(obj1_publics_T *publics, obj1_privates_T *privates);
int obj1_getVal2(obj1_publics_T *publics, obj1_privates_T *privates);
int obj1_getVal3(obj1_publics_T *publics, obj1_privates_T *privates);
void obj1_usePubVars1(obj1_publics_T *publics, obj1_privates_T *privates,/*Here start user input variables*/ int x);
int obj1_usePubVars2(obj1_publics_T *publics, obj1_privates_T *privates);
void obj1_usePrivFun(obj1_publics_T *publics, obj1_privates_T *privates);
/*  pub function wrappers */
void pubWrapperObj1_inst1_setVal1(int val);
void pubWrapperObj1_inst1_setVal2(int val);
void pubWrapperObj1_inst1_setVal3(int val);
int pubWrapperObj1_inst1_getVal1(void);
int pubWrapperObj1_inst1_getVal2(void);
int pubWrapperObj1_inst1_getVal3(void);
void pubWrapperObj1_inst1_usePubVars1(int x);
int pubWrapperObj1_inst1_usePubVars2(void);
void pubWrapperObj1_inst1_usePrivFun(void);

void pubWrapperObj1_inst2_setVal1(int val);
void pubWrapperObj1_inst2_setVal2(int val);
void pubWrapperObj1_inst2_setVal3(int val);
int pubWrapperObj1_inst2_getVal1(void);
int pubWrapperObj1_inst2_getVal2(void);
int pubWrapperObj1_inst2_getVal3(void);
void pubWrapperObj1_inst2_usePubVars1(int x);
int pubWrapperObj1_inst2_usePubVars2(void);
void pubWrapperObj1_inst2_usePrivFun(void);
#elif
/* Extern to give access to objects */
extern obj1_publics_T obj1_instance1;
extern obj1_publics_T obj1_instance2;
#endif

#endif /* __OBJ1_H__ */
