#include "hashTable.h"

struct node {
    int key;
    int value;
    struct node *next;
};

struct hash {
    int size;
    node* array;
};

hash hashCreate( int size ){
    // Alocação da estrutura de dados.
    hash hashTable = malloc( sizeof( hash ) );

    // Alicação do vetor da hash
    hash->array = malloc( sizeof( node ) * size );

    // Inicialização de valores da hash
    hash.size = size;
    for( int i = 0; i < size; ++i ){
        hash->array[i]->next = NULL;
        hash->array[i]->key = -1;
        hash->array[i]->value = -1;
    }
}

void hashPut( hash* hashTable, int key, int value ){
    node auxNode;
    int hashIndex = key % hash.size;

    while( hash->array[hashIndex]->next != NULL ){
        auxNode = hash->array[hashIndex]->next;
    }
    auxNode.key = key;
    auxNode.value = value;
    auxNode->next = malloc( sizeof( node ) );
    auxNode->next->next = NULL;
    auxNode->next.key = -1;
    auxNode->next.value = -1;
}

int hashGet( hash* hashTable, key int ){
    int hashIndex = key % hash.size;
    node auxNode = hash->array[hashIndex];
    while ( auxNode->next != NULL ) {
        if( auxNode.key == key ) return( auxNode.value )
        else auxNode = auxNode->next;
    }
    return( -1 );
}

int hashRemove( hash* hashTable, key int ){
    int hashIndex = key % hash.size;
    node auxNode = hash->array[hashIndex];
    node auxNext = auxNode->next;

    if( auxNode.key == key ){
        hash->array[hashIndex] = auxNode->next;
        free(auxNode);
        return( 0 );
    }

    while ( auxNode->next != NULL ) {
        if( auxNode->next.key == key ){
            auxNext = auxNode->Next;
            auxNode->next = auxNext->next;
            free( auxNext );
            return( 0 )
        } else {
            auxNode = auxNode->next;
        }
    }
    return( -1 );
}
