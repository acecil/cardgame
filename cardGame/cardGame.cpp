// cardGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Game.h"
#include "Player.h"
#include "Settings.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Game *game = new Game(&Trumps, 1);

	game->AddPlayer(new Player("Andrew"));
	game->AddPlayer(new Player("Richard"));
	game->AddPlayer(new Player("Judy"));

	game->Play();

	return 0;
}

