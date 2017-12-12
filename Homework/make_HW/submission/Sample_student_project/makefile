all: output

output: main.o game.o othello.o
	g++ main.o game.o othello.o -o output

main.o: main.cc game.h othello.h
	g++ -c main.cc game.h othello.h

game.o: game.cc game.h
	g++ -c game.cc


othello.o: othello.cc othello.h game.h piece.h colors.h
	g++ -c othello.cc game.h piece.h colors.h

clean:
	rm *.o output

