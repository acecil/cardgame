#pragma once

class Settings
{
public:
	unsigned int CardsPerPlayer;
	bool LastWinnerPlaysFirst;
	bool FollowSuit;
	bool Trumps;
	bool PlayInOrder;
	bool PlayAllCards;

};

const Settings Whist = { 7, true, true, false, true, true };
