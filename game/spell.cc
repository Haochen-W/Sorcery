#include "spell.h"

Spell::Spell(std::string cardName, int cost):
	Card{cardName, cost} {}

void Spell::playCard(Player * playedby, Player * opponent, int i, bool onme, int t) {return;}
void Spell::playCard(Player * playedby, Player * opponent, int i, bool onme, bool ritual){return;}
