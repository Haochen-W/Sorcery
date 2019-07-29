#include "ritual.h"

Ritual::Ritual(std::string cardName, int cost, int activationCost, int charge): 
  Card{cardName, cost}, activationCost{activationCost}, charge{charge} {}

int Ritual::getactivationCost () const {return activationCost;}
int Ritual::getcharge () const {return charge;}

void Ritual::setactivationCost (int nactivationCost){activationCost = nactivationCost;}
void Ritual::setcharge (int ncharge){charge = ncharge;}

void Ritual::playCard(Player * playedby, Player * opponent, int i){
	std::shared_ptr<Card> temp{(playedby->gethand())[i - 1]};
	(playedby->gethand()).erase((playedby->gethand()).begin() + i - 1);
	playedby->getactiveRitual().emplace_back(temp);
}
