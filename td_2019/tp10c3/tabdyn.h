#pragma once

#define NBELEM 10

typedef void* T;

typedef struct{
  T *tab;
  int size;
}TabDyn;

extern TabDyn newTabDyn(const int );
extern int size(const TabDyn );
extern void iniTabDyn(TabDyn * , const T);
extern T get(const TabDyn , const int);
extern void set(TabDyn * , int ,T );
