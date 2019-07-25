#include "card.h"

Card::Card(std::string cardName, int cost):
  cardName{cardName}, cost{cost} {}

int Card::getcost() {return cost;}
std::string Card::getcardName() {return cardName;}
void Card::setcost(int ncost){cost = ncost;}

void Card::playCard(Player * playedby, Player * opponent, int i){return;}

void Card::minionAttack(Player * target){return;}

void Card::minionAttack(Player * target, int i){return;}

void Card::takeDamage(int damage){return;}

bool Card::miniondead(){return false;}

void Card::setaction(int naction){return;}

int Card::getaction(){return 0;}

void Card::gainaction(){return;}

void Card::triggereffect(Player * playedby, Player * opponent, std::shared_ptr<Card> c){return;}
void Card::toGraveyard(Player * p, int i){return;}

int Card::getattackval(){return 0;}
int Card::getdefenceval(){return 0;}
void Card::setattackval(int nattackval){return;}
void Card::setdefenceval(int ndefenceval){return;}
