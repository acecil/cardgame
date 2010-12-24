CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=cardGame.cpp Game.cpp Deck.cpp Player.cpp Trick.cpp Hand.cpp Card.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=cardgame

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@