#include "concreteritual.h"
#include "minion.h"

Darkritual::Darkritual(): Ritual{"Dark Ritual", 0, 1, 5} {
	setactivationCost(1);
	setcharge(5);
}

std::vector<std::string> Darkritual::getoutput(){
	std::vector<std::string> temp {display_ritual("Dark Ritual", 0, activationCost, "At the start of your turn, gain 1 magic", charge)};
	return temp;
}

void Darkritual::triggereffect(Player * playedby, Player * opponent, Card * c){
	if(getcharge() < getactivationCost()){
		InvalidMove e{"Not enough charges"};
		throw e;
	}
	setcharge(getcharge() - getactivationCost());
}


Auraofpower::Auraofpower(): Ritual{"Aura of Power", 1, 1, 4} {
	setactivationCost(1);
	setcharge(4);
}

std::vector<std::string> Auraofpower::getoutput(){
	std::vector<std::string> temp {display_ritual("Aura of Power", 1, activationCost, "Whenever a minion enters play under your control, it gains +1/+1", charge)};
	return temp;
}

void Auraofpower::triggereffect(Player * playedby, Player * opponent, Card * c){
	if(getcharge() < getactivationCost()){
		InvalidMove e{"Not enough charges"};
		throw e;
	}
	c->setattackval(c->getattackval() + 1);
	c->setdefenceval(c->getdefenceval() + 1);
	setcharge(getcharge() - getactivationCost());
}


Standstill::Standstill(): Ritual{"Standstill", 3, 2, 4} {
	setactivationCost(2);
	setcharge(4);
}

std::vector<std::string> Standstill::getoutput(){
	std::vector<std::string> temp {display_ritual("Standstill", 3, activationCost, "Whenever a minion enters play, destroy it", charge)};
	return temp;
};

void Standstill::triggereffect(Player * playedby, Player * opponent, Card * c){
	if(getcharge() < getactivationCost()){
		InvalidMove e{"Not enough charges"};
		throw e;
	}
	playedby->trigger(GameStage::minionLeave, nullptr, opponent);
	opponent->trigger(GameStage::minionLeave, nullptr, opponent);
	c->toGraveyard(playedby, (playedby->getminionslot()).size());
	setcharge(getcharge() - getactivationCost());
}

