#ifndef SPELL_H
#define SPELL_H
#include <string>
#include <iostream>
#include "card.h"

class Spell : public Card {
public:
	Spell(std::string cardName, int cost);
	~Spell() = default;
};

#endif
