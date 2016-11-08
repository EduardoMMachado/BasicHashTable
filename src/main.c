#include "hashTable.h"

int main() {
  int max=1000000;
  int i;
  hash* hashTable = hashCreate(5051);

  puts("Put");
  for( i=0; i<max; ++i){
    hashPut(hashTable, i, max-i);
  }

  puts("Get");
  for( i=0; i<max; ++i){
    printf("%d\n", hashGet(hashTable, i));
  }

  return( 0 );
}
