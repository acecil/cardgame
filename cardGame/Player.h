#pragma once

#include <string>

class Hand;
class Trick;
class Card;

class Player
{
public:
	Player(void);
	Player(std::string name);
	~Player(void);

	void Reset(void) { m_score = 0; }

	void Deal(Hand* hand);

	Card* PlayCard(Trick* trick, bool followSuit);

	int GetScore(void) const;
	void AddScore(int score);

	unsigned int GetNumCards(void) const;

	std::string ToString(void) const { return m_name; }

	bool operator<(Player*& other){ return other->m_name < m_name; }

private:
	std::string m_name;
	int m_score;
	Hand* m_hand;
	
};
