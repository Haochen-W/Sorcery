#ifndef SPELL_H
#define SPELL_H
#include <string>
#include <iostream>
#include "card.h"

class Spell : public Card {
public:
	Spell(std::string cardName, int cost);
	~Spell() = default;
	virtual void playCard(Player * playedby, Player * opponent, int i);
	virtual void playCard(Player * playedby, Player * opponent, int i, bool onme, int t); // play ith card on t's minion
	virtual void playCard(Player * playedby, Player * opponent, int i, bool onme, bool ritual); // play ith card on ritual
};

#endif
