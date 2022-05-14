.PHONY: clean bin/main
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD

bin/main: obj/src/chessviz/main.o obj/src/libchessviz/libchessviz.a
	gcc $(CFLAGS) -o $@ $^

bin/test: obj/test/main.o obj/src/libchessviz/libchessviz.a
	gcc $(CFLAGS) -o $@ $^


obj/src/libchessviz/libchessviz.a: obj/src/libchessviz/print_chess_board.o obj/src/libchessviz/coordinates.o obj/src/libchessviz/move.o obj/src/libchessviz/pawn_move.o obj/test/test.o
	ar src $@ $^

obj/src/libchessviz/print_chess_board.o: src/libchessviz/print_chess_board.c
	gcc -c $(CFLAGS) $(CPPFLAGS) -I src/ -o $@ src/libchessviz/print_chess_board.c

obj/src/libchessviz/coordinates.o:  src/libchessviz/coordinates.c
	gcc -c $(CFLAGS) $(CPPFLAGS) -I src/ -o $@ src/libchessviz/coordinates.c

obj/src/libchessviz/move.o: src/libchessviz/move.c
	gcc -c $(CFLAGS) $(CPPFLAGS) -I src/ -o $@ src/libchessviz/move.c

obj/src/libchessviz/pawn_move.o: src/libchessviz/pawn_move.c
	gcc -c $(CFLAGS) $(CPPFLAGS) -I src/ -o $@ src/libchessviz/pawn_move.c

obj/src/chessviz/main.o: src/chessviz/main.c
	gcc -c $(CFLAGS) $(CPPFLAGS) -I src/ -o $@ src/chessviz/main.c


obj/test/test.o: test/test.c
	gcc -c $(CFLAGS) $(CPPFLAGS) -I src/ -o $@ $<

obj/test/main.o: test/main.c
	gcc -c $(CFLAGS) $(CPPFLAGS) -I src/ -o $@ $<

run/main:
	./bin/main

run/test:
	./bin/test

clean:
	rm obj/src/chessviz/.o
	rm obj/src/libchessviz/.o
	rm obj/src/chessviz/.d
	rm obj/src/libchessviz/.d
	rm obj/test/.o obj/test/.d