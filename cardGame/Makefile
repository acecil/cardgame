#
# (c) Copyright 2010, 2011, Andrew Gascoyne-Cecil, Winni Lam.
#
# This file is part of CardGame.
#
# CardGame is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# CardGame is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with CardGame.  If not, see <http://www.gnu.org/licenses/>.
#

CC = g++
CFLAGS = -c -Wall
LDFLAGS =
SOURCES = cardGame.cpp Game.cpp Deck.cpp Player.cpp Trick.cpp Hand.cpp Card.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = cardgame

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@