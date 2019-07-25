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
	~Ritual() = default;

	int getactivationCost ();
	int getcharge ();
	void setactivationCost (int nactivationCost);
	void setcharge (int ncharge);

	void playCard(Player * playedby, Player * opponent, int i) override; // place ritual on ritual slot
	// play i p t {return;}
};

#endif
