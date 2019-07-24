#include "card.h"

Card::Card(std::string cardName, int cost):
  cardName{cardName}, cost{cost} {}

Card::~Card(){}
