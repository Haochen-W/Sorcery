#include "minion.h"
#include "concreteminion.h"

Minion::Minion(std::string cardName, int cost, int attackval, int defenceval, int abilityCost):
  Card{cardName, cost}, attackval{attackval}, defenceval{defenceval}, abilityCost{abilityCost}, action{0}, actioneachturn{1}, canuse{true}{}

int Minion::getattackval() const {return attackval;}
int Minion::getdefenceval() const {return defenceval;}
int Minion::getabilityCost() const {return abilityCost;}
int Minion::getaction() const {return action;}
int Minion::getactioneachturn() const {return actioneachturn;}
std::vector<std::string> & Minion::getEnchantmentadded(){return Enchantmentadded;}
bool Minion::getcanuse() const {return canuse;}

void Minion::setattackval(int nattackval){attackval = nattackval;}
void Minion::setdefenceval(int ndefenceval){defenceval = ndefenceval;}
void Minion::setabilityCost(int nabilityCost){abilityCost = nabilityCost;}
void Minion::setaction(int naction){action = naction;}
void Minion::setactioneachturn(int nactioneachturn){actioneachturn = nactioneachturn;}
void Minion::setcanuse(bool ncanuse){canuse = ncanuse;}

void Minion::minionAttack(Player * target){
	const int att = getattackval();
	target->setlife(target->getlife() - att);
}
void Minion::minionAttack(Player * target, int i){
	const int att = getattackval();
	target->getminionslot()[i - 1]->takeDamage(att);
}
void Minion::playCard(Player * playedby, Player * opponent, int i){
	if (playedby->getminionslot().size() >= 5){
		InvalidMove e {"Your minion slot is full."};
        throw e;
	}
	std::shared_ptr<Card> temp{(playedby->gethand())[i - 1]};
	(playedby->gethand()).erase((playedby->gethand()).begin() + i - 1);
	(playedby->getminionslot()).emplace_back(temp);
	playedby->trigger(GameStage::curNewMinion, temp, opponent);
	opponent->trigger(GameStage::oppNewMinion, temp, playedby);
}
void Minion::useMinion(Player * playedby, Player * opponent){return;}
void Minion::useMinion(Player * playedby, Player * opponent, Card * c, int t){return;}

void Minion::takeDamage(int damage){
	defenceval -= damage;
}
void Minion::toGraveyard(Player * p, int i){
	std::shared_ptr<Card> temp{p->getminionslot()[i - 1]};
	p->getminionslot().erase(p->getminionslot().begin() + i - 1);
	temp->disenchantall();
	p->getgraveyard().emplace_back(temp);
}
bool Minion::miniondead() {
	return (getdefenceval() <= 0);
}

void Minion::gainaction(){
	setaction(getactioneachturn());
}
void Minion::disenchantall(){
	const int m = getEnchantmentadded().size();
	for (int i = 0; i < m; i++){
		int index = getEnchantmentadded().size() - 1;
		std::string s = getEnchantmentadded()[index];
		const int att = getattackval();
		const int def = getdefenceval();
		if (s == "Giant Strength"){
			setattackval(att - 2);
			setdefenceval(def - 2);
		} else if (s == "Enrage"){
			setattackval(att / 2);
			setdefenceval(def / 2);
		} else if (s == "Haste"){
			const int curr = getactioneachturn();
			setactioneachturn(curr - 1);
		} else if (s == "Magic Fatigue"){
			const int curr = getabilityCost();
			setabilityCost(curr - 2);
		} else if (s == "Silence"){
			setcanuse(true);
		}
		getEnchantmentadded().erase(getEnchantmentadded().begin() + index);
	}
}
