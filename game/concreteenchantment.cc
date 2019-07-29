#include "concreteenchantment.h"

Giantstrength::Giantstrength(Minion * component): Enchantment{"Giant Strength", 1, component} {}

std::vector<std::string> Giantstrength::getoutput(){
	std::vector<std::string> temp {display_enchantment_attack_defence("Giant Strength", 1, "", "+2", "+2")};
	return temp;
}

void Giantstrength::playCard(Player * playedby, Player * opponent, int i, bool onme, int t){
	std::string s = "Giant Strength";
	if (onme){
		const int att = playedby->getminionslot()[t - 1]->getattackval();
		const int def = playedby->getminionslot()[t - 1]->getdefenceval();
		playedby->getminionslot()[t - 1]->setattackval(att + 2);
		playedby->getminionslot()[t - 1]->setdefenceval(def + 2);
		playedby->getminionslot()[t - 1]->getEnchantmentadded().emplace_back(s);
	} else {
		const int att = opponent->getminionslot()[t - 1]->getattackval();
		const int def = opponent->getminionslot()[t - 1]->getdefenceval();
		opponent->getminionslot()[t - 1]->setattackval(att + 2);
		opponent->getminionslot()[t - 1]->setdefenceval(def + 2);
		opponent->getminionslot()[t - 1]->getEnchantmentadded().emplace_back(s);
	}
	playedby->gethand().erase(playedby->gethand().begin() + i - 1);
}


Enrage::Enrage(Minion * component): Enchantment{"Enrage", 2, component} {}

std::vector<std::string> Enrage::getoutput(){
	std::vector<std::string> temp {display_enchantment_attack_defence("Enrage", 2, "", "*2", "*2")};
	return temp;
}

void Enrage::playCard(Player * playedby, Player * opponent, int i, bool onme, int t){
	std::string s = "Enrage";
	if (onme){
		const int att = playedby->getminionslot()[t - 1]->getattackval();
		const int def = playedby->getminionslot()[t - 1]->getdefenceval();
		playedby->getminionslot()[t - 1]->setattackval(att * 2);
		playedby->getminionslot()[t - 1]->setdefenceval(def * 2);
		playedby->getminionslot()[t - 1]->getEnchantmentadded().emplace_back(s);
	} else {
		const int att = opponent->getminionslot()[t - 1]->getattackval();
		const int def = opponent->getminionslot()[t - 1]->getdefenceval();
		opponent->getminionslot()[t - 1]->setattackval(att * 2);
		opponent->getminionslot()[t - 1]->setdefenceval(def * 2);
		opponent->getminionslot()[t - 1]->getEnchantmentadded().emplace_back(s);
	}
	playedby->gethand().erase(playedby->gethand().begin() + i - 1);
}


Haste::Haste(Minion * component): Enchantment{"Haste", 1, component} {}

std::vector<std::string> Haste::getoutput(){
	std::vector<std::string> temp {display_enchantment("Haste", 1, "Enchanted minion gains +1 action each turn")};
	return temp;
}

void Haste::playCard(Player * playedby, Player * opponent, int i, bool onme, int t){
	std::string s = "Haste";
	if (onme){
		const int curr = playedby->getminionslot()[t - 1]->getactioneachturn();
		const int now = playedby->getminionslot()[t - 1]->getaction();
		playedby->getminionslot()[t - 1]->setaction(now + 1);
		playedby->getminionslot()[t - 1]->setactioneachturn(curr + 1);
		playedby->getminionslot()[t - 1]->getEnchantmentadded().emplace_back(s);
	} else {
		const int curr = opponent->getminionslot()[t - 1]->getactioneachturn();
		const int now = opponent->getminionslot()[t - 1]->getaction();
		opponent->getminionslot()[t - 1]->setaction(now + 1);
		opponent->getminionslot()[t - 1]->setactioneachturn(curr + 1);
		opponent->getminionslot()[t - 1]->getEnchantmentadded().emplace_back(s);
	}
	playedby->gethand().erase(playedby->gethand().begin() + i - 1);
}


Magicfatigue::Magicfatigue(Minion * component): Enchantment{"Magic Fatigue", 0, component} {}

std::vector<std::string> Magicfatigue::getoutput(){
	std::vector<std::string> temp {display_enchantment("Magic Fatigue", 0, "Enchanted minion's activated ability costs 2 more")};
	return temp;
}

void Magicfatigue::playCard(Player * playedby, Player * opponent, int i, bool onme, int t){
	std::string s = "Magic Fatigue";
	if (onme){
		const int curr = playedby->getminionslot()[t - 1]->getabilityCost();
		playedby->getminionslot()[t - 1]->setabilityCost(curr + 2);
		playedby->getminionslot()[t - 1]->getEnchantmentadded().emplace_back(s);
	} else {
		const int curr = opponent->getminionslot()[t - 1]->getabilityCost();
		opponent->getminionslot()[t - 1]->setabilityCost(curr + 2);
		opponent->getminionslot()[t - 1]->getEnchantmentadded().emplace_back(s);
	}
	playedby->gethand().erase(playedby->gethand().begin() + i - 1);
}


Silence::Silence(Minion * component): Enchantment{"Silence", 1, component} {}

std::vector<std::string> Silence::getoutput(){
	std::vector<std::string> temp {display_enchantment("Silence", 1, "Enchanted minion cannot use abilities")};
	return temp;
}

void Silence::playCard(Player * playedby, Player * opponent, int i, bool onme, int t){
	std::string s = "Silence";
	if (onme){
		playedby->getminionslot()[t - 1]->setcanuse(false);
		playedby->getminionslot()[t - 1]->getEnchantmentadded().emplace_back(s);
	} else {
		opponent->getminionslot()[t - 1]->setcanuse(false);
		opponent->getminionslot()[t - 1]->getEnchantmentadded().emplace_back(s);
	}
	playedby->gethand().erase(playedby->gethand().begin() + i - 1);
}

