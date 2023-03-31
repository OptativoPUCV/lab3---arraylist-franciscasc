#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) {
    ArrayList *list = (ArrayList *) malloc(sizeof(ArrayList));
    list->capacity = 2;
    list->size = 0;
    list->data = malloc(sizeof(ArrayList));
  return list;
}

void append(ArrayList * l, void * data){
  if(l->capacity == l->size){
    l->data = realloc(l->data, ((l->capacity) * 2) * sizeof(void *));
    l->data[l->size] = data;
    l->size++;
    l->capacity *=2;
  }
  else{
    l->data[l->size] = data;
    l->size++;
  }
}

void push(ArrayList * l, void * data, int i){
  if(i > l->size) return;
  if(l->size == l->capacity){
    l->data = realloc(l->data, ((l->capacity) * 2) * sizeof(void *));
    l->data[l->size] = data;
    l->capacity *=2;
  }
  for(int h = l->size; h > i; h--){
    l->data[h] = l->data[h - 1];
  }
  
  l->data[i] = data;
  l->size++;
}

void* pop(ArrayList * l, int i){
  if(i >= l->size) return NULL;
  if(i < 0)
    get(l, i);
  if(i > 0){
    for(int h = 0; h < l->size; h++){
      l->data[h - 1] = l->data[h];
    }
  }
  if(l->size == 0) return l->data[i];
  l->data[l->size] = NULL;
  l->size--;
  return l->data[i];
}

void* get(ArrayList * l, int i){
  int h;
  if(i >= l->size) return NULL;
  if(i < 0){
    for(h = l->size; h < l->size + 1; h--){
      if(l->data[l->size + i] == l->data[h])
        return l->data[h];
    }
  }
  return l->data[i];
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
  l->capacity = 2;
  l->size = 0;
  l->data = malloc(sizeof(ArrayList));
}
