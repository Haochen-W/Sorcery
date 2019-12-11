#ifndef DECORATOR_H
#define DECORATOR_H
#include "minion.h"

class Decorator: public Card {
protected:
	Minion * component;
public:
	Decorator(std::string cardName, int cost, Minion * component);
	~Decorator() = default;

	Minion * getcomponent();
	void setcomponent(Minion * ncomponent);
	
	virtual void playCard(Player * playedby, Player * opponent, int i, bool onme, int t);
};

#endif
