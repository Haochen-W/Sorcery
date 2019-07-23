#include "concretespell.h"

Banish::Banish(): Spell{"Banish", 2} {}

std::vector<std::string> & Banish::getoutput(){
	return display_spell("Banish", 2, "Destroy target minion or ritual");
}


Unsummon::Unsummon(): Spell{"Unsummon", 1} {}

std::vector<std::string> & Unsummon::getoutput(){
	return display_spell("Unsummon", 1, "Return target minion to its owner's hand");
}


Recharge::Recharge(): Spell{"Recharge", 1} {}

std::vector<std::string> & Recharge::getoutput(){
	return display_spell("Recharge", 1, "Your ritual gains 3 charges");
}


Disenchant::Disenchant(): Spell{"Disenchant", 1} {}

std::vector<std::string> & Disenchant::getoutput(){
	return display_spell("Disenchant", 1, "Destroy the top enchantment on target minion");
}


Raisedead::Raisedead(): Spell{"Raise Dead", 1} {}

std::vector<std::string> & Raisedead::getoutput(){
	return display_spell("Raise Dead", 1, "Resurrect the top minion in your graveyard and set its defence to 1");
}


Blizzard::Blizzard(): Spell{"Blizzard", 3} {}

std::vector<std::string> & Blizzard::getoutput(){
	return display_spell("Blizzard", 3, "Deal 2 damage to all minions");
}
