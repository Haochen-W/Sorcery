#include "concreteenchantment.h"

Giantstrength::Giantstrength(): Enchantment{"Giant Strength", 1} {}

std::vector<std::string> Giantstrength::getoutput(){
	std::vector<std::string> temp {display_enchantment_attack_defence("Giant Strength", 1, "", "+2", "+2")};
	return temp;
}


Enrage::Enrage(): Enchantment{"Enrage", 2} {}

std::vector<std::string> Enrage::getoutput(){
	std::vector<std::string> temp {display_enchantment_attack_defence("Enrage", 2, "", "*2", "*2")};
	return temp;
}


Haste::Haste(): Enchantment{"Haste", 1} {}

std::vector<std::string> Haste::getoutput(){
	std::vector<std::string> temp {display_enchantment("Haste", 1, "Enchanted minion gains +1 action each turn")};
	return temp;
}


Magicfatigue::Magicfatigue(): Enchantment{"Magic Fatigue", 0} {}

std::vector<std::string> Magicfatigue::getoutput(){
	std::vector<std::string> temp {display_enchantment("Magic Fatigue", 0, "Enchanted minion's activated ability costs 2 more")};
	return temp;
}


Silence::Silence(): Enchantment{"Silence", 1} {}

std::vector<std::string> Silence::getoutput(){
	std::vector<std::string> temp {display_enchantment("Silence", 1, "Enchanted minion cannot use abilities")};
	return temp;
}

