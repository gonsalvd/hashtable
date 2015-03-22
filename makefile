all: hash-table

hash-table: hashtable_main.o
	g++ -std=c++0x -o hash-table hashtable_main.o

hash-table.o: hashtable_main.cpp
	g++ -c sb_main_final.cpp

#linear.o: linear.cpp linear.h
#	g++ -c linear.cpp

#binary.o: binary.cpp binary.h
#	g++ -c binary.cpp

clean:
	rm -rf *.o
	rm -rf hash-table

    
    