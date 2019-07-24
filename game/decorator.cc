#include "decorator.h"

Minion * Decorator::getcomponent(){
	return component;
}
void Decorator::setcomponent(Minion * ncomponent){
	component = ncomponent;
}