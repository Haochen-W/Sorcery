#include "card.h"

Card::Card(std::string cardName, int cost):
  cardName{cardName}, cost{cost} {}

int Card::getcost() {return cost;}
std::string Card::getcardName() {return cardName;}
void Card::setcost(int ncost){cost = ncost;}

void Card::playCard(Player * playedby, Player * opponent, int i){return;}
void Card::playCard(Player * playedby, Player * opponent, int i, bool onme, int t){return;}
void Card::playCard(Player * playedby, Player * opponent, int i, bool onme, bool ritual){return;}

void Card::minionAttack(Player * target){return;}

void Card::minionAttack(Player * target, int i){return;}

void Card::takeDamage(int damage){return;}

bool Card::miniondead(){return false;}

void Card::gainaction(){return;}

void Card::triggereffect(Player * playedby, Player * opponent, Card * c){return;}
void Card::playCard(Player * playedby, Card * target){return;}

void Card::toGraveyard(Player * p, int i){return;}

int Card::getattackval(){return 0;}
int Card::getdefenceval(){return 0;}
int Card::getaction(){return 0;}
int Card::getabilityCost(){return 0;}
int Card::getactioneachturn(){return 0;}
std::vector<std::string> & Card::getEnchantmentadded(){
	std::vector<std::string> temp;
	return temp;
}
bool Card::getcanuse(){return true;}

void Card::setattackval(int nattackval){return;}
void Card::setdefenceval(int ndefenceval){return;}
void Card::setabilityCost(int nabilityCost){return;}
void Card::setaction(int naction){return;}
void Card::setactioneachturn(int nactioneachturn){return;}
void Card::setcanuse(bool ncanuse){return;}

void Card::useMinion(Player * playedby, Player * opponent){return;}
void Card::useMinion(Player * playedby, Player * opponent, Card * c) {return;}

int Card::getcharge (){return 0;}
void Card::setcharge (int ncharge){return;}
