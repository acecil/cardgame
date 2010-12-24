#pragma once

class Settings
{
public:
	unsigned int CardsPerPlayer;
	bool LastWinnerPlaysFirst;
	bool FollowSuit;
	bool Trumps;
	bool TrumpsRandom;
	bool PlayInOrder;
	bool PlayAllCards;
	bool AcesHigh;

};

const Settings Whist = { 7, true, true, false, false, true, true, true };
const Settings Trumps = { 7, true, true, true, true, true, true, true };
