#####################################################################
# Copyright (c) 2019 EG
# Distributed under the MIT software license, see the accompanying
# file LICENSE or http://www.opensource.org/licenses/mit-license.php.
#####################################################################

CFLAGS = -O -g -std=c++11
INC = -I./src -I./src/extras -I./src -I./src/crypto -I./depends/x86_64-pc-linux-gnu/include
LIB = -L./depends/x86_64-pc-linux-gnu/lib
CC = g++
LNK = -lgmp

dockerCI: main.o bignumber.o
	$(CC) $(CFLAGS) $(INC) -o dockerCITest main.o $(LIB) $(LNK)

main.o: src/main.cpp
	$(CC) $(CFLAGS) $(INC) -c src/main.cpp $(LIB) $(LNK)

bignumber.o: src/bignumber.h
	$(CC) $(CFLAGS) $(INC) -c src/bignumber.h $(LIB) $(LNK)
	
clean:
	rm -f core src/*.o