#include "minion.h"
#include "concreteminion.h"

Minion::Minion(std::string cardName, int cost, int attackval, int defenceval, int abilityCost):
  Card{cardName, cost}, attackval{attackval}, defenceval{defenceval}, abilityCost{abilityCost}, action{0} {}

int Minion::getattackval() {return attackval;}
int Minion::getdefenceval() {return defenceval;}
int Minion::getabilityCost() {return abilityCost;}
int Minion::getaction() {return action;}

void Minion::setattackval(int nattackval){attackval = nattackval;}
void Minion::setdefenceval(int ndefenceval){defenceval = ndefenceval;}
void Minion::setabilityCost(int nabilityCost){abilityCost = nabilityCost;}
void Minion::setaction(int naction){action = naction;}

void Minion::playCard(Player * playedby, Player * opponent, int i){
	std::shared_ptr<Card> temp{(playedby->gethand())[i - 1]};
	(playedby->gethand()).erase((playedby->gethand()).begin() + i - 1);
	(playedby->getminionslot()).emplace_back(temp);
	playedby->trigger(GameStage::curNewMinion, temp, opponent);
	opponent->trigger(GameStage::oppNewMinion, temp, opponent);
}

// void Minion::playCard(Player * playedby, Card * target) {return;}
void Minion::minionAttack(Player * target){
	const int att = getattackval();
	target->setlife(target->getlife() - att);
}

void Minion::takeDamage(int damage){
	defenceval -= damage;
}

void Minion::minionAttack(Player * target, int i){
	const int att = getattackval();
	target->getminionslot()[i - 1]->takeDamage(att);
}

bool Minion::miniondead() {
	return (getdefenceval() <= 0);
}

void Minion::toGraveyard(Player * p, int i){
	std::shared_ptr<Card> temp{p->getminionslot()[i - 1]};
    p->getminionslot().erase(p->getminionslot().begin() + i - 1);
    p->getgraveyard().emplace_back(temp);
}

void Minion::gainaction(){
	setaction(1);
}
