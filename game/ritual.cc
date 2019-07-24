#include "ritual.h"

Ritual::Ritual(std::string cardName, int cost, int activationCost, int charge): 
  Card{cardName, cost}, activationCost{activationCost}, charge{charge} {}

int Ritual::getactivationCost () {return activationCost;}
int Ritual::getcharge () {return charge;}

void Ritual::setactivationCost (int nactivationCost){activationCost = nactivationCost;}
void Ritual::setcharge (int ncharge){charge = ncharge;}

