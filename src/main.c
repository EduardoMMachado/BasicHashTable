#include "hashTable.h"

int main() {
  int max=10000;
  hash* hashTable = hashCreate(20);

  for( int i=0; i<max; i+=5){
    hashPut(hashTable, i, max-i);
  }

  for( int i=0; i<max; i+=5){
    printf("%d\n", hashGet(hashTable, i));
  }

  return( 0 );
}
