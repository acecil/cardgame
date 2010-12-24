#pragma once

struct Settings
{
	unsigned int CardsPerPlayer;
	bool LastWinnerPlaysFirst;
	bool FollowSuit;
	bool Trumps;
	bool PlayInOrder;

};

const Settings Whist = { 7, true, true, false, true };
