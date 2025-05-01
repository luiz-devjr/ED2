#include <stdio.h>
#include <stdlib.h>

void deslocar_key(int v[] , int key) {
    int tam = (sizeof(v))/2;
    for(int i = tam-1;i > 0;i--)
        v[i] = v[i-1];
    v[0] = key;
}