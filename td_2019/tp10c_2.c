#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#define NBELEM 10

typedef void * T;

typedef struct{
  T *tab;
  int size;
}TabDyn;


TabDyn newTabDyn(const int n){
  assert(n>0);
  TabDyn t= { calloc(sizeof(T), n) , n};
  return t;
}

int size(const TabDyn t){
  return t.size;
}
// Role : Initialiser, Prosedure!!! ->fleche
void iniTabDyn(TabDyn *t, const T v){
  for(int i=0;i<size(*t);i++)
    t->tab[i] = v;
}

T get(const TabDyn t, const int i){
  assert(i>=0 && i<size(t));
  // i est un indice valide
  return t.tab[i];
}

void set(TabDyn *t, int i,T v){
  assert(i>=0);
  // i indice est valide
  if(i>=size(*t)){
    int newSize = i+NBELEM;
    t->tab = realloc(t->tab,newSize*sizeof(T));//realcallocarray()
    t->size = newSize;
  }
  //
  t->tab[i] = v; 
}

int *newInt(int n){
  int *p = malloc(sizeof(int));
  *p = n;
  return p;
}

char *newString(char *s){
  /*char *p = malloc(sizeof(*s));
  *p = *s;
  return p; */
  return strdup(s);
}

int main(void){
  TabDyn  t = newTabDyn(10);

  set(&t, 2, newInt(16));
  printf("%d\n",*((int *)get(t,2)) );

  set(&t, 4, newString("toto"));
  printf("%s\n",((char *)get(t,4)) );
  
  return EXIT_SUCCESS;
}
