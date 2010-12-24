// cardGame.cpp : Defines the entry point for the console application.
//

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

