#include "concreteminion.h"

Airelemental::Airelemental(): Minion{"Air Elemental", 0, 1, 1, 0, 0} {}

std::vector<std::string> & Airelemental::getoutput(){
	return display_minion_no_ability("Air Elemental", 0, attactval, defenceval);
}


Earthelemental::Earthelemental(): Minion{"Earth Elemental", 3, 4, 4, 0, 0} {}

std::vector<std::string> & Earthelemental::getoutput(){
	return display_minion_no_ability("Earth Elemental", 3, attactval, defenceval);
}


Bonegolem::Bonegolem(): Minion{"Bone Golem", 2, 1, 3, 0, 0} {}

std::vector<std::string> & Bonegolem::getoutput(){
	return display_minion_triggered_ability("Bone Golem", 2, attactval, defenceval, "Gain +1/+1 whenever a minion leaves play");
}


Fireelemental::Fireelemental(): Minion{"Fire Elemental", 2, 2, 2, 0, 0} {}

std::vector<std::string> & Fireelemental::getoutput(){
	return display_minion_triggered_ability("Fire Elemental", 2, attactval, defenceval, "Whenever an opponent's minion enters play, deal 1 damage to it");
}


Potionseller::Potionseller(): Minion{"Potion Seller", 2, 1, 3, 0, 0} {}

std::vector<std::string> & Potionseller::getoutput(){
	return display_minion_triggered_ability("Potion Seller", 2, attactval, defenceval, "At the end of your turn, all your minions gain +0/+1");
}


Novicepyromancer::Novicepyromancer(): Minion{"Novice Pyromancer", 1, 0, 1, 1, 0} {}

std::vector<std::string> & Novicepyromancer::getoutput(){
	return display_minion_activated_ability("Novice Pyromancer", 1, attactval, defenceval, abilityCost, "Deal 1 damage to target minion");
}


Apprenticesummoner::Apprenticesummoner(): Minion{"Apprentice Summoner", 1, 1, 1, 1, 0} {}

std::vector<std::string> & Apprenticesummoner::getoutput(){
	return display_minion_activated_ability("Apprentice Summoner", 1, attactval, defenceval, abilityCost, "Summon a 1/1 air elemental");
}


Mastersummoner::Mastersummoner(): Minion{"Master Summoner", 3, 2, 3, 2, 0} {}

std::vector<std::string> & Mastersummoner::getoutput(){
	return display_minion_activated_ability("Master Summoner", 3, attactval, defenceval, abilityCost, "Summon up to three 1/1 air elementals");
}

