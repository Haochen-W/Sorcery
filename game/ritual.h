#ifndef RITUAL_H
#define RITUAL_H
#include <string>
#include <iostream>
#include "card.h"

class Ritual : public Card { // observer
	int activationCost;
	int charge;
	// effect

public:
	Spell(std::string cardName, int cost, int activationCost, int charge); // effect

	Card * playCard() override; // return ritual, call effect function
	void playCard(Card * target) override; // call effect function on target minion / ritural

	// inspect i, hand
	// friend std::ostream &operator<<(std::ostream &out, const Card c);
};

#endif
