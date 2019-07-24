#include "card.h"

Card::Card(std::string cardName, int cost):
  cardName{cardName}, cost{cost} {}

int Card::getcost() {
	return cost;
}

std::string Card::getcardName() {
	return cardName;
}

void Card::setcost(int ncost){
	cost = ncost;
}