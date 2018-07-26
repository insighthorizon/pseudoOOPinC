#ifndef _SINGLETON1_H_
#define _SINGLETON1_H_

typedef struct{ // never use this define to create another instance of this class
  int pubVar1;
  int pubVar2;
  void (*pubFun1)(void);
  void (*pubFun2)(void);
  void (*pubFun3)(int, int);
}singleton1_t;

#ifdef _SINGLETON1_C_
void pubFun1(void);
void pubFun2(void);
void pubFun3(int x, int y);

static int getPriv1(void); // priv functions
static int getPriv2(void);
#else
extern singleton1_t mySingleton;
#endif

#endif
