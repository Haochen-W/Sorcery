#ifndef SPELL_H
#define SPELL_H
#include <string>
#include <iostream>
#include "card.h"

Class Spell : public Card {
	// effect

public:
	Spell(std::string cardName, int cost); // effect

	Card * playCard() override; // return nullptr, call effect function
	void playCard(Card * target) override; // call effect function on target minion / ritural

	// inspect i, hand
	// friend std::ostream &operator<<(std::ostream &out, const Card c);
};

#endif
