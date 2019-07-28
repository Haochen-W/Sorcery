#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H
#include <string>
#include <iostream>
#include "decorator.h"

class Enchantment : public Decorator { // decorator of minion
public:
	Enchantment(std::string cardName, int cost, Minion * component);
	~Enchantment() = default;
	virtual void playCard(Player * playedby, Player * opponent, int i, bool onme, int t);
};

#endif
