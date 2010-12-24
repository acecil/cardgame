CC=g++
CFLAGS=

IDIR=.
ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = Game.h Settings.h Deck.h Player.h Trick.h Hand.h Card.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = Game.o Settings.o Deck.o Player.o Trick.o Hand.o Card.o cardGame.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

cardgame: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(IDIR)/*~ 