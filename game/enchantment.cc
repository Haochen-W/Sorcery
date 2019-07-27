#include "enchantment.h"

Enchantment::Enchantment(std::string cardName, int cost, Minion * component):
  Decorator{cardName, cost, component} {}
