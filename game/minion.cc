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

// void Minion::playCard(Player * playedby, Player * target, int i){
// 	std::shared_ptr<Card> temp{(playedby->gethand())[i]};
// 	(playedby->gethand()).erase((playedby->gethand()).begin() + i - 1);
// 	(playedby->getminionslot()).emplace_back(temp);
// }

// void Minion::playCard(Player * playedby, Card * target) {return;}
