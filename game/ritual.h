#ifndef RITUAL_H
#define RITUAL_H
#include <string>
#include <iostream>
#include "card.h"

class Ritual : public Card { // observer
protected:
	int activationCost;
	int charge;

public:
	Ritual(std::string cardName, int cost, int activationCost, int charge);

	virtual std::vector<std::string> & getoutput() = 0;

	virtual void playCard(Player * playedby, Player * target) = 0; // place the card on ritual slot
	virtual void playCard(Player * playedby, Card * target) = 0; 

	// inspect i, hand
	// friend std::ostream &operator<<(std::ostream &out, const Card c);
};

#endif
