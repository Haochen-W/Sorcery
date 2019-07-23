#ifndef MINION_H
#define MINION_H
#include <string>
#include <iostream>
#include "card.h"

class Minion : public Card {
protected:
	int attackval;
	int defenceval;
	int abilityCost;
	int action;

public:
	Minion(std::string cardName, int cost, int attackval, int defenceval, int abilityCost);

	virtual std::vector<std::string> & getoutput() = 0;

	void minionAttack(Player * target) override; // return damage
	void minionAttack(Player * target, int i) override; // call mbeattack on target minion
	void playCard(Player * playedby, Player * target) override; // place the minion into minion slot
	void playCard(Player * playedby, Card * target) override; // do nothing
	virtual void useMinion(Player * playedby, Player * target) = 0; // call activated ability
	virtual void useMinion(Player * playedby, Card * target) = 0; // with target

	void takeDamage(int damage); // cause damage on minion

	// inspect i, hand
	// friend std::ostream &operator<<(std::ostream &out, const Card c);
};

#endif
