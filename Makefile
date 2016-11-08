# Implementado por Eduardo Machado e Bruna Maciel
# 2016

CC=gcc
LIB=./lib
INCLUDE=./include
SRC=./src
OBJ=./obj
FLAGS = -Wall -Wextra -lm -g -o3

main:	hashTable
	$(CC) $(SRC)/main.c $(OBJ)/hashTable.o $(FLAGS) -I$(INCLUDE) -L$(LIB) -o hashTest

hashTable:
	$(CC) -c $(SRC)/hashTable.c $(FLAGS) -I$(INCLUDE) -o $(OBJ)/hashTable.o
	ar -cr $(LIB)/hashTable.a $(OBJ)/hashTable.o

clean:
	rm hashTest core $(SRC)/*~ $(OBJ)/*o $(LIB)/*a
