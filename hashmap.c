#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"


typedef struct HashMap HashMap;
int enlarge_called=0;

struct HashMap {
    Pair ** buckets;
    long size; //cantidad de datos/pairs en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
};

Pair * createPair( char * key,  void * value) {
    Pair * new = (Pair *)malloc(sizeof(Pair));
    new->key = key;
    new->value = value;
    return new;
}

long hash( char * key, long capacity) {
    unsigned long hash = 0;
     char * ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    return hash%capacity;
}

int is_equal(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}


void insertMap(HashMap * map, char * key, void * value) {
  long posicionNuevoDato = hash(value, map->capacity);
  Pair* parInsertar = createPair(key, value);
  map->current = posicionNuevoDato;
  
  
  while(map->buckets[map->current] != NULL && map->buckets[map->current]->key != NULL){
      map->current++;
    if (map->current >= map->capacity) {
        map->current = 0;
    }
  }

  map->buckets[map->current] = parInsertar;

  map->size++;

}

void enlarge(HashMap * map) {
    enlarge_called = 1; //no borrar (testing purposes)


}


HashMap * createMap(long capacity) {

  HashMap* mapaHash = (HashMap *)malloc(sizeof(HashMap));
  mapaHash->buckets = (Pair**) malloc(10 * sizeof(Pair*));

  for(int k = 0 ; k < capacity ; k++)
    {
      mapaHash->buckets[k] = NULL;
    }

  mapaHash->size = 0;
  mapaHash->capacity = capacity;
  mapaHash->current = -1;
  
    return mapaHash;
}

void eraseMap(HashMap * map,  char * key) {    


}

Pair * searchMap(HashMap * map,  char * key) {   


    return NULL;
}

Pair * firstMap(HashMap * map) {

    return NULL;
}

Pair * nextMap(HashMap * map) {

    return NULL;
}
