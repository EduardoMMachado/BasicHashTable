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

hash* hashCreate( int size ){
    hash* hashTable = (hash*)malloc( sizeof( hash ) );

    // Alicação do vetor da hash
    hashTable->array = (node*)malloc( sizeof( node ) * size );

    // Inicialização de valores da hash
    hashTable->size = size;
    for( int i = 0; i < size; ++i ){
        hashTable->array[i].next = NULL;
        hashTable->array[i].key = -1;
        hashTable->array[i].value = -1;
    }

    return(hashTable);
}

void hashPut( hash* hashTable, int key, int value ){
    int hashIndex = key % hashTable->size;
    node* auxNode = &hashTable->array[hashIndex];

    while( auxNode->next != NULL ){
        auxNode = auxNode->next;
    }

    auxNode->key = key;
    auxNode->value = value;

    auxNode->next = (node*)malloc( sizeof( node ) );
    auxNode->next->next = NULL;
    auxNode->next->key = -1;
    auxNode->next->value = -1;
}

int hashGet( hash* hashTable, int key ){
    int hashIndex = key % hashTable->size;
    node* auxNode = &hashTable->array[hashIndex];

    auxNode = &hashTable->array[hashIndex];

    while ( auxNode->next != NULL ) {
        if( auxNode->key == key ) return( auxNode->value );
        else auxNode = auxNode->next;
    }
    
    return( -1 );
}

int hashRemove( hash* hashTable, int key ){
    int hashIndex = key % hashTable->size;

    node* auxNode = (node*)malloc(sizeof(node));
    auxNode = &hashTable->array[hashIndex];

    node* auxNext = (node*)malloc(sizeof(node));
    auxNext = auxNode->next;

    if( auxNode->key == key ){
        hashTable->array[hashIndex] = *auxNode->next;
        free(auxNode);
        return( 0 );
    }

    while ( auxNode->next != NULL ) {
        if( auxNode->next->key == key ){
            auxNext = auxNode->next;
            auxNode->next = auxNext->next;
            free( auxNext );
            return( 0 );
        } else {
            auxNode = auxNode->next;
        }
    }
    return( -1 );
}
