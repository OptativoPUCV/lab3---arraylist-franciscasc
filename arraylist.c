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
  if(l->data[l->capacity] != NULL){
    l->data = realloc(l->data, ((l->capacity) * 2) * sizeof(ArrayList));
    l->data[l->size] = data;
    l->size++;
  }
  else{
    l->data[l->size] = data;
    l->size++;
    l->capacity *=2;
  }
}

void push(ArrayList * l, void * data, int i){

}

void* pop(ArrayList * l, int i){
    return NULL;
}

void* get(ArrayList * l, int i){
    return NULL;
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}
