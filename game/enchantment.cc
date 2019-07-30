#include "enchantment.h"

Enchantment::Enchantment(std::string cardName, int cost, Minion * component):
  Decorator{cardName, cost, component} {}

void Enchantment::playCard(Player * playedby, Player * opponent, int i, bool onme, int t){return;}
