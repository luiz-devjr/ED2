#include <stdio.h>
#include <stdlib.h>

int const tam = 30000;

int busca_sequencial(int vet[], int key) {
    for(int i = 0;i < tam;i++){
        if(vet[i] == key){
            deslocar_key(vet ,vet[i]);
            return key;
        }
    }
    
    return -1;
}