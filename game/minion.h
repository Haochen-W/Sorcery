#ifndef MINION_H
#define MINION_H
#include <string>
#include <iostream>
#include "card.h"

class Minion : public Card {
	int attackval;
	int defenceval;
	int action;
	// effect

public:
	Minion(std::string cardName, int cost, int attackval, int defenceval); // effect

	int minionAttack() override; // return damage
	int minionAttack(int i) override; // call mbeattack on target minion
	Card * playCard() override; // return the minion, place the minion into minion slot
	void playCard(Card * target) override; // call effect function on target minion / ritural
	void useMinion() override; // call effect function
	void useMinion(Card * target) override; // call effect function on target minion / ritual

	void causeDamage(int damage); // cause damage on minion

	// inspect i, hand
	// friend std::ostream &operator<<(std::ostream &out, const Card c);
};

#endif
