#ifndef ENCHANTMENT_H
#define ENCHANTMENT_H
#include <string>
#include <iostream>
#include "decorator.h"

class Enchantment : public Decorator { // decorator of minion
public:
	Enchantment(std::string cardName, int cost);
	~Enchantment() = default;
};

#endif
