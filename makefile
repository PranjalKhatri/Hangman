all: main.o classes.o
	g++ -o Hangman main.o classes.o

main.o: main.cpp
	g++ -c main.cpp

classes.o: classes.cpp
	g++ -c classes.cpp

clean:
	del *.o
	del *.exe
rebuild:
	make clean
	make