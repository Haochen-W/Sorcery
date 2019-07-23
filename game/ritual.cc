#include "ritual.h"

Ritual::Ritual(std::string cardName, int cost, int activationCost, int charge): 
  Card{cardName, cost}, activationCost{activationCost}, charge{charge} {}
