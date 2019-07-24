#include "decorator.h"

Decorator::Decorator(std::string cardName, int cost): 
	Card{cardName, cost}, component{nullptr}{}

Minion * Decorator::getcomponent(){return component;}
void Decorator::setcomponent(Minion * ncomponent){component = ncomponent;}

