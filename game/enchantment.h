#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H
#include <string>
#include <iostream>
#include "decorator.h"

class Enchantment : public Decorator { // decorator

public:
	Enchantment(std::string cardName, int cost);

	virtual std::vector<std::string> & getoutput() = 0;

	vitual void playCard(Player * playedby, Player * target) = 0; // empty function body
	vitual void playCard(Player * playedby, Card * target) = 0; // call effect function on target minion / ritural

	// inspect i, hand
	// friend std::ostream &operator<<(std::ostream &out, const Card c);
};

#endif
