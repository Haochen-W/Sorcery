#include "minion.h"

Minion::Minion(std::string cardName, int cost, int attackval, int defenceval, int abilityCost):
  Card{cardName, cost}, attackval{attackval}, defenceval{defenceval}, abilityCost{abilityCost}, action{0} {}
