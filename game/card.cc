#include "card.h"
Card::Card(std::string cardName, int cost):
  cardName{cardName}, cost{cost} {}


int Card::getcost() {return cost;}
std::string Card::getcardName() {return cardName;}
void Card::setcost(int ncost){cost = ncost;}

void Card::playCard(Player * playedby, Player * opponent, int i){return;}
void Card::playCard(Player * playedby, Player * opponent, int i, bool onme, int t){return;}
void Card::playCardonRitual(Player * playedby, Player * opponent, int i, bool onme){return;}

// for minions
int Card::getattackval() const {return 0;}
int Card::getdefenceval() const {return 0;}
int Card::getabilityCost() const {return 0;}
int Card::getaction() const {return 0;}
int Card::getactioneachturn() const {return 0;}
std::vector<std::string> & Card::getEnchantmentadded(){
	auto temp = std::make_shared<std::vector<std::string>>();
	return *temp;
}
bool Card::getcanuse() const {return true;}

void Card::setattackval(int nattackval){return;}
void Card::setdefenceval(int ndefenceval){return;}
void Card::setabilityCost(int nabilityCost){return;}
void Card::setaction(int naction){return;}
void Card::setactioneachturn(int nactioneachturn){return;}
void Card::setcanuse(bool ncanuse){return;}

void Card::minionAttack(Player * target){return;}
void Card::minionAttack(Player * target, int i){return;}
void Card::takeDamage(int damage){return;}
bool Card::miniondead(){return false;}
void Card::gainAction(){return;}
void Card::disenchantall(){return;}
void Card::toGraveyard(Player * p, int i){return;}
void Card::triggereffect(Player * playedby, Player * opponent, Card * c){return;}
void Card::useMinion(Player * playedby, Player * opponent){return;}
void Card::useMinion(Player * playedby, Player * opponent, Card * c, int t) {return;}

// for rituals
int Card::getcharge () const {return 0;}
void Card::setcharge (int ncharge){return;}
