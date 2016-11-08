#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node node;
typedef struct hash hash;

//==============================================================================
// Inicializa a tabela de hash.
// Parâmetros:
//    size: Tamanho da tabela (precisa ser pensado de maneira a ter o menor
//          número de colisões possível).
// Retorno:
//    hash: Um tabela hash com todas as alocações já feitas dentro da função.
//==============================================================================
hash* hashCreate( int size );

//==============================================================================
// Insere um elemento na tabela hash.
// Parâmetros:
//    hashTable: ponteiro para a tabela em que deseja inserir o elemento.
//    key: chave do elemento a ser inserido.
//    value: conteúdo do elemento a ser inserido.
// Retorno:
//    não há.
//==============================================================================
void hashPut( hash* hashTable, int key, int value );

//==============================================================================
// Pega o conteúdo de um elemento a partir de sua chave.
// Parâmetros:
//    hashTable: ponteiro para a tabela em que deseja buscar o elemento.
//    key: chave do elemento a ser buscado.
// Retorno:
//    int:  conteúdo do elemento buscado, caso a busca tenha sucesso;
//          -1, caso o elemento não tenha sido encontrado.
//==============================================================================
int hashGet( hash* hashTable, int key );

//==============================================================================
// Remove um elemento da hash.
// Parâmetros:
//    hashTable: ponteiro para a tabela em que deseja remover o elemento.
//    key: chave do elemento a ser removido.
// Retorno:
//    int:  0, caso a remoção tenha sucesso;
//          -1, caso o elemento não tenha sido encontrado.
//==============================================================================
int hashRemove( hash* hashTable, int key );
