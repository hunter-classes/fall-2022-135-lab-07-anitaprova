main: main.o unindent.o indent.o
	g++ -o main main.o unindent.o indent.o

main.o: main.cpp unindent.h indent.h
	g++ -c main.cpp

unindent.o: unindent.cpp unindent.h
	g++ -c unindent.cpp

indent.o: indent.cpp indent.h
	g++ -c indent.cpp

clean:
	rm -f main main.o unindent.o indent.o 
