/*
 * (c) Copyright 2010, 2011, Andrew Gascoyne-Cecil, Winni Lam.
 *
 * This file is part of CardGame.
 *
 * CardGame is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CardGame is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CardGame.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>

#include "Game.h"
#include "Player.h"
#include "Settings.h"

int main(int argc, char* argv[])
{
	Game *game = new Game(&Trumps, 1);

	game->AddPlayer(new Player("Andrew"));
	game->AddPlayer(new Player("Richard"));

	game->Play();

	game->PrintResult();

	std::cin.ignore();
	std::cin.ignore();

	return 0;
}

