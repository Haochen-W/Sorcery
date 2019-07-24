#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>
#include "player.h"

// class Player;

class Card {
	std::string cardName;
	int cost;

public:
	Card(std::string cardName, int cost);
	int getcost() const;
	std::string getcardName() const;

	void setcost(int ncost);
	virtual ~Card();	
	virtual std::vector<std::string> getoutput() = 0;

	// virtual void minionAttack(Player * target); // return damage, override in minion only
	// virtual void minionAttack(Player * target, int i); // attack ith minion, override in minion only
	// virtual void playCard(Player * playedby, Player * target) = 0; // return minion / ritual, and place it into minion slot
	// virtual void playCard(Player * playedby, Card * target) = 0; 
	// virtual void useMinion(Player * playedby, Player * target); // override in minion only
	// virtual void useMinion(Player * playedby, Card * target); // override in minion only

	// inspect i, hand
	// friend std::ostream &operator<<(std::ostream &out, const Card c);
};

#endif
