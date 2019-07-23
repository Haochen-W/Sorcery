#include "concreteenchantment.h"

Giantstrength::Giantstrength(): Enchantment{"Giant Strength", 1} {}

std::vector<std::string> & Giantstrength::getoutput(){
	return display_enchantment_attack_defense("Giant Strength", 1, "", "+2", "+2");
}


Enrage::Enrage(): Enchantment{"Enrage", 2} {}

std::vector<std::string> & Enrage::getoutput(){
	return display_enchantment_attack_defense("Enrage", 2, "", "*2", "*2");
}


Haste::Haste(): Enchantment{"Haste", 1} {}

std::vector<std::string> & Haste::getoutput(){
	return display_enchantment("Haste", 1, "Enchanted minion gains +1 action each turn");
}


Magicfatigue::Magicfatigue(): Enchantment{"Magic Fatigue", 0} {}

std::vector<std::string> & Magicfatigue::getoutput(){
	return display_enchantment("Magic Fatigue", 0, "Enchanted minion's activated ability costs 2 more");
}


Silence::Silence(): Enchantment{"Silence", 1} {}

std::vector<std::string> & Silence::getoutput(){
	return display_enchantment("Silence", 1, "Enchanted minion cannot use abilities");
}

