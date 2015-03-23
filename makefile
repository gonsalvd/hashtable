all: hash-table

hash-table: hashtable_main.o hashtable.o
	g++ -std=c++0x -o hash-table hashtable_main.o hashtable.o

hash-table.o: hashtable_main.cpp
	g++ -c sb_main_final.cpp

hashtable.o: hashtable.cpp hashtable.h
	g++ -c hashtable.cpp

#binary.o: binary.cpp binary.h
#	g++ -c binary.cpp

clean:
	rm -rf *.o
	rm -rf hash-table

    
    