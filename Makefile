APP_NAME = main
LIB_NAME = libchessviz
SOURCE=src/chessviz/
LIBSOURCE=src/libchessviz/
OBJLIB=obj/src/libchessviz/
OBJCHESS=obj/src/chessviz/

CC = gcc -c
CFLAGS = -Wall -Werror
INCLUDEPATH = -I src

all: bin/chessviz

obj/src/libchessviz/coordinates.o: $(LIBSOURCE)coordinates.c
	$(CC) $(INCLUDEPATH) $< -o $@
obj/src/libchessviz/print_chess_board.o: $(LIBSOURCE)print_chess_board.c
	$(CC) $(INCLUDEPATH) $< -o $@
obj/src/libchessviz/move.o: $(LIBSOURCE)move.c
	$(CC) $(INCLUDEPATH) $< -o $@
obj/src/libchessviz/pawn_move.o: $(LIBSOURCE)pawn_move.c
	$(CC) $(INCLUDEPATH) $< -o $@
obj/src/chessviz/main.o: $(SOURCE)main.c
	$(CC) $(INCLUDEPATH) $< -o $@

obj/src/libchessviz/libchessviz.a: $(OBJLIB)coordinates.o $(OBJLIB)print_chess_board.o $(OBJLIB)move.o $(OBJLIB)pawn_move.o
	ar rcs $@ $^

bin/chessviz: $(OBJCHESS)main.o $(OBJLIB)libchessviz.a 
	gcc $(CFLAGS) $(INCLUDEPATH) $^ -o $@
run:
	./bin/chessviz
clean:
	rm -f $(OBJLIB)*.[oa]
	rm -f $(OBJCHESS)*.o
