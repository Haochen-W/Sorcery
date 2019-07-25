#include "concreteminion.h"

Airelemental::Airelemental(): Minion{"Air Elemental", 0, 1, 1, 0} {}

std::vector<std::string> Airelemental::getoutput(){
	std::vector<std::string> temp {display_minion_no_ability("Air Elemental", 0, attackval, defenceval)};
	return temp;
}


Earthelemental::Earthelemental(): Minion{"Earth Elemental", 3, 4, 4, 0} {}

std::vector<std::string> Earthelemental::getoutput(){
	std::vector<std::string> temp {display_minion_no_ability("Earth Elemental", 3, attackval, defenceval)};
	return temp;
}


Bonegolem::Bonegolem(): Minion{"Bone Golem", 2, 1, 3, 0} {}

std::vector<std::string> Bonegolem::getoutput(){
	std::vector<std::string> temp {display_minion_triggered_ability("Bone Golem", 2, attackval, defenceval, "Gain +1/+1 whenever a minion leaves play")};
	return temp;
}

void Bonegolem::triggereffect(Player * playedby, Player * opponent, std::shared_ptr<Card> c){
	std::cout << "HI" << std::endl;
	c->setattackval(c->getattackval() + 1);
	c->setdefenceval(c->getdefenceval() + 1);
}


Fireelemental::Fireelemental(): Minion{"Fire Elemental", 2, 2, 2, 0} {}

std::vector<std::string> Fireelemental::getoutput(){
	std::vector<std::string> temp {display_minion_triggered_ability("Fire Elemental", 2, attackval, defenceval, "Whenever an opponent's minion enters play, deal 1 damage to it")};
	return temp;
}

void Fireelemental::triggereffect(Player * playedby, Player * opponent, std::shared_ptr<Card> c){
	c->setdefenceval(c->getdefenceval() - 1);
}


Potionseller::Potionseller(): Minion{"Potion Seller", 2, 1, 3, 0} {}

std::vector<std::string> Potionseller::getoutput(){
	std::vector<std::string> temp {display_minion_triggered_ability("Potion Seller", 2, attackval, defenceval, "At the end of your turn, all your minions gain +0/+1")};
	return temp;
}

void Potionseller::triggereffect(Player * playedby, Player * opponent, std::shared_ptr<Card> c){
	c->setdefenceval(c->getdefenceval() + 1);
}


Novicepyromancer::Novicepyromancer(): Minion{"Novice Pyromancer", 1, 0, 1, 1} {}

std::vector<std::string> Novicepyromancer::getoutput(){
	std::vector<std::string> temp {display_minion_activated_ability("Novice Pyromancer", 1, attackval, defenceval, abilityCost, "Deal 1 damage to target minion")};
	return temp;
}


Apprenticesummoner::Apprenticesummoner(): Minion{"Apprentice Summoner", 1, 1, 1, 1} {}

std::vector<std::string> Apprenticesummoner::getoutput(){
	std::vector<std::string> temp {display_minion_activated_ability("Apprentice Summoner", 1, attackval, defenceval, abilityCost, "Summon a 1/1 air elemental")};
	return temp;
}


Mastersummoner::Mastersummoner(): Minion{"Master Summoner", 3, 2, 3, 2} {}

std::vector<std::string> Mastersummoner::getoutput(){
	std::vector<std::string> temp {display_minion_activated_ability("Master Summoner", 3, attackval, defenceval, abilityCost, "Summon up to three 1/1 air elementals")};
	return temp;
}

