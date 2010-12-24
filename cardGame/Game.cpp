#include "StdAfx.h"

#include <iostream>
#include <algorithm>
#include <time.h>

#include "Game.h"

#include "Deck.h"
#include "Player.h"
#include "Hand.h"
#include "Card.h"
#include "Settings.h"
#include "Trick.h"

Game::Game(const Settings* settings, unsigned int numRounds)
{
	m_settings = settings;
	m_numRounds = numRounds;

	Card::SetAcesHigh(m_settings->AcesHigh);

	m_deck = new Deck();

	reset();
}


Game::~Game(void)
{
	if(m_deck) delete m_deck;

	while(!m_players.empty())
	{
		delete m_players.front();
		m_players.pop_front();
	}

	while(!m_tricks.empty())
	{
		delete m_tricks.front();
		m_tricks.pop_front();
	}
}

void Game::AddPlayer(Player* player)
{
	m_players.push_back(player);
}

void Game::Play(void)
{
	reset();

	while(!m_gameOver)
	{
		PlayRound();

		if(m_roundsPlayed >= m_numRounds)
		{
			m_gameOver = true;
		}
	}
}

void Game::PlayRound(void)
{
	/* Shuffle */
	m_deck->Shuffle();

	/* Deal */
	unsigned int numPlayers = m_players.size();
	std::list<Hand*> hands;

	for(unsigned int i = 0; i < numPlayers; i++)
	{
		hands.push_back(new Hand());
	}
	
	std::vector<Card*>::iterator c = m_deck->Begin();
	std::list<Hand*>::iterator h;
	for(unsigned int i = 0; i < m_settings->CardsPerPlayer; i++)
	{
		for(h = hands.begin(); h != hands.end(); ++h)
		{
			(*h)->Deal(*c);
			c++;
		}
	}

	std::list<Player*>::iterator p;
	for(p = m_players.begin(), h = hands.begin(); p != m_players.end(), h != hands.end(); ++p, ++h)
	{
		(*p)->Deal(*h);
	}

	if(m_settings->PlayAllCards)
	{
		while(count_cards() > 0)
		{
			PlayTrick();
		}
	}
	else
	{
		/* Some other means for determining the round is complete. */
	}

	m_roundsPlayed++;

}

void Game::PlayTrick(void)
{
	/* Play */
	Player* nextPlayer = m_players.front();
	if(m_settings->LastWinnerPlaysFirst)
	{
		if(m_lastWinner)
		{
			nextPlayer = m_lastWinner;
		}
	}
	else
	{
		/* Some other means for deciding the player order. */
	}

	/* Determine trumps. */
	Suit trumps;
	if(m_settings->Trumps)
	{
		if(m_settings->TrumpsRandom)
		{
			trumps = (Suit)(rand() % LastSuit);
			std::cout << "Trumps: " << SuitToString(trumps) << std::endl;
		}
		else
		{
			/* Other methods for determining trumps. */
		}
	}

	Trick *trick = new Trick(m_settings, m_players, trumps);

	while(!trick->Complete())
	{
		trick->Play(nextPlayer, nextPlayer->PlayCard(trick, m_settings->FollowSuit));

		if(m_settings->PlayInOrder)
		{
			std::list<Player*>::iterator it = std::find(m_players.begin(), m_players.end(), nextPlayer);
			std::list<Player*>::iterator it2 = it;
			if(it2 == m_players.end() || (++it2) == m_players.end())
			{
				nextPlayer = m_players.front();
			}
			else
			{
				nextPlayer = *(++it);
			}
		}
		else
		{
			/* Determine next player by some other means here. */
			std::list<Player*>::iterator it = std::find(m_players.begin(), m_players.end(), nextPlayer);
			std::list<Player*>::iterator it2 = it;
			if(it2 == m_players.end() || (++it2) == m_players.end())
			{
				nextPlayer = m_players.front();
			}
			else
			{
				nextPlayer = *(++it);
			}
		}
	}

	/* Score */
	m_lastWinner = trick->Score();

	std::list<Player*>::iterator p;
	for(p = m_players.begin(); p != m_players.end(); ++p)
	{
		std::cout << (*p)->ToString() << ": " << (*p)->GetScore() << std::endl;
	}

	m_tricks.push_back(trick);
}

Player* Game::GetWinner(void) const
{
	Player* winner;
	int maxScore = 0;

	std::list<Player*>::const_iterator i;
	for(i = m_players.begin(); i != m_players.end(); ++i)
	{
		if((*i)->GetScore() > maxScore)
		{
			winner = *i;
			maxScore = (*i)->GetScore();
		}
	}

	return winner;
}

void Game::reset(void)
{
	srand(unsigned int(time(NULL)));

	std::list<Trick*>::iterator t;
	for(t = m_tricks.begin(); t != m_tricks.end(); ++t)
	{
		delete m_tricks.front();
		m_tricks.pop_front();
	}

	m_gameOver = false;

	m_roundsPlayed = 0;

	m_lastWinner = NULL;

	std::list<Player*>::iterator p;
	for(p = m_players.begin(); p != m_players.end(); ++p)
	{
		(*p)->Reset();
	}
}

unsigned int Game::count_cards(void) const
{
	unsigned int num_cards = 0;

	std::list<Player*>::const_iterator p;
	for(p = m_players.begin(); p != m_players.end(); ++p)
	{
		num_cards += (*p)->GetNumCards();
	}

	return num_cards;
}
