#ifndef SPELL_H
#define SPELL_H
#include <string>
#include <iostream>
#include "card.h"

class Spell : public Card {
public:
	Spell(std::string cardName, int cost);

	virtual std::vector<std::string> & getoutput() = 0;

	virtual void playCard(Player * playedby, Player * target) = 0;
	virtual void playCard(Player * playedby, Card * target) = 0;

	// inspect i, hand
	// friend std::ostream &operator<<(std::ostream &out, const Card c);
};

#endif
