#ifndef _DECORATOR_H_
#define _DECORATOR_H_
#include "minion.h"

class Decorator: public Card {
protected:
	Minion * component;
public:
	Decorator(std::string cardName, int cost, Minion * component);
	~Decorator() = default;

	Minion * getcomponent();
	void setcomponent(Minion * ncomponent);
};

#endif
