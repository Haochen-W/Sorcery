#include "minion.h"

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


