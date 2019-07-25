#include "card.h"

Card::Card(std::string cardName, int cost):
  cardName{cardName}, cost{cost} {}

int Card::getcost() {return cost;}
std::string Card::getcardName() {return cardName;}
void Card::setcost(int ncost){cost = ncost;}

void Card::playCard(Player * playedby, Player * target, int i){return;}

void Card::minionAttack(Player * target){return;}

void Card::minionAttack(Player * target, int i){return;}

void Card::takeDamage(int damage){return;}

bool Card::miniondead(){return false;}

void Card::setaction(int naction){return;}

int Card::getaction(){return 0;}

void Card::gainaction(){return;}