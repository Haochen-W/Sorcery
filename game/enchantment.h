#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H
#include <string>
#include <iostream>
#include "decorator.h"

class Enchantment : public Decorator { // decorator
	// effect

public:
	Enchantment(std::string cardName, int cost); // effect

	Card * playCard() override; // empty function body
	void playCard(Card * target) override; // call effect function on target minion / ritural

	// inspect i, hand
	// friend std::ostream &operator<<(std::ostream &out, const Card c);
};

#endif
