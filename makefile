all: search

search: linear.o binary.o sb_main_final.o
	g++ -std=c++0x -o search linear.o sb_main_final.o binary.o

linear.o: linear.cpp linear.h
	g++ -c linear.cpp

sb_main_final.o: sb_main_final.cpp linear.h binary.h
	g++ -c sb_main_final.cpp

binary.o: binary.cpp binary.h
	g++ -c binary.cpp

clean:
	rm -rf *.o
	rm -rf search

    
    