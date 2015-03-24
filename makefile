all: hash-table

hash-table: hashtable.o hashtable_main.o
	g++ -g -std=c++0x -o hash-table hashtable.o hashtable_main.o

hashtable.o: hashtable.cpp hashtable.h
	g++ -c hashtable.cpp

hashtable_main.o: hashtable_main.cpp hashtable.h
	g++ -c hashtable_main.cpp

clean:
	rm -rf *.o
	rm -rf hash-table

    
    